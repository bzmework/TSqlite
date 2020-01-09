/*
	Resultset.cpp
*/

#include "stdafx.h"
#include "TSqlite.h"
#include "Resultset.h"
#include "Rows.h"
#include "Row.h"
#include "Columns.h"
#include "Parameters.h"
#include "Messages.h"
#include "Glob.h"

//ϵͳ���ɣ���ɾ��
STDMETHODIMP Resultset::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IResultset
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//������
HRESULT Resultset::create_row(LONG nSize, CComVariant& v)
{
	CComVariant val;
	HRESULT hr;
	
	v.parray = SafeArrayCreateVector(VT_VARIANT, 0, nSize);
	if (v.parray)
	{
		V_VT(&v) = VT_VARIANT | VT_ARRAY;
		
		CComVariant idx;
		DataTypeConstants eType;
		for(LONG i = 0; i < nSize; i++ )
		{
			idx = i;
			
			hr = get_ColumnType(idx, &eType);
			if (FAILED(hr))
			{
				return hr;
			}
			
			hr = get_ColumnValue(idx, eType, &val);
			if (FAILED(hr))
			{
				return hr;
			}
			
			hr = SafeArrayPutElement(v.parray, &i, &val);
			if (FAILED(hr))
			{
				return m_ErrMsg.system_error(hr);
			}
		}
		
		return hr;
	}
	else
	{
		return m_ErrMsg.system_error(E_OUTOFMEMORY);
	}
}

//�Ʋ���������
static DataTypeConstants guess_type(const CComVariant& v)
{
	DataTypeConstants eType = dtUnknown;
	switch(V_VT(&v) & VT_TYPEMASK)
	{
	case VT_EMPTY:
	case VT_NULL:
		eType = dtNull;
		break;

	case VT_I1:
	case VT_UI2:
	case VT_I2:
	case VT_I4:
	case VT_INT:
	case VT_BOOL:
	case VT_UI4:
	case VT_UINT:
		eType = dtInteger;
		break;

	case VT_DECIMAL:
	{
		DECIMAL dm;
		if ( V_ISBYREF(&v) )
		{
			dm = *V_DECIMALREF(&v);
		}
		else
		{
			dm = V_DECIMAL(&v);
		}
		
		if ( is_decimal_integer( dm ) )
		{
			eType = dtInteger;
		}
		else
		{
			eType = dtFloat;
		}
	}
	break;

	case VT_R4:
	case VT_R8:
	case VT_CY:
	case VT_ERROR:
		eType = dtFloat;
		break;
	
	case VT_DATE:
		eType = dtDate;
		break;

	case VT_BSTR:
	case VT_LPSTR:
	case VT_LPWSTR:
		eType = dtString;
		break;

	case VT_UI1:
		if ( V_ISARRAY(&v) )
		{
			eType = dtBinary;
		}
		else
		{
			eType = dtInteger;
		}
		break;
	}

	return eType;
}

//�󶨶����ƴ�����
HRESULT Resultset::bind_blob(CComPtr<IStream>& pSrc, LONG nColumn, int& nRet)
{
	HRESULT hr;
	STATSTG st;

	hr = pSrc->Stat(&st, STATFLAG_NONAME);
	if (FAILED(hr)) 
	{
		return hr;
	}

	CComPtr<IStream> pStream;
	hr = CreateStreamOnHGlobal(NULL, TRUE, &pStream);
	if (FAILED(hr))
	{
		return hr;
	}

	hr = pSrc->CopyTo(pStream, st.cbSize, NULL, NULL);
	if (FAILED(hr))
	{
		return hr;
	}

	HGLOBAL hMem;
	hr = GetHGlobalFromStream(pStream, &hMem);
	if (FAILED(hr)) 
	{
		return hr;
	}

	PVOID pMem = GlobalLock(hMem);
	nRet = sqlite3_bind_blob(m_stmt, nColumn, pMem, st.cbSize.LowPart, SQLITE_TRANSIENT);
	GlobalUnlock(hMem);

	return S_OK;
}

//�󶨶����ƴ�����
HRESULT Resultset::bind_blob(SAFEARRAY* sa, LONG nColumn, int& nRet)
{
	HRESULT hr;
	PVOID pBuffer;

	hr = SafeArrayAccessData(sa, (void HUGEP**)&pBuffer);
	if (FAILED(hr)) 
	{
		return hr;
	}

	nRet = sqlite3_bind_blob(m_stmt, nColumn, pBuffer,	sa->rgsabound[0].cElements,	SQLITE_TRANSIENT);
	hr = SafeArrayUnaccessData(sa);

	return hr;
}

//�������
HRESULT Resultset::get_column_name(LONG nColumn, CComBSTR& colName) const
{
	#ifdef _UNICODE
	const WCHAR* pszName = (const WCHAR*)sqlite3_column_name16(m_stmt, nColumn);
	if (pszName != NULL)
	{
		colName = pszName;
	}
	else
	{
		return m_ErrMsg.system_error(E_NO_COLUMN_NAME);
	}
	#else
	USES_CONV_UTF8;
	const CHAR* pszName = sqlite3_column_name(m_stmt, nColumn);
	if (pszName != NULL)
	{
		colName = UTF82W(pszName);
	}
	else
	{
		return m_ErrMsg.system_error(E_NO_COLUMN_NAME);
	}
	#endif

	return S_OK;
}

//���������
DataTypeConstants Resultset::get_column_type(int nColumn) const
{
	DataTypeConstants eType;
	switch(sqlite3_column_type(m_stmt, nColumn))
	{
	case SQLITE_INTEGER: eType = dtInteger; break;
	case SQLITE_FLOAT: eType = dtFloat; break;
	case SQLITE_TEXT: eType = dtString; break;
	case SQLITE_BLOB: eType = dtBinary; break;
	case SQLITE_NULL: eType = dtNull; break;
	default: eType = dtUnknown; break;
	}
	return eType;
}

//���������
HRESULT Resultset::get_column_index(const VARIANT& idx, int& nColumn) const
{
	HRESULT hr;

	CComVariant v(idx);
	hr = variant_normalize(v);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	int nCount = sqlite3_column_count(m_stmt);
	switch(V_VT(&v) & VT_TYPEMASK)
	{
	case VT_INT: // integer
		nColumn = V_I4(&v);
		if (nColumn < 0 || nColumn >= nCount)
		{
			hr = E_COLUMN_OUT_OF_RANGE;
		}
		break;

	case VT_BSTR: // column name
	{
		CComBSTR bsName;
		bool bFind = false;

		for( int i = 0; i < nCount; i++)
		{
			hr = get_column_name(i, bsName);
			if (SUCCEEDED(hr))
			{
				if (VARCMP_EQ == compare_bstr(v.bstrVal, bsName))
				{
					nColumn = i;
					bFind = true;
					break;
				}
			}
		}

		if (!bFind)
		{
			hr = E_UNKNOWN_COLUMN_NAME;
		}
	}
	break;

	default:
		ATLASSERT(FALSE);
		break;
	}

	if (FAILED(hr)) 
	{
		return m_ErrMsg.system_error(hr);
	}

	return hr;
}

//��ò�������
HRESULT Resultset::get_parameter_index(const VARIANT& idx, int& nParameter) const
{
	USES_CONV_UTF8;

	HRESULT hr;

	CComVariant v(idx);
	hr = variant_normalize(v);
	if (FAILED(hr)) 
	{
		return m_ErrMsg.system_error(hr);
	}

	switch(V_VT(&v) & VT_TYPEMASK)
	{
	case VT_INT: // integer
	{
		int nCount = sqlite3_bind_parameter_count(m_stmt);
		if (SUCCEEDED(hr))
		{
			nParameter = V_I4(&v);
			if (nParameter <= 0 || nParameter > nCount)
			{
				hr = E_PARAM_OUT_OF_RANGE;
			}
		}
	}
	break;

	case VT_BSTR: // column name
	{
		nParameter = sqlite3_bind_parameter_index(m_stmt, W2UTF8(V_BSTR(&v)));

		if ( nParameter == 0 )
		{
			hr = E_UNKNOWN_PARAM_NAME;
		}
	}
	break;

	default: // shouldn't happend
		ATLASSERT(FALSE);
		break;
	}

	if (FAILED(hr)) 
	{
		return m_ErrMsg.system_error(hr);
	}

	return hr;
}

//���ص�ǰ����Ӷ���
STDMETHODIMP Resultset::get_ActiveConnection(IConnection* *pVal)
{
	return m_pConnection.QueryInterface(pVal);
}

//���õ�ǰ����Ӷ���
STDMETHODIMP Resultset::put_ActiveConnection(IConnection *pVal)
{
	if (m_eState == osClosed)
	{
		return pVal->QueryInterface(IID_IConnectionObject, (void**)&m_pConnection);
	}
	else
	{
		return m_ErrMsg.system_error(E_ALREADY_PREPARED);
	}
}

//���ش�ִ�е�SQL��ѯ
STDMETHODIMP Resultset::get_SQL(BSTR *pVal)
{
	return m_strSql.CopyTo(pVal);
}

//���ô�ִ�е�SQL��ѯ
STDMETHODIMP Resultset::put_SQL(BSTR newVal)
{
	if (m_eState == osClosed)
	{
		m_strSql = newVal;
		return S_OK;
	}
	else
	{
		return m_ErrMsg.system_error(E_ALREADY_PREPARED);
	}
}

//Ԥ��SQL��ѯ
STDMETHODIMP Resultset::Prepare(BSTR strSql)
{
	#ifndef _UNICODE
	USES_CONV_UTF8;
	#endif
	
	//Sqlite����δ�ر�
	if (m_eState != osClosed)
	{
		return m_ErrMsg.system_error(E_ALREADY_PREPARED);
	}
	
	//�Ƿ��Ѱ󶨵�����Ӷ���
	if (!m_pConnection)
	{
		return m_ErrMsg.system_error(E_NO_ACTIVE_CONNECTION);
	}
	
	//��û���Ӷ���
	sqlite3* db;
	HRESULT hr = m_pConnection->GetCurrentDB((void**)&db);
	if (FAILED(hr)) 
	{
		return m_ErrMsg.system_error(hr);
	}
	
	//���ô���ѯ��SQL
	if (SysStringLen(strSql) > 0)
	{
		m_strSql = strSql;
	}
	if (m_strSql.Length() == 0)
	{
		return m_ErrMsg.system_error(E_NO_COMMAND_STRING);
	}
	
	//Ԥ��SQL
	//����sqlite3_prepare()��SQL������Ϊsqlite�ڲ�һ���ṹ��(sqlite3_stmt).
	//�ýṹ���а����˽�Ҫִ�еĵ�SQL������Ϣ.
	//���ںܶ�SQL�����˵��ִ��sqlite3_prepare()��ʱ����ڻ��߳���ִ��sqlite3_step()��ʱ�䡣����Ӧ����Ƶ������sqlite3_prepare(��
	//sqlite3_get_tableЧ�ʵ���, �ٷ��Ƽ�ʹ��sqlite3_prepare_v2���.
	int nRet = 0;
	#ifdef _UNICODE
		nRet = sqlite3_prepare16_v2(db, m_strSql, -1, &m_stmt, NULL);
	#else
		nRet = sqlite3_prepare_v2(db, W2UTF8(m_strSql), -1, &m_stmt, NULL);
	#endif
	if (nRet == SQLITE_OK)
	{
		m_eState = osPrepared; //��Ԥ����
		m_nRowCount = 0;//��������
		m_bEOF = false;//������־
	}
	
	//����
	return m_ErrMsg.sqlite_error(db);
}

//ִ��SQL��ѯ
STDMETHODIMP Resultset::Execute()
{
	//SQL�Ƿ���׼����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//����SQL��ѯ
	int nRet = sqlite3_reset(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_bEOF = false;
	}

	//�ƶ�����һ����¼λ��
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//����
	return S_OK;
}

//����ִ��SQL��ѯ
STDMETHODIMP Resultset::Requery()
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//����SQL��ѯ
	int nRet = sqlite3_reset(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_bEOF = false;
	}
	else
	{
		return m_ErrMsg.sqlite_error(nRet);
	}
	
	//�ƶ�����һ����¼
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//����
	return S_OK;
}

//�رս����
STDMETHODIMP Resultset::Close()
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return S_OK;
	}
	
	//�رս����
	int nRet = sqlite3_finalize(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_eState = osClosed;
		m_nRowCount = 0;
		m_bEOF = true;
		m_stmt = NULL;
	}
	
	//����
	return m_ErrMsg.sqlite_error(nRet);
}

//��ǰ��¼λ��λ�ڽ�����ĵ�һ����¼֮ǰ
/*
STDMETHODIMP Resultset::get_BOF(VARIANT_BOOL* pVal)
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//�Ƿ��ѵ��˽�����ײ�
	*pVal = (m_bBOF? VARIANT_TRUE: VARIANT_FALSE);
	
	return S_OK;
}
*/

//��ǰ��¼λ��λ�ڽ���������һ����¼֮��
STDMETHODIMP Resultset::get_EOF(VARIANT_BOOL* pVal)
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//�Ƿ��ѵ��˽����β��
	*pVal = (m_bEOF? VARIANT_TRUE: VARIANT_FALSE);

	return S_OK;
}

//�ƶ�����һ����¼
STDMETHODIMP Resultset::MoveFirst()
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//����SQL��ѯ
	int nRet = sqlite3_reset(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_bEOF = false;
	}
	else
	{
		return m_ErrMsg.sqlite_error(nRet);
	}

	//�ƶ�����һ����¼λ��
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//����
	return S_OK;
}

//�ƶ�����һ����¼
STDMETHODIMP Resultset::MoveNext()
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//�ƶ�����һ��
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//����
	return S_OK;
}

//�ƶ�����һ����¼
//STDMETHODIMP Resultset::MovePrevious()

//�ƶ������һ����¼
STDMETHODIMP Resultset::MoveLast()
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//�ƶ������һ��
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	LONG lngRow = (LONG)(m_nRowCount - 1);
	HRESULT hr = this->MoveStep(lngRow, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}
	
	//����
	return S_OK;
}

//�ƶ���ָ���ļ�¼��
//STDMETHODIMP Resultset::MoveSpecial(LONG lngRow)
 
//�ƶ�ָ������
HRESULT Resultset::MoveStep(LONG nSteps,  VARIANT_BOOL *pbEOF)
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//��֤�����Ƿ���Ч
	if (nSteps <= 0)
	{
		return m_ErrMsg.system_error(E_STMT_BAD_STEP_PARAMETER);
	}
	
	//�ƶ���ָ������
	//ִ��SQL��ѯ
	//sqlite3_step�ķ���ֵȡ���ڴ���sqlite3_stmt������ʹ�õĺ�����
	//����ʹ���ϰ汾�Ľӿ�sqlite3_prepare()��sqlite3_prepare16()��
	//����ֵ����SQLITE_BUSY��SQLITE_DONE��SQLITE_ROW��SQLITE_ERROR �� SQLITE_MISUSE��
	//��v2�汾�Ľӿ�sqlite3_prepare_v2()��sqlite3_prepare16_v2()������Щֵ���⣬�����ܷ�����չ״̬�롣
	
	//����sqlite3_step(),��ʱ��SQL��������ִ��.
	//ע��ú����ķ���ֵ,SQLITE_DONE��SQLITE_ROW���Ǳ�ʾִ�гɹ�,
	//��ͬ����SQLITE_DONE��ʾû�в�ѯ���,��UPDATE,INSERT��ЩSQL��䶼�Ƿ���SQLITE_DONE,
	//SELECT��ѯ����ڲ�ѯ�����Ϊ�յ�ʱ�򷵻�SQLITE_ROW,�ڲ�ѯ���Ϊ�յ�ʱ�򷵻�SQLITE_DONE.
	//SQLITE_DONE���ܱ����Ϊerror code�����ǲ�������ִ�д��󣬶�����ζ�Ų�ѯ���Ϊ�ա�
	//SQLITE_OK��ʾִ�н������в�ѯ���
	
	//ÿ�ε���sqlite3_step()��ʱ��,ֻ����һ������,ʹ��sqlite3_column_XXX()������ȡ����Щ����.
	//Ҫȡ��ȫ����������Ҫ��������sqlite3_step(). (ע��,��bind������ʱ��, �����б��index��1��ʼ,��ȡ�����ݵ�ʱ��, �е�index�Ǵ�0��ʼ). 
	int nRet = 0;
	bool bStop = false;
	while((nSteps > 0) && !bStop)
	{
		nRet = sqlite3_step(m_stmt);
		switch(nRet)
		{
		case SQLITE_ROW: //��Ч����
			break;
			
		case SQLITE_DONE: //�ѵ������β��
			m_bEOF = true;
			bStop = true;
			break;
			
		//case SQLITE_ERROR:
		//case SQLITE_MISUSE: // raise error
		default: //���ش���
			{
				sqlite3* db;
				HRESULT hr = m_pConnection->GetCurrentDB((void**)&db);
				if (FAILED(hr)) 
				{
					return m_ErrMsg.system_error(nRet);
				}
				return m_ErrMsg.sqlite_error(db);
			}
		}
		nSteps--;
	}
	
	//�Ƿ��˽����β��
	*pbEOF = (m_bEOF? VARIANT_TRUE : VARIANT_FALSE);

	//����
	return m_ErrMsg.sqlite_error(nRet);
}

//��������
STDMETHODIMP Resultset::get_ColumnCount(LONG *pVal)
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//��������
	*pVal = sqlite3_column_count(m_stmt);
	return S_OK;
}

//����������
STDMETHODIMP Resultset::get_ColumnType(VARIANT varIndex, DataTypeConstants* eType )
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//���������
	int nColumn = 0;
	HRESULT hr = get_column_index(varIndex, nColumn);
	if (FAILED(hr))
	{
		return hr;
	}
	
	//����������
	*eType = get_column_type(nColumn);
	
	return S_OK;
}

//��������
STDMETHODIMP Resultset::get_ColumnName(LONG lngIndex, BSTR *pVal)
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//�������
	CComBSTR colName;
	HRESULT hr = get_column_name(lngIndex, colName);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//��������
	*pVal = colName.Detach();
	if (*pVal != NULL)
	{
		return S_OK;
	}
	else
	{
		return m_ErrMsg.system_error(E_OUTOFMEMORY);
	}
}

//������ֵ
STDMETHODIMP Resultset::get_ColumnValue(VARIANT varIndex, DataTypeConstants eType, VARIANT *pVal)
{
	//SQL�Ƿ���Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//���������
	int nColumn = 0;
	HRESULT hr = get_column_index(varIndex, nColumn);
	if (FAILED(hr)) 
	{
		return hr;
	}

	//���������
	if (eType == dtUnknown)
	{
		eType = get_column_type(nColumn);
		if (eType == dtUnknown) 
		{
			return m_ErrMsg.system_error(E_UNKNOWN_COLUMN_TYPE);
		}
	}
	
	//�����ֵ
	CComVariant v;
	switch(eType)
	{
	//��ֵ
	case dtNull:
		V_VT(&v) = VT_NULL;
		break;

	//����ֵ
	case dtInteger:
	case dtLong:
	{
		sqlite_int64 nVal = sqlite3_column_int64(m_stmt, nColumn);
		HRESULT hr = make_integer_or_decimal(v, nVal);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
	}
	break;

	//����ֵ
	case dtFloat:
		v = sqlite3_column_double(m_stmt, nColumn);
		break;
	
	//����ֵ
	case dtDate:
		V_VT(&v) = VT_DATE;
		V_DATE(&v) = gat_automation_date(sqlite3_column_double(m_stmt, nColumn));
		break;

	//�ַ�ֵ
	case dtString:
	{
		#ifdef _UNICODE
		const WCHAR* pszValue = (const WCHAR*)sqlite3_column_text16(m_stmt, nColumn);
		if (pszValue != NULL)
		{
			v = pszValue;
		}
		else
		{
			V_VT(&v) = VT_EMPTY;
		}
		#else
		USES_CONV_UTF8;
		const CHAR* pszValue = (const CHAR*)sqlite3_column_text(m_stmt, nColumn);
		if (pszValue != NULL)
		{
			v = UTF82W(pszValue);
		}
		else
		{
			V_VT(&v) = VT_EMPTY;
		}
		#endif
	}
	break;

	//�����ƴ�����ֵ
	case dtBinary:
	{
		#ifdef _UNICODE
		int nColumnBytes = sqlite3_column_bytes16(m_stmt, nColumn);
		#else
		int nColumnBytes = sqlite3_column_bytes(m_stmt, nColumn);
		#endif
		v.parray = SafeArrayCreateVector(VT_UI1, 0, nColumnBytes);
		if (v.parray)
		{
			PVOID pData;

			V_VT(&v) = VT_UI1|VT_ARRAY;
			hr = SafeArrayAccessData(v.parray, (void HUGEP**)&pData);
			if (FAILED(hr))
			{
				return m_ErrMsg.system_error(hr);
			}

			memcpy(pData, sqlite3_column_blob(m_stmt, nColumn), nColumnBytes);

			hr = SafeArrayUnaccessData(v.parray);
			if (FAILED(hr))
			{
				return m_ErrMsg.system_error(hr);
			}
		}
		else
		{
			return m_ErrMsg.system_error(E_OUTOFMEMORY);
		}
	}
	break;

	}
	
	//����
	return v.Detach(pVal);
}

//�����м�
STDMETHODIMP Resultset::get_Columns(IColumns** pCols)
{
	if (pCols == NULL)
	{
		return E_POINTER;
	}
	
	//����׼��SQL
	if (m_eState == osClosed)
	{ 
		CComBSTR bsEmpty;
		HRESULT hRes = Prepare(bsEmpty);
		if ( FAILED(hRes) )
		{
			return hRes;
		}
	}
	
	//�Ƿ�׼����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//�����м�
	HRESULT hRet = Columns::CreateObject(this, pCols);
	
	//����
	return hRet;
}

//������ֵ
STDMETHODIMP Resultset::get_Row(RowTypeConstants eMode, VARIANT *pVal)
{
	//SQL�Ƿ�Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//����м�
	HRESULT hRet = S_OK;
	CComVariant v;
	switch(eMode)
	{
	//����Variant
	case rtDefault:
	{
		LONG nColumns = sqlite3_column_count(m_stmt);
		switch(nColumns)
		{
		case 0: // NULL
			V_VT(&v) = VT_NULL;
			break;
				
		case 1: // no array, one scalar
			{
				CComVariant idx(0);
				hRet = get_ColumnValue(idx, dtUnknown, &v);
			}
			break;
				
		default:
			hRet = create_row(nColumns, v);
			break;
		}
	}
	break;
	
	//����Array
	case rtArray:
	{
		LONG nColumns = sqlite3_column_count(m_stmt);
		hRet = create_row(nColumns, v);
	}
	break;
	
	//����Collection
	case rtCollection:
	{
		CComPtr<IRow> pRow;
		hRet = Row::CreateObject(this, &pRow);
		if (SUCCEEDED(hRet))
		{
			v = pRow;
		}
	}
	break;
	
	//����
	default:
		hRet = m_ErrMsg.system_error(E_OUTOFMEMORY);
		break;
	}
	
	//������ֵ
	if (FAILED(hRet))
	{
		return hRet;
	}
	else
	{
		return v.Detach(pVal);
	}
}

//��������
STDMETHODIMP Resultset::get_RowCount(VARIANT *pVal)
{
	//SQL�Ƿ�Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//��������
	if(m_nRowCount > 0)
	{
		//�����ȡ��������ֱ�ӷ���
		CComVariant v;
		HRESULT hr = make_integer_or_decimal(v, m_nRowCount);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		return v.Detach(pVal);
	}
	else
	{
		//��������
		m_nRowCount = 0;

		//����SQL��ѯ
		int nRet = sqlite3_reset(m_stmt);
		if (nRet == SQLITE_OK)
		{
			m_bEOF = false;
		}
		else
		{
			return m_ErrMsg.sqlite_error(nRet);
		}
		
		//ִ��SQL��ѯ��ѭ��ͳ������
		LONGLONG nCount = 0;
		bool bStop = false;
		while(!bStop)
		{
			nRet = sqlite3_step(m_stmt);
			switch(nRet)
			{
			case SQLITE_ROW: //������Ч��
				nCount++;
				break;
				
			case SQLITE_DONE: //�Ѿ����˽����β��
				bStop = true;
				break;
				
			//case SQLITE_ERROR:
			//case SQLITE_MISUSE:
			default: //���ش���
				{
					sqlite3* db;
					HRESULT hr = m_pConnection->GetCurrentDB((void**)&db);
					if (FAILED(hr)) 
					{
						return m_ErrMsg.system_error(nRet);
					}
					return m_ErrMsg.sqlite_error(db);
				}
			}
		}
		
		//ͳ����ɺ��������SQL��ѯ
		nRet = sqlite3_reset(m_stmt);
		if (nRet != SQLITE_OK)
		{
			return m_ErrMsg.sqlite_error(nRet);
		}
		
		//�ƶ�����һ�м�¼λ��
		VARIANT_BOOL bEOF = VARIANT_FALSE;
		HRESULT hr = this->MoveStep(1, &bEOF);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}

		//ת������
		CComVariant v;
		hr = make_integer_or_decimal(v, nCount);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		m_nRowCount = nCount;

		//����
		return v.Detach(pVal);
	}
}

//�����м�
STDMETHODIMP Resultset::get_Rows(VARIANT_BOOL blnStatic, LONG lngMaxRecords, IRows** ppRows)
{
	if (ppRows == NULL)
	{
		return E_POINTER;
	}
	
	//����׼��SQL
	if (m_eState == osClosed)
	{ 
		CComBSTR bsEmpty;
		HRESULT hRet = Prepare(bsEmpty);
		if (FAILED(hRet))
		{
			return hRet;
		}
	}
	
	//�Ƿ�׼����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//�����м�
	HRESULT hRet = Rows::CreateObject(!(blnStatic == VARIANT_FALSE), lngMaxRecords, this, ppRows);
	
	//����
	return hRet;
}

//�󶨲���
STDMETHODIMP Resultset::BindParameters(LPSAFEARRAY* varParams)
{
	//SQL�Ƿ�Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	HRESULT hr = S_OK;
	LONG lLower;
	LONG lUpper;
	LONG p = 1;
	CComVariant v;
	CComVariant vIdx;
	VARTYPE vt = VT_EMPTY;
	
	hr = SafeArrayGetLBound(*varParams, 1, &lLower);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	hr = SafeArrayGetUBound(*varParams, 1, &lUpper);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	if (lUpper >= lLower)
	{
		hr = SafeArrayGetVartype(*varParams, &vt);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		ATLASSERT(vt == VT_VARIANT);
	}
	
	//�󶨲���
	for(LONG i = lLower; i <= lUpper; i++, p++)
	{
		hr = SafeArrayGetElement(*varParams, &i, &v);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		
		vIdx = p;
		hr = BindParameter(vIdx, v, dtUnknown);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
	}
	
	return S_OK;	
}

//��һ������
STDMETHODIMP Resultset::BindParameter(VARIANT varIndex,  VARIANT varValue,  DataTypeConstants eType)
{
	//SQL�Ƿ���׼����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	int nParam;
	CComVariant v(varValue);
	HRESULT hr;

	//��ò�������
	hr = get_parameter_index(varIndex, nParam);
	if (FAILED(hr))
	{
		return hr;
	}

	//������������
	int nRet = SQLITE_OK;
	if (eType == dtUnknown)
	{
		eType = guess_type(v);
	}

	/*�󶨲���*/
	switch(eType)
	{
	//��ֵ
	case dtNull:
		nRet = sqlite3_bind_null(m_stmt, nParam);
		break;

	//����
	case dtInteger:
	case dtLong:
	{
		switch(V_VT(&v) & VT_TYPEMASK)
		{
		case VT_I1:
		case VT_UI2:
		case VT_I2:
		case VT_I4:
		case VT_INT:
		case VT_BOOL:
			hr = v.ChangeType(VT_INT);
			if (FAILED(hr)) 
			{
				return m_ErrMsg.system_error(hr);
			}
			nRet = sqlite3_bind_int(m_stmt, nParam, V_INT(&v));
			break;
			
		case VT_UI4:
		case VT_UINT:
			hr = v.ChangeType(VT_UINT);
			if (FAILED(hr))
			{
				return m_ErrMsg.system_error(hr);
			}
			nRet = sqlite3_bind_int64(m_stmt, nParam, V_UINT(&v));
			break;
				
		default:			
			hr = v.ChangeType(VT_DECIMAL);
			if (FAILED(hr)) 
			{
				return m_ErrMsg.system_error(hr);
			}
			if (is_decimal_integer(V_DECIMAL(&v)))
			{
				nRet = sqlite3_bind_int64(m_stmt, nParam, get_decimal_integer(V_DECIMAL(&v)));
			}
			else
			{
				hr = v.ChangeType(VT_R8);
				if (FAILED(hr)) 
				{
					return m_ErrMsg.system_error(hr);
				}
				nRet = sqlite3_bind_double(m_stmt, nParam, V_R8(&v));
			}
			break;
		}
	}
	break;
	
	//������
	case dtFloat:
	{
		hr = v.ChangeType(VT_R8);
		if (FAILED(hr)) 
		{
			return m_ErrMsg.system_error(hr);
		}
		nRet = sqlite3_bind_double(m_stmt, nParam, V_R8(&v));
	}
	break;
	
	//������
	case dtDate:
	{
		hr = v.ChangeType(VT_DATE);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		nRet = sqlite3_bind_double(m_stmt, nParam, get_julian_date(V_DATE(&v)));
	}
	break;
	
	//�ַ���
	case dtString:
	{
		#ifndef _UNICODE
		USES_CONV_UTF8;
		#endif

		hr = v.ChangeType(VT_BSTR);
		if (FAILED(hr)) 
		{
			return m_ErrMsg.system_error(hr);
		}
		#ifdef _UNICODE
			nRet = sqlite3_bind_text16(m_stmt, nParam, V_BSTR(&v), -1, SQLITE_TRANSIENT);
		#else
			nRet = sqlite3_bind_text(m_stmt, nParam, W2UTF8( V_BSTR(&v) ), -1, SQLITE_TRANSIENT);
		#endif
	}
	break;
	
	//�����ƴ�����
	case dtBinary:
	{
		switch(V_VT(&v) & VT_TYPEMASK)
		{
		case VT_BSTR:
		case VT_LPSTR:
		case VT_LPWSTR:
		{
			hr = v.ChangeType(VT_BSTR);
			if (FAILED(hr))
			{
				return m_ErrMsg.system_error(hr);
			}	
			UINT nBytes = SysStringByteLen(V_BSTR(&v));
			nRet = sqlite3_bind_blob(m_stmt, nParam, V_BSTR(&v), nBytes, NULL);
		}
		break;

		case VT_UNKNOWN:
		{
			CComPtr<IStream> pStream;
			hr = V_UNKNOWN(&v)->QueryInterface(IID_IStream, (void**)&pStream);
			if (hr == S_OK)
			{
				hr = bind_blob(pStream, nParam, nRet);
				if (FAILED(hr)) 
				{
					return m_ErrMsg.system_error(hr);
				}
			}
			else
			{
				return m_ErrMsg.system_error(E_UNKNOWN_BINARY_DATA);
			}
		}
		break;

		case VT_UI1:
			if (V_ISARRAY(&v))
			{
				hr = bind_blob(v.parray, nParam, nRet);
			}
			else
			{
				return m_ErrMsg.system_error(E_UNKNOWN_BINARY_DATA);
			}
			break;

		default:
			return m_ErrMsg.system_error(E_UNKNOWN_BINARY_DATA);
		}
	}
	break;
	
	//δ֪
	default:
		return m_ErrMsg.system_error(E_UNKNOWN_TYPE);
	}

	return m_ErrMsg.sqlite_error(nRet);
}

//���ز�������
STDMETHODIMP Resultset::get_ParameterCount(LONG *pVal)
{
	//SQL�Ƿ�Ԥ����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//���ز�������
	*pVal = sqlite3_bind_parameter_count(m_stmt);
	return S_OK;
}

//���ز�������
STDMETHODIMP Resultset::get_ParameterName(LONG lngIndex, BSTR *strName)
{
	USES_CONV_UTF8;
	
	//SQL�Ƿ�׼����
	if ( m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//��ò�����
	CComBSTR paraName;
	const CHAR* pszName = sqlite3_bind_parameter_name(m_stmt, lngIndex);
	if (pszName != NULL)
	{
		paraName = UTF82W(pszName);
	}
	else
	{
		paraName = _T("");
	}
	
	//���ز�����
	return paraName.CopyTo(strName);
}

//���ز�������
STDMETHODIMP Resultset::get_Parameters(IParameters** ppParams)
{
	if (ppParams == NULL)
	{
		return E_POINTER;
	}
	
	//����׼��SQL
	if (m_eState == osClosed)
	{ 
		CComBSTR bsEmpty;
		HRESULT hRet = Prepare(bsEmpty);
		if (FAILED(hRet))
		{
			return hRet;
		}
	}
	
	//�Ƿ�׼����
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//���������ز�������
	HRESULT hRet = Parameters::CreateObject(this, ppParams);

	return hRet;
}

//����״̬
STDMETHODIMP Resultset::get_State(ObjectStateConstants *pVal)
{
	*pVal = m_eState;
	return S_OK;
}
