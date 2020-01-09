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

//系统生成，勿删除
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

//创建行
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

//推测数据类型
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

//绑定二进制大数据
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

//绑定二进制大数据
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

//获得列名
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

//获得列类型
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

//获得列索引
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

//获得参数索引
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

//返回当前活动连接对象
STDMETHODIMP Resultset::get_ActiveConnection(IConnection* *pVal)
{
	return m_pConnection.QueryInterface(pVal);
}

//设置当前活动连接对象
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

//返回待执行的SQL查询
STDMETHODIMP Resultset::get_SQL(BSTR *pVal)
{
	return m_strSql.CopyTo(pVal);
}

//设置待执行的SQL查询
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

//预备SQL查询
STDMETHODIMP Resultset::Prepare(BSTR strSql)
{
	#ifndef _UNICODE
	USES_CONV_UTF8;
	#endif
	
	//Sqlite对象未关闭
	if (m_eState != osClosed)
	{
		return m_ErrMsg.system_error(E_ALREADY_PREPARED);
	}
	
	//是否已绑定到活动连接对象
	if (!m_pConnection)
	{
		return m_ErrMsg.system_error(E_NO_ACTIVE_CONNECTION);
	}
	
	//获得活动连接对象
	sqlite3* db;
	HRESULT hr = m_pConnection->GetCurrentDB((void**)&db);
	if (FAILED(hr)) 
	{
		return m_ErrMsg.system_error(hr);
	}
	
	//设置待查询的SQL
	if (SysStringLen(strSql) > 0)
	{
		m_strSql = strSql;
	}
	if (m_strSql.Length() == 0)
	{
		return m_ErrMsg.system_error(E_NO_COMMAND_STRING);
	}
	
	//预备SQL
	//调用sqlite3_prepare()将SQL语句编译为sqlite内部一个结构体(sqlite3_stmt).
	//该结构体中包含了将要执行的的SQL语句的信息.
	//对于很多SQL语句来说，执行sqlite3_prepare()的时间等于或者超过执行sqlite3_step()的时间。所以应避免频繁调用sqlite3_prepare(）
	//sqlite3_get_table效率低下, 官方推荐使用sqlite3_prepare_v2替代.
	int nRet = 0;
	#ifdef _UNICODE
		nRet = sqlite3_prepare16_v2(db, m_strSql, -1, &m_stmt, NULL);
	#else
		nRet = sqlite3_prepare_v2(db, W2UTF8(m_strSql), -1, &m_stmt, NULL);
	#endif
	if (nRet == SQLITE_OK)
	{
		m_eState = osPrepared; //已预备好
		m_nRowCount = 0;//重置行数
		m_bEOF = false;//结束标志
	}
	
	//返回
	return m_ErrMsg.sqlite_error(db);
}

//执行SQL查询
STDMETHODIMP Resultset::Execute()
{
	//SQL是否已准备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//重置SQL查询
	int nRet = sqlite3_reset(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_bEOF = false;
	}

	//移动到第一条记录位置
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//返回
	return S_OK;
}

//重新执行SQL查询
STDMETHODIMP Resultset::Requery()
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//重置SQL查询
	int nRet = sqlite3_reset(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_bEOF = false;
	}
	else
	{
		return m_ErrMsg.sqlite_error(nRet);
	}
	
	//移动到第一条记录
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//返回
	return S_OK;
}

//关闭结果集
STDMETHODIMP Resultset::Close()
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return S_OK;
	}
	
	//关闭结果集
	int nRet = sqlite3_finalize(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_eState = osClosed;
		m_nRowCount = 0;
		m_bEOF = true;
		m_stmt = NULL;
	}
	
	//返回
	return m_ErrMsg.sqlite_error(nRet);
}

//当前记录位置位于结果集的第一条记录之前
/*
STDMETHODIMP Resultset::get_BOF(VARIANT_BOOL* pVal)
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//是否已到了结果集首部
	*pVal = (m_bBOF? VARIANT_TRUE: VARIANT_FALSE);
	
	return S_OK;
}
*/

//当前记录位置位于结果集的最后一条记录之后
STDMETHODIMP Resultset::get_EOF(VARIANT_BOOL* pVal)
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//是否已到了结果集尾部
	*pVal = (m_bEOF? VARIANT_TRUE: VARIANT_FALSE);

	return S_OK;
}

//移动到第一条记录
STDMETHODIMP Resultset::MoveFirst()
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//重置SQL查询
	int nRet = sqlite3_reset(m_stmt);
	if (nRet == SQLITE_OK)
	{
		m_bEOF = false;
	}
	else
	{
		return m_ErrMsg.sqlite_error(nRet);
	}

	//移动到第一条记录位置
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//返回
	return S_OK;
}

//移动到下一条记录
STDMETHODIMP Resultset::MoveNext()
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//移动到下一条
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	HRESULT hr = this->MoveStep(1, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}

	//返回
	return S_OK;
}

//移动到上一条记录
//STDMETHODIMP Resultset::MovePrevious()

//移动到最后一条记录
STDMETHODIMP Resultset::MoveLast()
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//移动到最后一条
	VARIANT_BOOL bEOF = VARIANT_FALSE;
	LONG lngRow = (LONG)(m_nRowCount - 1);
	HRESULT hr = this->MoveStep(lngRow, &bEOF);
	if (FAILED(hr))
	{
		return m_ErrMsg.system_error(hr);
	}
	
	//返回
	return S_OK;
}

//移动到指定的记录行
//STDMETHODIMP Resultset::MoveSpecial(LONG lngRow)
 
//移动指定行数
HRESULT Resultset::MoveStep(LONG nSteps,  VARIANT_BOOL *pbEOF)
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//验证步数是否有效
	if (nSteps <= 0)
	{
		return m_ErrMsg.system_error(E_STMT_BAD_STEP_PARAMETER);
	}
	
	//移动到指定步数
	//执行SQL查询
	//sqlite3_step的返回值取决于创建sqlite3_stmt参数所使用的函数，
	//假如使用老版本的接口sqlite3_prepare()或sqlite3_prepare16()，
	//返回值会是SQLITE_BUSY、SQLITE_DONE、SQLITE_ROW、SQLITE_ERROR 或 SQLITE_MISUSE；
	//而v2版本的接口sqlite3_prepare_v2()和sqlite3_prepare16_v2()除了这些值以外，还可能返回扩展状态码。
	
	//调用sqlite3_step(),这时候SQL语句才真正执行.
	//注意该函数的返回值,SQLITE_DONE和SQLITE_ROW都是表示执行成功,
	//不同的是SQLITE_DONE表示没有查询结果,像UPDATE,INSERT这些SQL语句都是返回SQLITE_DONE,
	//SELECT查询语句在查询结果不为空的时候返回SQLITE_ROW,在查询结果为空的时候返回SQLITE_DONE.
	//SQLITE_DONE尽管被归结为error code，但是不代表着执行错误，而是意味着查询结果为空。
	//SQLITE_OK表示执行结束并有查询结果
	
	//每次调用sqlite3_step()的时候,只返回一行数据,使用sqlite3_column_XXX()函数来取出这些数据.
	//要取出全部的数据需要反复调用sqlite3_step(). (注意,在bind参数的时候, 参数列表的index从1开始,而取出数据的时候, 列的index是从0开始). 
	int nRet = 0;
	bool bStop = false;
	while((nSteps > 0) && !bStop)
	{
		nRet = sqlite3_step(m_stmt);
		switch(nRet)
		{
		case SQLITE_ROW: //有效的行
			break;
			
		case SQLITE_DONE: //已到结果集尾部
			m_bEOF = true;
			bStop = true;
			break;
			
		//case SQLITE_ERROR:
		//case SQLITE_MISUSE: // raise error
		default: //返回错误
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
	
	//是否到了结果集尾部
	*pbEOF = (m_bEOF? VARIANT_TRUE : VARIANT_FALSE);

	//返回
	return m_ErrMsg.sqlite_error(nRet);
}

//返回列数
STDMETHODIMP Resultset::get_ColumnCount(LONG *pVal)
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//返回列数
	*pVal = sqlite3_column_count(m_stmt);
	return S_OK;
}

//返回列类型
STDMETHODIMP Resultset::get_ColumnType(VARIANT varIndex, DataTypeConstants* eType )
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//获得列索引
	int nColumn = 0;
	HRESULT hr = get_column_index(varIndex, nColumn);
	if (FAILED(hr))
	{
		return hr;
	}
	
	//返回列类型
	*eType = get_column_type(nColumn);
	
	return S_OK;
}

//返回列名
STDMETHODIMP Resultset::get_ColumnName(LONG lngIndex, BSTR *pVal)
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//获得列名
	CComBSTR colName;
	HRESULT hr = get_column_name(lngIndex, colName);
	if (FAILED(hr)) 
	{
		return hr;
	}
	
	//返回列名
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

//返回列值
STDMETHODIMP Resultset::get_ColumnValue(VARIANT varIndex, DataTypeConstants eType, VARIANT *pVal)
{
	//SQL是否已预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	//获得列索引
	int nColumn = 0;
	HRESULT hr = get_column_index(varIndex, nColumn);
	if (FAILED(hr)) 
	{
		return hr;
	}

	//获得列类型
	if (eType == dtUnknown)
	{
		eType = get_column_type(nColumn);
		if (eType == dtUnknown) 
		{
			return m_ErrMsg.system_error(E_UNKNOWN_COLUMN_TYPE);
		}
	}
	
	//获得列值
	CComVariant v;
	switch(eType)
	{
	//空值
	case dtNull:
		V_VT(&v) = VT_NULL;
		break;

	//整型值
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

	//浮点值
	case dtFloat:
		v = sqlite3_column_double(m_stmt, nColumn);
		break;
	
	//日期值
	case dtDate:
		V_VT(&v) = VT_DATE;
		V_DATE(&v) = gat_automation_date(sqlite3_column_double(m_stmt, nColumn));
		break;

	//字符值
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

	//二进制大数据值
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
	
	//返回
	return v.Detach(pVal);
}

//返回列集
STDMETHODIMP Resultset::get_Columns(IColumns** pCols)
{
	if (pCols == NULL)
	{
		return E_POINTER;
	}
	
	//尝试准备SQL
	if (m_eState == osClosed)
	{ 
		CComBSTR bsEmpty;
		HRESULT hRes = Prepare(bsEmpty);
		if ( FAILED(hRes) )
		{
			return hRes;
		}
	}
	
	//是否准备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//创建列集
	HRESULT hRet = Columns::CreateObject(this, pCols);
	
	//返回
	return hRet;
}

//返回行值
STDMETHODIMP Resultset::get_Row(RowTypeConstants eMode, VARIANT *pVal)
{
	//SQL是否预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//获得行集
	HRESULT hRet = S_OK;
	CComVariant v;
	switch(eMode)
	{
	//返回Variant
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
	
	//返回Array
	case rtArray:
	{
		LONG nColumns = sqlite3_column_count(m_stmt);
		hRet = create_row(nColumns, v);
	}
	break;
	
	//返回Collection
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
	
	//错误
	default:
		hRet = m_ErrMsg.system_error(E_OUTOFMEMORY);
		break;
	}
	
	//返回行值
	if (FAILED(hRet))
	{
		return hRet;
	}
	else
	{
		return v.Detach(pVal);
	}
}

//返回行数
STDMETHODIMP Resultset::get_RowCount(VARIANT *pVal)
{
	//SQL是否预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//返回行数
	if(m_nRowCount > 0)
	{
		//如果已取得行数则直接返回
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
		//重置行数
		m_nRowCount = 0;

		//重置SQL查询
		int nRet = sqlite3_reset(m_stmt);
		if (nRet == SQLITE_OK)
		{
			m_bEOF = false;
		}
		else
		{
			return m_ErrMsg.sqlite_error(nRet);
		}
		
		//执行SQL查询，循环统计行数
		LONGLONG nCount = 0;
		bool bStop = false;
		while(!bStop)
		{
			nRet = sqlite3_step(m_stmt);
			switch(nRet)
			{
			case SQLITE_ROW: //返回有效行
				nCount++;
				break;
				
			case SQLITE_DONE: //已经到了结果集尾部
				bStop = true;
				break;
				
			//case SQLITE_ERROR:
			//case SQLITE_MISUSE:
			default: //返回错误
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
		
		//统计完成后必须重置SQL查询
		nRet = sqlite3_reset(m_stmt);
		if (nRet != SQLITE_OK)
		{
			return m_ErrMsg.sqlite_error(nRet);
		}
		
		//移动到第一行记录位置
		VARIANT_BOOL bEOF = VARIANT_FALSE;
		HRESULT hr = this->MoveStep(1, &bEOF);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}

		//转换行数
		CComVariant v;
		hr = make_integer_or_decimal(v, nCount);
		if (FAILED(hr))
		{
			return m_ErrMsg.system_error(hr);
		}
		m_nRowCount = nCount;

		//返回
		return v.Detach(pVal);
	}
}

//返回行集
STDMETHODIMP Resultset::get_Rows(VARIANT_BOOL blnStatic, LONG lngMaxRecords, IRows** ppRows)
{
	if (ppRows == NULL)
	{
		return E_POINTER;
	}
	
	//尝试准备SQL
	if (m_eState == osClosed)
	{ 
		CComBSTR bsEmpty;
		HRESULT hRet = Prepare(bsEmpty);
		if (FAILED(hRet))
		{
			return hRet;
		}
	}
	
	//是否准备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//创建行集
	HRESULT hRet = Rows::CreateObject(!(blnStatic == VARIANT_FALSE), lngMaxRecords, this, ppRows);
	
	//返回
	return hRet;
}

//绑定参数
STDMETHODIMP Resultset::BindParameters(LPSAFEARRAY* varParams)
{
	//SQL是否预备好
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
	
	//绑定参数
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

//绑定一个参数
STDMETHODIMP Resultset::BindParameter(VARIANT varIndex,  VARIANT varValue,  DataTypeConstants eType)
{
	//SQL是否已准备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}

	int nParam;
	CComVariant v(varValue);
	HRESULT hr;

	//获得参数索引
	hr = get_parameter_index(varIndex, nParam);
	if (FAILED(hr))
	{
		return hr;
	}

	//评估参数类型
	int nRet = SQLITE_OK;
	if (eType == dtUnknown)
	{
		eType = guess_type(v);
	}

	/*绑定参数*/
	switch(eType)
	{
	//空值
	case dtNull:
		nRet = sqlite3_bind_null(m_stmt, nParam);
		break;

	//整型
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
	
	//浮点型
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
	
	//日期型
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
	
	//字符型
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
	
	//二进制大数据
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
	
	//未知
	default:
		return m_ErrMsg.system_error(E_UNKNOWN_TYPE);
	}

	return m_ErrMsg.sqlite_error(nRet);
}

//返回参数数量
STDMETHODIMP Resultset::get_ParameterCount(LONG *pVal)
{
	//SQL是否预备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//返回参数数量
	*pVal = sqlite3_bind_parameter_count(m_stmt);
	return S_OK;
}

//返回参数名称
STDMETHODIMP Resultset::get_ParameterName(LONG lngIndex, BSTR *strName)
{
	USES_CONV_UTF8;
	
	//SQL是否准备好
	if ( m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//获得参数名
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
	
	//返回参数名
	return paraName.CopyTo(strName);
}

//返回参数集合
STDMETHODIMP Resultset::get_Parameters(IParameters** ppParams)
{
	if (ppParams == NULL)
	{
		return E_POINTER;
	}
	
	//尝试准备SQL
	if (m_eState == osClosed)
	{ 
		CComBSTR bsEmpty;
		HRESULT hRet = Prepare(bsEmpty);
		if (FAILED(hRet))
		{
			return hRet;
		}
	}
	
	//是否准备好
	if (m_eState != osPrepared)
	{
		return m_ErrMsg.system_error(E_STMT_NOT_PREPARED);
	}
	
	//创建并返回参数集合
	HRESULT hRet = Parameters::CreateObject(this, ppParams);

	return hRet;
}

//返回状态
STDMETHODIMP Resultset::get_State(ObjectStateConstants *pVal)
{
	*pVal = m_eState;
	return S_OK;
}
