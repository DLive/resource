// DocDispatch.h: interface for the CDocDispatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCDISPATCH_H__929A2C92_A835_418C_BB2E_CB1CE7AB5563__INCLUDED_)
#define AFX_DOCDISPATCH_H__929A2C92_A835_418C_BB2E_CB1CE7AB5563__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDocDispatch : public IDispatch  
{
public:
	CDocDispatch();
	virtual ~CDocDispatch();
	long refcount;

// IUnknown
public:
        HRESULT STDMETHODCALLTYPE QueryInterface( 
            REFIID riid,
            void __RPC_FAR *__RPC_FAR *ppvObject);
        
		ULONG STDMETHODCALLTYPE AddRef( void);
        
        ULONG STDMETHODCALLTYPE Release( void);

// IDispatch
public:
        HRESULT STDMETHODCALLTYPE GetTypeInfoCount( 
            UINT __RPC_FAR *pctinfo);
        
        HRESULT STDMETHODCALLTYPE GetTypeInfo( 
            UINT iTInfo,
            LCID lcid,
            ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT STDMETHODCALLTYPE GetIDsOfNames( 
            REFIID riid,
            LPOLESTR __RPC_FAR *rgszNames,
            UINT cNames,
            LCID lcid,
            DISPID __RPC_FAR *rgDispId);
        
        HRESULT STDMETHODCALLTYPE Invoke( 
            DISPID dispIdMember,
            REFIID riid,
            LCID lcid,
            WORD wFlags,
            DISPPARAMS __RPC_FAR *pDispParams,
            VARIANT __RPC_FAR *pVarResult,
            EXCEPINFO __RPC_FAR *pExcepInfo,
            UINT __RPC_FAR *puArgErr);
};

#endif // !defined(AFX_DOCDISPATCH_H__929A2C92_A835_418C_BB2E_CB1CE7AB5563__INCLUDED_)
