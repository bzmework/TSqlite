/*
	LargeInteger.h
*/

#ifndef __LARGE_INTEGER_H_
#define __LARGE_INTEGER_H_

#include "resource.h"       // main symbols
#include "TSqlite.h"

class ATL_NO_VTABLE CLargeInteger :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<CLargeInteger, &CLSID_LargeInteger>,
	public IDispatchImpl<ILargeInteger, &IID_ILargeInteger, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_LargeInteger, NULL, &LIBID_TSqlite>
{
public:

	CLargeInteger()
	{
		m_li.QuadPart = 0i64;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_LARGEINTEGER)

	DECLARE_NOT_AGGREGATABLE(CLargeInteger)

	BEGIN_COM_MAP(CLargeInteger)
		COM_INTERFACE_ENTRY(ILargeInteger)
		COM_INTERFACE_ENTRY(IDispatch)
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
	}
	
protected:

	LARGE_INTEGER m_li;	

public:

	STDMETHOD(get_LowPart)(LONG* pVal);
	STDMETHOD(put_LowPart)(LONG newVal);
	STDMETHOD(get_HighPart)(LONG* pVal);
	STDMETHOD(put_HighPart)(LONG newVal);
	STDMETHOD(get_QuadPart)(DECIMAL* pVal);
	STDMETHOD(put_QuadPart)(DECIMAL newVal);
	STDMETHOD(get_MaxValue)(DECIMAL* pVal);
	STDMETHOD(get_MinValue)(DECIMAL* pVal);
	STDMETHOD(get_QuadPartCy)(CY* pVal);
	STDMETHOD(put_QuadPartCy)(CY newVal);
	STDMETHOD(get_MinValueCy)(CY* pVal);
	STDMETHOD(get_MaxValueCy)(CY* pVal);
};

#endif //__LARGE_INTEGER_H_