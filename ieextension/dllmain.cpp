// dllmain.cpp : DllMain ��ʵ�֡�

#include "stdafx.h"
#include "resource.h"
#include "ieextension_i.h"
#include "dllmain.h"

CieextensionModule _AtlModule;

// DLL ��ڵ�
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TCHAR pszLoader[MAX_PATH];

		//���ص�����ģ������ƣ���һ������ӦΪNULL�����msdn��
		GetModuleFileName(NULL,pszLoader,MAX_PATH);
		_tcslwr(pszLoader);
		if (_tcsstr(pszLoader,_T("explorer.exe"))) 
			return FALSE;
	}

	return _AtlModule.DllMain(dwReason, lpReserved); 
}
