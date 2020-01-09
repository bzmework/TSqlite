/*
	Connection.cpp
*/

#include "stdafx.h"
#include "Glob.h"
#include "Messages.h"
#include "blobfn.h"
#include "unaccfn.h"
#include "TSqlite.h"
#include "Connection.h"
#include "Resultset.h"

//系统自动生成，勿修改
STDMETHODIMP Connection::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IConnection
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//创建结果集对象
HRESULT Connection::create_statement(CComPtr<IResultset>& pRs)
{
	//创建结果集
	CComObject<Resultset>* p = new CComObject<Resultset>;
	HRESULT hr = p->FinalConstruct();
	if (FAILED(hr))
	{
		delete p;
		return hr;
	}
	
	//查找结果集接口
	hr = p->QueryInterface(&pRs);
	if (FAILED(hr))
	{
		delete p;
		return hr;
	}
	
	//查找连接对象接口
	CComPtr<IConnection> pThis;
	hr = QueryInterface(IID_IConnection, (void**)&pThis);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//绑定连接对象到结果集
	hr = pRs->put_ActiveConnection(pThis);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//返回
	return S_OK;
}

//系统繁忙中监控回调处理
int Connection::busy_callback(void* pThis, int nTimes)
{
	Connection* poThis = static_cast<Connection*>(pThis);
	VARIANT_BOOL bResult;
	HRESULT hRet = poThis->Fire_Busy(nTimes, &bResult); //触发繁忙中事件
	if (SUCCEEDED(hRet))
	{
		return (VARIANT_FALSE == bResult)? 0 : 1;
	}
	else
	{
		return 0;
	}
}

//语句执行中监控回调处理
int Connection::progress_callback(void* pThis)
{
	Connection* poThis = static_cast<Connection*>(pThis);
	VARIANT_BOOL bResult;
	HRESULT hRet = poThis->Fire_Progress(&bResult); //触发执行中事件
	if (SUCCEEDED(hRet))
	{
		return (VARIANT_FALSE == bResult) ? 1 : 0;
	}
	else
	{
		return 0;
	}
}

//关于 
STDMETHODIMP Connection::AboutMe()
{
	MessageBox(NULL, ABOUTME, COPYRIGHT, MB_ICONWARNING | MB_OK);
	return S_OK;
}

//返回版本号
STDMETHODIMP Connection::get_Version(VARIANT *pVal)
{
	CComVariant v;
	CComBSTR bsVersion(sqlite3_libversion());	
	v = bsVersion;
	return v.Detach(pVal);
}

//获取当前数据库
STDMETHODIMP Connection::GetCurrentDB(void** pDB)
{
	*pDB = m_db;
	return S_OK;
}

//返回数据库, 例如: C:\NorthWind.db
STDMETHODIMP Connection::get_Db(BSTR *pVal)
{
	m_strDb.CopyTo(pVal);
	return S_OK;
}

//设置数据库, 例如: C:\NorthWind.db" 
STDMETHODIMP Connection::put_Db(BSTR newVal)
{
	if (m_db != NULL) //不能反复设置数据库, 必须先关闭.
	{
		return m_ErrMsg.system_error(E_DB_IS_OPEN);
	}
	m_strDb = newVal;
	return S_OK;
}

//打开数据库, strDb: 数据库(如C:\NorthWind.db) 或内存数据库(:memory:). 如果设置了Db属性, 则该参数可以忽略.
STDMETHODIMP Connection::Open(BSTR strDb)
{
	#ifndef _UNICODE
	USES_CONV_UTF8;
	#endif
	
	//不能反复打开数据库, 必须先关闭.
	if (m_db != NULL) 
	{
		return m_ErrMsg.system_error(E_DB_IS_OPEN);
	}
	
	//验证数据库是否有效
	if (SysStringLen(strDb) > 0)
	{
		put_Db(strDb);
	}
	
	//打开数据库
	int nRet = 0;
	#ifdef _UNICODE
		nRet = sqlite3_open16(m_strDb, &m_db);
	#else
		nRet = sqlite3_open(W2UTF8(m_strDb), &m_db);
	#endif
	
	//注册事件等
	if (nRet == SQLITE_OK)
	{
		sqlite3_register_blob_functions(m_db);

		#ifndef _NO_UNACC_STUFF
		m_vUnaccContext = sqlite3_register_unacc_functions( m_db );
		#endif

		sqlite3_busy_handler(m_db, &busy_callback, this);
		sqlite3_progress_handler(m_db, m_nProgress, &progress_callback, this);
	}
	
	//返回
	return m_ErrMsg.sqlite_error(nRet);
}

//打开内存数据库, 当数据库关闭时, 内存数据库中的所有内容将同时被销毁. 本函数等价于: oConn.Open(":memory:")
STDMETHODIMP Connection::OpenMemoryDb()
{
	CComBSTR strDb( _T(":memory:") );
	return Open(strDb);
}

//关闭数据库
STDMETHODIMP Connection::Close()
{
	int nRet = SQLITE_OK;
	
	if (m_db)
	{
		//中断数据库的所有操作
		sqlite3_interrupt(m_db);

		//反注册事件等
		#ifndef _NO_UNACC_STUFF
		sqlite3_unregister_unacc_functions(m_db, m_vUnaccContext);
		#endif
		sqlite3_busy_handler(m_db, NULL, 0);
		sqlite3_progress_handler(m_db, DEF_PROGRESS_PERIOD, NULL, 0);
		
		//关闭数据库
		nRet = sqlite3_close(m_db);
		if (nRet == SQLITE_OK) 
		{
			m_db = NULL;
		}
	}
	
	return m_ErrMsg.sqlite_error(nRet);
}

//执行SQL语句, 返回结果集Resultset. 
//例如: Set oRs = oConn.Execute("SELECT * FROM T WHERE c > 10")
STDMETHODIMP Connection::Execute(BSTR strSql, IResultset **ppRs)
{
	//验证数据库是否已被打开
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//创建结果集对象
	CComPtr<IResultset> pRs;
	HRESULT hr = create_statement(pRs);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(E_CANNOT_CREATE_STATEMENT);
	}
	
	//执行SQL
	hr = pRs->Prepare(strSql);
	if (FAILED(hr)) 
	{
		return hr;
	}

	//返回结果集
	return pRs->QueryInterface(ppRs);
}

//快速执行SQL语句, 语句中可以包含参数, 如果返回多行仅取第一行记录的数据. 
//例如: oConn.ExecuteSQL("INSERT INTO T(a, b) VALUES (?, ?)", "money", 88.88)
//或 nMax = oConn.ExecuteSQL("SELECT Max(c) FROM T")
STDMETHODIMP Connection::ExecuteSql(BSTR strSql, LPSAFEARRAY *params, VARIANT *pVal)
{
	//验证数据库是否已被打开
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//创建结果集对象
	CComPtr<IResultset> pRs;
	HRESULT hr = create_statement(pRs);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(E_CANNOT_CREATE_STATEMENT);
	}
	
	//准备SQL
	hr = pRs->Prepare(strSql);
	if (FAILED(hr)) 
	{
		return hr;
	}

	//绑定参数
	hr = pRs->BindParameters(params);
	if (FAILED(hr))
	{
		return hr;	
	}

	//取得第一条记录
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	hr = pRs->MoveStep(1, &bEOF);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//如果有返回记录则取第一列的值，如果无返回记录则返回空(Empty)
	if (bEOF == VARIANT_FALSE)
	{
		hr = pRs->get_Row(rtDefault, pVal);
		if (FAILED(hr)) 
		{
			return hr;
		}
	}
	else
	{
		pVal->vt = VT_EMPTY;
	}
	
	//关闭结果集
	hr = pRs->Close();
	if (FAILED(hr)) 
	{
		return hr;
	}

	return S_OK;
}

//批量执行SQL语句, 语句中不应包含查询语句. 
//例如: oConn.ExecuteSQLs("CREATE TABLE T(c); CREATE INDEX idx ON T(c);")
STDMETHODIMP Connection::ExecuteSqls(BSTR strSql)
{
	//验证数据库是否已被打开
	if ( m_db == NULL )
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//批量执行SQL
	USES_CONV_UTF8;
	char* pszErrMsg = NULL;
	int nRet = sqlite3_exec(m_db, W2UTF8(strSql), NULL, NULL, &pszErrMsg);
	HRESULT hr = m_ErrMsg.sqlite_error(nRet, pszErrMsg);
	sqlite3_free(pszErrMsg);

	return hr;
}

//中断SQL执行, 取消所有操作.
STDMETHODIMP Connection::Cancel()
{
	//验证数据库是否已被打开
	if ( m_db == NULL )
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//中断执行所有操作
	sqlite3_interrupt(m_db);

	return S_OK;
}

//返回最近一次更改数据库(插入或删除)的所影响到的记录行数
STDMETHODIMP Connection::get_RowsAffected(LONG *pnVal)
{
	//验证数据库是否已被打开
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//获取最近一次更改数据库(插入或删除)的所影响到的记录行数
	*pnVal = sqlite3_changes(m_db);

	return S_OK;
}

//返回最近一次插入数据库中的记录的行ID
STDMETHODIMP Connection::get_LastInsertRowID(VARIANT *pVal)
{
	//验证数据库是否已被打开
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//获得最近一次插入数据库中的记录的行ID 
	CComVariant v;
	HRESULT hr = make_integer_or_decimal(v, sqlite3_last_insert_rowid(m_db));
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}
	
	//返回
	return v.Detach(pVal);
}

//返回SQL语句执行进度
STDMETHODIMP Connection::get_Progress(LONG *pnPeriod)
{
	*pnPeriod = m_nProgress;
	return S_OK;
}

//设置SQL语句执行进度
STDMETHODIMP Connection::put_Progress(LONG nPeriod)
{
	m_nProgress = nPeriod;

	if (m_db != NULL)
	{
		sqlite3_progress_handler(m_db, m_nProgress, progress_callback, this);
	}

	return S_OK;
}

//开启事务
STDMETHODIMP Connection::BeginTrans()
{
	if(m_bTrans)
	{
        //存在已开启的事务未提交或未回滚，不能开启事务
		return m_ErrMsg.system_error(E_TRANS_BEGIN_DISABLED);
	}
	else
	{
		//开启事务
		CComBSTR strSql = _T("BEGIN TRANSACTION");
		HRESULT hr = this->ExecuteSqls(strSql);
		if(FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		//开启成功
		m_bTrans = TRUE; 
	}
	return S_OK;
}

//提交事务
STDMETHODIMP Connection::CommitTrans()
{
	if(!m_bTrans)
	{
        //当前未开启事务或事务已回滚，不能提交事务
		return m_ErrMsg.system_error(E_TRANS_COMMIT_DISABLED);
	}
	else
	{
		//设置关闭, 如果提交失败再次提交时会报错
		m_bTrans = FALSE;

		//提交事务
		CComBSTR strSql = _T("COMMIT TRANSACTION");
		HRESULT hr = this->ExecuteSqls(strSql);
		if(FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
	}
	return S_OK;
}

//回滚事务
STDMETHODIMP Connection::RollbackTrans()
{
	if(!m_bTrans)
	{
        //当前未开启事务或事务已提交，不能回滚事务
		return m_ErrMsg.system_error(E_TRANS_ROLLBACK_DISABLED);
	}
	else
	{
		//设置关闭, 如果提交失败再次回滚时会报错
		m_bTrans = FALSE;

		//回滚事务
		CComBSTR strSql = _T("ROLLBACK TRANSACTION");
		HRESULT hr = this->ExecuteSqls(strSql);
		if(FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
	}
	return S_OK;
}
