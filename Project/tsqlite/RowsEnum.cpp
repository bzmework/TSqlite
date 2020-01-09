/*
	RowsEnum.cpp
*/

#include "stdafx.h"
#include "TSqlite.h"
#include "Resultset.h"
#include "RowsEnum.h"

//系统生成，勿修改
STDMETHODIMP RowsDynEnum::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IEnumVARIANT
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//创建动态行集枚举(RowsDynEnum)
HRESULT RowsDynEnum::CreateObject(IResultset* pRs, IUnknown** ppEnum)
{
	typedef CComObject<RowsDynEnum> TRowsDynEnum;

	HRESULT hRet = E_POINTER;
	if (ppEnum != NULL)
	{
		*ppEnum = NULL;
		TRowsDynEnum* p;
		hRet = TRowsDynEnum::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(pRs);
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

//初始化
HRESULT RowsDynEnumImpl::Init(IResultset* pRs)
{
	m_pRs = pRs;
	return S_OK;
}

//转到下一行
STDMETHODIMP RowsDynEnumImpl::Next(ULONG celt, VARIANT* rgelt,
	ULONG* pceltFetched)
{
	if (pceltFetched != NULL)
	{
		*pceltFetched = 0;
	}
	
	if (celt == 0)
	{
		return E_INVALIDARG;
	}

	if (rgelt == NULL || (celt != 1 && pceltFetched == NULL))
	{
		return E_POINTER;
	}

	VARIANT* pVar = rgelt;
	CComVariant var;
	ULONG i, nCounter = 0;
	VARIANT_BOOL bEOF;
	HRESULT hr;
	
	for(i = 0; i < celt; pVar++, i++)
	{
		//移动到下一条记录
		bEOF = VARIANT_FALSE;
		hr = m_pRs->MoveStep(1, &bEOF);
		if (FAILED(hr)) 
		{
			break;
		}
		
		//是否到结果集尾部
		if (bEOF == VARIANT_TRUE) 
		{
			break;
		}
		
		//获得行集
		hr = m_pRs->get_Row(rtCollection, &var);
		if (FAILED(hr)) 
		{
			break;
		}
		
		//转换成Dispatch类型
		hr = var.ChangeType(VT_DISPATCH);
		if (FAILED(hr)) 
		{
			break;
		}
		
		//返回(Row对象)
		hr = var.Detach(pVar);
		if (FAILED(hr)) 
		{
			break;
		}
		
		//跳转到下一行
		nCounter++;
	}
	
	//返回
	if (FAILED(hr))
	{
		return hr;
	}
	else
	{
		if (pceltFetched != NULL)
		{
			*pceltFetched = nCounter;
		}
		return (celt == nCounter)? S_OK : S_FALSE;
	}

}

//跳过
STDMETHODIMP RowsDynEnumImpl::Skip(ULONG celt)
{
	if (celt == 0)
	{
		return E_INVALIDARG;
	}
	
	//移动到下一条记录
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hRet = m_pRs->MoveStep(celt, &bEOF);
	if (FAILED(hRet))
	{
		return hRet;
	}
	else
	{
		return (bEOF == VARIANT_FALSE)? S_OK : S_FALSE;
	}

}

//重置
STDMETHODIMP RowsDynEnumImpl::Reset()
{
	return m_pRs->Requery();
}

//复制
STDMETHODIMP RowsDynEnumImpl::Clone(IEnumVARIANT** ppEnum)
{
	CComPtr<IUnknown> pUnkEnum;
	HRESULT hRet = RowsDynEnum::CreateObject(m_pRs.p, &pUnkEnum.p);
	if (FAILED(hRet))
	{
		return hRet;
	}
	else
	{
		hRet = pUnkEnum->QueryInterface(IID_IEnumVARIANT, (void**)ppEnum);
		return hRet;
	}
}
