// QrFileSharingDoc.h : interface of the CQrFileSharingDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QRFILESHARINGDOC_H__E1AF60C9_59E0_41D8_B058_ACC9A2D1ABC3__INCLUDED_)
#define AFX_QRFILESHARINGDOC_H__E1AF60C9_59E0_41D8_B058_ACC9A2D1ABC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CQrFileSharingDoc : public CDocument
{
protected: // create from serialization only
	CQrFileSharingDoc();
	DECLARE_DYNCREATE(CQrFileSharingDoc)

// Attributes
public:

	CString GetCurrentDirectory( void );
	CString GetIpAddress( void );
	CString GetCurrentFile( void );

	CString GetInString( void );
	void SetInString( CString m_strInString );

	CString GetOutImage( void );
	void SetOutImage( CString m_strOutImage );

	CString GetDefaultString( void );
	void SetDefaultString( CString m_strDefaultString );

	CString GetDefaultOutImage( void );
	void SetDefaultOutImage( CString m_strDefaultOutImage );

	HBITMAP GetDefaultHBitMap( void );
	void SetDefaultHBitMap( HBITMAP m_DefaultHBitMap );

	BOOL GetDocContentIsChanged( void );
	void SetDocContentIsChanged( BOOL m_bDocContentIsChanged );

	int GetIntPortNumber( void );
	CString GetStringPortNumber( void );
	void SetPortNumber( int	m_nPortNumber );

	//文件属性
	int GetFileAttribute( CString filename, CString &filetime, CString &fileszie );

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQrFileSharingDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CQrFileSharingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQrFileSharingDoc)
	//afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	CString	m_strCurrentDirectory;
	CString	m_strIpAddress;

	CString	m_strInString;
	CString	m_strOutImage;

	CString	m_strDefaultString;
	CString	m_strDefaultOutImage;

	HBITMAP m_DefaultHBitMap;

	//文档内容是否发生了变化
	BOOL m_bDocContentIsChanged;

	int	m_nPortNumber;

	CString	m_strCurrentFile;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QRFILESHARINGDOC_H__E1AF60C9_59E0_41D8_B058_ACC9A2D1ABC3__INCLUDED_)
