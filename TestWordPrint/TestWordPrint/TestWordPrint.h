// TestWordPrint.h : main header file for the TESTWORDPRINT application
//

#if !defined(AFX_TESTWORDPRINT_H__D7BE5CA9_0B5F_4E66_A750_C5148BAC8F8B__INCLUDED_)
#define AFX_TESTWORDPRINT_H__D7BE5CA9_0B5F_4E66_A750_C5148BAC8F8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestWordPrintApp:
// See TestWordPrint.cpp for the implementation of this class
//

class CTestWordPrintApp : public CWinApp
{
public:
	CTestWordPrintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestWordPrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestWordPrintApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTWORDPRINT_H__D7BE5CA9_0B5F_4E66_A750_C5148BAC8F8B__INCLUDED_)
