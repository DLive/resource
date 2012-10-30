// dlext.h : Cdlext ������

#pragma once
#include "resource.h"       // ������

#include "ieextension_i.h"
#include "_IdlextEvents_CP.h"
#include "ExDisp.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
