/*
	Parameter.cpp
*/

#include "stdafx.h"
#include "Parameter.h"

//系统生成，勿修改
STDMETHODIMP Parameter::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IParameter
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//初始化
HRESULT Parameter::Init(IResultset *pRs, LONG nIndex)
{
	m_pRs = pRs;
	m_nIndex = nIndex;
	return S_OK;
}

//创建参数(IParameter)
HRESULT Parameter::CreateObject(IResultset* pRs, LONG nIndex, IParameter** ppParam)
{
	typedef CComObject<Parameter> TParameter;
	HRESULT hRet = E_POINTER;
	if (ppParam != NULL)
	{
		*ppParam = NULL;
		TParameter* p;
		hRet = TParameter::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(pRs, nIndex);
			if (SUCCEEDED(hRet))
			{
				hRet = p->_InternalQueryInterface(IID_IDispatch, (void**)ppParam);
			}
			
			if (FAILED(hRet))
			{
				delete p;
			}
		}
	}

	return hRet;
}

//返回参数索引
STDMETHODIMP Parameter::get_Index(LONG* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	
	*pVal = m_nIndex;
	return S_OK;
}

//返回参数名称
STDMETHODIMP Parameter::get_Name(BSTR* pVal)
{
	HRESULT hRet = m_pRs->get_ParameterName(m_nIndex + 1, pVal);
	return hRet;
}

//绑定指定参数
STDMETHODIMP Parameter::Bind(VARIANT varValue, DataTypeConstants eType)
{
	CComVariant idx(m_nIndex + 1);
	HRESULT hRet = m_pRs->BindParameter(idx, varValue, eType);
	return hRet;
}
