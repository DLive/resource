// nodebookDoc.cpp : CnodebookDoc 类的实现
//

#include "stdafx.h"
#include "nodebook.h"

#include "nodebookDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CnodebookDoc

IMPLEMENT_DYNCREATE(CnodebookDoc, CDocument)

BEGIN_MESSAGE_MAP(CnodebookDoc, CDocument)
END_MESSAGE_MAP()


// CnodebookDoc 构造/析构

CnodebookDoc::CnodebookDoc()
{
	// TODO: 在此添加一次性构造代码

}

CnodebookDoc::~CnodebookDoc()
{
}

BOOL CnodebookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CnodebookDoc 序列化

void CnodebookDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CnodebookDoc 诊断

#ifdef _DEBUG
void CnodebookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CnodebookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CnodebookDoc 命令
