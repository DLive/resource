// DocHandler.cpp: implementation of the CDocHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DocHandler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDocHandler::CDocHandler() : refcount(1)
{
}

CDocHandler::~CDocHandler()
{

}

HRESULT STDMETHODCALLTYPE CDocHandler::QueryInterface( 
        REFIID riid,
        void __RPC_FAR *__RPC_FAR *ppvObject)
{
	if ((riid == IID_IUnknown)||(riid == IID_IDocHostUIHandler)||(riid == IID_IDispatch))
	{
        *ppvObject = this;
        AddRef();
    }
    else
      return E_NOINTERFACE;
    return S_OK;
}
        
ULONG STDMETHODCALLTYPE CDocHandler::AddRef( void)
{
	InterlockedIncrement(&refcount);
    return refcount;
}
        
ULONG STDMETHODCALLTYPE CDocHandler::Release( void)
{
	InterlockedDecrement(&refcount);
    if (refcount == 0)
      delete this;
    return refcount;
}


/////////////////////////////////////////////////////////////////
// IDocHostUIHandler
/////////////////////////////////////////////////////////////////
HRESULT STDMETHODCALLTYPE CDocHandler::ShowContextMenu( 
            DWORD dwID,
            POINT __RPC_FAR *ppt,
            IUnknown __RPC_FAR *pcmdtReserved,
            IDispatch __RPC_FAR *pdispReserved) 
{ 
	return S_FALSE; 
}

HRESULT STDMETHODCALLTYPE CDocHandler::GetHostInfo( 
            DOCHOSTUIINFO __RPC_FAR *pInfo) 
{ 
	return S_OK ; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::ShowUI( 
            DWORD dwID,
            IOleInPlaceActiveObject __RPC_FAR *pActiveObject,
            IOleCommandTarget __RPC_FAR *pCommandTarget,
            IOleInPlaceFrame __RPC_FAR *pFrame,
            IOleInPlaceUIWindow __RPC_FAR *pDoc) 
{ 
	return S_OK ; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::HideUI( void) 
{ 
	return S_OK ; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::UpdateUI( void) 
{ 
	return S_OK ; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::EnableModeless( 
            BOOL fEnable) 
{ 
	return S_OK; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::OnDocWindowActivate( 
            BOOL fActivate) 
{ 
	return S_OK ; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::OnFrameWindowActivate( 
            BOOL fActivate) 
{ 
	return S_OK; 
}

HRESULT STDMETHODCALLTYPE CDocHandler::ResizeBorder( 
            LPCRECT prcBorder,
            IOleInPlaceUIWindow __RPC_FAR *pUIWindow,
            BOOL fRameWindow) 
{ 
	return S_OK; 
}
   
HRESULT STDMETHODCALLTYPE CDocHandler::TranslateAccelerator( 
            LPMSG lpMsg,
            const GUID __RPC_FAR *pguidCmdGroup,
            DWORD nCmdID) 
{ 
	return S_FALSE; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::GetOptionKeyPath( 
            LPOLESTR __RPC_FAR *pchKey,
            DWORD dw) 
{ 
	return S_OK ; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::GetDropTarget( 
            IDropTarget __RPC_FAR *pDropTarget,
            IDropTarget __RPC_FAR *__RPC_FAR *ppDropTarget) 
{ 
	return E_NOTIMPL; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::GetExternal( 
            IDispatch __RPC_FAR *__RPC_FAR *ppDispatch) 
{ 
	*ppDispatch = (IDispatch *)(new CDocDispatch());//(IDispatch *)IDocDispatch;
	return S_OK; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::TranslateUrl( 
            DWORD dwTranslate,
            OLECHAR __RPC_FAR *pchURLIn,
            OLECHAR __RPC_FAR *__RPC_FAR *ppchURLOut) 
{ 
	return S_FALSE; 
}
        
HRESULT STDMETHODCALLTYPE CDocHandler::FilterDataObject( 
            IDataObject __RPC_FAR *pDO,
            IDataObject __RPC_FAR *__RPC_FAR *ppDORet) 
{ 
	return S_FALSE; 
}
