// nodebookView.cpp : CnodebookView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CnodebookView 构造/析构

CnodebookView::CnodebookView()
{
	// TODO: 在此处添加构造代码

}

CnodebookView::~CnodebookView()
{
}

BOOL CnodebookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CnodebookView 绘制

void CnodebookView::OnDraw(CDC* /*pDC*/)
{
	CnodebookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CnodebookView 打印

BOOL CnodebookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CnodebookView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CnodebookView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CnodebookView 诊断

#ifdef _DEBUG
void CnodebookView::AssertValid() const
{
	CView::AssertValid();
}

void CnodebookView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CnodebookDoc* CnodebookView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CnodebookDoc)));
	return (CnodebookDoc*)m_pDocument;
}
#endif //_DEBUG


// CnodebookView 消息处理程序
