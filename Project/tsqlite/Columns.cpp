/*
	Columns.cpp
*/

#include "stdafx.h"
#include "Column.h"
#include "Columns.h"
#include "Glob.h"
#include "Messages.h"

//系统生成，勿修改
STDMETHODIMP Columns::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IColumns
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//初始化
HRESULT Columns::Init(IResultset* pRs)
{
	m_pRs = pRs;

	HRESULT hRet = m_pRs->get_ColumnCount(&m_nCount);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	SAFEARRAY* sa = SafeArrayCreateVectorEx(VT_DISPATCH, 0, m_nCount, (PVOID)&IID_IColumn);
	if (sa == NULL)
	{
		return E_FAIL;
	}
	
	for(LONG i = 0; i < m_nCount; i++)
	{
		CComPtr<IColumn> pColumn;
		hRet = Column::CreateObject(m_pRs, i, &pColumn);
		if (FAILED(hRet))
		{
			break;
		}
		
		hRet = SafeArrayPutElement(sa, &i, pColumn);
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

//创建列集(IColumns)
HRESULT Columns::CreateObject(IResultset* pRs, IColumns** ppCols)
{
	typedef CComObject<Columns> TColumns;

	HRESULT hRet = E_POINTER;
	if (ppCols != NULL)
	{
		*ppCols = NULL;
		TColumns* p;
		hRet = TColumns::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(pRs);
			if (SUCCEEDED(hRet))
			{
				hRet = p->_InternalQueryInterface(IID_IColumns, (void**)ppCols);
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
STDMETHODIMP Columns::get__NewEnum(IUnknown** ppEnum)
{
	CComPtr<IUnknown> pThis;
	HRESULT hRet = _InternalQueryInterface(IID_IUnknown, (void**)&pThis);
	if (FAILED(hRet))
	{
		return hRet;
	}
	return ColumnsEnum::CreateObject(m_sa, pThis, ppEnum);
}

//返回列
STDMETHODIMP Columns::get_Item(VARIANT varIndex, IColumn** ppCol)
{
	if (ppCol == NULL)
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
			CComPtr<IColumn> pColumn;		
			hRet = SafeArrayGetElement(m_sa, (LONG*)&V_INT(&v), &pColumn);
			if (S_OK == hRet)
			{
				hRet = pColumn->QueryInterface(IID_IColumn, (void**)ppCol);
			}
		}
		break;
		
	case VT_BSTR:
		{
			CComBSTR bsName;
			bool bFind = false;
			for( LONG i=0; i<m_nCount; i++ )
			{
				CComBSTR bsIdx(V_BSTR(&v));
				CComPtr<IDispatch> pVColumn;
				hRet = SafeArrayGetElement(m_sa, &i, &pVColumn);
				if (S_OK != hRet) break;
				
				CComPtr<IColumn> pColumn;
				hRet = pVColumn.QueryInterface(&pColumn);
				if (S_OK != hRet) break;
				
				hRet = pColumn->get_Value(&bsName);
				if (S_OK != hRet) break;
				
				if (VARCMP_EQ == compare_bstr(V_BSTR(&v), bsName))
				{
					hRet = pColumn->QueryInterface(IID_IColumn, (void**)ppCol);
					bFind = true;
					break;
				}
			}
			
			if ((S_OK == hRet) && !bFind)
			{
				hRet = E_UNKNOWN_COLUMN_NAME;
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

//返回列数
STDMETHODIMP Columns::get_Count(LONG* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	*pVal = m_nCount;
	return S_OK;
}
