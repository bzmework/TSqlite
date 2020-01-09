/*
	Row.cpp
*/

#include "stdafx.h"
#include "Row.h"
#include "Glob.h"
#include "Messages.h"

//ϵͳ���ɣ����޸�
STDMETHODIMP Row::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IRow
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//��ʼ��
HRESULT Row::Init(IResultset* pRs)
{
	CComPtr<IResultset> poRs(pRs);
	HRESULT hRet = S_OK;
	
	//�������
	hRet = poRs->get_ColumnCount(&m_nSize);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	//�����
	CComVariant var;
	hRet = poRs->get_Row(rtArray, &var);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	//�Ƿ���Ч������
	ATLASSERT(V_VT(&var) == (VT_ARRAY | VT_VARIANT));
	ATLASSERT(V_ARRAY(&var) != NULL);
	
	//������Ϣ��������
	hRet = SafeArrayCopy(V_ARRAY(&var), &m_sa);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	//����
	return hRet;
}

//������(Row)
HRESULT Row::CreateObject(IResultset* pRs, IRow** ppRow)
{
	typedef CComObject<Row> TRow;

	HRESULT hRet = E_POINTER;
	if (ppRow != NULL)
	{
		*ppRow = NULL;
		TRow* p;
		hRet = TRow::CreateInstance(&p);
		if (SUCCEEDED(hRet))
		{
			// If this object has ownership of the data then we need to keep it around
			hRet = p->Init(pRs);
			if (SUCCEEDED(hRet))
			{
				hRet = p->_InternalQueryInterface(IID_IRow, (void**)ppRow);
			}
			
			if (FAILED(hRet))
			{
				delete p;
			}
		}
	}

	return hRet;
}

//ForEach
STDMETHODIMP Row::get__NewEnum(IUnknown** ppEnum)
{
	CComPtr<IUnknown> pThis;
	HRESULT hRet = _InternalQueryInterface(IID_IUnknown, (void**)&pThis);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	return RowEnum::CreateObject(m_sa, pThis, ppEnum);
}

//�����е�ָ����ֵ
STDMETHODIMP Row::get_Item(LONG lngIndex, DataTypeConstants eType, VARIANT* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	
	//����������������ȡ����ֵ
	CComVariant val;
	HRESULT hRet = SafeArrayGetElement(m_sa, &lngIndex, &val);
	if (FAILED(hRet))
	{
		return hRet;
	}
	
	//�������÷��ز�ͬ���͵���ֵ
	switch(eType)
	{
	case dtUnknown: // nothing to do
		break;
		
	case dtInteger:
	case dtLong:
		{
			CComVariant vint;
			hRet = vint.ChangeType(VT_I8, &val);
			if (S_OK == hRet)
			{
				hRet = make_integer_or_decimal(val, V_I8(&vint));
			}
		}
		break;
		
	case dtFloat:
		{
			hRet = val.ChangeType(VT_R8);
		}
		break;
		
	case dtString:
		{
			hRet = val.ChangeType(VT_BSTR);
		}
		break;
		
	case dtDate:
		{
			CComVariant vdate;
			hRet = vdate.ChangeType(VT_R8, &val);
			if (S_OK == hRet)
			{
				V_VT(&val) = VT_DATE;
				V_DATE(&val) = gat_automation_date(V_R8(&vdate));
			}
		}
		break;
		
	default:
		{
			hRet = E_UNUPPORTED_VALUE_TYPE;
		}
		break;
	}

	if (FAILED(hRet))
	{
		return m_ErrMsg.system_error(hRet);
	}
	
	//����
	return val.Detach(pVal);
}

//�����е���ֵ, ForEachʱ�Զ���ת����һ�в�������ֵ")] 
STDMETHODIMP Row::get_Value(VARIANT* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	
	HRESULT hRet = S_OK;
	LONG nIndex = 0;

	switch(m_nSize)
	{
	case 0:
		hRet = VariantClear(pVal);
		break;
		
	case 1:
		hRet = SafeArrayGetElement(m_sa, &nIndex, pVal);
		break;
		
	default:
		{
			CComVariant var;
			V_VT(&var) = VT_ARRAY | VT_VARIANT;
			hRet = SafeArrayCopy(m_sa, &var.parray);
			if (SUCCEEDED(hRet))
			{
				var.Detach(pVal);
			}
		}
		break;
	}
	
	return S_OK;
}

//�����а���������
STDMETHODIMP Row::get_Count(LONG* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}

	*pVal = m_nSize;

	return S_OK;
}