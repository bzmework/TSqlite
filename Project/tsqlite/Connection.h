/*
	Connection.h
*/

#ifndef __CONNECTION_H_
#define __CONNECTION_H_

#include "resource.h"       // main symbols
#include "TSqlite.h"
#include "IBusy_CP.H"
#include "IProgress_CP.H"
#include "ErrorMsg.h"

#define DEF_PROGRESS_PERIOD 0

class ATL_NO_VTABLE Connection : 
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Connection, &CLSID_Connection>,
	public ISupportErrorInfo,
	public IConnectionObject,
	public IDispatchImpl<IConnection, &IID_IConnection, &LIBID_TSqlite>,
	public IConnectionPointContainerImpl<Connection>,
	public CProxyIBusy<Connection>,
	public CProxyIProgress<Connection>,
	
	/*
	Knowledge Base  
	How To Enable ActiveX Control Event Handling on a Web Page
	PSS ID Number: 200839
	*/	
	public IProvideClassInfo2Impl<&CLSID_Connection, &IID_IProgress, &LIBID_TSqlite>

{
public:

	Connection()
	{
		m_ErrMsg.Init(CLSID_Connection, IID_IConnection);
		
		m_db = NULL;
		#ifndef _NO_UNACC_STUFF
		m_vUnaccContext = NULL;
		#endif
		m_nProgress = DEF_PROGRESS_PERIOD;
		m_bTrans = FALSE;
	}
	
	void FinalRelease()
	{
		if ( m_db != NULL )
		{
			//中断所有操作
			sqlite3_interrupt( m_db );
			
			//反注册事件等
			#ifndef _NO_UNACC_STUFF
			sqlite3_unregister_unacc_functions(m_db, m_vUnaccContext);
			#endif
			sqlite3_busy_handler(m_db, NULL, 0);
			sqlite3_progress_handler(m_db, DEF_PROGRESS_PERIOD, NULL, 0);
			
			//关闭数据库
			sqlite3_close(m_db);
		}
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_CONNECTION)

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(Connection)
		COM_INTERFACE_ENTRY(IConnection)
		COM_INTERFACE_ENTRY(IConnectionObject)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(Connection)
		CONNECTION_POINT_ENTRY(IID_IProgress)
		CONNECTION_POINT_ENTRY(IID_IBusy)
	END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IConnectionObject
public:
	
	//获取当前数据库
	STDMETHOD(GetCurrentDB)(/*[out,retval]*/ void** ppDB);

// IConnection
public:
	
	//关于 
	STDMETHOD(AboutMe)();

	//返回版本号
	STDMETHOD(get_Version)(/*[out, retval]*/ VARIANT* pVal);
	
	//返回数据库,例如: C:\NorthWind.db
	STDMETHOD(get_Db)(/*[out, retval]*/ BSTR* pVal);
	
	//设置数据库,例如: C:\NorthWind.db" 
	STDMETHOD(put_Db)(/*[in]*/ BSTR newVal);

	//打开数据库, strDb: 数据库(如C:\NorthWind.db) 或内存数据库(:memory:). 如果设置了Db属性, 则该参数可以忽略.
	STDMETHOD(Open)(/*[in, defaultvalue("")]*/ BSTR strDb);

	//打开内存数据库, 当数据库关闭时, 内存数据库中的所有内容将同时被销毁. 本函数等价于: oConn.Open(":memory:")
	STDMETHOD(OpenMemoryDb)();

	//关闭数据库
	STDMETHOD(Close)();
	
	//执行SQL语句, 返回结果集Resultset. 
	//例如: Set oRs = oConn.Execute("SELECT * FROM T WHERE c > 10")
	STDMETHOD(Execute)(/*[in]*/ BSTR strSql, /*[out,retval]*/ IResultset** ppRs);

	//快速执行SQL语句, 语句中可以包含参数, 如果返回多行仅取第一行记录的数据. 
	//例如: oConn.ExecuteSQL("INSERT INTO T(a, b) VALUES (?, ?)", "money", 88.88)
	//或 nMax = oConn.ExecuteSQL("SELECT Max(c) FROM T")
	STDMETHOD(ExecuteSql)(/*[in]*/ BSTR strSql, /*[in]*/ LPSAFEARRAY* varParams, /*[out, retval]*/ VARIANT* pVal);

	//批量执行SQL语句, 语句中不应包含查询语句. 
	//例如: oConn.ExecuteSQLs("CREATE TABLE T(c); CREATE INDEX idx ON T(c);")
	STDMETHOD(ExecuteSqls)(/*[in]*/ BSTR strSql);

	//中断SQL执行, 取消所有操作.
	STDMETHOD(Cancel)();
	
	//返回最近一次更改数据库(插入或删除)的所影响到的记录行数
	STDMETHOD(get_RowsAffected)(/*[out, retval]*/ LONG* pVal);

	//返回最近一次插入数据库中的记录的行ID
	STDMETHOD(get_LastInsertRowID)(/*[out, retval]*/ VARIANT* pVal);
	
	//返回SQL语句执行进度
	STDMETHOD(get_Progress)(/*[out, retval]*/ LONG* pVal);
	
	//设置SQL语句执行进度
	STDMETHOD(put_Progress)(/*[in]*/ LONG newVal);

	//开启事务
	STDMETHOD(BeginTrans)();

	//提交事务
	STDMETHOD(CommitTrans)();

	//回滚事务
	STDMETHOD(RollbackTrans)();

protected:

	CComBSTR m_strDb; //数据库名称, 例如: C:\NorthWind.db
	sqlite3* m_db;	  //数据库对象 
	#ifndef _NO_UNACC_STUFF
	void* m_vUnaccContext;
	#endif
	LONG m_nProgress; //执行进度
	BOOL m_bTrans;	  //事务标志

protected:

	HRESULT create_statement(CComPtr<IResultset>& pRs);
	static int busy_callback(void* pThis, int nTimes);
	static int progress_callback(void* pThis);

private:
	ErrorMsg m_ErrMsg;//错误日志

};

#endif //__CONNECTION_H_
