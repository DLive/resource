

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sun Jan 01 14:02:47 2012
 */
/* Compiler settings for .\ieextension.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ieextension_i_h__
#define __ieextension_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Idlext_FWD_DEFINED__
#define __Idlext_FWD_DEFINED__
typedef interface Idlext Idlext;
#endif 	/* __Idlext_FWD_DEFINED__ */


#ifndef ___IdlextEvents_FWD_DEFINED__
#define ___IdlextEvents_FWD_DEFINED__
typedef interface _IdlextEvents _IdlextEvents;
#endif 	/* ___IdlextEvents_FWD_DEFINED__ */


#ifndef __dlext_FWD_DEFINED__
#define __dlext_FWD_DEFINED__

#ifdef __cplusplus
typedef class dlext dlext;
#else
typedef struct dlext dlext;
#endif /* __cplusplus */

#endif 	/* __dlext_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __Idlext_INTERFACE_DEFINED__
#define __Idlext_INTERFACE_DEFINED__

/* interface Idlext */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_Idlext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71B47AE4-9577-44D0-A97B-E307DE6352BF")
    Idlext : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IdlextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Idlext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Idlext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Idlext * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Idlext * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Idlext * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Idlext * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Idlext * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IdlextVtbl;

    interface Idlext
    {
        CONST_VTBL struct IdlextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Idlext_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Idlext_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Idlext_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Idlext_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Idlext_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Idlext_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Idlext_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __Idlext_INTERFACE_DEFINED__ */



#ifndef __ieextensionLib_LIBRARY_DEFINED__
#define __ieextensionLib_LIBRARY_DEFINED__

/* library ieextensionLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ieextensionLib;

#ifndef ___IdlextEvents_DISPINTERFACE_DEFINED__
#define ___IdlextEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IdlextEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IdlextEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3D26EA5C-A518-4B38-A02E-E4DA83E33262")
    _IdlextEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IdlextEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IdlextEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IdlextEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IdlextEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IdlextEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IdlextEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IdlextEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IdlextEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IdlextEventsVtbl;

    interface _IdlextEvents
    {
        CONST_VTBL struct _IdlextEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IdlextEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IdlextEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IdlextEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IdlextEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IdlextEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IdlextEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IdlextEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IdlextEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_dlext;

#ifdef __cplusplus

class DECLSPEC_UUID("2742B128-BC1B-4254-BBBB-7E19FFB0F44B")
dlext;
#endif
#endif /* __ieextensionLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


