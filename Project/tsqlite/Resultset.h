/*
	Resultset.h
*/

#ifndef __RESULTSET_H_
#define __RESULTSET_H_

#include "resource.h"       // main symbols
#include "ErrorMsg.h"

class ATL_NO_VTABLE Resultset : 
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Resultset, &CLSID_Resultset>,
	public ISupportErrorInfo,
	public IDispatchImpl<IResultset, &IID_IResultset, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Resultset, NULL, &LIBID_TSqlite>
{
public:

	Resultset()
	{
		m_ErrMsg.Init(CLSID_Resultset, IID_IResultset);

		m_bEOF = true;
		m_nRowCount = 0;
		m_eState = osClosed;
		m_stmt = NULL;
	}

	void FinalRelease()
	{
		//SQL�Ѿ�׼����
		if (m_eState == osPrepared)
		{
			//sqlite3_finalize
			//����һ��׼�����(prepared statement)��������Ҫʱִ��������ٺ����Է�ֹ�ڴ�й¶��
			//��׼��������Ϊ��ָ��ʱ�����������Ҳû��ʲôӰ�졣
			//sqlite3_finalize�ͷ�stmtռ�õ��ڴ�.���ڴ�����sqlite3_prepare()ʱ�����. 
			int nRet = sqlite3_finalize(m_stmt);
			m_eState = osClosed;
			m_nRowCount = 0;
			m_bEOF = true;
			m_stmt = NULL;
		}
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_RESULTSET)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(Resultset)
		COM_INTERFACE_ENTRY(IResultset)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
	END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ILiteStatement
public:

	//���ص�ǰ����Ӷ���")] 
	STDMETHOD(get_ActiveConnection)(/*[out, retval]*/ IConnection** ppConn);

	//���õ�ǰ����Ӷ���
	STDMETHOD(put_ActiveConnection)(/*[in]*/ IConnection* pConn);

	//���ش�ִ�е�SQL��ѯ
	STDMETHOD(get_SQL)(/*[out, retval]*/ BSTR* pVal);

	//���ô�ִ�е�SQL��ѯ
	STDMETHOD(put_SQL)(/*[in]*/ BSTR newVal);

	//Ԥ��SQL��ѯ
	STDMETHOD(Prepare)(/*[in, defaultvalue("")]*/ BSTR strSql);

	//ִ��SQL��ѯ
	STDMETHOD(Execute)();

	//����ִ��SQL��ѯ
	STDMETHOD(Requery)();

	//�رս����
	STDMETHOD(Close)();
	
	//��ǰ��¼λ��λ�ڽ�����ĵ�һ����¼֮ǰ
	//STDMETHOD(get_BOF)(/*[out, retval]*/ VARIANT_BOOL* pVal);

	//��ǰ��¼λ��λ�ڽ���������һ����¼֮��
	STDMETHOD(get_EOF)(/*[out, retval]*/ VARIANT_BOOL* pVal);

	//�ƶ�����һ����¼
	STDMETHOD(MoveFirst)();

	//�ƶ�����һ����¼
	STDMETHOD(MoveNext)();

	//�ƶ�����һ����¼
	//STDMETHOD(MovePrevious)();

	//�ƶ������һ����¼
	STDMETHOD(MoveLast)();

	//�ƶ���ָ���ļ�¼��
	//STDMETHOD(MoveSpecial)(/*[in, defaultvalue(1)]*/ LONG lngRow);
	
	//�ƶ�ָ������
	STDMETHOD(MoveStep)(/*[in, defaultvalue(1)]*/ LONG nSteps, /*[out, retval]*/ VARIANT_BOOL* pVal);

	//��������
	STDMETHOD(get_ColumnCount)(/*[out, retval]*/ LONG* pVal);

	//����������
	STDMETHOD(get_ColumnType)(/*[in]*/ VARIANT varIndex, /*[out, retval]*/ DataTypeConstants* pVal);

	//��������
	STDMETHOD(get_ColumnName)(/*[in]*/ LONG lngIndex, /*[out, retval]*/ BSTR* pVal);

	//������ֵ
	STDMETHOD(get_ColumnValue)(/*[in]*/ VARIANT varIndex, /*[in, defaultvalue(dtUnknown)]*/ DataTypeConstants eType, /*[out, retval]*/ VARIANT* pVal);
	
	//�����м�
	STDMETHOD(get_Columns)(/*[out, retval]*/ IColumns** ppCols);
	
	//������ֵ
	STDMETHOD(get_Row)(/*[in, defaultvalue(rtDefault)]*/ RowTypeConstants eMode, /*[out, retval]*/ VARIANT* pVal);
	
	//��������
	STDMETHOD(get_RowCount)(/*[out, retval]*/ VARIANT* pVal);

	//�����м�
	STDMETHOD(get_Rows)(/*[in, defaultvalue(0)]*/ VARIANT_BOOL blnStatic, /*[in, defaultvalue(0)]*/ LONG lngMaxRecords, /*[out, retval]*/ IRows** ppRows);

	//�󶨲���
	STDMETHOD(BindParameters)(/*[in]*/ LPSAFEARRAY* varParams);

	//��һ������
	STDMETHOD(BindParameter)(/*[in]*/ VARIANT varIndex, /*[in, optional]*/ VARIANT varValue, /*[in, defaultvalue(dtUnknown)]*/ DataTypeConstants eType);
	
	//���ز�������
	STDMETHOD(get_ParameterCount)(/*[out, retval]*/ LONG* pVal);

	//���ز�������
	STDMETHOD(get_ParameterName)(/*[in]*/ LONG lngIndex, /*[out, retval]*/ BSTR* strName);

	//���ز�������
	STDMETHOD(get_Parameters)(/*[out, retval]*/ IParameters** ppParams);
	
	//����״̬
	STDMETHOD(get_State)(/*[out, retval]*/ ObjectStateConstants* pVal);
 
protected:

	ObjectStateConstants m_eState;
	CComPtr<IConnectionObject> m_pConnection;
	sqlite3_stmt* m_stmt;
	CComBSTR m_strSql;
	LONGLONG m_nRowCount;
	bool m_bEOF;

	HRESULT bind_blob(CComPtr<IStream>&, LONG, int&);
	HRESULT bind_blob(SAFEARRAY*, LONG, int&);

	HRESULT create_row(LONG, CComVariant& v);
	DataTypeConstants get_column_type(int) const;
	HRESULT get_column_index(const VARIANT&, int&) const;
	HRESULT get_column_name(LONG, CComBSTR&) const;

	HRESULT get_parameter_index(const VARIANT&, int&) const;

private:
	ErrorMsg m_ErrMsg;

};

#endif //__RESULTSET_H_
