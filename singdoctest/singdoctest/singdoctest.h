// singdoctest.h : singdoctest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CsingdoctestApp:
// �йش����ʵ�֣������ singdoctest.cpp
//

class CsingdoctestApp : public CWinApp
{
public:
	CsingdoctestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CsingdoctestApp theApp;