/*
	Column.cpp
*/

#include "stdafx.h"
#include "TSqlite.h"
#include "Column.h"

//��ʼ��
HRESULT Column::Init(IResultset *pRs, LONG nIndex)
{
	CComPtr<IResultset> poRs(pRs);
	m_nIndex = nIndex;
	HRESULT hRet = poRs->get_ColumnName(nIndex, &m_strName);
	return S_OK;
}

//������(Column)
HRESULT Column::CreateObject(IResultset* pRs, LONG nIndex, IColumn** ppCol)
{
	typedef CComObject<Column> TColumn;
	HRESULT hRet = E_POINTER;
	if (ppCol != NULL)
	{
		*ppCol = NULL;
		TColumn* p;
		hRet = TColumn::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(pRs, nIndex);
			if (SUCCEEDED(hRet))
			{
				hRet = p->_InternalQueryInterface(IID_IColumn, (void**)ppCol);
			}
			
			if (FAILED(hRet))
			{
				delete p;
			}
		}
	}
	return hRet;
}

//����������
STDMETHODIMP Column::get_Index(LONG* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}

	*pVal = m_nIndex;
	return S_OK;
}

//����������
STDMETHODIMP Column::get_Value(BSTR* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	
	*pVal = m_strName.Copy();
	return S_OK;
}
