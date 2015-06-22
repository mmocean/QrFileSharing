; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQrFileSharingDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QrFileSharing.h"
LastPage=0

ClassCount=6
Class1=CQrFileSharingApp
Class2=CQrFileSharingDoc
Class3=CQrFileSharingView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX (English (U.S.))
Resource4=IDR_MAINFRAME (English (U.S.))
Class6=QrFileSharingDialog
Resource5=IDD_DIALOG_QRFILESHARING (English (U.S.))

[CLS:CQrFileSharingApp]
Type=0
HeaderFile=QrFileSharing.h
ImplementationFile=QrFileSharing.cpp
Filter=N
LastObject=CQrFileSharingApp

[CLS:CQrFileSharingDoc]
Type=0
HeaderFile=QrFileSharingDoc.h
ImplementationFile=QrFileSharingDoc.cpp
Filter=N
LastObject=CQrFileSharingDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CQrFileSharingView]
Type=0
HeaderFile=QrFileSharingView.h
ImplementationFile=QrFileSharingView.cpp
Filter=C
LastObject=ID_FILE_OPEN
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_FILE_NEW




[CLS:CAboutDlg]
Type=0
HeaderFile=QrFileSharing.cpp
ImplementationFile=QrFileSharing.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_DIALOG_QRFILESHARING (English (U.S.))]
Type=1
Class=QrFileSharingDialog
ControlCount=20
Control1=ID_BUTTON_RESET,button,1342242816
Control2=IDC_STATIC_FILETIME,static,1342308352
Control3=IDC_STATIC_FILENAME,static,1342308352
Control4=IDC_STATIC_FILESIZE,static,1342308352
Control5=IDC_EDIT_FILETIME,edit,1350633600
Control6=IDC_EDIT_FILENAME,edit,1350633600
Control7=IDC_EDIT_FILESIZE,edit,1350633600
Control8=IDC_BUTTON_PREV,button,1342242816
Control9=IDC_BUTTON_NEXT,button,1342242816
Control10=IDC_COMBO_PIXEL,combobox,1344340226
Control11=IDC_STATIC_PIXEL,static,1342308352
Control12=IDC_STATIC_LEVEL,static,1342308352
Control13=IDC_STATIC_FGCOLOR,static,1342308352
Control14=IDC_STATIC_BGCOLOR,static,1342308352
Control15=IDC_COMBO_LEVEL,combobox,1344340226
Control16=IDC_COMBO_FGCOLOR,combobox,1344340226
Control17=IDC_COMBO_BGCOLOR,combobox,1344340226
Control18=IDC_STATIC_BITMAP,static,1342177294
Control19=IDC_BUTTON_CONVERT,button,1342242816
Control20=IDC_EDIT_CONVERT,edit,1352728580

[CLS:QrFileSharingDialog]
Type=0
HeaderFile=QrFileSharingDialog.h
ImplementationFile=QrFileSharingDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

