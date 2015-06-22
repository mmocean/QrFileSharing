// QrFileSharingView.cpp : implementation of the CQrFileSharingView class
//

#include "stdafx.h"
#include "QrFileSharing.h"

#include "QrFileSharingDoc.h"
#include "QrFileSharingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingView

IMPLEMENT_DYNCREATE(CQrFileSharingView, CView)

BEGIN_MESSAGE_MAP(CQrFileSharingView, CView)
	//{{AFX_MSG_MAP(CQrFileSharingView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingView construction/destruction

CQrFileSharingView::CQrFileSharingView()
{
	// TODO: add construction code here

}

CQrFileSharingView::~CQrFileSharingView()
{
}

BOOL CQrFileSharingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingView drawing

void CQrFileSharingView::OnDraw(CDC* pDC)
{
	CQrFileSharingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	//new-added
	if( NULL == m_qfsd.GetSafeHwnd() )
	{	
		m_qfsd.Create( IDD_DIALOG_QRFILESHARING, this );//只能创建一次
		/*
		DS_MODALFRAME 是模态对话框
		WS_POPUP是弹出式的
		WS_CAPTION是有标题栏
		WS_VISIBLE是可见的				
		WS_CHILD：创建一个子窗口。这个风格不能与WS_POPUP风格合用。
		*/
		m_qfsd.ModifyStyle(WS_CAPTION|WS_CHILD, 0);	

		if( NULL == pDoc->GetDefaultHBitMap() )
		{
			//生成默认图片
			CString out = pDoc->GetCurrentDirectory() + "\.bmp";
			if( m_qfsd.GenerateImage( pDoc->GetDefaultString(), out ) < 0 )
			{
				MessageBox( "GenerateImage error" );		
			}
			pDoc->SetDefaultHBitMap( m_qfsd.GenerateHBitMap(out) );	
			//显示
			m_qfsd.DisplayImage( pDoc->GetDefaultHBitMap() );			
		} 
	}

	//子窗口和父窗口等大同时变化
	CRect rect;
	this->GetWindowRect(&rect);//获取父窗口大小
	m_qfsd.MoveWindow(rect);//子窗口改变大小

	//非模态的窗口需要显式调用
	m_qfsd.ShowWindow(SW_SHOW);//显示窗口
	
	/*
	MessageBox(  pDoc->GetCurrentDirectory().GetBuffer(0) );
	MessageBox(  pDoc->GetIpAddress().GetBuffer(0) );
	MessageBox(  pDoc->GetInString().GetBuffer(0) );
	MessageBox(  pDoc->GetOutImage().GetBuffer(0) );		
	*/

//	MessageBox( "CQrFileSharingView::OnDraw" );

	//判断文档内容是否发生了变化
	if( pDoc->GetDocContentIsChanged() )
	{
		//发自定义消息
	//	::PostMessage( m_qfsd.GetSafeHwnd(), WM_USER_FILEOPENED, 0, 0 );

	//	MessageBox( "pDoc->GetDocContentIsChanged()" );

		//目标字符串不为空
		if( !pDoc->GetInString().IsEmpty() )
		{
	//		MessageBox( "!pDoc->GetInString().IsEmpty()" );

			CString out = pDoc->GetCurrentDirectory() + "\.bmp";

			if( m_qfsd.GenerateImage( pDoc->GetInString(), out ) < 0 )
			{
				MessageBox( "GenerateImage error" );		
			} else {
				pDoc->SetOutImage( out );
			}

			//文件属性
			m_qfsd.GetFileAttribute();
			
			//显示
			m_qfsd.DisplayImage( m_qfsd.GenerateHBitMap(out) );
		} 
		pDoc->SetDocContentIsChanged( false );
	} 
}

/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingView diagnostics

#ifdef _DEBUG
void CQrFileSharingView::AssertValid() const
{
	CView::AssertValid();
}

void CQrFileSharingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQrFileSharingDoc* CQrFileSharingView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQrFileSharingDoc)));
	return (CQrFileSharingDoc*)m_pDocument;
}
#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////
// CQrFileSharingView message handlers

void CQrFileSharingView::OnFileOpen() 
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
		m_filename = fileDlg.GetPathName();  
		MessageBox( m_filename.GetBuffer(0) );
	}   
	
}
