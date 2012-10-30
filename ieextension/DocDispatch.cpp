// DocDispatch.cpp: implementation of the CDocDispatch class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DocDispatch.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDocDispatch::CDocDispatch(): refcount(1)
{
}

CDocDispatch::~CDocDispatch()
{

}

HRESULT STDMETHODCALLTYPE CDocDispatch::QueryInterface( 
        REFIID riid,
        void __RPC_FAR *__RPC_FAR *ppvObject)
{
	if (riid == IID_IDispatch)
	{
        *ppvObject = (IDispatch *)this;
        AddRef();
    }
    else
      return E_NOINTERFACE;
    return S_OK;
}
        
ULONG STDMETHODCALLTYPE CDocDispatch::AddRef( void)
{
	InterlockedIncrement(&refcount);
    return refcount;
}
        
ULONG STDMETHODCALLTYPE CDocDispatch::Release( void)
{
	InterlockedDecrement(&refcount);
    if (refcount == 0)
      delete this;
    return refcount;
}

HRESULT STDMETHODCALLTYPE CDocDispatch::GetTypeInfoCount( 
            UINT __RPC_FAR *pctinfo)
{
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CDocDispatch::GetTypeInfo( 
            UINT iTInfo,
            LCID lcid,
            ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo)
{
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CDocDispatch::GetIDsOfNames( 
            REFIID riid,
            LPOLESTR __RPC_FAR *rgszNames,
            UINT cNames,
            LCID lcid,
            DISPID __RPC_FAR *rgDispId)
{
	CComBSTR bsName(*rgszNames);
	if (bsName == L"getData")
	{
		*rgDispId = 2000;
		return S_OK;
	}
	return E_NOTIMPL;
}
        
HRESULT STDMETHODCALLTYPE CDocDispatch::Invoke( 
            DISPID dispIdMember,
            REFIID riid,
            LCID lcid,
            WORD wFlags,
            DISPPARAMS __RPC_FAR *pDispParams,
            VARIANT __RPC_FAR *pVarResult,
            EXCEPINFO __RPC_FAR *pExcepInfo,
            UINT __RPC_FAR *puArgErr)
{
	USES_CONVERSION;
	if(dispIdMember = 2000)
	{
		LPSTR lpmsg = OLE2A(pDispParams->rgvarg[0].bstrVal);
		MessageBoxA(NULL,lpmsg,"来自BHO提示",MB_OK);
	}
	return S_OK;
}
