// dlext.h : Cdlext 的声明

#pragma once
#include "resource.h"       // 主符号

#include "ieextension_i.h"
#include "_IdlextEvents_CP.h"
#include "ExDisp.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// Cdlext

class ATL_NO_VTABLE Cdlext :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Cdlext, &CLSID_dlext>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<Cdlext>,
	public CProxy_IdlextEvents<Cdlext>,
	public IObjectWithSiteImpl<Cdlext>,
	public IDispatchImpl<Idlext, &IID_Idlext, &LIBID_ieextensionLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	Cdlext()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DLEXT)


BEGIN_COM_MAP(Cdlext)
	COM_INTERFACE_ENTRY(Idlext)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(Cdlext)
	CONNECTION_POINT_ENTRY(__uuidof(_IdlextEvents))
END_CONNECTION_POINT_MAP()

	CComQIPtr<IWebBrowser2, &IID_IWebBrowser2> mWebBrowser2;
	DWORD mCookie;
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
	STDMETHOD(SetSite)(IUnknown *pUnkSite);
	HRESULT RegisterEventHandler(BOOL inAdvise);
	STDMETHODIMP Invoke(DISPID dispidMember,REFIID riid, LCID lcid,
		WORD wFlags, DISPPARAMS * pDispParams,
		VARIANT * pvarResult,EXCEPINFO * pexcepinfo,
		UINT * puArgErr);

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

};

OBJECT_ENTRY_AUTO(__uuidof(dlext), Cdlext)
