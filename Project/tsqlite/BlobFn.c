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
#include <ctype.h>
#include <malloc.h>
#include <tchar.h>
#include "blobfn.h"

#ifdef _UNICODE
#define BLOB_CP SQLITE_UTF16LE
#else
#define BLOB_CP SQLITE_UTF8
#endif

static int get_first_param( 
  sqlite3_context *context,
  int argc,
  sqlite3_value **argv,
  int* pnSize,
  const char** ppBlob)
{
    if ((argc > 0) && (sqlite3_value_type(argv[0]) == SQLITE_BLOB ))
    {
        *pnSize = sqlite3_value_bytes(argv[0]);
        *ppBlob = (const char*)sqlite3_value_blob(argv[0]);
        return 1;
    }
    else
    {
        return 0;
    }        
}    

static TCHAR get_second_param(
  sqlite3_context *context,
  int argc,
  sqlite3_value **argv,
  TCHAR cDef)
{
    if ((argc > 1) &&
        (sqlite3_value_bytes(argv[1])>0) &&
        (sqlite3_value_type(argv[1]) == SQLITE_TEXT))
    {
		#ifdef _UNICODE
        return *( (const WCHAR*)sqlite3_value_text16le(argv[1]) );
		#else
        return *sqlite3_value_text(argv[1]);
		#endif
    }
    else
    {
        return cDef;
    }        
}    

/*
** tovis
*/
static void tovisFunc(
  sqlite3_context *context,
  int argc,
  sqlite3_value **argv)
{
    int nSize, i;
    const char* pBlob;
    PTSTR pszRes;
    TCHAR cRep;
	char c;
    
    if (!get_first_param(context, argc, argv, &nSize, &pBlob))
    {
        return;
    }
    
    cRep = get_second_param(context, argc, argv, _T('\0'));
    if (!_istprint(cRep)) 
	{
		cRep = _T('.'); // default value
    }

    pszRes = malloc(nSize * sizeof(TCHAR));
    if (!pszRes)
    {
        return;
    }    
    
    for(i=0; i<nSize; i++)
    {
        c = pBlob[i];
        pszRes[i] = isprint(c)? c : cRep;
    }

	#ifdef _UNICODE
    sqlite3_result_text16le(context, pszRes, nSize * sizeof(WCHAR), SQLITE_TRANSIENT);
	#else
    sqlite3_result_text(context, pszRes, nSize, SQLITE_TRANSIENT);
	#endif

    free(pszRes);
}    

static const TCHAR HEXDIG[] = _T("0123456789ABCDEF");

/*
** tohex
*/
static void tohexFunc(
  sqlite3_context *context,
  int argc,
  sqlite3_value **argv )
{
    int nSize, i, j;
    const char* pBlob;
    PTSTR pszRes;
    TCHAR cSep;
	char c;
    int nAddSep;
    
    if (!get_first_param(context, argc, argv, &nSize, &pBlob))
    {
        return;
    }

    cSep = get_second_param(context, argc, argv, _T('\0'));
    nAddSep = _istprint(cSep);
   
    pszRes = malloc((nSize * (nAddSep? 3:2) + 1) * sizeof(TCHAR));
    if (!pszRes)
    {
        return;
    }
    
    j=0;
    for( i=0; i<nSize; i++)
    {
        c = pBlob[i];
        pszRes[j] = HEXDIG[ (c & 0xF0) >> 4 ];
        pszRes[j+1] = HEXDIG[ c & 0x0F ];
        
        if ( nAddSep )
        {
            pszRes[j+2] = cSep;
            j+=3;
        }
        else
        {    
            j+=2;
        }    
    }
    
    if (nAddSep && (nSize>0))
    {
        pszRes[j-1] = _T('\0');
    }
    else
    {
        pszRes[j] = _T('\0');
    }

	#ifdef _UNICODE
    sqlite3_result_text16le(context, pszRes, -1, SQLITE_TRANSIENT);
	#else    
    sqlite3_result_text(context, pszRes, -1, SQLITE_TRANSIENT);
	#endif

    free(pszRes);
}

/*
** This function registered all of the above C functions as SQL
** functions.  This should be the only routine in this file with
** external linkage.
*/
void sqlite3_register_blob_functions(sqlite3 *db){
	static struct 
	{
		char *zName;
		int nArg;
		void (*xFunc)(sqlite3_context*,int,sqlite3_value**);
	} aFuncs[] = 
	{
		#ifndef SQLITE_OMIT_BLOB_FUNCS
		{ "tovis",   -1, tovisFunc },
		{ "tohex",   -1, tohexFunc },
		#endif
	};

	int i;

	for(i=0; i<sizeof(aFuncs)/sizeof(aFuncs[0]); i++)
	{
		sqlite3_create_function(db, aFuncs[i].zName, aFuncs[i].nArg, BLOB_CP, 0, aFuncs[i].xFunc, 0, 0);
	}
}

