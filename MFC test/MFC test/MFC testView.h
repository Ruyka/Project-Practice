
// MFC testView.h : interface of the CMFCtestView class
//

#pragma once


class CMFCtestView : public CView
{
protected: // create from serialization only
	CMFCtestView();
	DECLARE_DYNCREATE(CMFCtestView)

// Attributes
public:
	CMFCtestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCtestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC testView.cpp
inline CMFCtestDoc* CMFCtestView::GetDocument() const
   { return reinterpret_cast<CMFCtestDoc*>(m_pDocument); }
#endif

