// QrFileSharing.h : main header file for the QRFILESHARING application
//

#if !defined(AFX_QRFILESHARING_H__076A117A_68D8_4674_9664_4056F6C01A03__INCLUDED_)
#define AFX_QRFILESHARING_H__076A117A_68D8_4674_9664_4056F6C01A03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingApp:
// See QrFileSharing.cpp for the implementation of this class
//

class CQrFileSharingApp : public CWinApp
{
public:
	CQrFileSharingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQrFileSharingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CQrFileSharingApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QRFILESHARING_H__076A117A_68D8_4674_9664_4056F6C01A03__INCLUDED_)
