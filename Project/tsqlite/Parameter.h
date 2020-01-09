/*
	Parameter.h
*/

#ifndef __PARAMETER_H_
#define __PARAMETER_H_

#include "TSqlite.h"

class ATL_NO_VTABLE Parameter :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Parameter, &CLSID_Parameter>,
	public ISupportErrorInfo,
	public IDispatchImpl<IParameter, &IID_IParameter, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Parameter, NULL, &LIBID_TSqlite>
{
public:

	Parameter()
	{
		m_nIndex = -1;
	}
	
	DECLARE_NOT_AGGREGATABLE(Parameter)

	BEGIN_COM_MAP(Parameter)
		COM_INTERFACE_ENTRY(IParameter)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		m_nIndex = -1;
	}

public:
	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:

	//初始化
	HRESULT Init(IResultset* pRs, LONG nIndex);

	//创建参数(IParameter)
	static HRESULT CreateObject(IResultset* pRs, LONG nIndex, IParameter** ppParam);

public:
	// IParameter

	//返回参数索引
	STDMETHOD(get_Index)(/*[out, retval]*/ LONG* pVal);

	//返回参数名称
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR* pVal);

	//绑定指定参数
	STDMETHOD(Bind)(/*[in, optional]*/ VARIANT varValue, /*[in, defaultvalue(dtUnknown)]*/ DataTypeConstants eType);

protected:
	
	CComPtr<IResultset> m_pRs;
	LONG m_nIndex;

};

#endif //__PARAMETER_H_
