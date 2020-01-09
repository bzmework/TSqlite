/*
** 2004 October 31
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
** This file contains the C functions that implement blob
** functions for SQLite.  
**
** There is only one exported symbol in this file - the function
** sqlite3_register_blob_functions() found at the bottom of the file.
** All other code has file scope.
**
*/

#include <windows.h>
//#include <sqlite3.h>
#include "..\sqlite\sqlite3.h"
#include "unaccfn.h"

#ifdef _NO_UNACC_STUFF

void* sqlite3_register_unacc_functions(sqlite3* db) { return NULL; }
void sqlite3_unregister_unacc_functions(sqlite3* db,void* ctx) {}

#else

#include <string.h>
#include <tchar.h>
#include "..\libunacc\unacc.h"

static const char COLLATION_UNACC[] = "unaccented";
static const char COLLATION_UNACC_I[] = "unaccentedi";
static const char FUNCTION_UNACC[] = "unaccent";

#ifdef _UNICODE
static const LCID EN_LOCALE = MAKELCID( MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL), SORT_DEFAULT );
#else
static const LCID EN_LOCALE = MAKELCID( MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US), SORT_DEFAULT );
#endif

#ifdef _UNICODE
#define UNACC_CP SQLITE_UTF16LE
#else
#define UNACC_CP SQLITE_UTF8
#endif

#if 0
// CompareStrings - strange behavior
static int compare_strings( PCTSTR pszStr1, int nLen1, PCTSTR pszStr2, int nLen2, DWORD dwFlags )
{
	int nRes;

	nRes = CompareString( EN_LOCALE, dwFlags,
		pszStr1, nLen1, 
		pszStr2, nLen2 );

	return ( nRes > 0 )? (nRes-2) : 0;
	return _tcsnccmp( pszStr1, pszStr2, min( nLen1, nLen2 ) );
}
#endif

static int compare_strings(PCTSTR pszStr1, int nLen1, PCTSTR pszStr2, int nLen2, DWORD dwFlags)
{
	int nRet = (dwFlags != 0)?
		_tcsncicmp(pszStr1, pszStr2, min( nLen1, nLen2 )):
		_tcsnccmp(pszStr1, pszStr2, min( nLen1, nLen2 ));
	return (nRet == 0 )? (nLen1-nLen2) : nRet;
}

static int unacc_compare_f(void* vContext,
	int _nLen1, const void* _pszStr1,
	int _nLen2, const void* _pszStr2,
	DWORD dwFlags )
{
	PTSTR  pszStr1;
	PCTSTR pszStr2;
	int nRes, nLen1, nLen2;

	pszStr2 = unacc_unaccent( vContext, _pszStr1, _nLen1/sizeof(TCHAR) );
	nLen1 = unacc_last_size( vContext );
	pszStr1 = malloc( nLen1 * sizeof(TCHAR) );
	if ( pszStr1 == NULL ) return 0;
	_tcsncpy( pszStr1, pszStr2, nLen1 );
	pszStr2 = unacc_unaccent( vContext, _pszStr2, _nLen2/sizeof(TCHAR) );
	nLen2 = unacc_last_size( vContext );

	nRes = compare_strings( pszStr1, nLen1, pszStr2, nLen2, dwFlags );
	free( pszStr1 );
	return nRes;
}

/*
	collation sequence callback
*/
static int unacc_compare(void* vContext,
	int _nLen1, const void* _pszStr1,
	int _nLen2, const void* _pszStr2 )
{
	return unacc_compare_f( vContext,
		_nLen1, _pszStr1,
		_nLen2, _pszStr2,
		0 );
}

static int unacc_comparei(void* vContext,
	int _nLen1, const void* _pszStr1,
	int _nLen2, const void* _pszStr2 )
{
	return unacc_compare_f( vContext,
		_nLen1, _pszStr1,
		_nLen2, _pszStr2,
		NORM_IGNORECASE );
}

/*
	unacc_func
*/
static void unacc_func(
  sqlite3_context *context,
  int argc,
  sqlite3_value **argv )
{
	if ( (argc > 0) && (sqlite3_value_type(argv[0]) == SQLITE_TEXT) )
	{
		PCTSTR pszText;
#ifndef _UNICODE
		int nRes;
#endif

#ifdef _UNICODE
		pszText = unacc_unaccent( 
			sqlite3_user_data(context),
			sqlite3_value_text16le(argv[0]), -1 );

		if ( pszText != NULL )
		{
			sqlite3_result_text16le(context,
				pszText, unacc_last_size( sqlite3_user_data(context) ) * sizeof(WCHAR),
				SQLITE_TRANSIENT);
		}
#else
		pszText = unacc_unaccent( 
			sqlite3_user_data(context),
			sqlite3_value_text(argv[0]), -1 );

		if ( pszText != NULL )
		{
			// WIN-1252 --> UTF-16LE
			nRes = MultiByteToWideChar( 1252, MB_PRECOMPOSED, 
				pszText, unacc_last_size( sqlite3_user_data(context) ),
				NULL, 0 );

			if ( nRes > 0 )
			{
				PWSTR psz;

				psz = unacc_allocW( sqlite3_user_data(context), nRes );

				if ( psz != NULL )
				{
					nRes = MultiByteToWideChar( 1252, MB_PRECOMPOSED, 
						pszText, unacc_last_size( sqlite3_user_data(context) ),
						psz, nRes );

					sqlite3_result_text16le(context,
						psz, nRes * sizeof(WCHAR),
						SQLITE_TRANSIENT);
				}
			}
		}
#endif
	}
}    


void* sqlite3_register_unacc_functions(sqlite3* pDb)
{
	UNACC_STRUCT* pUnacc;

	pUnacc = unacc_init( CP_UTF8, 1252 );
	if ( pUnacc )
	{
		int nRes;

		nRes = sqlite3_create_collation( pDb, COLLATION_UNACC, UNACC_CP,
			pUnacc, unacc_compare );
		if ( SQLITE_OK != nRes )
		{
			unacc_done( pUnacc );
			return NULL;
		}

		nRes = sqlite3_create_collation( pDb, COLLATION_UNACC_I, UNACC_CP,
			pUnacc, unacc_comparei );
		if ( SQLITE_OK != nRes )
		{
			sqlite3_create_collation( pDb, COLLATION_UNACC, UNACC_CP, pUnacc, NULL );
			unacc_done( pUnacc );
			return NULL;
		}

		nRes = sqlite3_create_function( pDb, FUNCTION_UNACC, 1, UNACC_CP,
			pUnacc, unacc_func, NULL, NULL );
		if ( SQLITE_OK != nRes )
		{
			sqlite3_create_collation( pDb, COLLATION_UNACC, UNACC_CP, pUnacc, NULL );
			sqlite3_create_collation( pDb, COLLATION_UNACC_I, UNACC_CP, pUnacc, NULL );
			unacc_done( pUnacc );
			return NULL;
		}

		return pUnacc;
	}
	else
	{
		return NULL;
	}
}

void sqlite3_unregister_unacc_functions(sqlite3* pDb, void* vContext )
{
	int nRes;
	
	nRes = sqlite3_create_collation( pDb, COLLATION_UNACC, UNACC_CP,
		vContext, NULL );
	nRes |= sqlite3_create_collation( pDb, COLLATION_UNACC_I, UNACC_CP,
		vContext, NULL );
	nRes |= sqlite3_create_function( pDb, FUNCTION_UNACC, 1, UNACC_CP,
		vContext,
		NULL, NULL, NULL );

	if ( nRes != SQLITE_OK )
	{
		unacc_done( vContext );
	}
}

#endif // _NO_UNACC_STUFF
