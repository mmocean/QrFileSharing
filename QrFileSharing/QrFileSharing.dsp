# Microsoft Developer Studio Project File - Name="QrFileSharing" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=QrFileSharing - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "QrFileSharing.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QrFileSharing.mak" CFG="QrFileSharing - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QrFileSharing - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "QrFileSharing - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "QrFileSharing - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "QrFileSharing - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "QrFileSharing - Win32 Release"
# Name "QrFileSharing - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\QrFileSharing.cpp
# End Source File
# Begin Source File

SOURCE=.\QrFileSharing.rc
# End Source File
# Begin Source File

SOURCE=.\QrFileSharingDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\QrFileSharingDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\QrFileSharingView.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\QrFileSharing.h
# End Source File
# Begin Source File

SOURCE=.\QrFileSharingDialog.h
# End Source File
# Begin Source File

SOURCE=.\QrFileSharingDoc.h
# End Source File
# Begin Source File

SOURCE=.\QrFileSharingView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\QrFileSharing.ico
# End Source File
# Begin Source File

SOURCE=.\res\QrFileSharing.rc2
# End Source File
# Begin Source File

SOURCE=.\res\QrFileSharingDoc.ico
# End Source File
# End Group
# Begin Group "qrencode-3.4.4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\qrencode-3.4.4\bitstream.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\bitstream.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\bmp.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\config.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\mask.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\mask.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\mmask.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\mmask.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\mqrspec.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\mqrspec.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrenc.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrencode.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrencode.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrencode_inner.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrinput.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrinput.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrspec.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\qrspec.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\rscode.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\rscode.h"
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\split.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\qrencode-3.4.4\split.h"
# End Source File
# End Group
# Begin Group "shttpd-1.38"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\shttpd-1.38\auth.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\cgi.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\compat_win32.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\compat_win32.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\config.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\defs.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io_cgi.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io_dir.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io_emb.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io_file.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io_socket.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io_ssi.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\io_ssl.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\llist.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\log.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\md5.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\md5.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\mime_type.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\shttpd.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\shttpd.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\ssl.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\standalone.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\std_includes.h"
# End Source File
# Begin Source File

SOURCE=".\shttpd-1.38\string.c"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
