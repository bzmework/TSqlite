/*
	Rows.h
*/

#ifndef __ROWS_H_
#define __ROWS_H_

#include "TSqlite.h"
#include <limits.h>

/*
	行集(静态)枚举类
*/
class ATL_NO_VTABLE RowsEnum: public CComSAEnum<IEnumVARIANT, &IID_IEnumVARIANT, IDispatch*, VARIANT>
{
public:
	
	//创建静态行集枚举(RowsEnum)
	static HRESULT CreateObject(SAFEARRAY* sa, IUnknown* pUnk, IUnknown** ppEnum)
	{
		typedef CComObject<RowsEnum> TRowsEnum;
		HRESULT hRet = E_POINTER;
		if (ppEnum != NULL)
		{
			*ppEnum = NULL;
			TRowsEnum* p;
			hRet = TRowsEnum::CreateInstance(&p);
			if (SUCCEEDED(hRet))
			{
				// If this object has ownership of the data then we need to keep it around
				hRet = p->Init(sa, pUnk);
				if (SUCCEEDED(hRet))
				{
					hRet = p->_InternalQueryInterface(IID_IUnknown, (void**)ppEnum);
				}
				
				if (FAILED(hRet))
				{
					delete p;
				}
			}
		}
		return hRet;
	} 
};

class ATL_NO_VTABLE Rows :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Rows, &CLSID_Rows>,
	public ISupportErrorInfo,
	public IDispatchImpl<IRows, &IID_IRows, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Rows, NULL, &LIBID_TSqlite>	
{
public:

	Rows()
	{
		m_sa = NULL;
		m_bStatic = false;
	}
	
	DECLARE_NOT_AGGREGATABLE(Rows)

	BEGIN_COM_MAP(Rows)
		COM_INTERFACE_ENTRY(IRows)
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
		if (m_sa != NULL)
		{
			SafeArrayDestroy(m_sa);
		}
	}	

public:
	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:

	//初始化
	HRESULT Init(bool, LONG, IResultset*);
	HRESULT Init(SAFEARRAY*);
	
	//创建行集(IRows)
	static HRESULT CreateObject(bool bStatic, LONG nMaxRecords, IResultset* pRs, IRows** ppRows);
	static HRESULT CreateObject(SAFEARRAY* sa, IRows** ppRows);

public:
	// IRows

	//支持ForEach
	STDMETHOD(get__NewEnum)(/*[out,retval]*/ IUnknown** ppEnum);

	//返回行
	STDMETHOD(get_Item)(/*[in, defaultvalue(-1)]*/ LONG lngIndex, /*[out, retval]*/ IRow** ppRow);
	
	//返回行数
	STDMETHOD(get_Count)(/*[out, retval]*/ VARIANT* pVal);
	
protected:

	CComPtr<IResultset> m_pRs;
	SAFEARRAY* m_sa;
	bool m_bStatic;
	
	HRESULT build_array_of_rows(LONG);
	
};

#endif //__ROWS_H_
