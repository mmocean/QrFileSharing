// QrFileSharingDoc.cpp : implementation of the CQrFileSharingDoc class
//

#include "stdafx.h"
#include "QrFileSharing.h"

#include "QrFileSharingDoc.h"

#include<winsock2.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingDoc

IMPLEMENT_DYNCREATE(CQrFileSharingDoc, CDocument)

BEGIN_MESSAGE_MAP(CQrFileSharingDoc, CDocument)
	//{{AFX_MSG_MAP(CQrFileSharingDoc)
//	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingDoc construction/destruction

CQrFileSharingDoc::CQrFileSharingDoc()
{
	// TODO: add one-time construction code here

	m_strInString = _T("");
	m_strOutImage = _T("");
	m_strDefaultString = _T("https://github.com/mmocean/QrFileSharing");
	m_DefaultHBitMap = NULL;
	m_bDocContentIsChanged= false;
	m_nPortNumber = 12306;
	m_strCurrentFile = _T("");
}

CQrFileSharingDoc::~CQrFileSharingDoc()
{
	DeleteObject(m_DefaultHBitMap);
}

BOOL CQrFileSharingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingDoc serialization

void CQrFileSharingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingDoc diagnostics

#ifdef _DEBUG
void CQrFileSharingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CQrFileSharingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingDoc commands

CString CQrFileSharingDoc::GetCurrentDirectory( void )
{
	//获取当前目录
	char szBuffer[MAX_PATH+1];
	memset( szBuffer, 0, sizeof(szBuffer) );
	::GetCurrentDirectory( sizeof(szBuffer), szBuffer );	
	m_strCurrentDirectory = szBuffer;

	return m_strCurrentDirectory;
}

CString CQrFileSharingDoc::GetIpAddress( void )
{
	char szHostName[MAX_PATH+1];
	memset( szHostName, 0, sizeof(szHostName) );
	gethostname( szHostName, sizeof(szHostName) );  //得到计算机名
	hostent *p = gethostbyname( szHostName ); //从计算机名得到主机信息
	if( !p )
	{
		AfxMessageBox("gethostbyname error!");
		exit( -1 );
	}
	
	//将32位IP转化为字符串IP
	char *pIP = inet_ntoa(*(in_addr *)p->h_addr_list[0]);
	if( !pIP )
	{
		AfxMessageBox("inet_ntoa error!");
		exit( -1 );	         
	} else {
		m_strIpAddress = pIP;  
	}

//	AfxMessageBox( m_strIpAddress.GetBuffer(0) );

	return m_strIpAddress;
}


CString CQrFileSharingDoc::GetCurrentFile( void )
{
	return m_strCurrentFile;
}


CString CQrFileSharingDoc::GetInString( void )
{
	return m_strInString;
}
void CQrFileSharingDoc::SetInString( CString m_strInString )
{
	this->m_strInString = m_strInString;
}


CString CQrFileSharingDoc::GetOutImage( void )
{
	return m_strOutImage;
}
void CQrFileSharingDoc::SetOutImage( CString m_strOutImage )
{
	this->m_strOutImage = m_strOutImage;
}


CString CQrFileSharingDoc::GetDefaultString( void )
{
	return m_strDefaultString;
}
void CQrFileSharingDoc::SetDefaultString( CString m_strDefaultString )
{
	this->m_strDefaultString = m_strDefaultString;
}


CString CQrFileSharingDoc::GetDefaultOutImage( void )
{
	return m_strDefaultOutImage;
}
void CQrFileSharingDoc::SetDefaultOutImage( CString m_strDefaultOutImage )
{
	this->m_strDefaultOutImage = m_strDefaultOutImage;  
}


HBITMAP CQrFileSharingDoc::GetDefaultHBitMap( void )
{
	return m_DefaultHBitMap;
}
void CQrFileSharingDoc::SetDefaultHBitMap( HBITMAP m_DefaultHBitMap )
{
	this->m_DefaultHBitMap = m_DefaultHBitMap;
}


BOOL CQrFileSharingDoc::GetDocContentIsChanged( void )
{
	return m_bDocContentIsChanged;
}
void CQrFileSharingDoc::SetDocContentIsChanged( BOOL m_bDocContentIsChanged )
{
	this->m_bDocContentIsChanged = m_bDocContentIsChanged;
}


int CQrFileSharingDoc::GetIntPortNumber( void )
{
	return m_nPortNumber;
}
CString CQrFileSharingDoc::GetStringPortNumber( void )
{
	CString portnumber;
	portnumber.Format( "%d", m_nPortNumber);
	return portnumber;
}
void CQrFileSharingDoc::SetPortNumber( int m_nPortNumber )
{
	this->m_nPortNumber = m_nPortNumber;
}


//文件属性
int CQrFileSharingDoc::GetFileAttribute( CString filename, CString &filetime, CString &fileszie )
{
	//文件大小
	CFileStatus fileStatus;  
	if( CFile::GetStatus( filename, fileStatus ) )  
	{  
		fileszie.Format( "%0.2f MB", fileStatus.m_size*1.0/1048576 );  
		//文件修改时间
		filetime = fileStatus.m_mtime.Format("%Y-%m-%d %H:%M:%S");
	}  
	return 0;
}

/*
void CQrFileSharingDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	// 设置过滤器   
	char szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");   
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, NULL);    

	// 显示打开文件对话框   
	if( IDOK == fileDlg.DoModal() )   
	{   
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		m_strCurrentFile = fileDlg.GetPathName();  
	//	MessageBox( NULL,m_strCurrentFile.GetBuffer(0), NULL, 0);

		m_strInString = GetIpAddress()+":"+GetStringPortNumber()+"/"+m_strCurrentFile;		
		m_bDocContentIsChanged = true;
	
		//这个函数可用实现文档更新然后通知视图
		UpdateAllViews( NULL );
	}   
}
*/
