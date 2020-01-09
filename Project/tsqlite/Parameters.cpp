/*
	Parameters.cpp
*/

#include "stdafx.h"
#include "Parameters.h"
#include "Parameter.h"
#include "Glob.h"
#include "Messages.h"

//系统生成，勿修改
STDMETHODIMP Parameters::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IParameters
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//初始化
HRESULT Parameters::Init(IResultset* pRs)
{
	m_pRs = pRs;

	HRESULT hRet = m_pRs->get_ParameterCount(&m_nCount);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	SAFEARRAY* sa = SafeArrayCreateVectorEx(VT_DISPATCH, 0, m_nCount, (PVOID)&IID_IDispatch);
	if (sa == NULL)
	{
		return E_FAIL;
	}
	
	for(LONG i = 0; i < m_nCount; i++)
	{
		CComPtr<IParameter> pParameter;
		hRet = Parameter::CreateObject(m_pRs, i, &pParameter);
		if (FAILED(hRet))
		{
			break;
		}
		
		hRet = SafeArrayPutElement(sa, &i, pParameter);
		if (FAILED(hRet))
		{
			break;
		}
	}

	if (FAILED(hRet))
	{
		SafeArrayDestroy(sa);
		return hRet;
	}
	else
	{
		m_sa = sa;
	}
	
	return S_OK;	

}

//创建参数集合(IParameters)
HRESULT Parameters::CreateObject(IResultset* pRs, IParameters** ppParams)
{
	typedef CComObject<Parameters> TParameters;

	HRESULT hRet = E_POINTER;
	if (ppParams != NULL)
	{
		*ppParams = NULL;
		TParameters* p;
		hRet = TParameters::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(pRs);
			if (SUCCEEDED(hRet))
			{
				hRet = p->_InternalQueryInterface(IID_IParameters, (void**)ppParams);
			}
			
			if (FAILED(hRet))
			{
				delete p;
			}
		}
	}
	return hRet;
}

//支持ForEach
STDMETHODIMP Parameters::get__NewEnum(IUnknown** pVal)
{
	CComPtr<IUnknown> pThis;
	HRESULT hRet = _InternalQueryInterface(IID_IUnknown, (void**)&pThis);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	return ParametersEnum::CreateObject(m_sa, pThis, pVal);
}

//返回参数
STDMETHODIMP Parameters::get_Item(VARIANT varIndex, IParameter** ppParam)
{
	if (ppParam == NULL)
	{
		return E_POINTER;
	}
	
	HRESULT hRet = S_OK;
	CComVariant v(varIndex);
	hRet = variant_normalize(v);
	if (FAILED(hRet)) 
	{
		return m_ErrMsg.system_error(hRet);
	}

	switch(V_VT(&v) & VT_TYPEMASK)
	{
	case VT_INT:
	{
		CComPtr<IParameter> pParameter;		
		hRet = SafeArrayGetElement(m_sa, (LONG*)&V_INT(&v), &pParameter);
		if (S_OK == hRet)
		{
			hRet = pParameter->QueryInterface(IID_IParameter, (void**)ppParam);
		}
	}
	break;
		
	case VT_BSTR:
	{
		CComBSTR bsName;
		bool bFind = false;
		for( LONG i = 0; i < m_nCount; i++)
		{
			CComPtr<IDispatch> pVParameter;
			hRet = SafeArrayGetElement(m_sa, &i, &pVParameter);
			if (S_OK != hRet) break;
				
			CComPtr<IParameter> pParameter;
			hRet = pVParameter.QueryInterface(&pParameter);
			if (S_OK != hRet) break;
				
			hRet = pParameter->get_Name(&bsName);
			if (S_OK != hRet) break;
				
			if (VARCMP_EQ == compare_bstr(V_BSTR(&v), bsName))
			{
				hRet = pParameter->QueryInterface(IID_IParameter, (void**)ppParam);
				bFind = true;
				break;
			}
		}
			
		if ((S_OK == hRet) && !bFind)
		{
			hRet = E_UNKNOWN_PARAM_NAME;
		}
			
	}
	break;
		
	default:
		ATLASSERT(FALSE);
		break;
	}
	
	if (FAILED(hRet)) 
	{
		return m_ErrMsg.system_error(hRet);
	}

	return hRet;
}

//返回参数数量
STDMETHODIMP Parameters::get_Count(LONG* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	*pVal = m_nCount;
	return S_OK;
}

//绑定多个参数
STDMETHODIMP Parameters::Bind(LPSAFEARRAY* varParams)
{
	if (varParams == NULL)
	{
		return E_POINTER;
	}
	
	HRESULT hRet = m_pRs->BindParameters(varParams);
	return hRet;
}