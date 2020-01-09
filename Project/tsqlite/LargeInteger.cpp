/*
	LargeInteger.cpp
*/

#include "stdafx.h"
#include <limits.h>
#include "LargeInteger.h"
#include "Glob.h"

STDMETHODIMP CLargeInteger::get_LowPart(LONG* pVal)
{
	if ( pVal == NULL )
	{
		return E_POINTER;
	}

	*pVal = (LONG)m_li.LowPart;
	return S_OK;
}

STDMETHODIMP CLargeInteger::put_LowPart(LONG newVal)
{
	m_li.LowPart = (DWORD)newVal;
	return S_OK;
}

STDMETHODIMP CLargeInteger::get_HighPart(LONG* pVal)
{
	if ( pVal == NULL )
	{
		return E_POINTER;
	}

	*pVal = m_li.HighPart;
	return S_OK;
}

STDMETHODIMP CLargeInteger::put_HighPart(LONG newVal)
{
	m_li.HighPart = newVal;
	return S_OK;
}

STDMETHODIMP CLargeInteger::get_QuadPart(DECIMAL* pVal)
{
	if ( pVal == NULL )
	{
		return E_POINTER;
	}
	
	CComVariant v(0);
	v.ChangeType( VT_DECIMAL );
	DECIMAL& dm = v.decVal;
	
	if ( m_li.QuadPart >=0 )
	{
		dm.sign = 0;
		dm.Lo64 = (ULONGLONG)m_li.QuadPart;
	}
	else
	{
		dm.sign = DECIMAL_NEG;
		dm.Lo64 = (ULONGLONG)(-m_li.QuadPart);
	}
	
	*pVal = dm;
	return S_OK;
}

STDMETHODIMP CLargeInteger::put_QuadPart(DECIMAL newVal)
{
	if ( is_decimal_integer( newVal ) )
	{
		if ( newVal.sign )
		{
			m_li.QuadPart = -((LONGLONG)newVal.Lo64);
		}
		else
		{
			m_li.QuadPart = newVal.Lo64;
		}
		return S_OK;
	}
	else
	{
		return DISP_E_OVERFLOW;
	}
}

STDMETHODIMP CLargeInteger::get_MaxValue(DECIMAL* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	
	CComVariant v(0);
	v.ChangeType(VT_DECIMAL);
	DECIMAL& dm = v.decVal;
	dm.Lo64 = 9223372036854775807ui64;
	*pVal = dm;
	return S_OK;
}

STDMETHODIMP CLargeInteger::get_MinValue(DECIMAL* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	
	CComVariant v(0);
	v.ChangeType(VT_DECIMAL);
	DECIMAL& dm = v.decVal;
	dm.sign = DECIMAL_NEG;
	dm.Lo64 = 9223372036854775808ui64;
	*pVal = dm;
	return S_OK;
}

STDMETHODIMP CLargeInteger::get_QuadPartCy(CY* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}
	pVal->int64 = m_li.QuadPart;
	return S_OK;
}

STDMETHODIMP CLargeInteger::put_QuadPartCy(CY newVal)
{
	m_li.QuadPart = newVal.int64;
	return S_OK;
}

STDMETHODIMP CLargeInteger::get_MinValueCy(CY* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}

	pVal->int64 = LONG_MIN;
	return S_OK;
}

STDMETHODIMP CLargeInteger::get_MaxValueCy(CY* pVal)
{
	if (pVal == NULL)
	{
		return E_POINTER;
	}

	pVal->int64 = LONG_MAX;
	return S_OK;
}
