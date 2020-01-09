

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for TSqlite.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "TSqlite.h"

#define TYPE_FORMAT_STRING_SIZE   1467                              
#define PROC_FORMAT_STRING_SIZE   1975                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   3            

typedef struct _TSqlite_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } TSqlite_MIDL_TYPE_FORMAT_STRING;

typedef struct _TSqlite_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } TSqlite_MIDL_PROC_FORMAT_STRING;

typedef struct _TSqlite_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } TSqlite_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const TSqlite_MIDL_TYPE_FORMAT_STRING TSqlite__MIDL_TypeFormatString;
extern const TSqlite_MIDL_PROC_FORMAT_STRING TSqlite__MIDL_ProcFormatString;
extern const TSqlite_MIDL_EXPR_FORMAT_STRING TSqlite__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IConnection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IConnection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IResultset_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IResultset_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBusy_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBusy_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IProgress_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IProgress_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRow_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRow_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRows_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRows_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IColumn_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IColumn_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IColumns_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IColumns_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IParameter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IParameter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IParameters_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IParameters_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   forced complex structure or array, new range semantics, compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const TSqlite_MIDL_PROC_FORMAT_STRING TSqlite__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure AboutMe */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 24 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Version */

/* 30 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x8 ),	/* 8 */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 46 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 48 */	NdrFcShort( 0x1 ),	/* 1 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 54 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 56 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 58 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SQL */


	/* Procedure get_Db */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x9 ),	/* 9 */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 82 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 84 */	NdrFcShort( 0x1 ),	/* 1 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 90 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0x4a8 ),	/* Type Offset=1192 */

	/* Return value */


	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SQL */


	/* Procedure put_Db */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0xa ),	/* 10 */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 118 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x1 ),	/* 1 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 126 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	NdrFcShort( 0x4b6 ),	/* Type Offset=1206 */

	/* Return value */


	/* Return value */

/* 132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Prepare */


	/* Procedure Open */

/* 138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0xb ),	/* 11 */
/* 146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 152 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 154 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x1 ),	/* 1 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter strSql */


	/* Parameter strDb */

/* 162 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 166 */	NdrFcShort( 0x4b6 ),	/* Type Offset=1206 */

	/* Return value */


	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Execute */


	/* Procedure OpenMemoryDb */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0xc ),	/* 12 */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 190 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Requery */


	/* Procedure Close */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0xd ),	/* 13 */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 220 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Execute */

/* 234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0xe ),	/* 14 */
/* 242 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 250 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter strSql */

/* 258 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 262 */	NdrFcShort( 0x4b6 ),	/* Type Offset=1206 */

	/* Parameter ppRs */

/* 264 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 268 */	NdrFcShort( 0x4c0 ),	/* Type Offset=1216 */

	/* Return value */

/* 270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExecuteSql */

/* 276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0xf ),	/* 15 */
/* 284 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 290 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 292 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 294 */	NdrFcShort( 0x1 ),	/* 1 */
/* 296 */	NdrFcShort( 0x1 ),	/* 1 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter strSql */

/* 300 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 304 */	NdrFcShort( 0x4b6 ),	/* Type Offset=1206 */

	/* Parameter varParams */

/* 306 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 310 */	NdrFcShort( 0x4e2 ),	/* Type Offset=1250 */

	/* Parameter pVal */

/* 312 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 316 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExecuteSqls */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x10 ),	/* 16 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 340 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x1 ),	/* 1 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter strSql */

/* 348 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	NdrFcShort( 0x4b6 ),	/* Type Offset=1206 */

	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveNext */


	/* Procedure Cancel */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x11 ),	/* 17 */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 376 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RowsAffected */

/* 390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x12 ),	/* 18 */
/* 398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x24 ),	/* 36 */
/* 404 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 406 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 414 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 416 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LastInsertRowID */

/* 426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x13 ),	/* 19 */
/* 434 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 440 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 442 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 444 */	NdrFcShort( 0x1 ),	/* 1 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 450 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 454 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */

/* 456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 458 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ColumnCount */


	/* Procedure get_Progress */

/* 462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x14 ),	/* 20 */
/* 470 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x24 ),	/* 36 */
/* 476 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 478 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 486 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 488 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Progress */

/* 498 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x15 ),	/* 21 */
/* 506 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 510 */	NdrFcShort( 0x8 ),	/* 8 */
/* 512 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 514 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nPeriod */

/* 522 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 524 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginTrans */

/* 534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x16 ),	/* 22 */
/* 542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 548 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 550 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CommitTrans */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x17 ),	/* 23 */
/* 572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 580 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RollbackTrans */

/* 594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x18 ),	/* 24 */
/* 602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 608 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 610 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 620 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ActiveConnection */

/* 624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x7 ),	/* 7 */
/* 632 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 638 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 640 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppConn */

/* 648 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 650 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 652 */	NdrFcShort( 0x4f0 ),	/* Type Offset=1264 */

	/* Return value */

/* 654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ActiveConnection */

/* 660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 668 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 676 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pConn */

/* 684 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 688 */	NdrFcShort( 0x4f4 ),	/* Type Offset=1268 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0xe ),	/* 14 */
/* 704 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 712 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EOF */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0xf ),	/* 15 */
/* 734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x22 ),	/* 34 */
/* 740 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 742 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 750 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 752 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 754 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 758 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveFirst */

/* 762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x10 ),	/* 16 */
/* 770 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 778 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 788 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveLast */

/* 792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x12 ),	/* 18 */
/* 800 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 808 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveStep */

/* 822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0x13 ),	/* 19 */
/* 830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 834 */	NdrFcShort( 0x22 ),	/* 34 */
/* 836 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 838 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nSteps */

/* 846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 848 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 852 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 854 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 856 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ColumnType */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x15 ),	/* 21 */
/* 872 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x24 ),	/* 36 */
/* 878 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 880 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x1 ),	/* 1 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varIndex */

/* 888 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Parameter pVal */

/* 894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 896 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 898 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 902 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ColumnName */

/* 906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x16 ),	/* 22 */
/* 914 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 922 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 924 */	NdrFcShort( 0x1 ),	/* 1 */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lngIndex */

/* 930 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 936 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 938 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 940 */	NdrFcShort( 0x4a8 ),	/* Type Offset=1192 */

	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ColumnValue */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x17 ),	/* 23 */
/* 956 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 962 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 964 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 966 */	NdrFcShort( 0x1 ),	/* 1 */
/* 968 */	NdrFcShort( 0x1 ),	/* 1 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varIndex */

/* 972 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 976 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Parameter eType */

/* 978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 980 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 982 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 984 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 986 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 988 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */

/* 990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 992 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Columns */

/* 996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1004 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1012 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCols */

/* 1020 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1024 */	NdrFcShort( 0x51c ),	/* Type Offset=1308 */

	/* Return value */

/* 1026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Row */

/* 1032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1046 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1048 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1050 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter eMode */

/* 1056 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1058 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1060 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1062 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1066 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */

/* 1068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1070 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RowCount */

/* 1074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1082 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1088 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1090 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1092 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1098 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1102 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */

/* 1104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Rows */

/* 1110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1118 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1120 */	NdrFcShort( 0xe ),	/* 14 */
/* 1122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1124 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1126 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter blnStatic */

/* 1134 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1138 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lngMaxRecords */

/* 1140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppRows */

/* 1146 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1150 */	NdrFcShort( 0x532 ),	/* Type Offset=1330 */

	/* Return value */

/* 1152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1154 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BindParameters */

/* 1158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1166 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1172 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1174 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varParams */

/* 1182 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1184 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1186 */	NdrFcShort( 0x4e2 ),	/* Type Offset=1250 */

	/* Return value */

/* 1188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1190 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BindParameter */

/* 1194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1202 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1208 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1210 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varIndex */

/* 1218 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1222 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Parameter varValue */

/* 1224 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1226 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1228 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Parameter eType */

/* 1230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1232 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1234 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ParameterCount */

/* 1242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1250 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1258 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1266 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ParameterName */

/* 1278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1286 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1294 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1296 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lngIndex */

/* 1302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1308 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	NdrFcShort( 0x4a8 ),	/* Type Offset=1192 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Parameters */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1336 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppParams */

/* 1344 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	NdrFcShort( 0x548 ),	/* Type Offset=1352 */

	/* Return value */

/* 1350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_State */

/* 1356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1364 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1370 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1372 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1380 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1382 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1384 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnBusy */

/* 1392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1400 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1404 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1408 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nTimes */

/* 1416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1422 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1424 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1426 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1430 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnProgress */

/* 1434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1442 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1448 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1450 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1456 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1458 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1460 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1462 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1466 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */


	/* Procedure get__NewEnum */


	/* Procedure get__NewEnum */

/* 1470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1484 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1486 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */


	/* Parameter ppEnum */


	/* Parameter ppEnum */

/* 1494 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1496 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1498 */	NdrFcShort( 0x55e ),	/* Type Offset=1374 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1502 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1514 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1516 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1522 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1524 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lngIndex */

/* 1530 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1532 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter eType */

/* 1536 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1538 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1540 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1542 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1544 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1546 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */

/* 1548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1550 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */


	/* Procedure get_Value */

/* 1554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1562 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1568 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1570 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1572 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1578 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1582 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Return value */


	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0xa ),	/* 10 */
/* 1598 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1606 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1614 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1616 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1622 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1634 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1640 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1642 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lngIndex */

/* 1650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1652 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppRow */

/* 1656 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1658 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1660 */	NdrFcShort( 0x574 ),	/* Type Offset=1396 */

	/* Return value */

/* 1662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1664 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Index */


	/* Procedure get_Index */

/* 1668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1676 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1682 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1684 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1692 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1694 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1700 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_Value */

/* 1704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1718 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1720 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1722 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1728 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1732 */	NdrFcShort( 0x4a8 ),	/* Type Offset=1192 */

	/* Return value */


	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1756 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varIndex */

/* 1764 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Parameter ppCol */

/* 1770 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1772 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1774 */	NdrFcShort( 0x58a ),	/* Type Offset=1418 */

	/* Return value */

/* 1776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1778 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */


	/* Procedure get_Count */

/* 1782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1790 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1796 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1798 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1806 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Bind */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1826 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1834 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 1842 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Parameter eType */

/* 1848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1850 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1852 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1856 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 1860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1868 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1874 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1876 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 1884 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1886 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1888 */	NdrFcShort( 0x5a0 ),	/* Type Offset=1440 */

	/* Return value */

/* 1890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1892 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1896 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1904 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1910 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1912 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varIndex */

/* 1920 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1922 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1924 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Parameter ppParam */

/* 1926 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1928 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1930 */	NdrFcShort( 0x5a4 ),	/* Type Offset=1444 */

	/* Return value */

/* 1932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1934 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Bind */

/* 1938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0xa ),	/* 10 */
/* 1946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1952 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1954 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1958 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varParams */

/* 1962 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1964 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1966 */	NdrFcShort( 0x4e2 ),	/* Type Offset=1250 */

	/* Return value */

/* 1968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const TSqlite_MIDL_TYPE_FORMAT_STRING TSqlite__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x496 ),	/* Offset= 1174 (1178) */
/*  6 */	
			0x13, 0x0,	/* FC_OP */
/*  8 */	NdrFcShort( 0x47e ),	/* Offset= 1150 (1158) */
/* 10 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 12 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 14 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 16 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 18 */	0x0 , 
			0x0,		/* 0 */
/* 20 */	NdrFcLong( 0x0 ),	/* 0 */
/* 24 */	NdrFcLong( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x2 ),	/* Offset= 2 (30) */
/* 30 */	NdrFcShort( 0x10 ),	/* 16 */
/* 32 */	NdrFcShort( 0x2f ),	/* 47 */
/* 34 */	NdrFcLong( 0x14 ),	/* 20 */
/* 38 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 40 */	NdrFcLong( 0x3 ),	/* 3 */
/* 44 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 46 */	NdrFcLong( 0x11 ),	/* 17 */
/* 50 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 52 */	NdrFcLong( 0x2 ),	/* 2 */
/* 56 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 58 */	NdrFcLong( 0x4 ),	/* 4 */
/* 62 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 64 */	NdrFcLong( 0x5 ),	/* 5 */
/* 68 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 70 */	NdrFcLong( 0xb ),	/* 11 */
/* 74 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 76 */	NdrFcLong( 0xa ),	/* 10 */
/* 80 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 82 */	NdrFcLong( 0x6 ),	/* 6 */
/* 86 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (318) */
/* 88 */	NdrFcLong( 0x7 ),	/* 7 */
/* 92 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 94 */	NdrFcLong( 0x8 ),	/* 8 */
/* 98 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (324) */
/* 100 */	NdrFcLong( 0xd ),	/* 13 */
/* 104 */	NdrFcShort( 0x100 ),	/* Offset= 256 (360) */
/* 106 */	NdrFcLong( 0x9 ),	/* 9 */
/* 110 */	NdrFcShort( 0x10c ),	/* Offset= 268 (378) */
/* 112 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 116 */	NdrFcShort( 0x118 ),	/* Offset= 280 (396) */
/* 118 */	NdrFcLong( 0x24 ),	/* 36 */
/* 122 */	NdrFcShort( 0x3c2 ),	/* Offset= 962 (1084) */
/* 124 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 128 */	NdrFcShort( 0x3bc ),	/* Offset= 956 (1084) */
/* 130 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 134 */	NdrFcShort( 0x3ba ),	/* Offset= 954 (1088) */
/* 136 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 140 */	NdrFcShort( 0x3b8 ),	/* Offset= 952 (1092) */
/* 142 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 146 */	NdrFcShort( 0x3b6 ),	/* Offset= 950 (1096) */
/* 148 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 152 */	NdrFcShort( 0x3b4 ),	/* Offset= 948 (1100) */
/* 154 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 158 */	NdrFcShort( 0x3b2 ),	/* Offset= 946 (1104) */
/* 160 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 164 */	NdrFcShort( 0x3b0 ),	/* Offset= 944 (1108) */
/* 166 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 170 */	NdrFcShort( 0x39a ),	/* Offset= 922 (1092) */
/* 172 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 176 */	NdrFcShort( 0x398 ),	/* Offset= 920 (1096) */
/* 178 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 182 */	NdrFcShort( 0x3a2 ),	/* Offset= 930 (1112) */
/* 184 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 188 */	NdrFcShort( 0x398 ),	/* Offset= 920 (1108) */
/* 190 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 194 */	NdrFcShort( 0x39a ),	/* Offset= 922 (1116) */
/* 196 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 200 */	NdrFcShort( 0x398 ),	/* Offset= 920 (1120) */
/* 202 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 206 */	NdrFcShort( 0x396 ),	/* Offset= 918 (1124) */
/* 208 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 212 */	NdrFcShort( 0x394 ),	/* Offset= 916 (1128) */
/* 214 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 218 */	NdrFcShort( 0x392 ),	/* Offset= 914 (1132) */
/* 220 */	NdrFcLong( 0x10 ),	/* 16 */
/* 224 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 226 */	NdrFcLong( 0x12 ),	/* 18 */
/* 230 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 232 */	NdrFcLong( 0x13 ),	/* 19 */
/* 236 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 238 */	NdrFcLong( 0x15 ),	/* 21 */
/* 242 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 244 */	NdrFcLong( 0x16 ),	/* 22 */
/* 248 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 250 */	NdrFcLong( 0x17 ),	/* 23 */
/* 254 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 256 */	NdrFcLong( 0xe ),	/* 14 */
/* 260 */	NdrFcShort( 0x370 ),	/* Offset= 880 (1140) */
/* 262 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 266 */	NdrFcShort( 0x374 ),	/* Offset= 884 (1150) */
/* 268 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 272 */	NdrFcShort( 0x372 ),	/* Offset= 882 (1154) */
/* 274 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 278 */	NdrFcShort( 0x32e ),	/* Offset= 814 (1092) */
/* 280 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 284 */	NdrFcShort( 0x32c ),	/* Offset= 812 (1096) */
/* 286 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 290 */	NdrFcShort( 0x32a ),	/* Offset= 810 (1100) */
/* 292 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 296 */	NdrFcShort( 0x320 ),	/* Offset= 800 (1096) */
/* 298 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 302 */	NdrFcShort( 0x31a ),	/* Offset= 794 (1096) */
/* 304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* Offset= 0 (308) */
/* 310 */	NdrFcLong( 0x1 ),	/* 1 */
/* 314 */	NdrFcShort( 0x0 ),	/* Offset= 0 (314) */
/* 316 */	NdrFcShort( 0xffff ),	/* Offset= -1 (315) */
/* 318 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 322 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 324 */	
			0x13, 0x0,	/* FC_OP */
/* 326 */	NdrFcShort( 0x18 ),	/* Offset= 24 (350) */
/* 328 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 330 */	NdrFcShort( 0x2 ),	/* 2 */
/* 332 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 334 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 336 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 338 */	0x0 , 
			0x0,		/* 0 */
/* 340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 350 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 354 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (328) */
/* 356 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 358 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 360 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 372 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 374 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 376 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 378 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 380 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 390 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 392 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 394 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 396 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 398 */	NdrFcShort( 0x2 ),	/* Offset= 2 (400) */
/* 400 */	
			0x13, 0x0,	/* FC_OP */
/* 402 */	NdrFcShort( 0x298 ),	/* Offset= 664 (1066) */
/* 404 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 406 */	NdrFcShort( 0x18 ),	/* 24 */
/* 408 */	NdrFcShort( 0xa ),	/* 10 */
/* 410 */	NdrFcLong( 0x8 ),	/* 8 */
/* 414 */	NdrFcShort( 0x64 ),	/* Offset= 100 (514) */
/* 416 */	NdrFcLong( 0xd ),	/* 13 */
/* 420 */	NdrFcShort( 0x9c ),	/* Offset= 156 (576) */
/* 422 */	NdrFcLong( 0x9 ),	/* 9 */
/* 426 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (634) */
/* 428 */	NdrFcLong( 0xc ),	/* 12 */
/* 432 */	NdrFcShort( 0x104 ),	/* Offset= 260 (692) */
/* 434 */	NdrFcLong( 0x24 ),	/* 36 */
/* 438 */	NdrFcShort( 0x174 ),	/* Offset= 372 (810) */
/* 440 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 444 */	NdrFcShort( 0x190 ),	/* Offset= 400 (844) */
/* 446 */	NdrFcLong( 0x10 ),	/* 16 */
/* 450 */	NdrFcShort( 0x1b4 ),	/* Offset= 436 (886) */
/* 452 */	NdrFcLong( 0x2 ),	/* 2 */
/* 456 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (928) */
/* 458 */	NdrFcLong( 0x3 ),	/* 3 */
/* 462 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (970) */
/* 464 */	NdrFcLong( 0x14 ),	/* 20 */
/* 468 */	NdrFcShort( 0x220 ),	/* Offset= 544 (1012) */
/* 470 */	NdrFcShort( 0xffff ),	/* Offset= -1 (469) */
/* 472 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 474 */	NdrFcShort( 0x4 ),	/* 4 */
/* 476 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 482 */	0x0 , 
			0x0,		/* 0 */
/* 484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 492 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 494 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 496 */	NdrFcShort( 0x4 ),	/* 4 */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x1 ),	/* 1 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	0x13, 0x0,	/* FC_OP */
/* 508 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (350) */
/* 510 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 512 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 514 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 520 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 522 */	NdrFcShort( 0x4 ),	/* 4 */
/* 524 */	NdrFcShort( 0x4 ),	/* 4 */
/* 526 */	0x11, 0x0,	/* FC_RP */
/* 528 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (472) */
/* 530 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 532 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 534 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 544 */	0x0 , 
			0x0,		/* 0 */
/* 546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 554 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 558 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 560 */	0x0 , 
			0x0,		/* 0 */
/* 562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 572 */	NdrFcShort( 0xff2c ),	/* Offset= -212 (360) */
/* 574 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 576 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x6 ),	/* Offset= 6 (588) */
/* 584 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 586 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 588 */	
			0x11, 0x0,	/* FC_RP */
/* 590 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (534) */
/* 592 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 602 */	0x0 , 
			0x0,		/* 0 */
/* 604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 612 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 616 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 618 */	0x0 , 
			0x0,		/* 0 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 628 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 630 */	NdrFcShort( 0xff04 ),	/* Offset= -252 (378) */
/* 632 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 634 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x6 ),	/* Offset= 6 (646) */
/* 642 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x11, 0x0,	/* FC_RP */
/* 648 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (592) */
/* 650 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 652 */	NdrFcShort( 0x4 ),	/* 4 */
/* 654 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 660 */	0x0 , 
			0x0,		/* 0 */
/* 662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 670 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 672 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 674 */	NdrFcShort( 0x4 ),	/* 4 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x1 ),	/* 1 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	0x13, 0x0,	/* FC_OP */
/* 686 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (1158) */
/* 688 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 690 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 692 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x6 ),	/* Offset= 6 (704) */
/* 700 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 702 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 704 */	
			0x11, 0x0,	/* FC_RP */
/* 706 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (650) */
/* 708 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 710 */	NdrFcLong( 0x2f ),	/* 47 */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 720 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 722 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 724 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 726 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 728 */	NdrFcShort( 0x1 ),	/* 1 */
/* 730 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 732 */	NdrFcShort( 0x4 ),	/* 4 */
/* 734 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 736 */	0x0 , 
			0x0,		/* 0 */
/* 738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 746 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 748 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 750 */	NdrFcShort( 0x10 ),	/* 16 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0xa ),	/* Offset= 10 (764) */
/* 756 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 758 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 760 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (708) */
/* 762 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 764 */	
			0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 766 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (726) */
/* 768 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 770 */	NdrFcShort( 0x4 ),	/* 4 */
/* 772 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 778 */	0x0 , 
			0x0,		/* 0 */
/* 780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 788 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 790 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 792 */	NdrFcShort( 0x4 ),	/* 4 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x1 ),	/* 1 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 802 */	0x13, 0x0,	/* FC_OP */
/* 804 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (748) */
/* 806 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 808 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 810 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x6 ),	/* Offset= 6 (822) */
/* 818 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 820 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 822 */	
			0x11, 0x0,	/* FC_RP */
/* 824 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (768) */
/* 826 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 830 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 832 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 834 */	NdrFcShort( 0x10 ),	/* 16 */
/* 836 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 838 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 840 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (826) */
			0x5b,		/* FC_END */
/* 844 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x18 ),	/* 24 */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0xa ),	/* Offset= 10 (860) */
/* 852 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 854 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 856 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (832) */
/* 858 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 860 */	
			0x11, 0x0,	/* FC_RP */
/* 862 */	NdrFcShort( 0xfeb8 ),	/* Offset= -328 (534) */
/* 864 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 866 */	NdrFcShort( 0x1 ),	/* 1 */
/* 868 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 874 */	0x0 , 
			0x0,		/* 0 */
/* 876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 884 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 886 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 892 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	NdrFcShort( 0x4 ),	/* 4 */
/* 898 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 900 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (864) */
/* 902 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 904 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 906 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 908 */	NdrFcShort( 0x2 ),	/* 2 */
/* 910 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 916 */	0x0 , 
			0x0,		/* 0 */
/* 918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 926 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 928 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 934 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 936 */	NdrFcShort( 0x4 ),	/* 4 */
/* 938 */	NdrFcShort( 0x4 ),	/* 4 */
/* 940 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 942 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (906) */
/* 944 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 946 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 948 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 950 */	NdrFcShort( 0x4 ),	/* 4 */
/* 952 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 958 */	0x0 , 
			0x0,		/* 0 */
/* 960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 968 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 970 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 976 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 978 */	NdrFcShort( 0x4 ),	/* 4 */
/* 980 */	NdrFcShort( 0x4 ),	/* 4 */
/* 982 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 984 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (948) */
/* 986 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 988 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 990 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 994 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1000 */	0x0 , 
			0x0,		/* 0 */
/* 1002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1010 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1012 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1016 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1018 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1020 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1022 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1024 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 1026 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (990) */
/* 1028 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1030 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1032 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1036 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1038 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1040 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1046 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1048 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1050 */	0x0 , 
			0x0,		/* 0 */
/* 1052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1056 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1060 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1062 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1032) */
/* 1064 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1066 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1068 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1070 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1040) */
/* 1072 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1072) */
/* 1074 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1076 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1078 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1080 */	NdrFcShort( 0xfd5c ),	/* Offset= -676 (404) */
/* 1082 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1084 */	
			0x13, 0x0,	/* FC_OP */
/* 1086 */	NdrFcShort( 0xfeae ),	/* Offset= -338 (748) */
/* 1088 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1090 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1092 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1094 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1096 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1098 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1100 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1102 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1104 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1106 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1108 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1110 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1112 */	
			0x13, 0x0,	/* FC_OP */
/* 1114 */	NdrFcShort( 0xfce4 ),	/* Offset= -796 (318) */
/* 1116 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1118 */	NdrFcShort( 0xfce6 ),	/* Offset= -794 (324) */
/* 1120 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1122 */	NdrFcShort( 0xfd06 ),	/* Offset= -762 (360) */
/* 1124 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1126 */	NdrFcShort( 0xfd14 ),	/* Offset= -748 (378) */
/* 1128 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1130 */	NdrFcShort( 0xfd22 ),	/* Offset= -734 (396) */
/* 1132 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1134 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1136) */
/* 1136 */	
			0x13, 0x0,	/* FC_OP */
/* 1138 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1158) */
/* 1140 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1142 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1144 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1146 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1148 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1150 */	
			0x13, 0x0,	/* FC_OP */
/* 1152 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1140) */
/* 1154 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1156 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1158 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1160 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1164) */
/* 1166 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1168 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1170 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1172 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1174 */	NdrFcShort( 0xfb74 ),	/* Offset= -1164 (10) */
/* 1176 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1178 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1186 */	NdrFcShort( 0xfb64 ),	/* Offset= -1180 (6) */
/* 1188 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1190 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1192) */
/* 1192 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1194 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1196 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0xfc94 ),	/* Offset= -876 (324) */
/* 1202 */	
			0x12, 0x0,	/* FC_UP */
/* 1204 */	NdrFcShort( 0xfcaa ),	/* Offset= -854 (350) */
/* 1206 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1208 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1210 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1202) */
/* 1216 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1218 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1220) */
/* 1220 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1222 */	NdrFcLong( 0x3d59cd42 ),	/* 1029295426 */
/* 1226 */	NdrFcShort( 0x97d3 ),	/* -26669 */
/* 1228 */	NdrFcShort( 0x4e1f ),	/* 19999 */
/* 1230 */	0xb4,		/* 180 */
			0xa,		/* 10 */
/* 1232 */	0xaf,		/* 175 */
			0x3d,		/* 61 */
/* 1234 */	0x4a,		/* 74 */
			0x9f,		/* 159 */
/* 1236 */	0x69,		/* 105 */
			0x3,		/* 3 */
/* 1238 */	
			0x11, 0x0,	/* FC_RP */
/* 1240 */	NdrFcShort( 0xa ),	/* Offset= 10 (1250) */
/* 1242 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1244 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1246) */
/* 1246 */	
			0x12, 0x0,	/* FC_UP */
/* 1248 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (1066) */
/* 1250 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1252 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1254 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1242) */
/* 1260 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1262 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1264 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1266 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1268) */
/* 1268 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1270 */	NdrFcLong( 0x2a2b1166 ),	/* 707465574 */
/* 1274 */	NdrFcShort( 0x4d8 ),	/* 1240 */
/* 1276 */	NdrFcShort( 0x4434 ),	/* 17460 */
/* 1278 */	0x94,		/* 148 */
			0x60,		/* 96 */
/* 1280 */	0xc8,		/* 200 */
			0x2a,		/* 42 */
/* 1282 */	0x96,		/* 150 */
			0xb5,		/* 181 */
/* 1284 */	0xa2,		/* 162 */
			0xfa,		/* 250 */
/* 1286 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1288 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1290 */	
			0x12, 0x0,	/* FC_UP */
/* 1292 */	NdrFcShort( 0xff7a ),	/* Offset= -134 (1158) */
/* 1294 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1298 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1290) */
/* 1304 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1306 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 1308 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1310 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1312) */
/* 1312 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1314 */	NdrFcLong( 0x97a223a1 ),	/* -1750981727 */
/* 1318 */	NdrFcShort( 0xaaa8 ),	/* -21848 */
/* 1320 */	NdrFcShort( 0x4ff1 ),	/* 20465 */
/* 1322 */	0xbb,		/* 187 */
			0x2e,		/* 46 */
/* 1324 */	0x71,		/* 113 */
			0xd0,		/* 208 */
/* 1326 */	0x79,		/* 121 */
			0x39,		/* 57 */
/* 1328 */	0x90,		/* 144 */
			0x0,		/* 0 */
/* 1330 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1332 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1334) */
/* 1334 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1336 */	NdrFcLong( 0x7ff1da45 ),	/* 2146556485 */
/* 1340 */	NdrFcShort( 0x467 ),	/* 1127 */
/* 1342 */	NdrFcShort( 0x4774 ),	/* 18292 */
/* 1344 */	0x88,		/* 136 */
			0xa0,		/* 160 */
/* 1346 */	0xbb,		/* 187 */
			0x8c,		/* 140 */
/* 1348 */	0x9f,		/* 159 */
			0xc3,		/* 195 */
/* 1350 */	0xc0,		/* 192 */
			0x74,		/* 116 */
/* 1352 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1354 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1356) */
/* 1356 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1358 */	NdrFcLong( 0xb98d0f82 ),	/* -1181937790 */
/* 1362 */	NdrFcShort( 0x2ba ),	/* 698 */
/* 1364 */	NdrFcShort( 0x4544 ),	/* 17732 */
/* 1366 */	0xa4,		/* 164 */
			0xe9,		/* 233 */
/* 1368 */	0x12,		/* 18 */
			0xb0,		/* 176 */
/* 1370 */	0xb0,		/* 176 */
			0x79,		/* 121 */
/* 1372 */	0xa5,		/* 165 */
			0xf9,		/* 249 */
/* 1374 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1376 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1378) */
/* 1378 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1390 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1392 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1394 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1396 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1398 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1400) */
/* 1400 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1402 */	NdrFcLong( 0x6b38137b ),	/* 1798837115 */
/* 1406 */	NdrFcShort( 0xb7e9 ),	/* -18455 */
/* 1408 */	NdrFcShort( 0x4ff4 ),	/* 20468 */
/* 1410 */	0x84,		/* 132 */
			0xce,		/* 206 */
/* 1412 */	0x83,		/* 131 */
			0x8f,		/* 143 */
/* 1414 */	0x9a,		/* 154 */
			0xcb,		/* 203 */
/* 1416 */	0x67,		/* 103 */
			0xf6,		/* 246 */
/* 1418 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1420 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1422) */
/* 1422 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1424 */	NdrFcLong( 0x8d9b58bb ),	/* -1919199045 */
/* 1428 */	NdrFcShort( 0x2dc2 ),	/* 11714 */
/* 1430 */	NdrFcShort( 0x4e1b ),	/* 19995 */
/* 1432 */	0x99,		/* 153 */
			0x93,		/* 147 */
/* 1434 */	0x85,		/* 133 */
			0x5b,		/* 91 */
/* 1436 */	0x84,		/* 132 */
			0xfd,		/* 253 */
/* 1438 */	0x39,		/* 57 */
			0x50,		/* 80 */
/* 1440 */	0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1442 */	NdrFcShort( 0xfbc6 ),	/* Offset= -1082 (360) */
/* 1444 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1446 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1448) */
/* 1448 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1450 */	NdrFcLong( 0xa5f95a37 ),	/* -1510385097 */
/* 1454 */	NdrFcShort( 0xad6e ),	/* -21138 */
/* 1456 */	NdrFcShort( 0x466f ),	/* 18031 */
/* 1458 */	0xa9,		/* 169 */
			0x23,		/* 35 */
/* 1460 */	0x9a,		/* 154 */
			0x5d,		/* 93 */
/* 1462 */	0xbf,		/* 191 */
			0x96,		/* 150 */
/* 1464 */	0x45,		/* 69 */
			0x95,		/* 149 */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            }

        };



/* Standard interface: __MIDL_itf_TSqlite_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IConnectionObject, ver. 0.0,
   GUID={0x13C4F14F,0x31CA,0x43c2,{0x8E,0x58,0x00,0x2E,0x49,0x82,0xC1,0x47}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IConnection, ver. 0.0,
   GUID={0x2A2B1166,0x04D8,0x4434,{0x94,0x60,0xC8,0x2A,0x96,0xB5,0xA2,0xFA}} */

#pragma code_seg(".orpc")
static const unsigned short IConnection_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    30,
    66,
    102,
    138,
    174,
    204,
    234,
    276,
    324,
    360,
    390,
    426,
    462,
    498,
    534,
    564,
    594
    };

static const MIDL_STUBLESS_PROXY_INFO IConnection_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IConnection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IConnection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IConnection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IConnectionProxyVtbl = 
{
    &IConnection_ProxyInfo,
    &IID_IConnection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IConnection::AboutMe */ ,
    (void *) (INT_PTR) -1 /* IConnection::get_Version */ ,
    (void *) (INT_PTR) -1 /* IConnection::get_Db */ ,
    (void *) (INT_PTR) -1 /* IConnection::put_Db */ ,
    (void *) (INT_PTR) -1 /* IConnection::Open */ ,
    (void *) (INT_PTR) -1 /* IConnection::OpenMemoryDb */ ,
    (void *) (INT_PTR) -1 /* IConnection::Close */ ,
    (void *) (INT_PTR) -1 /* IConnection::Execute */ ,
    (void *) (INT_PTR) -1 /* IConnection::ExecuteSql */ ,
    (void *) (INT_PTR) -1 /* IConnection::ExecuteSqls */ ,
    (void *) (INT_PTR) -1 /* IConnection::Cancel */ ,
    (void *) (INT_PTR) -1 /* IConnection::get_RowsAffected */ ,
    (void *) (INT_PTR) -1 /* IConnection::get_LastInsertRowID */ ,
    (void *) (INT_PTR) -1 /* IConnection::get_Progress */ ,
    (void *) (INT_PTR) -1 /* IConnection::put_Progress */ ,
    (void *) (INT_PTR) -1 /* IConnection::BeginTrans */ ,
    (void *) (INT_PTR) -1 /* IConnection::CommitTrans */ ,
    (void *) (INT_PTR) -1 /* IConnection::RollbackTrans */
};


static const PRPC_STUB_FUNCTION IConnection_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IConnectionStubVtbl =
{
    &IID_IConnection,
    &IConnection_ServerInfo,
    25,
    &IConnection_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IResultset, ver. 0.0,
   GUID={0x3D59CD42,0x97D3,0x4e1f,{0xB4,0x0A,0xAF,0x3D,0x4A,0x9F,0x69,0x03}} */

#pragma code_seg(".orpc")
static const unsigned short IResultset_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    624,
    660,
    66,
    102,
    138,
    174,
    204,
    696,
    726,
    762,
    360,
    792,
    822,
    462,
    864,
    906,
    948,
    996,
    1032,
    1074,
    1110,
    1158,
    1194,
    1242,
    1278,
    1320,
    1356
    };

static const MIDL_STUBLESS_PROXY_INFO IResultset_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IResultset_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IResultset_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IResultset_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(34) _IResultsetProxyVtbl = 
{
    &IResultset_ProxyInfo,
    &IID_IResultset,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_ActiveConnection */ ,
    (void *) (INT_PTR) -1 /* IResultset::put_ActiveConnection */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_SQL */ ,
    (void *) (INT_PTR) -1 /* IResultset::put_SQL */ ,
    (void *) (INT_PTR) -1 /* IResultset::Prepare */ ,
    (void *) (INT_PTR) -1 /* IResultset::Execute */ ,
    (void *) (INT_PTR) -1 /* IResultset::Requery */ ,
    (void *) (INT_PTR) -1 /* IResultset::Close */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_EOF */ ,
    (void *) (INT_PTR) -1 /* IResultset::MoveFirst */ ,
    (void *) (INT_PTR) -1 /* IResultset::MoveNext */ ,
    (void *) (INT_PTR) -1 /* IResultset::MoveLast */ ,
    (void *) (INT_PTR) -1 /* IResultset::MoveStep */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_ColumnCount */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_ColumnType */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_ColumnName */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_ColumnValue */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_Columns */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_Row */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_RowCount */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_Rows */ ,
    (void *) (INT_PTR) -1 /* IResultset::BindParameters */ ,
    (void *) (INT_PTR) -1 /* IResultset::BindParameter */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_ParameterCount */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_ParameterName */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_Parameters */ ,
    (void *) (INT_PTR) -1 /* IResultset::get_State */
};


static const PRPC_STUB_FUNCTION IResultset_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IResultsetStubVtbl =
{
    &IID_IResultset,
    &IResultset_ServerInfo,
    34,
    &IResultset_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IBusy, ver. 0.0,
   GUID={0x45E835B4,0xDB0E,0x429e,{0x95,0x14,0x03,0xAF,0x96,0xF6,0x16,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IBusy_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1392
    };

static const MIDL_STUBLESS_PROXY_INFO IBusy_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IBusy_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBusy_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IBusy_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IBusyProxyVtbl = 
{
    &IBusy_ProxyInfo,
    &IID_IBusy,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IBusy::OnBusy */
};


static const PRPC_STUB_FUNCTION IBusy_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IBusyStubVtbl =
{
    &IID_IBusy,
    &IBusy_ServerInfo,
    8,
    &IBusy_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IProgress, ver. 0.0,
   GUID={0x536DB7B3,0x9C73,0x4675,{0xA3,0x8C,0x7D,0xE0,0x03,0x4D,0x48,0xBC}} */

#pragma code_seg(".orpc")
static const unsigned short IProgress_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1434
    };

static const MIDL_STUBLESS_PROXY_INFO IProgress_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IProgress_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IProgress_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IProgress_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IProgressProxyVtbl = 
{
    &IProgress_ProxyInfo,
    &IID_IProgress,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IProgress::OnProgress */
};


static const PRPC_STUB_FUNCTION IProgress_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IProgressStubVtbl =
{
    &IID_IProgress,
    &IProgress_ServerInfo,
    8,
    &IProgress_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRow, ver. 0.0,
   GUID={0x6B38137B,0xB7E9,0x4ff4,{0x84,0xCE,0x83,0x8F,0x9A,0xCB,0x67,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IRow_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1470,
    1506,
    1554,
    1590
    };

static const MIDL_STUBLESS_PROXY_INFO IRow_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IRow_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRow_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IRow_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IRowProxyVtbl = 
{
    &IRow_ProxyInfo,
    &IID_IRow,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRow::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IRow::get_Item */ ,
    (void *) (INT_PTR) -1 /* IRow::get_Value */ ,
    (void *) (INT_PTR) -1 /* IRow::get_Count */
};


static const PRPC_STUB_FUNCTION IRow_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IRowStubVtbl =
{
    &IID_IRow,
    &IRow_ServerInfo,
    11,
    &IRow_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRows, ver. 0.0,
   GUID={0x7FF1DA45,0x0467,0x4774,{0x88,0xA0,0xBB,0x8C,0x9F,0xC3,0xC0,0x74}} */

#pragma code_seg(".orpc")
static const unsigned short IRows_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1470,
    1626,
    1554
    };

static const MIDL_STUBLESS_PROXY_INFO IRows_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IRows_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRows_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IRows_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IRowsProxyVtbl = 
{
    &IRows_ProxyInfo,
    &IID_IRows,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRows::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IRows::get_Item */ ,
    (void *) (INT_PTR) -1 /* IRows::get_Count */
};


static const PRPC_STUB_FUNCTION IRows_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IRowsStubVtbl =
{
    &IID_IRows,
    &IRows_ServerInfo,
    10,
    &IRows_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IColumn, ver. 0.0,
   GUID={0x8D9B58BB,0x2DC2,0x4e1b,{0x99,0x93,0x85,0x5B,0x84,0xFD,0x39,0x50}} */

#pragma code_seg(".orpc")
static const unsigned short IColumn_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1668,
    1704
    };

static const MIDL_STUBLESS_PROXY_INFO IColumn_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IColumn_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IColumn_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IColumn_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IColumnProxyVtbl = 
{
    &IColumn_ProxyInfo,
    &IID_IColumn,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IColumn::get_Index */ ,
    (void *) (INT_PTR) -1 /* IColumn::get_Value */
};


static const PRPC_STUB_FUNCTION IColumn_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IColumnStubVtbl =
{
    &IID_IColumn,
    &IColumn_ServerInfo,
    9,
    &IColumn_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IColumns, ver. 0.0,
   GUID={0x97A223A1,0xAAA8,0x4ff1,{0xBB,0x2E,0x71,0xD0,0x79,0x39,0x90,0x00}} */

#pragma code_seg(".orpc")
static const unsigned short IColumns_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1470,
    1740,
    1782
    };

static const MIDL_STUBLESS_PROXY_INFO IColumns_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IColumns_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IColumns_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IColumns_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IColumnsProxyVtbl = 
{
    &IColumns_ProxyInfo,
    &IID_IColumns,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IColumns::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IColumns::get_Item */ ,
    (void *) (INT_PTR) -1 /* IColumns::get_Count */
};


static const PRPC_STUB_FUNCTION IColumns_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IColumnsStubVtbl =
{
    &IID_IColumns,
    &IColumns_ServerInfo,
    10,
    &IColumns_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IParameter, ver. 0.0,
   GUID={0xA5F95A37,0xAD6E,0x466f,{0xA9,0x23,0x9A,0x5D,0xBF,0x96,0x45,0x95}} */

#pragma code_seg(".orpc")
static const unsigned short IParameter_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1668,
    1704,
    1818
    };

static const MIDL_STUBLESS_PROXY_INFO IParameter_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IParameter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IParameter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IParameter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IParameterProxyVtbl = 
{
    &IParameter_ProxyInfo,
    &IID_IParameter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IParameter::get_Index */ ,
    (void *) (INT_PTR) -1 /* IParameter::get_Name */ ,
    (void *) (INT_PTR) -1 /* IParameter::Bind */
};


static const PRPC_STUB_FUNCTION IParameter_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IParameterStubVtbl =
{
    &IID_IParameter,
    &IParameter_ServerInfo,
    10,
    &IParameter_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IParameters, ver. 0.0,
   GUID={0xB98D0F82,0x02BA,0x4544,{0xA4,0xE9,0x12,0xB0,0xB0,0x79,0xA5,0xF9}} */

#pragma code_seg(".orpc")
static const unsigned short IParameters_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1860,
    1896,
    1782,
    1938
    };

static const MIDL_STUBLESS_PROXY_INFO IParameters_ProxyInfo =
    {
    &Object_StubDesc,
    TSqlite__MIDL_ProcFormatString.Format,
    &IParameters_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IParameters_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TSqlite__MIDL_ProcFormatString.Format,
    &IParameters_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IParametersProxyVtbl = 
{
    &IParameters_ProxyInfo,
    &IID_IParameters,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IParameters::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IParameters::get_Item */ ,
    (void *) (INT_PTR) -1 /* IParameters::get_Count */ ,
    (void *) (INT_PTR) -1 /* IParameters::Bind */
};


static const PRPC_STUB_FUNCTION IParameters_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IParametersStubVtbl =
{
    &IID_IParameters,
    &IParameters_ServerInfo,
    11,
    &IParameters_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    TSqlite__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _TSqlite_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IParameterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IResultsetProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRowsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IConnectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRowProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IParametersProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IColumnsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IProgressProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBusyProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IColumnProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _TSqlite_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IParameterStubVtbl,
    ( CInterfaceStubVtbl *) &_IResultsetStubVtbl,
    ( CInterfaceStubVtbl *) &_IRowsStubVtbl,
    ( CInterfaceStubVtbl *) &_IConnectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IRowStubVtbl,
    ( CInterfaceStubVtbl *) &_IParametersStubVtbl,
    ( CInterfaceStubVtbl *) &_IColumnsStubVtbl,
    ( CInterfaceStubVtbl *) &_IProgressStubVtbl,
    ( CInterfaceStubVtbl *) &_IBusyStubVtbl,
    ( CInterfaceStubVtbl *) &_IColumnStubVtbl,
    0
};

PCInterfaceName const _TSqlite_InterfaceNamesList[] = 
{
    "IParameter",
    "IResultset",
    "IRows",
    "IConnection",
    "IRow",
    "IParameters",
    "IColumns",
    "IProgress",
    "IBusy",
    "IColumn",
    0
};

const IID *  const _TSqlite_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _TSqlite_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _TSqlite, pIID, n)

int __stdcall _TSqlite_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _TSqlite, 10, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _TSqlite, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _TSqlite, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _TSqlite, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _TSqlite, 10, *pIndex )
    
}

const ExtendedProxyFileInfo TSqlite_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _TSqlite_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _TSqlite_StubVtblList,
    (const PCInterfaceName * ) & _TSqlite_InterfaceNamesList,
    (const IID ** ) & _TSqlite_BaseIIDList,
    & _TSqlite_IID_Lookup, 
    10,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

