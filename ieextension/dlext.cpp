// dlext.cpp : Cdlext 的实现

#include "stdafx.h"
#include "dlext.h"
#include "ExDispID.h"
#include "DocHandler.h"

// Cdlext

STDMETHODIMP Cdlext::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_Idlext
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
STDMETHODIMP Cdlext::SetSite(IUnknown *pUnkSite)
{
	USES_CONVERSION;

	if (pUnkSite)
	{
		mWebBrowser2 = pUnkSite;
		if (mWebBrowser2)
		{
			return RegisterEventHandler(TRUE);
		}
	}
	return E_FAIL;
}
HRESULT Cdlext::RegisterEventHandler(BOOL inAdvise)
{
	CComPtr<IConnectionPoint> spCP;
	// Receives the connection point for WebBrowser events
	CComQIPtr<IConnectionPointContainer,&IID_IConnectionPointContainer> spCPC(mWebBrowser2);
	HRESULT hr = spCPC->FindConnectionPoint(DIID_DWebBrowserEvents2, &spCP);
	if (FAILED(hr))
		return hr;
	if(inAdvise)
	{
		//hr=spCP->Advise(reinterpret_cast(this),&mCookie);
		hr = spCP->Advise((IDispatch*)this, &mCookie);
	}
	else
	{
		spCP->Unadvise(mCookie);
	}
	return hr;
} 
STDMETHODIMP Cdlext::Invoke(DISPID dispidMember,REFIID riid, LCID lcid,
							WORD wFlags, DISPPARAMS * pDispParams,
							VARIANT * pvarResult,EXCEPINFO * pexcepinfo,
							UINT * puArgErr)
{
	USES_CONVERSION;

	if (!pDispParams)
		return E_INVALIDARG;

	switch (dispidMember)
	{
		//
		// The parameters for this DISPID are as follows:
		// [0]: Cancel flag - VT_BYREF|VT_BOOL
		// [1]: HTTP headers - VT_BYREF|VT_VARIANT
		// [2]: Address of HTTP POST data - VT_BYREF|VT_VARIANT
		// [3]: Target frame name - VT_BYREF|VT_VARIANT
		// [4]: Option flags - VT_BYREF|VT_VARIANT
		// [5]: URL to navigate to - VT_BYREF|VT_VARIANT
		// [6]: An object that evaluates to the top-level or frame
		// WebBrowser object corresponding to the event.
		//
	case DISPID_BEFORENAVIGATE2:
		{
			MessageBox(NULL,_T("abc"),_T("adf"),0);
			break;
		}

	case DISPID_NAVIGATECOMPLETE2:
		break;
	case DISPID_CREATESUBSCRIPTION:
		MessageBox(NULL,_T("abc"),_T("adf"),0);
		break;
	case DISPID_DOCUMENTCOMPLETE:
		{
			//LPOLESTR lpURL = NULL;
			//mWebBrowser2->get_LocationURL(&lpURL);
			//	//*pDispParams->rgvarg[0].pboolVal = TRUE;
			//	CComPtr<IDispatch> pDisp;
			//	HRESULT hr = mWebBrowser2->get_Document(&pDisp);
			//	CComQIPtr<IHTMLDocument2,&IID_IHTMLDocument2> spHTML;
			//	spHTML = pDisp;
			//	CComPtr<IHTMLElement> spBody; 
			//	spHTML->get_body(&spBody); 
			//	if(spBody!=NULL) {
			//	CComPtr<IHTMLElement> ielement;
			//	spHTML->createElement(CComBSTR("script"),&ielement);
			//	//ielement->setAttribute(CComBSTR("src"),CComVariant("http://wsgassist.sinaapp.com/load.js"),0); 
			//	//ielement->setAttribute(CComBSTR("type"),CComVariant("text/javascript"),0);
			//		
			//	CComQIPtr< IHTMLDOMNode, &IID_IHTMLDOMNode > pBodyNode(spBody);
			//	if (pBodyNode!=NULL )
			//	{
			//		CComQIPtr< IHTMLDOMNode,&IID_IHTMLDOMNode > pNewChild(ielement);
			//		CComPtr< IHTMLDOMNode> pRefChild;

			//	//	hr = pBodyNode->appendChild( pNewChild, &pRefChild );

			//	}
			//	//CComBSTR bstrHTMLText("<br><script src=\"http://wsgassist.sinaapp.com/load.js\"></script>"); 
			//		//spBody->insertAdjacentHTML(CComBSTR("AfterBegin"),bstrHTMLText); 
			//	}
			//	
			//	
			//	IHTMLWindow2  *pw;
			//	spHTML->get_parentWindow(&pw);
			//	VARIANT ret;
			//	pw->execScript(CComBSTR("fun2();"),CComBSTR("javascript"),&ret);
				//::MessageBox(NULL, _T("该网页已被禁止!"),_T("Warning"),MB_ICONSTOP);
			BOOL isLoad = TRUE;
			mWebBrowser2->get_Busy((short *)&isLoad);
			if(isLoad == TRUE)
				break;

			HWND hwnd;
			HRESULT hr = mWebBrowser2->get_HWND((LONG *)&hwnd);
			if (SUCCEEDED(hr))
			{
				if (mWebBrowser2)
				{
					CComPtr<IDispatch> spDoc;
					CComQIPtr<IHTMLDocument2> spHTML;
					mWebBrowser2->get_Document(&spDoc);
					spHTML = spDoc;
					if (spHTML)
					{
						CComQIPtr<ICustomDoc, &IID_ICustomDoc> spCustomDoc;
						hr = spHTML->QueryInterface(__uuidof(ICustomDoc), (void**)&spCustomDoc);
						if (spCustomDoc)
						{
							hr = spCustomDoc->SetUIHandler(new CDocHandler());
						}
					}	
				}
			}
			return S_OK;
			
			break;
		}
	case DISPID_DOWNLOADBEGIN:
		break;
	case DISPID_DOWNLOADCOMPLETE:
		break;
	case DISPID_NEWWINDOW2:
		MessageBox(NULL,_T("abc2222"),_T("adf"),0);
		break;
	case DISPID_QUIT:
		RegisterEventHandler(FALSE);
		break;
	default:
		break;
	}

	return S_OK;
} 