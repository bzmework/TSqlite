/*
	Glob.cpp
*/

#include "stdafx.h"
#include "Glob.h"
#include "Messages.h"

static const double VARIANT_DATE_BASE = 2415018.5;

//将sqlite消息转换成hResult消息
HRESULT sqlite_2_hr(int nErrCode)
{
	HRESULT hRet = E_FAIL;

	switch(nErrCode)
	{
	case SQLITE_OK:
		hRet = S_SQLITE_OK;
		break;

	case SQLITE_ERROR:
		hRet = E_SQLITE_ERROR;
		break;

	case SQLITE_INTERNAL:
		hRet = E_SQLITE_INTERNAL;
		break;

	case SQLITE_PERM:
		hRet = E_SQLITE_PERM;
		break;

	case SQLITE_ABORT:
		hRet = E_SQLITE_ABORT;
		break;

	case SQLITE_BUSY:
		hRet = E_SQLITE_BUSY;
		break;

	case SQLITE_LOCKED:
		hRet = E_SQLITE_LOCKED;
		break;

	case SQLITE_NOMEM:
		hRet = E_SQLITE_NOMEM;
		break;

	case SQLITE_READONLY:
		hRet = E_SQLITE_READONLY;
		break;

	case SQLITE_INTERRUPT:
		hRet = E_SQLITE_INTERRUPT;
		break;

	case SQLITE_IOERR:
		hRet = E_SQLITE_IOERR;
		break;

	case SQLITE_CORRUPT:
		hRet = E_SQLITE_CORRUPT;
		break;

	case SQLITE_NOTFOUND:
		hRet = E_SQLITE_NOTFOUND;
		break;

	case SQLITE_FULL:
		hRet = E_SQLITE_FULL;
		break;

	case SQLITE_CANTOPEN:
		hRet = E_SQLITE_CANTOPEN;
		break;

	case SQLITE_PROTOCOL:
		hRet = E_SQLITE_PROTOCOL;
		break;

	case SQLITE_EMPTY:
		hRet = E_SQLITE_EMPTY;
		break;

	case SQLITE_SCHEMA:
		hRet = E_SQLITE_SCHEMA;
		break;

	case SQLITE_TOOBIG:
		hRet = E_SQLITE_TOOBIG;
		break;

	case SQLITE_CONSTRAINT:
		hRet = E_SQLITE_CONSTRAINT;
		break;

	case SQLITE_MISMATCH:
		hRet = E_SQLITE_MISMATCH;
		break;

	case SQLITE_MISUSE:
		hRet = E_SQLITE_MISUSE;
		break;

	case SQLITE_NOLFS:
		hRet = E_SQLITE_NOLFS;
		break;

	case SQLITE_AUTH:
		hRet = E_SQLITE_AUTH;
		break;

	case SQLITE_FORMAT:
		hRet = E_SQLITE_FORMAT;
		break;

	case SQLITE_RANGE:
		hRet = E_SQLITE_RANGE;
		break;

	case SQLITE_NOTADB:
		hRet = E_SQLITE_NOTADB;
		break;

	case SQLITE_ROW:
		hRet = S_SQLITE_ROW;
		break;

	case SQLITE_DONE:
		hRet = S_SQLITE_DONE;
		break;
	}

	return hRet;
}

//获得消息描述
bool get_description(HRESULT hRet, CComBSTR& bsDesc)
{
	PTCHAR pBuffer;

	DWORD dwRet = FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM,
		_Module.m_hInstResource,
		hRet,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(PTSTR)&pBuffer, 
		10,
		NULL);

	if (dwRet)
	{
		bsDesc = pBuffer;
		LocalFree(pBuffer);
		return true;
	}
	else
	{
		return false;
	}

}

HRESULT compare_bstr(BSTR bs1, BSTR bs2)
{
	return VarBstrCmp(bs1, bs2,
		MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), SORT_DEFAULT),
		NORM_IGNORECASE);
}

HRESULT variant_normalize(CComVariant& v)
{
	HRESULT hr = S_OK;
	switch(V_VT(&v) & VT_TYPEMASK)
	{
	case VT_I1:
	case VT_I2:
	case VT_I4:
	case VT_INT:
	case VT_UI1:
	case VT_UI2:
	case VT_UI4:
	case VT_UINT:
		hr = v.ChangeType( VT_INT );
		break;
	
	case VT_BSTR:
	case VT_LPSTR:
	case VT_LPWSTR:
		hr = v.ChangeType( VT_BSTR );
		break;
	
	default:
		hr = E_UNKNOWN_PARAM_INDEX_TYPE;
		break;
	}
	
	return hr;
}

double get_julian_date(DATE d)
{
	return d + VARIANT_DATE_BASE;
}

DATE gat_automation_date(double d)
{
	return d - VARIANT_DATE_BASE;
}

bool is_decimal_integer(const DECIMAL& dm)
{
	if (dm.scale != 0) 
	{
		return false;
	}

	if (dm.Hi32 != 0)
	{
		return false;
	}
	
	if (dm.sign)
	{
		return (dm.Lo64 <= 9223372036854775808ui64);
	}
	else
	{
		return (dm.Lo64 <= 9223372036854775807ui64);
	}
}

LONGLONG get_decimal_integer(const DECIMAL& dm)
{
	ATLASSERT(is_decimal_integer(dm));
	
	if (dm.sign)
	{
		return -((LONGLONG)dm.Lo64);
	}
	else
	{
		return (LONGLONG)dm.Lo64;
	}
}

HRESULT make_integer_or_decimal(CComVariant& v, LONGLONG n)
{
	if ((n >= -2147483648i64 ) && (n <= 2147483647i64 ))
	{
		v = (LONG)n;
	}
	#if _MSC_VER > 1300	
	else if ((n >= 0i64) && (n <= 0xffffffffi64))
	{
		v = (ULONG)n;
	}
	#endif	
	else
	{
		v = 0;
		v.ChangeType(VT_DECIMAL);
		DECIMAL& dm = v.decVal;
		
		if (n >= 0)
		{
			dm.sign = 0;
			dm.Lo64 = (ULONGLONG)n;
		}
		else
		{
			dm.sign = DECIMAL_NEG;
			dm.Lo64 = (ULONGLONG)(-n);
		}
		//v.ChangeType(VT_DECIMAL);
	}
	
	return S_OK;
}

