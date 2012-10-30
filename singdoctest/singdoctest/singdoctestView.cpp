// singdoctestView.cpp : CsingdoctestView 类的实现
//

#include "stdafx.h"
#include "singdoctest.h"

#include "singdoctestDoc.h"
#include "singdoctestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsingdoctestView

IMPLEMENT_DYNCREATE(CsingdoctestView, CView)

BEGIN_MESSAGE_MAP(CsingdoctestView, CView)
	ON_COMMAND(ID_TRANSFER_GETDATA, &CsingdoctestView::OnTransferGetdata)
	ON_COMMAND(ID_TRANSFER_STOREDATA, &CsingdoctestView::OnTransferStoredata)
	ON_UPDATE_COMMAND_UI(ID_TRANSFER_STOREDATA, &CsingdoctestView::OnUpdateTransferStoredata)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CsingdoctestView 构造/析构

CsingdoctestView::CsingdoctestView()
{
	// TODO: 在此处添加构造代码

}

CsingdoctestView::~CsingdoctestView()
{
}

BOOL CsingdoctestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CsingdoctestView 绘制

void CsingdoctestView::OnDraw(CDC* /*pDC*/)
{
	CsingdoctestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CsingdoctestView 诊断

#ifdef _DEBUG
void CsingdoctestView::AssertValid() const
{
	CView::AssertValid();
}

void CsingdoctestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsingdoctestDoc* CsingdoctestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsingdoctestDoc)));
	return (CsingdoctestDoc*)m_pDocument;
}
#endif //_DEBUG


// CsingdoctestView 消息处理程序

void CsingdoctestView::OnTransferGetdata()
{
	// TODO: 在此添加命令处理程序代码
	CsingdoctestDoc* pDoc = GetDocument();
	m_rich.SetWindowText(pDoc->m_strText);
	m_rich.SetModify(FALSE);
}

void CsingdoctestView::OnTransferStoredata()
{
	// TODO: 在此添加命令处理程序代码
	CsingdoctestDoc* pDoc = GetDocument();
	m_rich.GetWindowText(pDoc->m_strText);
	m_rich.SetModify(FALSE);
}

void CsingdoctestView::OnUpdateTransferStoredata(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(m_rich.GetModify());
}

int CsingdoctestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO:  在此添加您专用的创建代码
	CRect rect(0, 0, 0, 0);
	m_rich.Create(ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN |
	              WS_CHILD | WS_VISIBLE | WS_VSCROLL, rect, this, 1);
	return 0;
}

void CsingdoctestView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: 在此处添加消息处理程序代码
	CRect rect;
	GetClientRect(rect);
	m_rich.SetWindowPos(&wndTop, 0, 0, rect.right - rect.left,
	                    rect.bottom - rect.top, SWP_SHOWWINDOW);
}
