// TestWordPrintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestWordPrint.h"
#include "TestWordPrintDlg.h"
#include "msword.h"
#include "WINSPOOL.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestWordPrintDlg dialog

CTestWordPrintDlg::CTestWordPrintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestWordPrintDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestWordPrintDlg)
	m_WordFile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestWordPrintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestWordPrintDlg)
	DDX_Control(pDX, IDC_LIST1, m_Printer);
	DDX_Text(pDX, IDC_EDIT1, m_WordFile);
	DDV_MaxChars(pDX, m_WordFile, 100);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestWordPrintDlg, CDialog)
	//{{AFX_MSG_MAP(CTestWordPrintDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_WORDPRINT, OnWordprint)
	ON_EN_UPDATE(IDC_EDIT1, OnUpdateEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestWordPrintDlg message handlers

BOOL CTestWordPrintDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	

    initPrinterList() ;


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestWordPrintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestWordPrintDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestWordPrintDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestWordPrintDlg::OnWordprint() 
{
	// TODO: Add your control notification handler code here
      //CString text = 
	  _Application objWord;

	  CString   EditText;  
      GetDlgItemText( IDC_EDIT1,   EditText) ;
	  m_WordFile =  EditText ;
	  if( m_WordFile.GetLength() == 0 ) {
		  AfxMessageBox( "Please enter a word file( including path )" ) ;
		  return ;
	  }
      // Convenient values declared as ColeVariants.
      COleVariant covTrue((short)TRUE),
                  covFalse((short)FALSE),
                  covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

      // Get the IDispatch pointer and attach it to the objWord object.
      if (!objWord.CreateDispatch("Word.Application" , NULL ))
      {
         AfxMessageBox("Couldn't get Word object.");
         return;
      }
      objWord.SetVisible(FALSE);  //This shows the application.
      Documents docs(objWord.GetDocuments());
      _Document testDoc;

      testDoc.AttachDispatch(
		  docs.Open(COleVariant( m_WordFile ,VT_BSTR),
                    covFalse,    // Confirm Conversion.
                    covFalse,    // ReadOnly.
                    covFalse,    // AddToRecentFiles.
                    covOptional, // PasswordDocument.
                    covOptional, // PasswordTemplate.
                    covFalse,    // Revert.
                    covOptional, // WritePasswordDocument.
                    covOptional, // WritePasswordTemplate.
                    covOptional, // Format. // Last argument for Word 97
                    covOptional, // Encoding // New for Word 2000/2002
                    covTrue,     // Visible
                    covOptional, // OpenConflictDocument
                    covOptional, // OpenAndRepair
                    COleVariant((long)0),     // DocumentDirection wdDocumentDirection LeftToRight
                    covOptional  // NoEncodingDialog
                    )  // Close Open parameters
       ); // Close AttachDispatch(бн)

       //AfxMessageBox("Now printing 2 copies on the active printer");
	   //MailMerge mailMerge = testDoc.GetMailMerge() ;
	   //mailMerge.Execute(NULL) ;
	   //mailMerge.OpenDataSource( "" ) ;
	   CString printerName ;
	   
	   m_Printer.GetText( m_Printer.GetCurSel(), printerName );
	   LPSTR pName = printerName.GetBuffer(printerName.GetLength()) ;
       if( !SetPrinterDuplex( pName , true ) )
	   {
		   AfxMessageBox( "You cannot modify the duplex flag for this printer \n because it does not support duplex or the driver \n does not support setting it" ) ;
	   }
	   
       testDoc.PrintOut(covFalse,              // Background.
                        covOptional,           // Append.
                        covOptional,           // Range.
                        covOptional,           // OutputFileName.
                        covOptional,           // From.
                        covOptional,           // To.
                        covOptional,           // Item.
                        COleVariant((long)1),  // Copies.
                        covOptional,           // Pages.
                        covOptional,           // PageType.
                        covOptional,           // PrintToFile.
                        covOptional,           // Collate.
                        covOptional,           // ActivePrinterMacGX.
                        covTrue,            // ManualDuplexPrint.
                        covOptional,           // PrintZoomColumn  New with Word 2002
                        covOptional,           // PrintZoomRow          ditto
                        covOptional,           // PrintZoomPaperWidth   ditto
                        covOptional);          // PrintZoomPaperHeight  ditto

       // If you wish to Print Preview the document rather than print it,
       // you can use the PrintPreview member function instead of the
       // PrintOut member function:
       //    testDoc[i].PrintPreview.
SetPrinterDuplex( pName , false ) ;
      objWord.Quit(covFalse,  // SaveChanges.
                   covTrue,   // OriginalFormat.
                   covFalse   // RouteDocument.
                   );
}

void CTestWordPrintDlg::OnUpdateEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	//AfxMessageBox( m_WordFile ) ;
}

void CTestWordPrintDlg::OnButton1() 
{
	  _Application objWord;
      // Convenient values declared as ColeVariants.
      COleVariant covTrue((short)TRUE),
                  covFalse((short)FALSE),
                  covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

      // Get the IDispatch pointer and attach it to the objWord object.
      if (!objWord.CreateDispatch("Word.Application" , NULL ))
      {
         AfxMessageBox("Couldn't get Word object.");
         return;
      }
      objWord.SetVisible(TRUE);  //This shows the application.
      Documents docs(objWord.GetDocuments());
      _Document WordDoc ;

      WordDoc.AttachDispatch(
		  docs.Open(COleVariant( "c:\\TEST1.DOT" ,VT_BSTR),
                    covFalse,    // Confirm Conversion.
                    covFalse,    // ReadOnly.
                    covFalse,    // AddToRecentFiles.
                    covOptional, // PasswordDocument.
                    covOptional, // PasswordTemplate.
                    covFalse,    // Revert.
                    covOptional, // WritePasswordDocument.
                    covOptional, // WritePasswordTemplate.
                    covOptional, // Format. // Last argument for Word 97
                    covOptional, // Encoding // New for Word 2000/2002
                    covTrue,     // Visible
                    covOptional, // OpenConflictDocument
                    covOptional, // OpenAndRepair
                    COleVariant((long)0),     // DocumentDirection wdDocumentDirection LeftToRight
                    covOptional  // NoEncodingDialog
                    )  // Close Open parameters
       ); // Close AttachDispatch(бн)

	   MailMerge mailMerge = WordDoc.GetMailMerge() ;
       mailMerge.OpenDataSource( 
		   "C:\\TEST1.XTX" , 
		   covOptional , 
		   covOptional , 
		   covFalse , 
		   covOptional , 
		   covOptional ,
		   covOptional ,
		   covOptional ,
		   covOptional ,
		   covOptional ,
		   covOptional , 
		   covOptional , 
		   covOptional , 
		   covOptional ,
		   covOptional , 
		   covOptional ) ;
	   mailMerge.Execute( covOptional ) ;

	   _Document mergeDoc ;
	   mergeDoc = objWord.GetActiveDocument() ;
	   WordDoc.Close( COleVariant((long)0) , covOptional , covOptional ) ;
       WordDoc = mergeDoc ;
//       SetPrinterDuplex( "Macromedia FlashPaper" , true ) ;
	   
       WordDoc.PrintOut(covFalse,              // Background.
                        covTrue,           // Append.
                        covOptional,           // Range.
                        covOptional,           // OutputFileName.
                        covOptional,           // From.
                        covOptional,           // To.
                        covOptional,           // Item.
                        COleVariant((long)1),  // Copies.
                        covOptional,           // Pages.
                        covOptional,           // PageType.
                        covOptional,           // PrintToFile.
                        covOptional,           // Collate.
                        covOptional,           // ActivePrinterMacGX.
                        covTrue,            // ManualDuplexPrint.
                        covOptional,           // PrintZoomColumn  New with Word 2002
                        covOptional,           // PrintZoomRow          ditto
                        covOptional,           // PrintZoomPaperWidth   ditto
                        covOptional);          // PrintZoomPaperHeight  ditto

       // If you wish to Print Preview the document rather than print it,
       // you can use the PrintPreview member function instead of the
       // PrintOut member function:
       //    testDoc[i].PrintPreview.
      WordDoc.SaveAs( COleVariant( "C:\\T.DOC" ,VT_BSTR) , 
		  covOptional ,
		  covOptional,
		  covOptional,
		  covOptional,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ,
		  covOptional ) ;

      WordDoc.Close( COleVariant((long)0) , covOptional , covOptional ) ;
	  

      objWord.Quit(covFalse,  // SaveChanges.
                   covTrue,   // OriginalFormat.
                   covFalse   // RouteDocument.
                   );	
}

bool CTestWordPrintDlg::SetPrinterDuplex(LPTSTR  lpPrinterName, bool duplex)
{
    HANDLE   hPrinter   =   NULL;  
    DWORD   dwNeeded   =   0;  
    PRINTER_INFO_2   *pi2   =   NULL;  
    DEVMODE   *pDevMode   =   NULL;  
    PRINTER_DEFAULTS   pd;  
    BOOL   bFlag;  
    LONG   lFlag;  
   
    // Open   printer   handle   (on   Windows   NT,   you   need   full-access   because   you  
    // will   eventually   use   SetPrinter)...  
    ZeroMemory(&pd,   sizeof(pd));  
    pd.DesiredAccess   =   PRINTER_ALL_ACCESS;  
    bFlag = OpenPrinter(lpPrinterName,   &hPrinter,   &pd);  
    if (!bFlag   ||   (hPrinter   ==   NULL))  {
		AfxMessageBox( "Cannot open the printer specified" ) ;
       return   FALSE;  
    }
    //   The   first   GetPrinter   tells   you   how   big   the   buffer   should   be   in    
    //   order   to   hold   all   of   PRINTER_INFO_2.   Note   that   this   should   fail   with    
    //   ERROR_INSUFFICIENT_BUFFER.     If   GetPrinter   fails   for   any   other   reason    
    //   or   dwNeeded   isn't   set   for   some   reason,   then   there   is   a   problem...  
    SetLastError(0);  
    bFlag  = GetPrinter(hPrinter,   2,   0,   0,   &dwNeeded);  
    if((!bFlag)   &&   (GetLastError()   !=   ERROR_INSUFFICIENT_BUFFER) || (dwNeeded   ==   0))  
	{  

       ClosePrinter(hPrinter);  
	   AfxMessageBox( "Cannot get the size of the DEVMODE structure" ) ;
       return   FALSE;  
	}  
 
     //   Allocate   enough   space   for   PRINTER_INFO_2...  
    pi2   =   (PRINTER_INFO_2   *)GlobalAlloc(GPTR,   dwNeeded);  
    if(pi2   ==   NULL)  
	{  
       ClosePrinter(hPrinter);  
       return   FALSE;  
	}  
    //   The   second   GetPrinter   fills   in   all   the   current   settings,   so   all   you  
    //   need   to   do   is   modify   what   you're   interested   in...  
    bFlag  = GetPrinter(hPrinter,   2,   (LPBYTE)pi2,   dwNeeded,   &dwNeeded);  
    if   (!bFlag)  
	{  
      GlobalFree(pi2);  
      ClosePrinter(hPrinter);  
      return   FALSE;  
	}  
   
     //   If   GetPrinter   didn't   fill   in   the   DEVMODE,   try   to   get   it   by   calling  
    //   DocumentProperties...  
    if   (pi2->pDevMode   ==   NULL)  
	{  
       dwNeeded   =   DocumentProperties(NULL,   hPrinter,   lpPrinterName,  NULL,   NULL,   0);  
       if   (dwNeeded   <=   0)  
	   {  
			GlobalFree(pi2);  
			ClosePrinter(hPrinter);  
			return   FALSE;  
	   }	  
   
       pDevMode   =   (DEVMODE   *)GlobalAlloc(GPTR,   dwNeeded);  
       if(pDevMode   ==   NULL)  
	   {  
          GlobalFree(pi2);  
          ClosePrinter(hPrinter);  
          return   FALSE;  
	   }  
       lFlag   =   DocumentProperties(NULL,   hPrinter,  lpPrinterName,  pDevMode,   NULL, DM_OUT_BUFFER);  
       if   (lFlag   !=   IDOK   ||   pDevMode   ==   NULL)  
	   {  
            GlobalFree(pDevMode);  
			GlobalFree(pi2);  
			ClosePrinter(hPrinter);  
			return   FALSE;  
	   }  
       pi2->pDevMode = pDevMode;  
	}  
   
// 	if( pi2->pDevMode->dmFields & DM_DUPLEX ) {
//             GlobalFree(pDevMode);  
// 			GlobalFree(pi2);  
// 			ClosePrinter(hPrinter);  
// 			return   FALSE;  
// 	}
     pi2->pDevMode->dmFields = DM_DUPLEX | DM_ORIENTATION;  
     if( duplex ) 
        pi2->pDevMode->dmOrientation = DMORIENT_LANDSCAPE ;  
     else
        pi2->pDevMode->dmOrientation = DMORIENT_PORTRAIT ;  

	 pi2->pDevMode->dmDuplex = DMDUP_VERTICAL;
     lFlag   =   DocumentProperties(NULL,   hPrinter, lpPrinterName,  pi2->pDevMode,   pi2->pDevMode,  DM_IN_BUFFER|DM_OUT_BUFFER);  
     if   (lFlag   !=   IDOK)  
	 {  
        GlobalFree(pi2);  
        ClosePrinter(hPrinter);  
        if(pDevMode)  
        GlobalFree(pDevMode);  
        return   FALSE;  
	 }  
     bFlag   =   SetPrinter(hPrinter,   2,   (LPBYTE)pi2,   0);  
     if(!bFlag)  
	 {  
         GlobalFree(pi2);  
         ClosePrinter(hPrinter);  
         if(pDevMode)  
             GlobalFree(pDevMode);  
         return   FALSE;  
	 }  
     //   Add   End       By   Masatoshi   Kunishima@fb.tokyo.obic.co.jp   in   2003.2.25  
   
  SendMessageTimeout(HWND_BROADCAST,   WM_DEVMODECHANGE, 0L,  (LPARAM)(LPCSTR)lpPrinterName,  SMTO_NORMAL,   1000,   NULL);  
  if(pi2)  GlobalFree(pi2);  
  if(hPrinter)  ClosePrinter(hPrinter);  
  if(pDevMode)  GlobalFree(pDevMode);  
  return   TRUE;   
}

void CTestWordPrintDlg::initPrinterList()
{
    DWORD Flags = PRINTER_ENUM_FAVORITE | PRINTER_ENUM_LOCAL;   //local   printers  
    PRINTER_INFO_2* pPrinterEnum=new PRINTER_INFO_2;
    DWORD dwCount=0,dwBytes=0;
	TCHAR Name[500]   ;  
	memset(Name,   0,   sizeof(TCHAR) * 500)   ;   
    if (!EnumPrinters(Flags,Name,2,(LPBYTE)pPrinterEnum,sizeof(PRINTER_INFO_2),&dwBytes,&dwCount))
    {
        if (pPrinterEnum) delete pPrinterEnum;
        pPrinterEnum=(PRINTER_INFO_2*)(new BYTE[dwBytes]);
        EnumPrinters(Flags,Name,2,(LPBYTE)pPrinterEnum,dwBytes,&dwBytes,&dwCount);
    }
	
	DWORD i = 0 ;
	for( i = 0 ; i < dwCount ; i++ ) {
		CString printerName = pPrinterEnum[ i ].pPrinterName ;
		m_Printer.AddString( printerName ) ;
	}

    if (pPrinterEnum) {delete []pPrinterEnum;}   
}
