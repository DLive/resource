// singdoctestView.h : CsingdoctestView 类的接口
//


#pragma once


class CsingdoctestView : public CView
{
protected: // 仅从序列化创建
	CsingdoctestView();
	DECLARE_DYNCREATE(CsingdoctestView)

// 属性
public:
	CsingdoctestDoc* GetDocument() const;
	
	CRichEditCtrl m_rich;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CsingdoctestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTransferGetdata();
	afx_msg void OnTransferStoredata();
	afx_msg void OnUpdateTransferStoredata(CCmdUI *pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // singdoctestView.cpp 中的调试版本
inline CsingdoctestDoc* CsingdoctestView::GetDocument() const
   { return reinterpret_cast<CsingdoctestDoc*>(m_pDocument); }
#endif

