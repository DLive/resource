// nodebookDoc.cpp : CnodebookDoc ���ʵ��
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


// CnodebookDoc ����/����

CnodebookDoc::CnodebookDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CnodebookDoc::~CnodebookDoc()
{
}

BOOL CnodebookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CnodebookDoc ���л�

void CnodebookDoc::Serialize(CArchive& ar)
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


// CnodebookDoc ���

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


// CnodebookDoc ����
