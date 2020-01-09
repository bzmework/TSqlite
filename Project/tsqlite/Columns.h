/*
	Columns.h
*/

#ifndef __COLUMNS_H_
#define __COLUMNS_H_

#include "TSqlite.h"
#include "ErrorMsg.h"

class ATL_NO_VTABLE ColumnsEnum: public CComSAEnum<IEnumVARIANT, &IID_IEnumVARIANT, IDispatch*, VARIANT >
{
public:
	
	//创建列集枚举(ColumnsEnum)
	static HRESULT CreateObject(SAFEARRAY* sa, IUnknown* pUnk, IUnknown** ppEnum)
	{
		typedef CComObject<ColumnsEnum> TColumnsEnum;
		HRESULT hRet = E_POINTER;
		if (ppEnum != NULL)
		{
			*ppEnum = NULL;
			TColumnsEnum* p;
			hRet = TColumnsEnum::CreateInstance(&p);
			if (SUCCEEDED(hRet))
			{
				// If this object has ownership of the data then we need to keep it around
				hRet = p->Init(sa, NULL, AtlFlagCopy);
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

class ATL_NO_VTABLE Columns :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Columns, &CLSID_Columns>,
	public ISupportErrorInfo,
	public IDispatchImpl<IColumns, &IID_IColumns, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Columns, NULL, &LIBID_TSqlite>	
{
public:

	Columns()
	{
		m_ErrMsg.Init(CLSID_Columns, IID_IColumns);
		m_sa = NULL;
		m_nCount = 0;
	}
	
	DECLARE_NOT_AGGREGATABLE(Columns)

	BEGIN_COM_MAP(Columns)
		COM_INTERFACE_ENTRY(IColumns)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_sa = NULL;
		m_nCount = 0;
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
	HRESULT Init(IResultset* pRs);

	//创建列集(IColumns)
	static HRESULT CreateObject(IResultset* pRs, IColumns** ppCols);	

public:
	// IColumns

	//支持ForEach
	STDMETHOD(get__NewEnum)(IUnknown** ppEnum);

	//返回列
	STDMETHOD(get_Item)(/*[in]*/ VARIANT varIndex, /*[out, retval]*/ IColumn** ppCol);

	//返回列数
	STDMETHOD(get_Count)(/*[out,retval]*/ LONG* pVal);
 
protected:

	CComPtr<IResultset> m_pRs;
	SAFEARRAY* m_sa;
	LONG m_nCount;
	
private:
	ErrorMsg m_ErrMsg;

};

#endif //__COLUMNS_H_
