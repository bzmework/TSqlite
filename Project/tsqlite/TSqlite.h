

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __TSqlite_h__
#define __TSqlite_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IConnectionObject_FWD_DEFINED__
#define __IConnectionObject_FWD_DEFINED__
typedef interface IConnectionObject IConnectionObject;

#endif 	/* __IConnectionObject_FWD_DEFINED__ */


#ifndef __IConnection_FWD_DEFINED__
#define __IConnection_FWD_DEFINED__
typedef interface IConnection IConnection;

#endif 	/* __IConnection_FWD_DEFINED__ */


#ifndef __IResultset_FWD_DEFINED__
#define __IResultset_FWD_DEFINED__
typedef interface IResultset IResultset;

#endif 	/* __IResultset_FWD_DEFINED__ */


#ifndef __IBusy_FWD_DEFINED__
#define __IBusy_FWD_DEFINED__
typedef interface IBusy IBusy;

#endif 	/* __IBusy_FWD_DEFINED__ */


#ifndef __IProgress_FWD_DEFINED__
#define __IProgress_FWD_DEFINED__
typedef interface IProgress IProgress;

#endif 	/* __IProgress_FWD_DEFINED__ */


#ifndef __IRow_FWD_DEFINED__
#define __IRow_FWD_DEFINED__
typedef interface IRow IRow;

#endif 	/* __IRow_FWD_DEFINED__ */


#ifndef __IRows_FWD_DEFINED__
#define __IRows_FWD_DEFINED__
typedef interface IRows IRows;

#endif 	/* __IRows_FWD_DEFINED__ */


#ifndef __IColumn_FWD_DEFINED__
#define __IColumn_FWD_DEFINED__
typedef interface IColumn IColumn;

#endif 	/* __IColumn_FWD_DEFINED__ */


#ifndef __IColumns_FWD_DEFINED__
#define __IColumns_FWD_DEFINED__
typedef interface IColumns IColumns;

#endif 	/* __IColumns_FWD_DEFINED__ */


#ifndef __IParameter_FWD_DEFINED__
#define __IParameter_FWD_DEFINED__
typedef interface IParameter IParameter;

#endif 	/* __IParameter_FWD_DEFINED__ */


#ifndef __IParameters_FWD_DEFINED__
#define __IParameters_FWD_DEFINED__
typedef interface IParameters IParameters;

#endif 	/* __IParameters_FWD_DEFINED__ */


#ifndef __Connection_FWD_DEFINED__
#define __Connection_FWD_DEFINED__

#ifdef __cplusplus
typedef class Connection Connection;
#else
typedef struct Connection Connection;
#endif /* __cplusplus */

#endif 	/* __Connection_FWD_DEFINED__ */


#ifndef __Resultset_FWD_DEFINED__
#define __Resultset_FWD_DEFINED__

#ifdef __cplusplus
typedef class Resultset Resultset;
#else
typedef struct Resultset Resultset;
#endif /* __cplusplus */

#endif 	/* __Resultset_FWD_DEFINED__ */


#ifndef __Row_FWD_DEFINED__
#define __Row_FWD_DEFINED__

#ifdef __cplusplus
typedef class Row Row;
#else
typedef struct Row Row;
#endif /* __cplusplus */

#endif 	/* __Row_FWD_DEFINED__ */


#ifndef __Rows_FWD_DEFINED__
#define __Rows_FWD_DEFINED__

#ifdef __cplusplus
typedef class Rows Rows;
#else
typedef struct Rows Rows;
#endif /* __cplusplus */

#endif 	/* __Rows_FWD_DEFINED__ */


#ifndef __Column_FWD_DEFINED__
#define __Column_FWD_DEFINED__

#ifdef __cplusplus
typedef class Column Column;
#else
typedef struct Column Column;
#endif /* __cplusplus */

#endif 	/* __Column_FWD_DEFINED__ */


#ifndef __Columns_FWD_DEFINED__
#define __Columns_FWD_DEFINED__

#ifdef __cplusplus
typedef class Columns Columns;
#else
typedef struct Columns Columns;
#endif /* __cplusplus */

#endif 	/* __Columns_FWD_DEFINED__ */


#ifndef __Parameter_FWD_DEFINED__
#define __Parameter_FWD_DEFINED__

#ifdef __cplusplus
typedef class Parameter Parameter;
#else
typedef struct Parameter Parameter;
#endif /* __cplusplus */

#endif 	/* __Parameter_FWD_DEFINED__ */


#ifndef __Parameters_FWD_DEFINED__
#define __Parameters_FWD_DEFINED__

#ifdef __cplusplus
typedef class Parameters Parameters;
#else
typedef struct Parameters Parameters;
#endif /* __cplusplus */

#endif 	/* __Parameters_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_TSqlite_0000_0000 */
/* [local] */ 

typedef /* [helpstring][v1_enum] */ 
enum DataTypeConstants
    {
        dtUnknown	= -1,
        dtNull	= 0,
        dtInteger	= 1,
        dtLong	= 2,
        dtFloat	= 3,
        dtString	= 4,
        dtBinary	= 5,
        dtDate	= 6
    } 	DataTypeConstants;

typedef /* [helpstring][v1_enum] */ 
enum ObjectStateConstants
    {
        osClosed	= 0,
        osPrepared	= 1,
        osExecuted	= 2
    } 	ObjectStateConstants;

typedef /* [helpstring][v1_enum] */ 
enum RowTypeConstants
    {
        rtDefault	= 0,
        rtArray	= 1,
        rtCollection	= 2
    } 	RowTypeConstants;











extern RPC_IF_HANDLE __MIDL_itf_TSqlite_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_TSqlite_0000_0000_v0_0_s_ifspec;

#ifndef __IConnectionObject_INTERFACE_DEFINED__
#define __IConnectionObject_INTERFACE_DEFINED__

/* interface IConnectionObject */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConnectionObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13C4F14F-31CA-43c2-8E58-002E4982C147")
    IConnectionObject : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentDB( 
            /* [retval][out] */ void **ppDB) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IConnectionObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConnectionObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConnectionObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConnectionObject * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentDB )( 
            IConnectionObject * This,
            /* [retval][out] */ void **ppDB);
        
        END_INTERFACE
    } IConnectionObjectVtbl;

    interface IConnectionObject
    {
        CONST_VTBL struct IConnectionObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConnectionObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConnectionObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConnectionObject_GetCurrentDB(This,ppDB)	\
    ( (This)->lpVtbl -> GetCurrentDB(This,ppDB) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConnectionObject_INTERFACE_DEFINED__ */


#ifndef __IConnection_INTERFACE_DEFINED__
#define __IConnection_INTERFACE_DEFINED__

/* interface IConnection */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A2B1166-04D8-4434-9460-C82A96B5A2FA")
    IConnection : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AboutMe( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Db( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Db( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [defaultvalue][in] */ BSTR strDb = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenMemoryDb( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ BSTR strSql,
            /* [retval][out] */ IResultset **ppRs) = 0;
        
        virtual /* [helpstring][vararg][id] */ HRESULT STDMETHODCALLTYPE ExecuteSql( 
            /* [in] */ BSTR strSql,
            /* [in] */ SAFEARRAY * *varParams,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteSqls( 
            /* [in] */ BSTR strSql) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RowsAffected( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastInsertRowID( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Progress( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Progress( 
            /* [in] */ LONG nPeriod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginTrans( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CommitTrans( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RollbackTrans( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConnection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IConnection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IConnection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IConnection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IConnection * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AboutMe )( 
            IConnection * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IConnection * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Db )( 
            IConnection * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Db )( 
            IConnection * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IConnection * This,
            /* [defaultvalue][in] */ BSTR strDb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenMemoryDb )( 
            IConnection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IConnection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IConnection * This,
            /* [in] */ BSTR strSql,
            /* [retval][out] */ IResultset **ppRs);
        
        /* [helpstring][vararg][id] */ HRESULT ( STDMETHODCALLTYPE *ExecuteSql )( 
            IConnection * This,
            /* [in] */ BSTR strSql,
            /* [in] */ SAFEARRAY * *varParams,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExecuteSqls )( 
            IConnection * This,
            /* [in] */ BSTR strSql);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IConnection * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowsAffected )( 
            IConnection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastInsertRowID )( 
            IConnection * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Progress )( 
            IConnection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Progress )( 
            IConnection * This,
            /* [in] */ LONG nPeriod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginTrans )( 
            IConnection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitTrans )( 
            IConnection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RollbackTrans )( 
            IConnection * This);
        
        END_INTERFACE
    } IConnectionVtbl;

    interface IConnection
    {
        CONST_VTBL struct IConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConnection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IConnection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IConnection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IConnection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IConnection_AboutMe(This)	\
    ( (This)->lpVtbl -> AboutMe(This) ) 

#define IConnection_get_Version(This,pVal)	\
    ( (This)->lpVtbl -> get_Version(This,pVal) ) 

#define IConnection_get_Db(This,pVal)	\
    ( (This)->lpVtbl -> get_Db(This,pVal) ) 

#define IConnection_put_Db(This,newVal)	\
    ( (This)->lpVtbl -> put_Db(This,newVal) ) 

#define IConnection_Open(This,strDb)	\
    ( (This)->lpVtbl -> Open(This,strDb) ) 

#define IConnection_OpenMemoryDb(This)	\
    ( (This)->lpVtbl -> OpenMemoryDb(This) ) 

#define IConnection_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IConnection_Execute(This,strSql,ppRs)	\
    ( (This)->lpVtbl -> Execute(This,strSql,ppRs) ) 

#define IConnection_ExecuteSql(This,strSql,varParams,pVal)	\
    ( (This)->lpVtbl -> ExecuteSql(This,strSql,varParams,pVal) ) 

#define IConnection_ExecuteSqls(This,strSql)	\
    ( (This)->lpVtbl -> ExecuteSqls(This,strSql) ) 

#define IConnection_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IConnection_get_RowsAffected(This,pVal)	\
    ( (This)->lpVtbl -> get_RowsAffected(This,pVal) ) 

#define IConnection_get_LastInsertRowID(This,pVal)	\
    ( (This)->lpVtbl -> get_LastInsertRowID(This,pVal) ) 

#define IConnection_get_Progress(This,pVal)	\
    ( (This)->lpVtbl -> get_Progress(This,pVal) ) 

#define IConnection_put_Progress(This,nPeriod)	\
    ( (This)->lpVtbl -> put_Progress(This,nPeriod) ) 

#define IConnection_BeginTrans(This)	\
    ( (This)->lpVtbl -> BeginTrans(This) ) 

#define IConnection_CommitTrans(This)	\
    ( (This)->lpVtbl -> CommitTrans(This) ) 

#define IConnection_RollbackTrans(This)	\
    ( (This)->lpVtbl -> RollbackTrans(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConnection_INTERFACE_DEFINED__ */


#ifndef __IResultset_INTERFACE_DEFINED__
#define __IResultset_INTERFACE_DEFINED__

/* interface IResultset */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IResultset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3D59CD42-97D3-4e1f-B40A-AF3D4A9F6903")
    IResultset : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveConnection( 
            /* [retval][out] */ IConnection **ppConn) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActiveConnection( 
            /* [in] */ IConnection *pConn) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SQL( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SQL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Prepare( 
            /* [defaultvalue][in] */ BSTR strSql = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Requery( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EOF( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveFirst( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveNext( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveLast( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveStep( 
            /* [defaultvalue][in] */ LONG nSteps,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnCount( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnType( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ DataTypeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnName( 
            /* [in] */ LONG lngIndex,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnValue( 
            /* [in] */ VARIANT varIndex,
            /* [defaultvalue][in] */ DataTypeConstants eType,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Columns( 
            /* [retval][out] */ IColumns **ppCols) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Row( 
            /* [defaultvalue][in] */ RowTypeConstants eMode,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RowCount( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rows( 
            /* [defaultvalue][in] */ VARIANT_BOOL blnStatic,
            /* [defaultvalue][in] */ LONG lngMaxRecords,
            /* [retval][out] */ IRows **ppRows) = 0;
        
        virtual /* [helpstring][vararg][id] */ HRESULT STDMETHODCALLTYPE BindParameters( 
            /* [in] */ SAFEARRAY * *varParams) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BindParameter( 
            /* [in] */ VARIANT varIndex,
            /* [optional][in] */ VARIANT varValue,
            /* [defaultvalue][in] */ DataTypeConstants eType = dtUnknown) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParameterCount( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParameterName( 
            /* [in] */ LONG lngIndex,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parameters( 
            /* [retval][out] */ IParameters **ppParams) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ ObjectStateConstants *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IResultsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IResultset * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IResultset * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IResultset * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IResultset * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IResultset * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IResultset * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IResultset * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveConnection )( 
            IResultset * This,
            /* [retval][out] */ IConnection **ppConn);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveConnection )( 
            IResultset * This,
            /* [in] */ IConnection *pConn);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SQL )( 
            IResultset * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SQL )( 
            IResultset * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Prepare )( 
            IResultset * This,
            /* [defaultvalue][in] */ BSTR strSql);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IResultset * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Requery )( 
            IResultset * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IResultset * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EOF )( 
            IResultset * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveFirst )( 
            IResultset * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveNext )( 
            IResultset * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveLast )( 
            IResultset * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveStep )( 
            IResultset * This,
            /* [defaultvalue][in] */ LONG nSteps,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnCount )( 
            IResultset * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnType )( 
            IResultset * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ DataTypeConstants *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnName )( 
            IResultset * This,
            /* [in] */ LONG lngIndex,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnValue )( 
            IResultset * This,
            /* [in] */ VARIANT varIndex,
            /* [defaultvalue][in] */ DataTypeConstants eType,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Columns )( 
            IResultset * This,
            /* [retval][out] */ IColumns **ppCols);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Row )( 
            IResultset * This,
            /* [defaultvalue][in] */ RowTypeConstants eMode,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowCount )( 
            IResultset * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rows )( 
            IResultset * This,
            /* [defaultvalue][in] */ VARIANT_BOOL blnStatic,
            /* [defaultvalue][in] */ LONG lngMaxRecords,
            /* [retval][out] */ IRows **ppRows);
        
        /* [helpstring][vararg][id] */ HRESULT ( STDMETHODCALLTYPE *BindParameters )( 
            IResultset * This,
            /* [in] */ SAFEARRAY * *varParams);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BindParameter )( 
            IResultset * This,
            /* [in] */ VARIANT varIndex,
            /* [optional][in] */ VARIANT varValue,
            /* [defaultvalue][in] */ DataTypeConstants eType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParameterCount )( 
            IResultset * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParameterName )( 
            IResultset * This,
            /* [in] */ LONG lngIndex,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            IResultset * This,
            /* [retval][out] */ IParameters **ppParams);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IResultset * This,
            /* [retval][out] */ ObjectStateConstants *pVal);
        
        END_INTERFACE
    } IResultsetVtbl;

    interface IResultset
    {
        CONST_VTBL struct IResultsetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IResultset_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IResultset_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IResultset_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IResultset_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IResultset_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IResultset_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IResultset_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IResultset_get_ActiveConnection(This,ppConn)	\
    ( (This)->lpVtbl -> get_ActiveConnection(This,ppConn) ) 

#define IResultset_put_ActiveConnection(This,pConn)	\
    ( (This)->lpVtbl -> put_ActiveConnection(This,pConn) ) 

#define IResultset_get_SQL(This,pVal)	\
    ( (This)->lpVtbl -> get_SQL(This,pVal) ) 

#define IResultset_put_SQL(This,newVal)	\
    ( (This)->lpVtbl -> put_SQL(This,newVal) ) 

#define IResultset_Prepare(This,strSql)	\
    ( (This)->lpVtbl -> Prepare(This,strSql) ) 

#define IResultset_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#define IResultset_Requery(This)	\
    ( (This)->lpVtbl -> Requery(This) ) 

#define IResultset_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IResultset_get_EOF(This,pVal)	\
    ( (This)->lpVtbl -> get_EOF(This,pVal) ) 

#define IResultset_MoveFirst(This)	\
    ( (This)->lpVtbl -> MoveFirst(This) ) 

#define IResultset_MoveNext(This)	\
    ( (This)->lpVtbl -> MoveNext(This) ) 

#define IResultset_MoveLast(This)	\
    ( (This)->lpVtbl -> MoveLast(This) ) 

#define IResultset_MoveStep(This,nSteps,pVal)	\
    ( (This)->lpVtbl -> MoveStep(This,nSteps,pVal) ) 

#define IResultset_get_ColumnCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ColumnCount(This,pVal) ) 

#define IResultset_get_ColumnType(This,varIndex,pVal)	\
    ( (This)->lpVtbl -> get_ColumnType(This,varIndex,pVal) ) 

#define IResultset_get_ColumnName(This,lngIndex,pVal)	\
    ( (This)->lpVtbl -> get_ColumnName(This,lngIndex,pVal) ) 

#define IResultset_get_ColumnValue(This,varIndex,eType,pVal)	\
    ( (This)->lpVtbl -> get_ColumnValue(This,varIndex,eType,pVal) ) 

#define IResultset_get_Columns(This,ppCols)	\
    ( (This)->lpVtbl -> get_Columns(This,ppCols) ) 

#define IResultset_get_Row(This,eMode,pVal)	\
    ( (This)->lpVtbl -> get_Row(This,eMode,pVal) ) 

#define IResultset_get_RowCount(This,pVal)	\
    ( (This)->lpVtbl -> get_RowCount(This,pVal) ) 

#define IResultset_get_Rows(This,blnStatic,lngMaxRecords,ppRows)	\
    ( (This)->lpVtbl -> get_Rows(This,blnStatic,lngMaxRecords,ppRows) ) 

#define IResultset_BindParameters(This,varParams)	\
    ( (This)->lpVtbl -> BindParameters(This,varParams) ) 

#define IResultset_BindParameter(This,varIndex,varValue,eType)	\
    ( (This)->lpVtbl -> BindParameter(This,varIndex,varValue,eType) ) 

#define IResultset_get_ParameterCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ParameterCount(This,pVal) ) 

#define IResultset_get_ParameterName(This,lngIndex,pVal)	\
    ( (This)->lpVtbl -> get_ParameterName(This,lngIndex,pVal) ) 

#define IResultset_get_Parameters(This,ppParams)	\
    ( (This)->lpVtbl -> get_Parameters(This,ppParams) ) 

#define IResultset_get_State(This,pVal)	\
    ( (This)->lpVtbl -> get_State(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IResultset_INTERFACE_DEFINED__ */


#ifndef __IBusy_INTERFACE_DEFINED__
#define __IBusy_INTERFACE_DEFINED__

/* interface IBusy */
/* [helpstring][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IBusy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("45E835B4-DB0E-429e-9514-03AF96F61694")
    IBusy : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnBusy( 
            /* [in] */ LONG nTimes,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBusyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBusy * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBusy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBusy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBusy * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBusy * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBusy * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBusy * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnBusy )( 
            IBusy * This,
            /* [in] */ LONG nTimes,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IBusyVtbl;

    interface IBusy
    {
        CONST_VTBL struct IBusyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBusy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBusy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBusy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBusy_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBusy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBusy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBusy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBusy_OnBusy(This,nTimes,pVal)	\
    ( (This)->lpVtbl -> OnBusy(This,nTimes,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBusy_INTERFACE_DEFINED__ */


#ifndef __IProgress_INTERFACE_DEFINED__
#define __IProgress_INTERFACE_DEFINED__

/* interface IProgress */
/* [helpstring][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("536DB7B3-9C73-4675-A38C-7DE0034D48BC")
    IProgress : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnProgress( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProgress * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProgress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProgress * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProgress * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProgress * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProgress * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProgress * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnProgress )( 
            IProgress * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IProgressVtbl;

    interface IProgress
    {
        CONST_VTBL struct IProgressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProgress_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProgress_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProgress_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProgress_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IProgress_OnProgress(This,pVal)	\
    ( (This)->lpVtbl -> OnProgress(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProgress_INTERFACE_DEFINED__ */


#ifndef __IRow_INTERFACE_DEFINED__
#define __IRow_INTERFACE_DEFINED__

/* interface IRow */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6B38137B-B7E9-4ff4-84CE-838F9ACB67F6")
    IRow : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG lngIndex,
            /* [defaultvalue][in] */ DataTypeConstants eType,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRow * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRow * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRow * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRow * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRow * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRow * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IRow * This,
            /* [retval][out] */ IUnknown **ppEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IRow * This,
            /* [in] */ LONG lngIndex,
            /* [defaultvalue][in] */ DataTypeConstants eType,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IRow * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IRow * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IRowVtbl;

    interface IRow
    {
        CONST_VTBL struct IRowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRow_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRow_get__NewEnum(This,ppEnum)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnum) ) 

#define IRow_get_Item(This,lngIndex,eType,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,lngIndex,eType,pVal) ) 

#define IRow_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IRow_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRow_INTERFACE_DEFINED__ */


#ifndef __IRows_INTERFACE_DEFINED__
#define __IRows_INTERFACE_DEFINED__

/* interface IRows */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRows;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7FF1DA45-0467-4774-88A0-BB8C9FC3C074")
    IRows : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [defaultvalue][in] */ LONG lngIndex,
            /* [retval][out] */ IRow **ppRow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRowsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRows * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRows * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRows * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRows * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRows * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRows * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRows * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IRows * This,
            /* [retval][out] */ IUnknown **ppEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IRows * This,
            /* [defaultvalue][in] */ LONG lngIndex,
            /* [retval][out] */ IRow **ppRow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IRows * This,
            /* [retval][out] */ VARIANT *pVal);
        
        END_INTERFACE
    } IRowsVtbl;

    interface IRows
    {
        CONST_VTBL struct IRowsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRows_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRows_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRows_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRows_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRows_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRows_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRows_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRows_get__NewEnum(This,ppEnum)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnum) ) 

#define IRows_get_Item(This,lngIndex,ppRow)	\
    ( (This)->lpVtbl -> get_Item(This,lngIndex,ppRow) ) 

#define IRows_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRows_INTERFACE_DEFINED__ */


#ifndef __IColumn_INTERFACE_DEFINED__
#define __IColumn_INTERFACE_DEFINED__

/* interface IColumn */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IColumn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8D9B58BB-2DC2-4e1b-9993-855B84FD3950")
    IColumn : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IColumnVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IColumn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IColumn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IColumn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IColumn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IColumn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IColumn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IColumn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IColumn * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IColumn * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IColumnVtbl;

    interface IColumn
    {
        CONST_VTBL struct IColumnVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IColumn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IColumn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IColumn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IColumn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IColumn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IColumn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IColumn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IColumn_get_Index(This,pVal)	\
    ( (This)->lpVtbl -> get_Index(This,pVal) ) 

#define IColumn_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IColumn_INTERFACE_DEFINED__ */


#ifndef __IColumns_INTERFACE_DEFINED__
#define __IColumns_INTERFACE_DEFINED__

/* interface IColumns */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IColumns;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("97A223A1-AAA8-4ff1-BB2E-71D079399000")
    IColumns : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ IColumn **ppCol) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IColumnsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IColumns * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IColumns * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IColumns * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IColumns * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IColumns * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IColumns * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IColumns * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IColumns * This,
            /* [retval][out] */ IUnknown **ppEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IColumns * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ IColumn **ppCol);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IColumns * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IColumnsVtbl;

    interface IColumns
    {
        CONST_VTBL struct IColumnsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IColumns_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IColumns_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IColumns_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IColumns_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IColumns_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IColumns_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IColumns_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IColumns_get__NewEnum(This,ppEnum)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnum) ) 

#define IColumns_get_Item(This,varIndex,ppCol)	\
    ( (This)->lpVtbl -> get_Item(This,varIndex,ppCol) ) 

#define IColumns_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IColumns_INTERFACE_DEFINED__ */


#ifndef __IParameter_INTERFACE_DEFINED__
#define __IParameter_INTERFACE_DEFINED__

/* interface IParameter */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IParameter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A5F95A37-AD6E-466f-A923-9A5DBF964595")
    IParameter : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Bind( 
            /* [optional][in] */ VARIANT varValue,
            /* [defaultvalue][in] */ DataTypeConstants eType = dtUnknown) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IParameterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParameter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParameter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParameter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IParameter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IParameter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IParameter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IParameter * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IParameter * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IParameter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Bind )( 
            IParameter * This,
            /* [optional][in] */ VARIANT varValue,
            /* [defaultvalue][in] */ DataTypeConstants eType);
        
        END_INTERFACE
    } IParameterVtbl;

    interface IParameter
    {
        CONST_VTBL struct IParameterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParameter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParameter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParameter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParameter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IParameter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IParameter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IParameter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IParameter_get_Index(This,pVal)	\
    ( (This)->lpVtbl -> get_Index(This,pVal) ) 

#define IParameter_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IParameter_Bind(This,varValue,eType)	\
    ( (This)->lpVtbl -> Bind(This,varValue,eType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParameter_INTERFACE_DEFINED__ */


#ifndef __IParameters_INTERFACE_DEFINED__
#define __IParameters_INTERFACE_DEFINED__

/* interface IParameters */
/* [unique][nonextensible][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IParameters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B98D0F82-02BA-4544-A4E9-12B0B079A5F9")
    IParameters : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ IParameter **ppParam) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Bind( 
            /* [in] */ SAFEARRAY * *varParams) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParameters * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParameters * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParameters * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IParameters * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IParameters * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IParameters * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IParameters * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IParameters * This,
            /* [retval][out] */ IUnknown **ppEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IParameters * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ IParameter **ppParam);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IParameters * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Bind )( 
            IParameters * This,
            /* [in] */ SAFEARRAY * *varParams);
        
        END_INTERFACE
    } IParametersVtbl;

    interface IParameters
    {
        CONST_VTBL struct IParametersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParameters_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParameters_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParameters_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParameters_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IParameters_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IParameters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IParameters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IParameters_get__NewEnum(This,ppEnum)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnum) ) 

#define IParameters_get_Item(This,varIndex,ppParam)	\
    ( (This)->lpVtbl -> get_Item(This,varIndex,ppParam) ) 

#define IParameters_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IParameters_Bind(This,varParams)	\
    ( (This)->lpVtbl -> Bind(This,varParams) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParameters_INTERFACE_DEFINED__ */



#ifndef __TSqlite_LIBRARY_DEFINED__
#define __TSqlite_LIBRARY_DEFINED__

/* library TSqlite */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TSqlite;

EXTERN_C const CLSID CLSID_Connection;

#ifdef __cplusplus

class DECLSPEC_UUID("3B8B28CC-8ABD-49dc-AE66-B7BBABD4C0A1")
Connection;
#endif

EXTERN_C const CLSID CLSID_Resultset;

#ifdef __cplusplus

class DECLSPEC_UUID("489F9B06-E245-4124-9EC6-25C479959B15")
Resultset;
#endif

EXTERN_C const CLSID CLSID_Row;

#ifdef __cplusplus

class DECLSPEC_UUID("5C1FFF03-C6BF-43fd-9E1F-18566B6D4F12")
Row;
#endif

EXTERN_C const CLSID CLSID_Rows;

#ifdef __cplusplus

class DECLSPEC_UUID("663A9DF0-AA24-41d6-A1DC-5B0EBFE5D8F7")
Rows;
#endif

EXTERN_C const CLSID CLSID_Column;

#ifdef __cplusplus

class DECLSPEC_UUID("76DA4BEA-89BB-407e-85B8-DFA4642D3834")
Column;
#endif

EXTERN_C const CLSID CLSID_Columns;

#ifdef __cplusplus

class DECLSPEC_UUID("8A311715-C11C-4fd0-BE71-BDD9882BE1F3")
Columns;
#endif

EXTERN_C const CLSID CLSID_Parameter;

#ifdef __cplusplus

class DECLSPEC_UUID("9BF4CE7E-6A89-470d-8411-6330DCE54B0B")
Parameter;
#endif

EXTERN_C const CLSID CLSID_Parameters;

#ifdef __cplusplus

class DECLSPEC_UUID("10E7AB56-718E-458f-989F-26D73701A6A6")
Parameters;
#endif
#endif /* __TSqlite_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


