/*
	Glob.h
*/

#ifndef _GLOB_H_
#define _GLOB_H_

bool get_description(HRESULT, CComBSTR&);
HRESULT sqlite_2_hr(int);

bool is_decimal_integer(const DECIMAL&);
LONGLONG get_decimal_integer( const DECIMAL&);
HRESULT make_integer_or_decimal(CComVariant&, LONGLONG);

HRESULT compare_bstr(BSTR, BSTR);
HRESULT variant_normalize(CComVariant&);

double get_julian_date(DATE);
DATE gat_automation_date(double);

#endif // _GLOB_H_
