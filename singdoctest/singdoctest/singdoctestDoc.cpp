// singdoctestDoc.cpp : CsingdoctestDoc 类的实现
//

#include "stdafx.h"
#include "singdoctest.h"

#include "singdoctestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsingdoctestDoc

IMPLEMENT_DYNCREATE(CsingdoctestDoc, CDocument)

BEGIN_MESSAGE_MAP(CsingdoctestDoc, CDocument)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR_ALL, &CsingdoctestDoc::OnUpdateEditClearAll)
	ON_COMMAND(ID_EDIT_CLEAR_ALL, &CsingdoctestDoc::OnEditClearAll)
END_MESSAGE_MAP()


// CsingdoctestDoc 构造/析构

CsingdoctestDoc::CsingdoctestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CsingdoctestDoc::~CsingdoctestDoc()
{
}

BOOL CsingdoctestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	m_strText = "Hello (from CEx12aDoc::OnNewDocument)";
	return TRUE;
}




// CsingdoctestDoc 序列化

void CsingdoctestDoc::Serialize(CArchive& ar)
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


// CsingdoctestDoc 诊断

#ifdef _DEBUG
void CsingdoctestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CsingdoctestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CsingdoctestDoc 命令

void CsingdoctestDoc::OnUpdateEditClearAll(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(!m_strText.IsEmpty());
}

void CsingdoctestDoc::OnEditClearAll()
{
	// TODO: 在此添加命令处理程序代码
	m_strText.Empty();
}
