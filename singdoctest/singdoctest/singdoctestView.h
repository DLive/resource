// singdoctestView.h : CsingdoctestView ��Ľӿ�
//


#pragma once


class CsingdoctestView : public CView
{
protected: // �������л�����
	CsingdoctestView();
	DECLARE_DYNCREATE(CsingdoctestView)

// ����
public:
	CsingdoctestDoc* GetDocument() const;
	
	CRichEditCtrl m_rich;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CsingdoctestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTransferGetdata();
	afx_msg void OnTransferStoredata();
	afx_msg void OnUpdateTransferStoredata(CCmdUI *pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // singdoctestView.cpp �еĵ��԰汾
inline CsingdoctestDoc* CsingdoctestView::GetDocument() const
   { return reinterpret_cast<CsingdoctestDoc*>(m_pDocument); }
#endif

