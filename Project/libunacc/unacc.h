/*
	unacc.h
*/

#ifndef _UNACC_H_
#define _UNACC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define UNACC_MODE_LATIN1 0	// convert to Latin1 
#define UNACC_MODE_ALL    1	// discard all accents (default)

typedef struct _UNACC_STRUCT
{
	UINT nCodePage;
	UINT nDestCodePage;

	size_t nBufASize;
	PSTR pBufA;
	size_t nBufWSize;
	PWSTR pBufW;
	size_t nSecBufWSize;
	PWSTR pSecBufW;

	DWORD dwAFlags;
	DWORD dwADestFlags;
	DWORD dwWFlags;
	DWORD dwWDestFlags;

	// vectors
	PCSTR   (* unacc_unaccentA)( struct _UNACC_STRUCT*, PCSTR, size_t );
	PCWSTR  (* unacc_unaccentW)( struct _UNACC_STRUCT*, PCWSTR, size_t );

	// number of characters returned
	int nLastDestSize;

} UNACC_STRUCT, *PUNACC_STRUCT;

UNACC_STRUCT* unacc_init_ex( UINT, UINT, UINT );

UNACC_STRUCT* unacc_init( UINT, UINT );
UNACC_STRUCT* unacc_init_oem(void);
UNACC_STRUCT* unacc_init_ansi(void);

void unacc_done( UNACC_STRUCT* );

PSTR unacc_allocA( UNACC_STRUCT*, size_t );
PWSTR unacc_allocW( UNACC_STRUCT*, size_t );

PCSTR  unacc_unaccentA( UNACC_STRUCT*, PCSTR, size_t );
PCWSTR unacc_unaccentW( UNACC_STRUCT*, PCWSTR, size_t );

int unacc_last_size( UNACC_STRUCT* );

#ifdef _UNICODE
#define unacc_unaccent unacc_unaccentW
#define unacc_alloc unacc_allocW
#else
#define unacc_unaccent unacc_unaccentA
#define unacc_alloc unacc_allocA
#endif


#ifdef __cplusplus
};
#endif

#endif

