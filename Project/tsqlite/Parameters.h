/*
	Parameters.h
*/

#ifndef __LITEPARAMETERS_H
#define __LITEPARAMETERS_H

#include "TSqlite.h"
#include "ErrorMsg.h"

//参数集合枚举
class ATL_NO_VTABLE ParametersEnum: public CComSAEnum<IEnumVARIANT, &IID_IEnumVARIANT, IDispatch*, VARIANT>
{
public:
	
	//创建参数集合枚举(ParametersEnum)
	static HRESULT CreateObject(SAFEARRAY* sa, IUnknown* pUnk, IUnknown** ppEnum)
	{
		typedef CComObject<ParametersEnum> TParametersEnum;
		HRESULT hRet = E_POINTER;
		if (ppEnum != NULL)
		{
			*ppEnum = NULL;
			TParametersEnum* p;
			hRet = TParametersEnum::CreateInstance(&p);
			if (SUCCEEDED(hRet))
			{
				// If this object has ownership of the data then we need to keep it around
				hRet = p->Init(sa, pUnk, AtlFlagNoCopy);
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

class ATL_NO_VTABLE Parameters :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Parameters, &CLSID_Parameters>,
	public ISupportErrorInfo,
	public IDispatchImpl<IParameters, &IID_IParameters, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Parameters, NULL, &LIBID_TSqlite>
{
public:

	Parameters()
	{
		m_ErrMsg.Init(CLSID_Parameters, IID_IParameters);
		m_nCount = 0;
	}
	
	DECLARE_NOT_AGGREGATABLE(Parameters)

	BEGIN_COM_MAP(Parameters)
		COM_INTERFACE_ENTRY(IParameters)
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
		if ( m_sa != NULL )
		{
			SafeArrayDestroy( m_sa );
		}
	}
	
public:
	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:

	//初始化
	HRESULT Init(IResultset*);

	//创建参数集合(IParameters)
	static HRESULT CreateObject(IResultset* pRs, IParameters** ppParams);	

public:
	// IParameters

	//支持ForEach
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown** ppEnum);
	
	//返回参数
	STDMETHOD(get_Item)(/*[in]*/ VARIANT vIndex, /*[out, retval]*/ IParameter** ppParam);

	//返回参数数量
	STDMETHOD(get_Count)(/*[out, retval]*/ LONG* pVal);

	//绑定多个参数
	STDMETHOD(Bind)(/*[in]*/ LPSAFEARRAY* varParams);

protected:
	
	CComPtr<IResultset> m_pRs;
	SAFEARRAY* m_sa;
	LONG m_nCount;
	
private:
	ErrorMsg m_ErrMsg;

};

#endif
