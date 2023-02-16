# Microsoft Developer Studio Project File - Name="GRP2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GRP2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GRP2.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GRP2.MAK" CFG="GRP2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GRP2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GRP2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GRP2 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x407 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MTd /w /W0 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GRP2 - Win32 Release"
# Name "GRP2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\GRP2.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2.rc
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm1.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm2.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm3.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm4.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm5.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm6.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn1.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn2.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn3.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn4.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2info.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2Koord.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param1.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param2.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param2Bx.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param2By.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param3.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param4.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param5.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2prg.cpp
# End Source File
# Begin Source File

SOURCE=.\GRP2splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\..\__H_C++_\DATACONV.HPP"
# End Source File
# Begin Source File

SOURCE=..\..\__H_C_\FN_PQ.h
# End Source File
# Begin Source File

SOURCE=..\..\__H_C_\FN_SORT.H
# End Source File
# Begin Source File

SOURCE=.\GRP2.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm1.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm2.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm3.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm4.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm5.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2diagrm6.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2Dlg.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn1.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn2.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn3.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2fn4.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2info.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2koord.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param1.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param2.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param2Bx.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param2By.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param3.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param4.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2param5.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2prg.hpp
# End Source File
# Begin Source File

SOURCE=.\GRP2splash.hpp
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_a.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_d.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_i.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_l.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_m.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_s.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00009.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00011.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00012.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00013.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00014.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00015.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00016.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00017.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor3.cur
# End Source File
# Begin Source File

SOURCE=.\res\GRP2.ico
# End Source File
# Begin Source File

SOURCE=.\res\GRP2.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon_ax_.ico
# End Source File
# End Group
# End Target
# End Project
