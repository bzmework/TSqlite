/*
	Column.h
*/

#ifndef __COLUMN_H_
#define __COLUMN_H_

#include "TSqlite.h"

// CColumn

class ATL_NO_VTABLE Column :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Column, &CLSID_Column>,
	public IDispatchImpl<IColumn, &IID_IColumn, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Column, NULL, &LIBID_TSqlite>	
{

public:

	Column()
	{
		m_nIndex = -1;
	}
	
	DECLARE_NOT_AGGREGATABLE(Column)

	BEGIN_COM_MAP(Column)
		COM_INTERFACE_ENTRY(IColumn)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	
	//��ʼ��
	HRESULT Init(IResultset* pRs, LONG nIndex);

	//������(IColumn)
	static HRESULT CreateObject(IResultset* pRs, LONG nIndex, IColumn** ppCol);

public:
	// IColumn
	
	//����������
	STDMETHOD(get_Index)(/*[out, retval]*/ LONG* pVal);

	//����������
	STDMETHOD(get_Value)(/*[out, retval]*/ BSTR* pVal);

protected:

	LONG m_nIndex;		//������
	CComBSTR m_strName;	//������
	
};

#endif //__COLUMN_H_

