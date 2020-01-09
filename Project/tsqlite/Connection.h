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
			//�ж����в���
			sqlite3_interrupt( m_db );
			
			//��ע���¼���
			#ifndef _NO_UNACC_STUFF
			sqlite3_unregister_unacc_functions(m_db, m_vUnaccContext);
			#endif
			sqlite3_busy_handler(m_db, NULL, 0);
			sqlite3_progress_handler(m_db, DEF_PROGRESS_PERIOD, NULL, 0);
			
			//�ر����ݿ�
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
	
	//��ȡ��ǰ���ݿ�
	STDMETHOD(GetCurrentDB)(/*[out,retval]*/ void** ppDB);

// IConnection
public:
	
	//���� 
	STDMETHOD(AboutMe)();

	//���ذ汾��
	STDMETHOD(get_Version)(/*[out, retval]*/ VARIANT* pVal);
	
	//�������ݿ�,����: C:\NorthWind.db
	STDMETHOD(get_Db)(/*[out, retval]*/ BSTR* pVal);
	
	//�������ݿ�,����: C:\NorthWind.db" 
	STDMETHOD(put_Db)(/*[in]*/ BSTR newVal);

	//�����ݿ�, strDb: ���ݿ�(��C:\NorthWind.db) ���ڴ����ݿ�(:memory:). ���������Db����, ��ò������Ժ���.
	STDMETHOD(Open)(/*[in, defaultvalue("")]*/ BSTR strDb);

	//���ڴ����ݿ�, �����ݿ�ر�ʱ, �ڴ����ݿ��е��������ݽ�ͬʱ������. �������ȼ���: oConn.Open(":memory:")
	STDMETHOD(OpenMemoryDb)();

	//�ر����ݿ�
	STDMETHOD(Close)();
	
	//ִ��SQL���, ���ؽ����Resultset. 
	//����: Set oRs = oConn.Execute("SELECT * FROM T WHERE c > 10")
	STDMETHOD(Execute)(/*[in]*/ BSTR strSql, /*[out,retval]*/ IResultset** ppRs);

	//����ִ��SQL���, ����п��԰�������, ������ض��н�ȡ��һ�м�¼������. 
	//����: oConn.ExecuteSQL("INSERT INTO T(a, b) VALUES (?, ?)", "money", 88.88)
	//�� nMax = oConn.ExecuteSQL("SELECT Max(c) FROM T")
	STDMETHOD(ExecuteSql)(/*[in]*/ BSTR strSql, /*[in]*/ LPSAFEARRAY* varParams, /*[out, retval]*/ VARIANT* pVal);

	//����ִ��SQL���, ����в�Ӧ������ѯ���. 
	//����: oConn.ExecuteSQLs("CREATE TABLE T(c); CREATE INDEX idx ON T(c);")
	STDMETHOD(ExecuteSqls)(/*[in]*/ BSTR strSql);

	//�ж�SQLִ��, ȡ�����в���.
	STDMETHOD(Cancel)();
	
	//�������һ�θ������ݿ�(�����ɾ��)����Ӱ�쵽�ļ�¼����
	STDMETHOD(get_RowsAffected)(/*[out, retval]*/ LONG* pVal);

	//�������һ�β������ݿ��еļ�¼����ID
	STDMETHOD(get_LastInsertRowID)(/*[out, retval]*/ VARIANT* pVal);
	
	//����SQL���ִ�н���
	STDMETHOD(get_Progress)(/*[out, retval]*/ LONG* pVal);
	
	//����SQL���ִ�н���
	STDMETHOD(put_Progress)(/*[in]*/ LONG newVal);

	//��������
	STDMETHOD(BeginTrans)();

	//�ύ����
	STDMETHOD(CommitTrans)();

	//�ع�����
	STDMETHOD(RollbackTrans)();

protected:

	CComBSTR m_strDb; //���ݿ�����, ����: C:\NorthWind.db
	sqlite3* m_db;	  //���ݿ���� 
	#ifndef _NO_UNACC_STUFF
	void* m_vUnaccContext;
	#endif
	LONG m_nProgress; //ִ�н���
	BOOL m_bTrans;	  //�����־

protected:

	HRESULT create_statement(CComPtr<IResultset>& pRs);
	static int busy_callback(void* pThis, int nTimes);
	static int progress_callback(void* pThis);

private:
	ErrorMsg m_ErrMsg;//������־

};

#endif //__CONNECTION_H_
