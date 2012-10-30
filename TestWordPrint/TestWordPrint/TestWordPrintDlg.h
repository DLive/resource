// TestWordPrintDlg.h : header file
//

#if !defined(AFX_TESTWORDPRINTDLG_H__1B62E8E5_CAEC_4178_B6A0_E94EC3AFEC74__INCLUDED_)
#define AFX_TESTWORDPRINTDLG_H__1B62E8E5_CAEC_4178_B6A0_E94EC3AFEC74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestWordPrintDlg dialog

class CTestWordPrintDlg : public CDialog
{
// Construction
public:
	bool SetPrinterDuplex( LPTSTR lpPrinterName , bool duplex );
	CTestWordPrintDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestWordPrintDlg)
	enum { IDD = IDD_TESTWORDPRINT_DIALOG };
	CListBox	m_Printer;
	CString	m_WordFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestWordPrintDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestWordPrintDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWordprint();
	afx_msg void OnUpdateEdit1();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void initPrinterList();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTWORDPRINTDLG_H__1B62E8E5_CAEC_4178_B6A0_E94EC3AFEC74__INCLUDED_)
