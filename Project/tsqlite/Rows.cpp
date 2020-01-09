/*
	Rows.cpp
*/

#include "stdafx.h"
#include "TSqlite.h"
#include "RowsEnum.h"
#include "Rows.h"
#include "Glob.h"

static const LONG DEF_SIZE = 100;
static const LONG DEF_GROW = DEF_SIZE / 2;

// Rows

//系统生成, 勿修改
STDMETHODIMP Rows::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IRows
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//绑定行集到数组
HRESULT Rows::build_array_of_rows(LONG nMaxRec)
{
	ULONG nSize = DEF_SIZE;
	SAFEARRAY* sa = SafeArrayCreateVectorEx(VT_DISPATCH, 0, nSize, (PVOID)&IID_IDispatch);
	if (sa == NULL)
	{
		return E_OUTOFMEMORY;
	}
	
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	CComVariant row;
	LONG nElements = 0;
	HRESULT hRet = S_OK;
	
	if (nMaxRec <= 0)
	{
		nMaxRec = LONG_MAX; // there's allways upper limit
	}
	
	//重新查询记录
	hRet = m_pRs->Requery();
	if (S_OK == hRet)
	{
		while(true)
		{
			hRet = m_pRs->MoveStep(1, &bEOF);
			if (FAILED(hRet)) 
			{
				break;
			}

			if (bEOF == VARIANT_TRUE) 
			{
				break;
			}
			
			if (nElements >= nMaxRec)
			{
				break;
			}
			
			if ((ULONG)nElements >= nSize)
			{
				SAFEARRAYBOUND sab;
				sab.cElements = nSize + DEF_GROW;
				sab.lLbound = 0;
				
				hRet = SafeArrayRedim(sa, &sab);
				if (FAILED(hRet))
				{
					break;
				}

				nSize = sab.cElements;
			}
			
			hRet = m_pRs->get_Row(rtCollection, &row);
			if (FAILED(hRet)) 
			{
				break;
			}
			
			hRet = SafeArrayPutElement(sa, &nElements, V_DISPATCH(&row));
			if (FAILED(hRet))
			{
				break;
			}
			
			nElements++;
		}
	}
	
	if (FAILED(hRet))
	{
		SafeArrayDestroy(sa);
	}
	else
	{
		SAFEARRAYBOUND sab;
		sab.cElements = nElements;
		sab.lLbound = 0;
		hRet = SafeArrayRedim(sa, &sab);
		
		if (S_OK == hRet)
		{
			m_sa = sa;
		}
	}
	
	return hRet;
}

//初始化
HRESULT Rows::Init(bool bStatic, LONG nMaxRecords, IResultset* pRs)
{
	HRESULT hRet = S_OK;
	m_bStatic = bStatic;
	m_pRs = pRs;
	if (bStatic)
	{
		hRet = build_array_of_rows(nMaxRecords);
	}
	
	return hRet;
}
HRESULT Rows::Init(SAFEARRAY* sa)
{
	m_bStatic = true;
	HRESULT hRet = SafeArrayCopy(sa, &m_sa);	
	return hRet;
}

//创建行集(IRows)
HRESULT Rows::CreateObject(bool bStatic, LONG nMaxRecords, IResultset* pRs, IRows** ppRows)
{
	typedef CComObject<Rows> TRows;

	HRESULT hRet = E_POINTER;
	if (ppRows != NULL)
	{
		*ppRows = NULL;
		TRows* p;
		hRet = TRows::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(bStatic, nMaxRecords, pRs);
			if (SUCCEEDED(hRet))
			{
				hRet = p->_InternalQueryInterface(IID_IRows, (void**)ppRows);
			}
			
			if (FAILED(hRet))
			{
				delete p;
			}
		}
	}
	return hRet;
}

//创建行集(Rows)
HRESULT Rows::CreateObject(SAFEARRAY* sa, IRows** ppRows)
{
	typedef CComObject<Rows> TRows;

	HRESULT hRet = E_POINTER;
	if (ppRows != NULL)
	{
		*ppRows = NULL;
		TRows* p;
		hRet = TRows::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(sa);
			if (SUCCEEDED(hRet))
			{
				hRet = p->_InternalQueryInterface(IID_IRows, (void**)ppRows);
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
STDMETHODIMP Rows::get__NewEnum(IUnknown** ppEnum)
{
	if (ppEnum == NULL)
	{
		return E_POINTER;
	}
	
	HRESULT hRet;
	if (m_bStatic)
	{
		CComPtr<IUnknown> pThis;
		hRet = _InternalQueryInterface(IID_IUnknown, (void**)&pThis);
		if (S_OK == hRet)
		{
			hRet = RowsEnum::CreateObject(m_sa, pThis, ppEnum);
		}
	}
	else
	{
		hRet = RowsDynEnum::CreateObject(m_pRs, ppEnum);
	}

	return hRet;
}

//返回行
STDMETHODIMP Rows::get_Item(LONG lngIndex, IRow** ppRow)
{
	HRESULT hr;

	if (m_bStatic)
	{
		hr = SafeArrayGetElement(m_sa, &lngIndex, ppRow);
	}
	else
	{
		ATLASSERT(lngIndex == -1);
		CComVariant val;
		hr = m_pRs->get_Row(rtCollection, &val);
		if (hr == S_OK)
		{
			ATLASSERT(V_VT(&val) == VT_DISPATCH);
			hr = V_DISPATCH(&val)->QueryInterface(IID_IRow, (void**)ppRow);
		}
	}
	
	return hr;
}

//返回行数
STDMETHODIMP Rows::get_Count(VARIANT* pVal)
{
	HRESULT hRet = S_OK;

	if (m_bStatic)
	{
		LONG nCount = 0;
		hRet = SafeArrayGetUBound(m_sa, 1, &nCount);
		if (S_OK == hRet)
		{
			nCount++;
			CComVariant val;
			val = nCount;
			hRet = val.Detach(pVal);
		}
	}
	else
	{
		hRet = m_pRs->get_RowCount(pVal);
	}

	return hRet;	
}
