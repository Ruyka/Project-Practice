
// MFC testView.cpp : implementation of the CMFCtestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC test.h"
#endif

#include "MFC testDoc.h"
#include "MFC testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtestView

IMPLEMENT_DYNCREATE(CMFCtestView, CView)

BEGIN_MESSAGE_MAP(CMFCtestView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtestView construction/destruction

CMFCtestView::CMFCtestView()
{
	// TODO: add construction code here

}

CMFCtestView::~CMFCtestView()
{
}

BOOL CMFCtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCtestView drawing

void CMFCtestView::OnDraw(CDC* /*pDC*/)
{
	CMFCtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CMFCtestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtestView diagnostics

#ifdef _DEBUG
void CMFCtestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtestDoc* CMFCtestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtestDoc)));
	return (CMFCtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtestView message handlers
