// dllmain.cpp : DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "ieextension_i.h"
#include "dllmain.h"

CieextensionModule _AtlModule;

// DLL 入口点
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TCHAR pszLoader[MAX_PATH];

		//返回调用者模块的名称，第一个参数应为NULL，详见msdn。
		GetModuleFileName(NULL,pszLoader,MAX_PATH);
		_tcslwr(pszLoader);
		if (_tcsstr(pszLoader,_T("explorer.exe"))) 
			return FALSE;
	}

	return _AtlModule.DllMain(dwReason, lpReserved); 
}
