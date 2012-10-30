// singdoctestDoc.cpp : CsingdoctestDoc ���ʵ��
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


// CsingdoctestDoc ����/����

CsingdoctestDoc::CsingdoctestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CsingdoctestDoc::~CsingdoctestDoc()
{
}

BOOL CsingdoctestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	m_strText = "Hello (from CEx12aDoc::OnNewDocument)";
	return TRUE;
}




// CsingdoctestDoc ���л�

void CsingdoctestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CsingdoctestDoc ���

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


// CsingdoctestDoc ����

void CsingdoctestDoc::OnUpdateEditClearAll(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(!m_strText.IsEmpty());
}

void CsingdoctestDoc::OnEditClearAll()
{
	// TODO: �ڴ���������������
	m_strText.Empty();
}
