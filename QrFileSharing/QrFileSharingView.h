// QrFileSharingView.h : interface of the CQrFileSharingView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QRFILESHARINGVIEW_H__AFB51180_7630_48F1_8DBC_AC8461BF21A4__INCLUDED_)
#define AFX_QRFILESHARINGVIEW_H__AFB51180_7630_48F1_8DBC_AC8461BF21A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "QrFileSharingDialog.h"

class CQrFileSharingView : public CView
{
protected: // create from serialization only
	CQrFileSharingView();
	DECLARE_DYNCREATE(CQrFileSharingView)

// Attributes
public:
	CQrFileSharingDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQrFileSharingView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CQrFileSharingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQrFileSharingView)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	QrFileSharingDialog m_qfsd;
	CString m_filename;
};

#ifndef _DEBUG  // debug version in QrFileSharingView.cpp
inline CQrFileSharingDoc* CQrFileSharingView::GetDocument()
   { return (CQrFileSharingDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QRFILESHARINGVIEW_H__AFB51180_7630_48F1_8DBC_AC8461BF21A4__INCLUDED_)
