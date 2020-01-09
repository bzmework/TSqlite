/*
	unacc.c
*/

#include <windows.h>
#include <stdlib.h>
#include "unacc.h"
#include <unac.h>

static const size_t BLOCK_SIZE = 1024;

// forward declarations
static PCSTR unacc_unaccentA_latin( UNACC_STRUCT*, PCSTR, size_t );
static PCWSTR unacc_unaccentW_latin( UNACC_STRUCT*, PCWSTR, size_t );
static PCSTR unacc_unaccentA_unac( UNACC_STRUCT*, PCSTR, size_t );
static PCWSTR unacc_unaccentW_unac( UNACC_STRUCT*, PCWSTR, size_t );

/*
	Some CP need only 0 flags
*/
static DWORD translate_flags( DWORD dwCurFlags, UINT nCodePage )
{
	switch( nCodePage )
	{
		case 50220:
		case 50221:
		case 50222:
		case 50225:
		case 50227:
		case 50229:
		case 52936:
		case 54936:
		case 57002:
		case 57003:
		case 57004:
		case 57005:
		case 57006:
		case 57007:
		case 57008:
		case 57009:
		case 57010:
		case 57011:

		case CP_UTF7:
		case CP_UTF8:
		case CP_SYMBOL:
		return 0;

		case CP_ACP:
		return translate_flags( dwCurFlags, GetACP() );

		case CP_OEMCP:
		return translate_flags( dwCurFlags, GetOEMCP() );

		case CP_THREAD_ACP:
		{
			CPINFOEX cix;
			if ( GetCPInfoEx( CP_THREAD_ACP, 0, &cix ) )
			{
				return translate_flags( dwCurFlags, cix.CodePage );
			}
			else
			{ // ???
				return translate_flags( dwCurFlags, GetACP() );
			}
		}

		default:
		return dwCurFlags;
	}
}

UNACC_STRUCT* unacc_init_ex( UINT nCodePage, UINT nDestCodePage, UINT nMode )
{
	UNACC_STRUCT* pUnacc = (UNACC_STRUCT*)malloc( sizeof(UNACC_STRUCT) );
	if ( pUnacc != NULL )
	{
		pUnacc->nCodePage = nCodePage;
		pUnacc->nDestCodePage = nDestCodePage;
		pUnacc->nBufASize = pUnacc->nBufWSize = pUnacc->nSecBufWSize = 0;
		pUnacc->pBufA = NULL;
		pUnacc->pBufW = NULL;
		pUnacc->pSecBufW = NULL;
		pUnacc->nLastDestSize = 0;

		pUnacc->dwAFlags = translate_flags( MB_PRECOMPOSED, nCodePage );
		pUnacc->dwADestFlags = translate_flags( MB_PRECOMPOSED, nDestCodePage );
		pUnacc->dwWFlags = translate_flags( WC_COMPOSITECHECK|WC_DISCARDNS, nCodePage );
		pUnacc->dwWDestFlags = translate_flags( WC_COMPOSITECHECK|WC_DISCARDNS, nDestCodePage );

		switch( nMode )
		{
			case UNACC_MODE_LATIN1:
			pUnacc->unacc_unaccentA = unacc_unaccentA_latin;
			pUnacc->unacc_unaccentW = unacc_unaccentW_latin;
			break;

			case UNACC_MODE_ALL:
			pUnacc->unacc_unaccentA = unacc_unaccentA_unac;
			pUnacc->unacc_unaccentW = unacc_unaccentW_unac;
			break;

			default:
			free( pUnacc );
			return NULL;
		}
	}

	return pUnacc;
}

UNACC_STRUCT* unacc_init( UINT nCodePage, UINT nDestCodePage )
{
	return unacc_init_ex( nCodePage, nDestCodePage, UNACC_MODE_ALL );
}

UNACC_STRUCT* unacc_init_oem(void)
{
	return unacc_init( CP_OEMCP, 437 );
}

UNACC_STRUCT* unacc_init_ansi(void)
{
	return unacc_init( CP_ACP, 1252 );
}

void unacc_done( UNACC_STRUCT* pUnacc )
{
	free( (void*)pUnacc->pBufA );
	free( (void*)pUnacc->pBufW );

	free( (void*)pUnacc );
}

static size_t extra_size( size_t nSize )
{
	return ((nSize / BLOCK_SIZE ) * BLOCK_SIZE) + (( nSize % BLOCK_SIZE)? BLOCK_SIZE : 0);
}

PSTR unacc_allocA( UNACC_STRUCT* pUnacc, size_t nSize )
{
	if ( pUnacc->nBufASize == 0 )
	{
		pUnacc->nBufASize = extra_size( nSize );
		pUnacc->pBufA = (PSTR)malloc( pUnacc->nBufASize * sizeof(CHAR) );
	}
	else if ( nSize > pUnacc->nBufASize )
	{
		pUnacc->nBufASize = extra_size( nSize );
		pUnacc->pBufA = (PSTR)realloc( pUnacc->pBufA, pUnacc->nBufASize * sizeof(CHAR) );
	}

	return pUnacc->pBufA;
}

PWSTR unacc_allocW( UNACC_STRUCT* pUnacc, size_t nSize )
{
	if ( pUnacc->nBufWSize == 0 )
	{
		pUnacc->nBufWSize = extra_size( nSize );
		pUnacc->pBufW = (PWSTR)malloc( pUnacc->nBufWSize * sizeof(WCHAR) );
	}
	else if ( nSize > pUnacc->nBufWSize )
	{
		pUnacc->nBufWSize = extra_size( nSize );
		pUnacc->pBufW = (PWSTR)realloc( pUnacc->pBufW, pUnacc->nBufWSize * sizeof(WCHAR) );
	}

	return pUnacc->pBufW;
}

static PWSTR unacc_allocSecW( UNACC_STRUCT* pUnacc, size_t nSize )
{
	if ( pUnacc->nSecBufWSize == 0 )
	{
		pUnacc->nSecBufWSize = extra_size( nSize );
		pUnacc->pSecBufW = (PWSTR)malloc( pUnacc->nSecBufWSize * sizeof(WCHAR) );
	}
	else if ( nSize > pUnacc->nSecBufWSize )
	{
		pUnacc->nSecBufWSize = extra_size( nSize );
		pUnacc->pSecBufW = (PWSTR)realloc( pUnacc->pSecBufW, pUnacc->nSecBufWSize * sizeof(WCHAR) );
	}
	return pUnacc->pSecBufW;
}

PCSTR  unacc_unaccentA( UNACC_STRUCT* pUnacc, PCSTR pszText, size_t nLength )
{
	return pUnacc->unacc_unaccentA( pUnacc, pszText, nLength );
}

PCWSTR unacc_unaccentW( UNACC_STRUCT* pUnacc, PCWSTR pwszText, size_t nLength )
{
	return pUnacc->unacc_unaccentW( pUnacc, pwszText, nLength );
}

int unacc_last_size( UNACC_STRUCT* pUnacc )
{
	return pUnacc->nLastDestSize;
}

// ==================================================================================

static PCWSTR multi_byte_to_wide_char( 
	UNACC_STRUCT* pUnacc,
	UINT nCodePage,
	DWORD dwFlags,
	LPCSTR lpMultiByteStr,
	int cchMultiByte,
	PWSTR (* _unacc_allocW)( UNACC_STRUCT*, size_t ),
	int* pnSize )
{
	int nRes;
	PWSTR pBufW;

	nRes = MultiByteToWideChar( nCodePage, dwFlags,
		lpMultiByteStr, cchMultiByte,
		NULL, 0 );
	if ( nRes == 0 ) return NULL;
	pBufW = _unacc_allocW( pUnacc, nRes );
	if ( pBufW == NULL ) return NULL;

	nRes = MultiByteToWideChar( nCodePage, dwFlags,
		lpMultiByteStr, cchMultiByte,
		pBufW, nRes );

	*pnSize = nRes;
	return ( nRes > 0 )? pBufW : NULL;
}

static PCSTR wide_char_to_multi_byte(
	UNACC_STRUCT* pUnacc,
	UINT CodePage,            // code page
	DWORD dwFlags,            // performance and mapping flags
	LPCWSTR lpWideCharStr,    // wide-character string
	int cchWideChar,          // number of chars in string.
	PSTR (* _unacc_allocA)( UNACC_STRUCT*, size_t ),
	int* pnSize
)
{
	int nRes;
	PSTR pBufA;

	nRes = WideCharToMultiByte( 
		CodePage,
		dwFlags,
		lpWideCharStr, cchWideChar,
		NULL, 0,
		NULL, NULL );
	if ( nRes == 0 ) return NULL;
	pBufA = _unacc_allocA( pUnacc, nRes );
	if ( pBufA == NULL ) return NULL;

	nRes = WideCharToMultiByte( 
		CodePage,
		dwFlags,
		lpWideCharStr, cchWideChar,
		pBufA, nRes,
		NULL, NULL );
	
	*pnSize = nRes;
	return (nRes>0)? pBufA : NULL;
}

// ==================================================================================

static PCSTR unacc_unaccentA_latin( UNACC_STRUCT* pUnacc, PCSTR pszText, size_t nLength )
{
	int nSize;
	PCSTR pBuffA;
	PCWSTR pBuffW;

	// 1) to UNICODE
	pBuffW = multi_byte_to_wide_char( pUnacc,
		pUnacc->nCodePage,
		pUnacc->dwAFlags,
		pszText, nLength,
		unacc_allocW,
		&nSize );
	if ( pBuffW == NULL ) return NULL;

	// 2) to OEM / ANSI
	pBuffA = wide_char_to_multi_byte( pUnacc,
		pUnacc->nDestCodePage,
		pUnacc->dwWDestFlags,
		pBuffW, nSize,
		unacc_allocA,
		&pUnacc->nLastDestSize );

	return pBuffA;
}

static PCWSTR unacc_unaccentW_latin( UNACC_STRUCT* pUnacc, PCWSTR pszText, size_t nLength )
{
	int nSize;
	PCSTR pBuffA;
	PCWSTR pBuffW;

	// 2) to OEM / ANSI
	pBuffA = wide_char_to_multi_byte( pUnacc,
		pUnacc->nDestCodePage,
		pUnacc->dwWDestFlags,
		pszText, nLength,
		unacc_allocA,
		&nSize );
	if ( pBuffA == NULL ) return NULL;

	// 2) to UNICODE
	pBuffW = multi_byte_to_wide_char( pUnacc,
		pUnacc->nDestCodePage,
		pUnacc->dwADestFlags,
		pBuffA, nSize,
		unacc_allocW,
		&pUnacc->nLastDestSize );

	return pBuffW;
}

// =======================================================================

/*
	based on unac
*/
static PCWSTR unacc_string_utf16(
	UNACC_STRUCT* pUnacc,
	PCWSTR pszText,
	size_t nSize,
	PWSTR (* _unacc_allocW)( UNACC_STRUCT*, size_t ),
	int* pnDestLength )
{
	PWSTR pBuffW;
	size_t nLength, nCurLength, nBuffSize, i;

	nLength = (nSize != (size_t)(-1) )? nSize : wcslen(pszText);
	nBuffSize = nLength + ( (nSize == (size_t)(-1) )? 1 : 0 );
	pBuffW = _unacc_allocW( pUnacc, nBuffSize );
	if ( pBuffW == NULL ) return NULL;

	nCurLength = 0;

	for( i=0; i<nLength; i++ )
	{
		WCHAR c;
		unsigned short* p;
		int l;

		c = pszText[i];
		unac_char_utf16( c, p, l );

		if ( (nCurLength + l) > nBuffSize )
		{
			nBuffSize += l;
			pBuffW = _unacc_allocW( pUnacc, nBuffSize );
			if ( pBuffW == NULL ) return NULL;
		}

		if(l > 0)
		{
			int k;

			/*
			* If there is a decomposition, insert it in the output 
			* string.
			*/

			for(k = 0; k < l; k++)
			{
				c = p[k];
				pBuffW[ nCurLength++ ] = c;
			}
		}
		else
		{
			pBuffW[ nCurLength++ ] = c;
		}
	}

	if ( nSize == (size_t)(-1) )
	{ // '\0'
		if ( (nCurLength + 1) > nBuffSize )
		{
			nBuffSize += 1;
			pBuffW = _unacc_allocW( pUnacc, nBuffSize );
			if ( pBuffW == NULL ) return NULL;
		}
		pBuffW[ nCurLength++ ] = L'\0';
	}

	*pnDestLength = nCurLength;
	return pBuffW;
}

static PCSTR unacc_unaccentA_unac( UNACC_STRUCT* pUnacc, PCSTR pszText, size_t nLength )
{
	int nSize;
	PCSTR pBuffA;
	PCWSTR pSecBuffW;
	PCWSTR pBuffW;

	// 1) to UNICODE
	pSecBuffW = multi_byte_to_wide_char( pUnacc,
		pUnacc->nCodePage,
		pUnacc->dwAFlags,
		pszText, nLength,
		unacc_allocSecW,
		&nSize );
	if ( pSecBuffW == NULL ) return NULL;

	// 2) Unaccent
	pBuffW = unacc_string_utf16( pUnacc, pSecBuffW, nSize,
		unacc_allocW, &nSize );
	if ( pBuffW == NULL ) return NULL;

	// 3) to OEM / ANSI
	pBuffA = wide_char_to_multi_byte( pUnacc,
		pUnacc->nDestCodePage,
		0,
		pBuffW, nSize,
		unacc_allocA,
		&pUnacc->nLastDestSize );

	return pBuffA;
}

static PCWSTR unacc_unaccentW_unac( UNACC_STRUCT* pUnacc, PCWSTR pszText, size_t nLength )
{
	return unacc_string_utf16( pUnacc, pszText, nLength,
		unacc_allocW, &pUnacc->nLastDestSize );
}

