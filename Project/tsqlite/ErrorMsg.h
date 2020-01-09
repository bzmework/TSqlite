/*
	ErrorMsg.h
*/

#ifndef __ERRORMSG_H_
#define __ERRORMSG_H_

#include "Glob.h"

//´íÎóÏûÏ¢
class ErrorMsg
{
private:
	CLSID m_CLSID;
	IID m_IID;

public:

	VOID Init(const CLSID &clsid, const IID &iid)
	{
		m_CLSID = clsid;
		m_IID = iid;
	}

	HRESULT system_error(HRESULT hr) const
	{
		CComBSTR bsDesc;
		if (FAILED(hr) && get_description(hr, bsDesc))
		{
			return AtlReportError(m_CLSID, bsDesc, 0, NULL, m_IID, hr);
		}
		else
		{	
			return hr;
		}
	}

	HRESULT sqlite_error(sqlite3* db) const
	{
		HRESULT hr = sqlite_2_hr(sqlite3_errcode(db));
		
		#ifdef _UNICODE
		const WCHAR* pszDesc = (const WCHAR*)sqlite3_errmsg16(db);
		#else
		const CHAR* pszDesc = (const CHAR*)sqlite3_errmsg(db);
		#endif
		
		if (FAILED(hr))
		{
			return AtlReportError(m_CLSID, pszDesc, 0, NULL, m_IID, hr);
		}
		else
		{
			return hr;
		}
	}

	HRESULT sqlite_error(int nError) const
	{
		return system_error(sqlite_2_hr(nError));
	}

	HRESULT sqlite_error(int nError, const char* pszMsg) const
	{
		HRESULT hr = sqlite_2_hr(nError);
		if (FAILED(hr))
		{
			return AtlReportError(m_CLSID, pszMsg, 0, NULL, m_IID, hr);
		}
		else
		{
			return hr;
		}
	}

};

#endif // __ERRORMSG_H_
