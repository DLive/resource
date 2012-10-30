// englishCetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "englishCet.h"
#include "englishCetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CenglishCetDlg �Ի���




CenglishCetDlg::CenglishCetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CenglishCetDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CenglishCetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CenglishCetDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CenglishCetDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CenglishCetDlg ��Ϣ�������

BOOL CenglishCetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CenglishCetDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CenglishCetDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CenglishCetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CenglishCetDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString   strServerName; 
	CString   path; 
	INTERNET_PORT   nPort; 
	DWORD   dwServiceType;
	if(AfxParseURL("http://cet.99sushe.com/",dwServiceType,strServerName,path,nPort))
	{
		CInternetSession * m_inernetSession = new CInternetSession();
		m_inernetSession->SetOption(INTERNET_OPTION_CONNECT_TIMEOUT,30*1000);
		CHttpConnection * m_httpConnection = m_inernetSession->GetHttpConnection("cet.99sushe.com",nPort,NULL,NULL );
		CHttpFile* m_httpfile=m_httpConnection->OpenRequest(CHttpConnection::HTTP_VERB_POST,"/s",NULL,1,NULL,"HTTP/1.1",INTERNET_FLAG_RELOAD);
		DWORD dw;
		dw=GetLastError();
		//ʹ��ChttpFile�������͵�Http����
		if(m_httpfile != NULL)
		{
			CString heads;
			heads.Append("Accept:image/gif, image/jpeg, image/pjpeg, image/pjpeg, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, application/x-silverlight, application/x-shockwave-flash, application/x-ms-application, application/x-ms-xbap, application/vnd.ms-xpsdocument, application/xaml+xml, application/QVOD, application/QVOD, */*");
			heads.Append("\r\nReferer: http://cet.99sushe.com/");
			heads.Append("\r\nAccept-Language: zh-cn");
			heads.Append("\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; QQDownload 538; CIBA; .NET CLR 2.0.50727; .NET CLR 3.0.04506.648; .NET CLR 3.5.21022)");
			heads.Append("\r\nContent-Type: application/x-www-form-urlencoded");
			heads.Append("\r\nAccept-Encoding: gzip, deflate");
			heads.Append("\r\nHost:cet.99sushe.com");
			heads.Append("\r\nContent-Length: 36");
			heads.Append("\r\nConnection: Keep-Alive");
			heads.Append("\r\nCache-Control: no-cache");
			heads.Append("\r\nCookie:cnzz_a30023677=0; sin30023677=; rtime30023677=2; ltime30023677=1316007896875; cnzz_eid30023677=60277024-1265091603-id=130050111110121&name=%C0%EE%D1%C7");
			m_httpfile->AddRequestHeaders(heads,HTTP_ADDREQ_FLAG_COALESCE);
			BOOL rv=m_httpfile->SendRequest();
			if(rv==TRUE)
			{
			return;
			}
		}
	}
}
