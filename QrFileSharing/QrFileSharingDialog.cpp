// QrFileSharingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "QrFileSharing.h"
#include "QrFileSharingDialog.h"

#include "qrencode-3.4.4/bmp.h"

#include "MainFrm.h"
#include "QrFileSharingDoc.h"
#include "QrFileSharingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// QrFileSharingDialog dialog


QrFileSharingDialog::QrFileSharingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(QrFileSharingDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(QrFileSharingDialog)
	m_nFgColor = COLOR_BLACK;
	m_nBgColor = COLOR_WHITE;
	m_nPixel= 0;
	m_nLevel= 0;
	m_EditConvert = _T("");
	m_EditFileName = _T("");
	m_EditFileSize = _T("");
	m_strErrorInfo = _T("");
	m_EditFileTime = _T("");
	//}}AFX_DATA_INIT


}


void QrFileSharingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(QrFileSharingDialog)
	DDX_Control(pDX, IDC_STATIC_BITMAP, m_StaticBitMap);
	DDX_Control(pDX, IDC_COMBO_PIXEL, m_ComboPixel);
	DDX_Control(pDX, IDC_COMBO_LEVEL, m_ComboLevel);
	DDX_Control(pDX, IDC_COMBO_FGCOLOR, m_ComboFgcolor);
	DDX_Control(pDX, IDC_COMBO_BGCOLOR, m_ComboBgColor);
	DDX_Text(pDX, IDC_EDIT_CONVERT, m_EditConvert);
	DDX_Text(pDX, IDC_EDIT_FILEDIRECTORY, m_EditFileTime);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_EditFileName);
	DDX_Text(pDX, IDC_EDIT_FILESIZE, m_EditFileSize);
	//}}AFX_DATA_MAP
	
	//初始化列表的内容
	m_ComboLevel.AddString( "Level_L" );
	m_ComboLevel.AddString( "Level_M" );
	m_ComboLevel.AddString( "Level_Q" );
	m_ComboLevel.AddString( "Level_H" );

	m_ComboPixel.AddString( "1X" );
	m_ComboPixel.AddString( "2X" );
	m_ComboPixel.AddString( "3X" );
	m_ComboPixel.AddString( "4X" );
	m_ComboPixel.AddString( "5X" );
	m_ComboPixel.AddString( "6X" );

	m_ComboFgcolor.AddString( "White" );
	m_ComboFgcolor.AddString( "Red" );
	m_ComboFgcolor.AddString( "Green" );
	m_ComboFgcolor.AddString( "Blue" );
	m_ComboFgcolor.AddString( "Black" );

	m_ComboBgColor.AddString( "White" );
	m_ComboBgColor.AddString( "Red" );
	m_ComboBgColor.AddString( "Green" );
	m_ComboBgColor.AddString( "Blue" );
	m_ComboBgColor.AddString( "Black" );

	//显示默认项
	m_ComboFgcolor.SetCurSel( COLOR_BLACK );
	m_ComboBgColor.SetCurSel( COLOR_WHITE );
	m_ComboPixel.SetCurSel( 0 );
	m_ComboLevel.SetCurSel( 0 );

}


BEGIN_MESSAGE_MAP(QrFileSharingDialog, CDialog)
	//{{AFX_MSG_MAP(QrFileSharingDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_BGCOLOR, OnSelchangeComboBgcolor)
	ON_CBN_SELCHANGE(IDC_COMBO_FGCOLOR, OnSelchangeComboFgcolor)
	ON_CBN_SELCHANGE(IDC_COMBO_LEVEL, OnSelchangeComboLevel)
	ON_CBN_SELCHANGE(IDC_COMBO_PIXEL, OnSelchangeComboPixel)
	ON_BN_CLICKED(ID_BUTTON_RESET, OnButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_CONVERT, OnButtonConvert)
	ON_WM_DROPFILES()
	ON_MESSAGE(WM_USER_FILEOPENED, OnUserFileOpened) 
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// QrFileSharingDialog message handlers

void QrFileSharingDialog::OnSelchangeComboBgcolor() 
{
	// TODO: Add your control notification handler code here

	m_nBgColor = m_ComboBgColor.GetCurSel();
	CString strCBText;
	m_ComboBgColor.GetLBText( m_nBgColor, strCBText );
	if( m_nFgColor == m_nBgColor )
	{
		MessageBox( "不能相同,重新选择" );
		m_nFgColor = COLOR_BLACK;
		m_nBgColor = COLOR_WHITE;
		m_ComboFgcolor.SetCurSel( COLOR_BLACK );
		m_ComboBgColor.SetCurSel( COLOR_WHITE );
	} else {
		UpdateAllViews();	
	}		
}

void QrFileSharingDialog::OnSelchangeComboFgcolor() 
{
	// TODO: Add your control notification handler code here

	m_nFgColor = m_ComboFgcolor.GetCurSel();
	CString strCBText;
	m_ComboFgcolor.GetLBText( m_nFgColor, strCBText );
	if( m_nFgColor == m_nBgColor )
	{
		//采用资源字符串的形式,中英文都有
		MessageBox( "不能相同,重新选择" );
		m_nFgColor = COLOR_BLACK;
		m_nBgColor = COLOR_WHITE;
		m_ComboFgcolor.SetCurSel( COLOR_BLACK );
		m_ComboBgColor.SetCurSel( COLOR_WHITE );
	} else {
		UpdateAllViews();
	}		
}

void QrFileSharingDialog::OnSelchangeComboLevel() 
{
	// TODO: Add your control notification handler code here

	m_nLevel = m_ComboLevel.GetCurSel();
	CString strCBText;
	m_ComboLevel.GetLBText( m_nLevel, strCBText );	
	UpdateAllViews();
}

void QrFileSharingDialog::OnSelchangeComboPixel() 
{
	// TODO: Add your control notification handler code here

	m_nPixel= m_ComboPixel.GetCurSel();
	CString strCBText;
	m_ComboPixel.GetLBText( m_nPixel, strCBText );	
	UpdateAllViews();
}

void QrFileSharingDialog::OnButtonReset() 
{
	// TODO: Add your control notification handler code here
	
	m_nFgColor = COLOR_BLACK;
	m_nBgColor = COLOR_WHITE;
	m_ComboFgcolor.SetCurSel( COLOR_BLACK );
	m_ComboBgColor.SetCurSel( COLOR_WHITE );
	m_ComboPixel.SetCurSel( 0 );
	m_ComboLevel.SetCurSel( 0 );
	
	m_EditConvert = _T("");
	m_EditFileName = _T("");
	m_EditFileSize = _T("");
	m_EditFileTime = _T("");

	( (CEdit*)GetDlgItem(IDC_EDIT_FILEDIRECTORY) )->SetWindowText( m_EditFileTime );
	( (CEdit*)GetDlgItem(IDC_EDIT_FILENAME) )->SetWindowText( m_EditFileName );
	( (CEdit*)GetDlgItem(IDC_EDIT_FILESIZE) )->SetWindowText( m_EditFileSize );
	( (CEdit*)GetDlgItem(IDC_EDIT_CONVERT) )->SetWindowText( m_EditConvert );

	m_StaticBitMap.SetBitmap( NULL );
} 

void QrFileSharingDialog::OnButtonConvert() 
{
	// TODO: Add your control notification handler code here
	
	( (CEdit*)GetDlgItem(IDC_EDIT_CONVERT) )->UpdateData(true);	
	( (CEdit*)GetDlgItem(IDC_EDIT_CONVERT) )->GetWindowText( m_EditConvert );
	//MessageBox( m_EditConvert.GetBuffer(0), NULL, 0);	

	//将数据填充到文档类中
	CQrFileSharingDoc *pDoc = (CQrFileSharingDoc *)( (CQrFileSharingView *)( (CMainFrame *)AfxGetApp()->GetMainWnd() )->GetActiveView() )->GetDocument();
	ASSERT(pDoc);	
	pDoc->SetInString( m_EditConvert );
	pDoc->SetDocContentIsChanged( true );
	pDoc->UpdateAllViews( NULL );

}

//生成图片
int QrFileSharingDialog::GenerateImage( CString instring, CString outimage )
{
	char errorinfo[128];
	//像素值需要在索引的基础上加1,没有0值
	if( writeBMP( instring.GetBuffer(0), outimage.GetBuffer(0), errorinfo, m_nPixel+4, m_nLevel, m_nFgColor, m_nBgColor ) < 0 )
	{
		MessageBox( errorinfo );
		return -1;
	}
	return 0;
}

void QrFileSharingDialog::UpdateAllViews( void )
{
	//自动更新文档视图 
	CQrFileSharingDoc *pDoc = (CQrFileSharingDoc *)( (CQrFileSharingView *)( (CMainFrame *)AfxGetApp()->GetMainWnd() )->GetActiveView() )->GetDocument();
	ASSERT(pDoc);	
	pDoc->SetDocContentIsChanged( true );
	pDoc->UpdateAllViews( NULL );
}

//生成位图句柄
HBITMAP QrFileSharingDialog::GenerateHBitMap( CString inimage )
{
	//动态加载显示位图
	HBITMAP m_HBitMap = (HBITMAP)LoadImage( AfxGetInstanceHandle(), 
			inimage, 
			IMAGE_BITMAP, 
			0, 
			0, 
			LR_LOADFROMFILE ); 
	return m_HBitMap;
}

//显示图片
void QrFileSharingDialog::DisplayImage( HBITMAP hbitmap )
{
	m_StaticBitMap.SetBitmap( hbitmap );
	( (CEdit*)GetDlgItem(IDC_EDIT_FILEDIRECTORY) )->SetWindowText( m_EditFileTime );
	( (CEdit*)GetDlgItem(IDC_EDIT_FILENAME) )->SetWindowText( m_EditFileName );
	( (CEdit*)GetDlgItem(IDC_EDIT_FILESIZE) )->SetWindowText( m_EditFileSize );
//	DeleteObject( hbitmap );
}


void QrFileSharingDialog::OnDropFiles(HDROP hDropInfo) 
{
	// TODO: Add your message handler code here and/or call default
	
	int count;
	count = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	if( count > 0 )
	{        
		for( int i=0; i<count; i++ )
		{
			char filePath[MAX_PATH];
			int pathLen = DragQueryFile(hDropInfo, i, filePath, sizeof(filePath));
			DWORD dwAttr = ::GetFileAttributes( filePath );  //得到文件属性
			if (dwAttr&FILE_ATTRIBUTE_DIRECTORY)  // 如果是目录
			{
				MessageBox( "directory" );
				continue;
			}
			//将数据填充到文档类中
			CQrFileSharingDoc *pDoc = (CQrFileSharingDoc *)( (CQrFileSharingView *)( (CMainFrame *)AfxGetApp()->GetMainWnd() )->GetActiveView() )->GetDocument();
			ASSERT(pDoc);	
			m_EditFileName = filePath;
			pDoc->GetFileAttribute( CString(filePath), m_EditFileTime, m_EditFileSize );
			pDoc->SetInString( pDoc->GetIpAddress()+":"+pDoc->GetStringPortNumber()+"/"+CString(filePath) );
			pDoc->SetDocContentIsChanged( true );
			pDoc->UpdateAllViews( NULL );
			if( (i+1) < count )
			MessageBox( "Next One" );
		}
	}
	DragFinish(hDropInfo);
	CDialog::OnDropFiles(hDropInfo);
}


LRESULT QrFileSharingDialog::OnUserFileOpened(WPARAM wParam, LPARAM lParam)
{
	MessageBox( "OnUserFileOpened" );
	CQrFileSharingDoc *pDoc = (CQrFileSharingDoc *)( (CQrFileSharingView *)( (CMainFrame *)AfxGetApp()->GetMainWnd() )->GetActiveView() )->GetDocument();
	ASSERT(pDoc);	
	m_EditFileName = pDoc->GetCurrentFile();
	pDoc->GetFileAttribute( m_EditFileName, m_EditFileTime, m_EditFileSize );
	return 0;
}

void QrFileSharingDialog::GetFileAttribute()
{
//	MessageBox( "GetFileAttribute" );
	CQrFileSharingDoc *pDoc = (CQrFileSharingDoc *)( (CQrFileSharingView *)( (CMainFrame *)AfxGetApp()->GetMainWnd() )->GetActiveView() )->GetDocument();
	ASSERT(pDoc);	
	m_EditFileName = pDoc->GetCurrentFile();
	pDoc->GetFileAttribute( m_EditFileName, m_EditFileTime, m_EditFileSize );
}
