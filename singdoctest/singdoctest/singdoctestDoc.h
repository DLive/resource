// singdoctestDoc.h : CsingdoctestDoc ��Ľӿ�
//


#pragma once


class CsingdoctestDoc : public CDocument
{
protected: // �������л�����
	CsingdoctestDoc();
	DECLARE_DYNCREATE(CsingdoctestDoc)

// ����
public:
	CString m_strText;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CsingdoctestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateEditClearAll(CCmdUI *pCmdUI);
	afx_msg void OnEditClearAll();
};


