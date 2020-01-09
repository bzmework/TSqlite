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

//ϵͳ�Զ����ɣ����޸�
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

//�������������
HRESULT Connection::create_statement(CComPtr<IResultset>& pRs)
{
	//���������
	CComObject<Resultset>* p = new CComObject<Resultset>;
	HRESULT hr = p->FinalConstruct();
	if (FAILED(hr))
	{
		delete p;
		return hr;
	}
	
	//���ҽ�����ӿ�
	hr = p->QueryInterface(&pRs);
	if (FAILED(hr))
	{
		delete p;
		return hr;
	}
	
	//�������Ӷ���ӿ�
	CComPtr<IConnection> pThis;
	hr = QueryInterface(IID_IConnection, (void**)&pThis);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//�����Ӷ��󵽽����
	hr = pRs->put_ActiveConnection(pThis);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//����
	return S_OK;
}

//ϵͳ��æ�м�ػص�����
int Connection::busy_callback(void* pThis, int nTimes)
{
	Connection* poThis = static_cast<Connection*>(pThis);
	VARIANT_BOOL bResult;
	HRESULT hRet = poThis->Fire_Busy(nTimes, &bResult); //������æ���¼�
	if (SUCCEEDED(hRet))
	{
		return (VARIANT_FALSE == bResult)? 0 : 1;
	}
	else
	{
		return 0;
	}
}

//���ִ���м�ػص�����
int Connection::progress_callback(void* pThis)
{
	Connection* poThis = static_cast<Connection*>(pThis);
	VARIANT_BOOL bResult;
	HRESULT hRet = poThis->Fire_Progress(&bResult); //����ִ�����¼�
	if (SUCCEEDED(hRet))
	{
		return (VARIANT_FALSE == bResult) ? 1 : 0;
	}
	else
	{
		return 0;
	}
}

//���� 
STDMETHODIMP Connection::AboutMe()
{
	MessageBox(NULL, ABOUTME, COPYRIGHT, MB_ICONWARNING | MB_OK);
	return S_OK;
}

//���ذ汾��
STDMETHODIMP Connection::get_Version(VARIANT *pVal)
{
	CComVariant v;
	CComBSTR bsVersion(sqlite3_libversion());	
	v = bsVersion;
	return v.Detach(pVal);
}

//��ȡ��ǰ���ݿ�
STDMETHODIMP Connection::GetCurrentDB(void** pDB)
{
	*pDB = m_db;
	return S_OK;
}

//�������ݿ�, ����: C:\NorthWind.db
STDMETHODIMP Connection::get_Db(BSTR *pVal)
{
	m_strDb.CopyTo(pVal);
	return S_OK;
}

//�������ݿ�, ����: C:\NorthWind.db" 
STDMETHODIMP Connection::put_Db(BSTR newVal)
{
	if (m_db != NULL) //���ܷ����������ݿ�, �����ȹر�.
	{
		return m_ErrMsg.system_error(E_DB_IS_OPEN);
	}
	m_strDb = newVal;
	return S_OK;
}

//�����ݿ�, strDb: ���ݿ�(��C:\NorthWind.db) ���ڴ����ݿ�(:memory:). ���������Db����, ��ò������Ժ���.
STDMETHODIMP Connection::Open(BSTR strDb)
{
	#ifndef _UNICODE
	USES_CONV_UTF8;
	#endif
	
	//���ܷ��������ݿ�, �����ȹر�.
	if (m_db != NULL) 
	{
		return m_ErrMsg.system_error(E_DB_IS_OPEN);
	}
	
	//��֤���ݿ��Ƿ���Ч
	if (SysStringLen(strDb) > 0)
	{
		put_Db(strDb);
	}
	
	//�����ݿ�
	int nRet = 0;
	#ifdef _UNICODE
		nRet = sqlite3_open16(m_strDb, &m_db);
	#else
		nRet = sqlite3_open(W2UTF8(m_strDb), &m_db);
	#endif
	
	//ע���¼���
	if (nRet == SQLITE_OK)
	{
		sqlite3_register_blob_functions(m_db);

		#ifndef _NO_UNACC_STUFF
		m_vUnaccContext = sqlite3_register_unacc_functions( m_db );
		#endif

		sqlite3_busy_handler(m_db, &busy_callback, this);
		sqlite3_progress_handler(m_db, m_nProgress, &progress_callback, this);
	}
	
	//����
	return m_ErrMsg.sqlite_error(nRet);
}

//���ڴ����ݿ�, �����ݿ�ر�ʱ, �ڴ����ݿ��е��������ݽ�ͬʱ������. �������ȼ���: oConn.Open(":memory:")
STDMETHODIMP Connection::OpenMemoryDb()
{
	CComBSTR strDb( _T(":memory:") );
	return Open(strDb);
}

//�ر����ݿ�
STDMETHODIMP Connection::Close()
{
	int nRet = SQLITE_OK;
	
	if (m_db)
	{
		//�ж����ݿ�����в���
		sqlite3_interrupt(m_db);

		//��ע���¼���
		#ifndef _NO_UNACC_STUFF
		sqlite3_unregister_unacc_functions(m_db, m_vUnaccContext);
		#endif
		sqlite3_busy_handler(m_db, NULL, 0);
		sqlite3_progress_handler(m_db, DEF_PROGRESS_PERIOD, NULL, 0);
		
		//�ر����ݿ�
		nRet = sqlite3_close(m_db);
		if (nRet == SQLITE_OK) 
		{
			m_db = NULL;
		}
	}
	
	return m_ErrMsg.sqlite_error(nRet);
}

//ִ��SQL���, ���ؽ����Resultset. 
//����: Set oRs = oConn.Execute("SELECT * FROM T WHERE c > 10")
STDMETHODIMP Connection::Execute(BSTR strSql, IResultset **ppRs)
{
	//��֤���ݿ��Ƿ��ѱ���
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//�������������
	CComPtr<IResultset> pRs;
	HRESULT hr = create_statement(pRs);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(E_CANNOT_CREATE_STATEMENT);
	}
	
	//ִ��SQL
	hr = pRs->Prepare(strSql);
	if (FAILED(hr)) 
	{
		return hr;
	}

	//���ؽ����
	return pRs->QueryInterface(ppRs);
}

//����ִ��SQL���, ����п��԰�������, ������ض��н�ȡ��һ�м�¼������. 
//����: oConn.ExecuteSQL("INSERT INTO T(a, b) VALUES (?, ?)", "money", 88.88)
//�� nMax = oConn.ExecuteSQL("SELECT Max(c) FROM T")
STDMETHODIMP Connection::ExecuteSql(BSTR strSql, LPSAFEARRAY *params, VARIANT *pVal)
{
	//��֤���ݿ��Ƿ��ѱ���
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//�������������
	CComPtr<IResultset> pRs;
	HRESULT hr = create_statement(pRs);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(E_CANNOT_CREATE_STATEMENT);
	}
	
	//׼��SQL
	hr = pRs->Prepare(strSql);
	if (FAILED(hr)) 
	{
		return hr;
	}

	//�󶨲���
	hr = pRs->BindParameters(params);
	if (FAILED(hr))
	{
		return hr;	
	}

	//ȡ�õ�һ����¼
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	hr = pRs->MoveStep(1, &bEOF);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//����з��ؼ�¼��ȡ��һ�е�ֵ������޷��ؼ�¼�򷵻ؿ�(Empty)
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
	
	//�رս����
	hr = pRs->Close();
	if (FAILED(hr)) 
	{
		return hr;
	}

	return S_OK;
}

//����ִ��SQL���, ����в�Ӧ������ѯ���. 
//����: oConn.ExecuteSQLs("CREATE TABLE T(c); CREATE INDEX idx ON T(c);")
STDMETHODIMP Connection::ExecuteSqls(BSTR strSql)
{
	//��֤���ݿ��Ƿ��ѱ���
	if ( m_db == NULL )
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//����ִ��SQL
	USES_CONV_UTF8;
	char* pszErrMsg = NULL;
	int nRet = sqlite3_exec(m_db, W2UTF8(strSql), NULL, NULL, &pszErrMsg);
	HRESULT hr = m_ErrMsg.sqlite_error(nRet, pszErrMsg);
	sqlite3_free(pszErrMsg);

	return hr;
}

//�ж�SQLִ��, ȡ�����в���.
STDMETHODIMP Connection::Cancel()
{
	//��֤���ݿ��Ƿ��ѱ���
	if ( m_db == NULL )
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//�ж�ִ�����в���
	sqlite3_interrupt(m_db);

	return S_OK;
}

//�������һ�θ������ݿ�(�����ɾ��)����Ӱ�쵽�ļ�¼����
STDMETHODIMP Connection::get_RowsAffected(LONG *pnVal)
{
	//��֤���ݿ��Ƿ��ѱ���
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//��ȡ���һ�θ������ݿ�(�����ɾ��)����Ӱ�쵽�ļ�¼����
	*pnVal = sqlite3_changes(m_db);

	return S_OK;
}

//�������һ�β������ݿ��еļ�¼����ID
STDMETHODIMP Connection::get_LastInsertRowID(VARIANT *pVal)
{
	//��֤���ݿ��Ƿ��ѱ���
	if (m_db == NULL)
	{
		return m_ErrMsg.system_error(E_DB_IS_NOT_OPEN);
	}
	
	//������һ�β������ݿ��еļ�¼����ID 
	CComVariant v;
	HRESULT hr = make_integer_or_decimal(v, sqlite3_last_insert_rowid(m_db));
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}
	
	//����
	return v.Detach(pVal);
}

//����SQL���ִ�н���
STDMETHODIMP Connection::get_Progress(LONG *pnPeriod)
{
	*pnPeriod = m_nProgress;
	return S_OK;
}

//����SQL���ִ�н���
STDMETHODIMP Connection::put_Progress(LONG nPeriod)
{
	m_nProgress = nPeriod;

	if (m_db != NULL)
	{
		sqlite3_progress_handler(m_db, m_nProgress, progress_callback, this);
	}

	return S_OK;
}

//��������
STDMETHODIMP Connection::BeginTrans()
{
	if(m_bTrans)
	{
        //�����ѿ���������δ�ύ��δ�ع������ܿ�������
		return m_ErrMsg.system_error(E_TRANS_BEGIN_DISABLED);
	}
	else
	{
		//��������
		CComBSTR strSql = _T("BEGIN TRANSACTION");
		HRESULT hr = this->ExecuteSqls(strSql);
		if(FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		//�����ɹ�
		m_bTrans = TRUE; 
	}
	return S_OK;
}

//�ύ����
STDMETHODIMP Connection::CommitTrans()
{
	if(!m_bTrans)
	{
        //��ǰδ��������������ѻع��������ύ����
		return m_ErrMsg.system_error(E_TRANS_COMMIT_DISABLED);
	}
	else
	{
		//���ùر�, ����ύʧ���ٴ��ύʱ�ᱨ��
		m_bTrans = FALSE;

		//�ύ����
		CComBSTR strSql = _T("COMMIT TRANSACTION");
		HRESULT hr = this->ExecuteSqls(strSql);
		if(FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
	}
	return S_OK;
}

//�ع�����
STDMETHODIMP Connection::RollbackTrans()
{
	if(!m_bTrans)
	{
        //��ǰδ����������������ύ�����ܻع�����
		return m_ErrMsg.system_error(E_TRANS_ROLLBACK_DISABLED);
	}
	else
	{
		//���ùر�, ����ύʧ���ٴλع�ʱ�ᱨ��
		m_bTrans = FALSE;

		//�ع�����
		CComBSTR strSql = _T("ROLLBACK TRANSACTION");
		HRESULT hr = this->ExecuteSqls(strSql);
		if(FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
	}
	return S_OK;
}
