// nodebookDoc.h : CnodebookDoc ��Ľӿ�
//


#pragma once


class CnodebookDoc : public CDocument
{
protected: // �������л�����
	CnodebookDoc();
	DECLARE_DYNCREATE(CnodebookDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CnodebookDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


