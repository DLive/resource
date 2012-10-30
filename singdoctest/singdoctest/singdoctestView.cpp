// singdoctestView.cpp : CsingdoctestView ���ʵ��
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

// CsingdoctestView ����/����

CsingdoctestView::CsingdoctestView()
{
	// TODO: �ڴ˴���ӹ������

}

CsingdoctestView::~CsingdoctestView()
{
}

BOOL CsingdoctestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CsingdoctestView ����

void CsingdoctestView::OnDraw(CDC* /*pDC*/)
{
	CsingdoctestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CsingdoctestView ���

#ifdef _DEBUG
void CsingdoctestView::AssertValid() const
{
	CView::AssertValid();
}

void CsingdoctestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsingdoctestDoc* CsingdoctestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsingdoctestDoc)));
	return (CsingdoctestDoc*)m_pDocument;
}
#endif //_DEBUG


// CsingdoctestView ��Ϣ�������

void CsingdoctestView::OnTransferGetdata()
{
	// TODO: �ڴ���������������
	CsingdoctestDoc* pDoc = GetDocument();
	m_rich.SetWindowText(pDoc->m_strText);
	m_rich.SetModify(FALSE);
}

void CsingdoctestView::OnTransferStoredata()
{
	// TODO: �ڴ���������������
	CsingdoctestDoc* pDoc = GetDocument();
	m_rich.GetWindowText(pDoc->m_strText);
	m_rich.SetModify(FALSE);
}

void CsingdoctestView::OnUpdateTransferStoredata(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(m_rich.GetModify());
}

int CsingdoctestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO:  �ڴ������ר�õĴ�������
	CRect rect(0, 0, 0, 0);
	m_rich.Create(ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN |
	              WS_CHILD | WS_VISIBLE | WS_VSCROLL, rect, this, 1);
	return 0;
}

void CsingdoctestView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: �ڴ˴������Ϣ����������
	CRect rect;
	GetClientRect(rect);
	m_rich.SetWindowPos(&wndTop, 0, 0, rect.right - rect.left,
	                    rect.bottom - rect.top, SWP_SHOWWINDOW);
}
