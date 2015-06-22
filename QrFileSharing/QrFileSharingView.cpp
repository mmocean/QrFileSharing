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
		m_qfsd.Create( IDD_DIALOG_QRFILESHARING, this );//ֻ�ܴ���һ��
		/*
		DS_MODALFRAME ��ģ̬�Ի���
		WS_POPUP�ǵ���ʽ��
		WS_CAPTION���б�����
		WS_VISIBLE�ǿɼ���				
		WS_CHILD������һ���Ӵ��ڡ�����������WS_POPUP�����á�
		*/
		m_qfsd.ModifyStyle(WS_CAPTION|WS_CHILD, 0);	

		if( NULL == pDoc->GetDefaultHBitMap() )
		{
			//����Ĭ��ͼƬ
			CString out = pDoc->GetCurrentDirectory() + "\.bmp";
			if( m_qfsd.GenerateImage( pDoc->GetDefaultString(), out ) < 0 )
			{
				MessageBox( "GenerateImage error" );		
			}
			pDoc->SetDefaultHBitMap( m_qfsd.GenerateHBitMap(out) );	
			//��ʾ
			m_qfsd.DisplayImage( pDoc->GetDefaultHBitMap() );			
		} 
	}

	//�Ӵ��ں͸����ڵȴ�ͬʱ�仯
	CRect rect;
	this->GetWindowRect(&rect);//��ȡ�����ڴ�С
	m_qfsd.MoveWindow(rect);//�Ӵ��ڸı��С

	//��ģ̬�Ĵ�����Ҫ��ʽ����
	m_qfsd.ShowWindow(SW_SHOW);//��ʾ����
	
	/*
	MessageBox(  pDoc->GetCurrentDirectory().GetBuffer(0) );
	MessageBox(  pDoc->GetIpAddress().GetBuffer(0) );
	MessageBox(  pDoc->GetInString().GetBuffer(0) );
	MessageBox(  pDoc->GetOutImage().GetBuffer(0) );		
	*/

//	MessageBox( "CQrFileSharingView::OnDraw" );

	//�ж��ĵ������Ƿ����˱仯
	if( pDoc->GetDocContentIsChanged() )
	{
		//���Զ�����Ϣ
	//	::PostMessage( m_qfsd.GetSafeHwnd(), WM_USER_FILEOPENED, 0, 0 );

	//	MessageBox( "pDoc->GetDocContentIsChanged()" );

		//Ŀ���ַ�����Ϊ��
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

			//�ļ�����
			m_qfsd.GetFileAttribute();
			
			//��ʾ
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
	
	// ���ù�����   
	char szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");   
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, NULL);    

	// ��ʾ���ļ��Ի���   
	if( IDOK == fileDlg.DoModal() )   
	{   
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		m_filename = fileDlg.GetPathName();  
		MessageBox( m_filename.GetBuffer(0) );
	}   
	
}
