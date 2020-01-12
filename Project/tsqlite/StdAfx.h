/*
	stdafx.h
*/

#if !defined(AFX_STDAFX_H__A30DF5E9_2F9D_4BC4_BF4C_049C8DF1031A__INCLUDED_)
#define AFX_STDAFX_H__A30DF5E9_2F9D_4BC4_BF4C_049C8DF1031A__INCLUDED_

/***版权标识**********************************/
#define COPYRIGHT _T("版权声明")
#define ABOUTME   _T("关于我们")
static const char *COMPANY = "elong"; 
static const char *AUTHOR = "denglf";
/*********************************************/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#if _MSC_VER <= 1200 // 1200=VC++6.0(vs98)
	#ifndef _WIN32_WINNT
	#define _WIN32_WINNT 0x400
	#endif
#else
	#if _MSC_VER <= 1400 // 1400=VC++ 8.0(vs2005)
		#ifndef _WIN32_WINNT
		#define _WIN32_WINNT 0x500
		#endif
	#else
		#ifndef _WIN32_WINNT
		#define _WIN32_WINNT 0x600
		#endif
	#endif
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
//#include <sqlite3.h>
#include "..\sqlite\sqlite3.h"
#include "SAEnum.h"

// UTF8 <--> UTF16
inline int w_2_utf8_length(PCWSTR lpw)
{
	ATLASSERT(lpw != NULL);
	return WideCharToMultiByte(CP_UTF8, 0, lpw, -1, NULL, 0, NULL, NULL);
}

inline PSTR w_2_utf8(PSTR lpa, int nChars, PCWSTR lpw)
{
	ATLASSERT(lpa != NULL);
	ATLASSERT(lpw != NULL);
	lpa[0] = '\0';
	WideCharToMultiByte(CP_UTF8, 0, lpw, -1, lpa, nChars, NULL, NULL);
	return lpa;
}

inline int utf8_2_w_length(PCSTR lpa)
{
	ATLASSERT(lpa != NULL);
	return MultiByteToWideChar(CP_UTF8, 0, lpa, -1, NULL, 0);
}

inline PWSTR utf8_2_w(PWSTR lpw, int nChars, PCSTR lpa)
{
	ATLASSERT(lpa != NULL);
	ATLASSERT(lpw != NULL);
	lpw[0] = L'\0';
	MultiByteToWideChar(CP_UTF8, 0, lpa, -1, lpw, nChars);
	return lpw;
}

//Convert char * to BSTR
inline BSTR ConvertStringToBSTR(const char* pSrc)
{
	if(!pSrc) return NULL;
	
	DWORD cwch;
	
	BSTR wsOut = NULL;
	
	if(cwch = ::MultiByteToWideChar(CP_ACP, 0, pSrc, -1, NULL, 0))//get size minus NULL terminator
	{
		cwch--;
		wsOut = ::SysAllocStringLen(NULL, cwch);
		
		if(wsOut)
		{
			if(!::MultiByteToWideChar(CP_ACP, 0, pSrc, -1, wsOut, cwch))
			{
				if(ERROR_INSUFFICIENT_BUFFER == ::GetLastError())
					return wsOut;
				::SysFreeString(wsOut);//must clean up
				wsOut = NULL;
			}
		}
		
	};
	
	return wsOut;
}

//Convert BSTR to char *
inline char* ConvertBSTRToString(BSTR pSrc)
{
	if(!pSrc) return NULL;
	
	DWORD cb,cwch = ::SysStringLen(pSrc);//convert even embeded NULL
	
	char *szOut = NULL;
	
	if(cb = ::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, NULL, 0, 0, 0))
	{
		szOut = new char[cb];
		if(szOut)
		{
			szOut[cb - 1]  = '\0';
			
			if(!::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, szOut, cb, 0, 0))
			{
				delete[] szOut;//clean up if failed;
				szOut = NULL;
			}
		}
	}
	
	return szOut;
}

#define USES_CONV_UTF8 int _u8convert;

#define W2UTF8(lpw) (\
	    (((void*)lpw)==NULL)? NULL : (\
		_u8convert=w_2_utf8_length(lpw),\
		w_2_utf8((PSTR)alloca(_u8convert*sizeof(CHAR)),_u8convert,lpw)))


#define UTF82W(lpa) (\
	    (((void*)lpa)==NULL)? NULL : (\
		_u8convert=utf8_2_w_length(lpa),\
		utf8_2_w((PWSTR)alloca(_u8convert*sizeof(WCHAR)),_u8convert,lpa)))

#endif // !defined(AFX_STDAFX_H__A30DF5E9_2F9D_4BC4_BF4C_049C8DF1031A__INCLUDED)
