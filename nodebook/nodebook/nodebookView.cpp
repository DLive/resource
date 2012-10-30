// nodebookView.cpp : CnodebookView ���ʵ��
//

#include "stdafx.h"
#include "nodebook.h"

#include "nodebookDoc.h"
#include "nodebookView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CnodebookView

IMPLEMENT_DYNCREATE(CnodebookView, CView)

BEGIN_MESSAGE_MAP(CnodebookView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CnodebookView ����/����

CnodebookView::CnodebookView()
{
	// TODO: �ڴ˴���ӹ������

}

CnodebookView::~CnodebookView()
{
}

BOOL CnodebookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CnodebookView ����

void CnodebookView::OnDraw(CDC* /*pDC*/)
{
	CnodebookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CnodebookView ��ӡ

BOOL CnodebookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CnodebookView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CnodebookView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CnodebookView ���

#ifdef _DEBUG
void CnodebookView::AssertValid() const
{
	CView::AssertValid();
}

void CnodebookView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CnodebookDoc* CnodebookView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CnodebookDoc)));
	return (CnodebookDoc*)m_pDocument;
}
#endif //_DEBUG


// CnodebookView ��Ϣ�������
