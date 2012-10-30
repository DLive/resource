// DocHandler.h: interface for the CDocHandler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCHANDLER_H__722BB2A9_020D_45E1_9054_6AE4453E271D__INCLUDED_)
#define AFX_DOCHANDLER_H__722BB2A9_020D_45E1_9054_6AE4453E271D__INCLUDED_
#include <mshtmhst.h>         // DOM interfaces
#include "DocDispatch.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDocHandler : 
	public IDocHostUIHandler
{
public:
	CDocHandler();
	virtual ~CDocHandler();
	long refcount;

// IUnknown
public:
        HRESULT STDMETHODCALLTYPE QueryInterface( 
             REFIID riid,
             void __RPC_FAR *__RPC_FAR *ppvObject);
        
		ULONG STDMETHODCALLTYPE AddRef( void);
        
        ULONG STDMETHODCALLTYPE Release( void);

// IDocHostUIHandler
public:
        HRESULT STDMETHODCALLTYPE ShowContextMenu( 
            DWORD dwID,
            POINT __RPC_FAR *ppt,
            IUnknown __RPC_FAR *pcmdtReserved,
            IDispatch __RPC_FAR *pdispReserved);
        
        HRESULT STDMETHODCALLTYPE GetHostInfo( 
            DOCHOSTUIINFO __RPC_FAR *pInfo);
        
        HRESULT STDMETHODCALLTYPE ShowUI( 
            DWORD dwID,
            IOleInPlaceActiveObject __RPC_FAR *pActiveObject,
            IOleCommandTarget __RPC_FAR *pCommandTarget,
            IOleInPlaceFrame __RPC_FAR *pFrame,
            IOleInPlaceUIWindow __RPC_FAR *pDoc);
        
        HRESULT STDMETHODCALLTYPE HideUI( void);
        
        HRESULT STDMETHODCALLTYPE UpdateUI( void);
        
        HRESULT STDMETHODCALLTYPE EnableModeless( 
            BOOL fEnable);
        
        HRESULT STDMETHODCALLTYPE OnDocWindowActivate( 
            BOOL fActivate);
        
        HRESULT STDMETHODCALLTYPE OnFrameWindowActivate( 
            BOOL fActivate);
        
        HRESULT STDMETHODCALLTYPE ResizeBorder( 
            LPCRECT prcBorder,
            IOleInPlaceUIWindow __RPC_FAR *pUIWindow,
            BOOL fRameWindow);
        
        HRESULT STDMETHODCALLTYPE TranslateAccelerator( 
            LPMSG lpMsg,
            const GUID __RPC_FAR *pguidCmdGroup,
            DWORD nCmdID);
        
        HRESULT STDMETHODCALLTYPE GetOptionKeyPath( 
            LPOLESTR __RPC_FAR *pchKey,
            DWORD dw);
        
        HRESULT STDMETHODCALLTYPE GetDropTarget( 
            IDropTarget __RPC_FAR *pDropTarget,
            IDropTarget __RPC_FAR *__RPC_FAR *ppDropTarget);
        
        HRESULT STDMETHODCALLTYPE GetExternal( 
            IDispatch __RPC_FAR *__RPC_FAR *ppDispatch);
        
        HRESULT STDMETHODCALLTYPE TranslateUrl( 
            DWORD dwTranslate,
            OLECHAR __RPC_FAR *pchURLIn,
            OLECHAR __RPC_FAR *__RPC_FAR *ppchURLOut);
        
        HRESULT STDMETHODCALLTYPE FilterDataObject( 
            IDataObject __RPC_FAR *pDO,
            IDataObject __RPC_FAR *__RPC_FAR *ppDORet);
};

#endif // !defined(AFX_DOCHANDLER_H__722BB2A9_020D_45E1_9054_6AE4453E271D__INCLUDED_)
