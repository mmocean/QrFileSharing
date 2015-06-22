#if !defined(AFX_QRFILESHARINGDIALOG_H__7038980D_2C47_48E5_8DE5_20583A067F2A__INCLUDED_)
#define AFX_QRFILESHARINGDIALOG_H__7038980D_2C47_48E5_8DE5_20583A067F2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QrFileSharingDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// QrFileSharingDialog dialog

class QrFileSharingDialog : public CDialog
{
// Construction
public:
	QrFileSharingDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(QrFileSharingDialog)
	enum { IDD = IDD_DIALOG_QRFILESHARING };
	CStatic	m_StaticBitMap;
	CComboBox	m_ComboPixel;
	CComboBox	m_ComboLevel;
	CComboBox	m_ComboFgcolor;
	CComboBox	m_ComboBgColor;
	CString	m_EditConvert;
	CString	m_EditFileTime;
	CString	m_EditFileName;
	CString	m_EditFileSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(QrFileSharingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(QrFileSharingDialog)
	afx_msg void OnSelchangeComboBgcolor();
	afx_msg void OnSelchangeComboFgcolor();
	afx_msg void OnSelchangeComboLevel();
	afx_msg void OnSelchangeComboPixel();
	afx_msg void OnButtonReset();
	afx_msg void OnButtonConvert();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	int m_nPixel;
	int m_nLevel;
	int m_nFgColor;
	int m_nBgColor;
	CString m_strErrorInfo;

private:
	void UpdateAllViews( void );

public:
	//生成图片
	int GenerateImage( CString instring, CString outimage );
	//生成位图句柄
	HBITMAP GenerateHBitMap( CString inimage );
	//显示图片
	void DisplayImage( HBITMAP hbitmap );
	//文件属性
	void GetFileAttribute();
public:
	//{{AFX_MSG(QrFileSharingDialog)
	afx_msg LRESULT OnUserFileOpened(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QRFILESHARINGDIALOG_H__7038980D_2C47_48E5_8DE5_20583A067F2A__INCLUDED_)
