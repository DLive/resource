// singdoctestDoc.h : CsingdoctestDoc 类的接口
//


#pragma once


class CsingdoctestDoc : public CDocument
{
protected: // 仅从序列化创建
	CsingdoctestDoc();
	DECLARE_DYNCREATE(CsingdoctestDoc)

// 属性
public:
	CString m_strText;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CsingdoctestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateEditClearAll(CCmdUI *pCmdUI);
	afx_msg void OnEditClearAll();
};


