// dlltest.h : dlltest DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CdlltestApp
// �йش���ʵ�ֵ���Ϣ������� dlltest.cpp
//

class CdlltestApp : public CWinApp
{
public:
	CdlltestApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};