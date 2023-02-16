# Microsoft Developer Studio Generated NMAKE File, Based on GRP2.DSP
!IF "$(CFG)" == ""
CFG=GRP2 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to GRP2 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "GRP2 - Win32 Release" && "$(CFG)" != "GRP2 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GRP2 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\GRP2.exe"

!ELSE 

ALL : "$(OUTDIR)\GRP2.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\GRP2.obj"
	-@erase "$(INTDIR)\GRP2.pch"
	-@erase "$(INTDIR)\GRP2.res"
	-@erase "$(INTDIR)\GRP2diagrm1.obj"
	-@erase "$(INTDIR)\GRP2diagrm2.obj"
	-@erase "$(INTDIR)\GRP2diagrm3.obj"
	-@erase "$(INTDIR)\GRP2diagrm4.obj"
	-@erase "$(INTDIR)\GRP2diagrm5.obj"
	-@erase "$(INTDIR)\GRP2diagrm6.obj"
	-@erase "$(INTDIR)\GRP2Dlg.obj"
	-@erase "$(INTDIR)\GRP2fn1.obj"
	-@erase "$(INTDIR)\GRP2fn2.obj"
	-@erase "$(INTDIR)\GRP2fn3.obj"
	-@erase "$(INTDIR)\GRP2fn4.obj"
	-@erase "$(INTDIR)\GRP2info.obj"
	-@erase "$(INTDIR)\GRP2Koord.obj"
	-@erase "$(INTDIR)\GRP2param1.obj"
	-@erase "$(INTDIR)\GRP2param2.obj"
	-@erase "$(INTDIR)\GRP2param2Bx.obj"
	-@erase "$(INTDIR)\GRP2param2By.obj"
	-@erase "$(INTDIR)\GRP2param3.obj"
	-@erase "$(INTDIR)\GRP2param4.obj"
	-@erase "$(INTDIR)\GRP2param5.obj"
	-@erase "$(INTDIR)\GRP2prg.obj"
	-@erase "$(INTDIR)\GRP2splash.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\GRP2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\GRP2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\GRP2.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GRP2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\GRP2.pdb" /machine:I386 /out:"$(OUTDIR)\GRP2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\GRP2.obj" \
	"$(INTDIR)\GRP2.res" \
	"$(INTDIR)\GRP2diagrm1.obj" \
	"$(INTDIR)\GRP2diagrm2.obj" \
	"$(INTDIR)\GRP2diagrm3.obj" \
	"$(INTDIR)\GRP2diagrm4.obj" \
	"$(INTDIR)\GRP2diagrm5.obj" \
	"$(INTDIR)\GRP2diagrm6.obj" \
	"$(INTDIR)\GRP2Dlg.obj" \
	"$(INTDIR)\GRP2fn1.obj" \
	"$(INTDIR)\GRP2fn2.obj" \
	"$(INTDIR)\GRP2fn3.obj" \
	"$(INTDIR)\GRP2fn4.obj" \
	"$(INTDIR)\GRP2info.obj" \
	"$(INTDIR)\GRP2Koord.obj" \
	"$(INTDIR)\GRP2param1.obj" \
	"$(INTDIR)\GRP2param2.obj" \
	"$(INTDIR)\GRP2param2Bx.obj" \
	"$(INTDIR)\GRP2param2By.obj" \
	"$(INTDIR)\GRP2param3.obj" \
	"$(INTDIR)\GRP2param4.obj" \
	"$(INTDIR)\GRP2param5.obj" \
	"$(INTDIR)\GRP2prg.obj" \
	"$(INTDIR)\GRP2splash.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\GRP2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\GRP2.exe"

!ELSE 

ALL : "$(OUTDIR)\GRP2.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\GRP2.obj"
	-@erase "$(INTDIR)\GRP2.pch"
	-@erase "$(INTDIR)\GRP2.res"
	-@erase "$(INTDIR)\GRP2diagrm1.obj"
	-@erase "$(INTDIR)\GRP2diagrm2.obj"
	-@erase "$(INTDIR)\GRP2diagrm3.obj"
	-@erase "$(INTDIR)\GRP2diagrm4.obj"
	-@erase "$(INTDIR)\GRP2diagrm5.obj"
	-@erase "$(INTDIR)\GRP2diagrm6.obj"
	-@erase "$(INTDIR)\GRP2Dlg.obj"
	-@erase "$(INTDIR)\GRP2fn1.obj"
	-@erase "$(INTDIR)\GRP2fn2.obj"
	-@erase "$(INTDIR)\GRP2fn3.obj"
	-@erase "$(INTDIR)\GRP2fn4.obj"
	-@erase "$(INTDIR)\GRP2info.obj"
	-@erase "$(INTDIR)\GRP2Koord.obj"
	-@erase "$(INTDIR)\GRP2param1.obj"
	-@erase "$(INTDIR)\GRP2param2.obj"
	-@erase "$(INTDIR)\GRP2param2Bx.obj"
	-@erase "$(INTDIR)\GRP2param2By.obj"
	-@erase "$(INTDIR)\GRP2param3.obj"
	-@erase "$(INTDIR)\GRP2param4.obj"
	-@erase "$(INTDIR)\GRP2param5.obj"
	-@erase "$(INTDIR)\GRP2prg.obj"
	-@erase "$(INTDIR)\GRP2splash.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\GRP2.exe"
	-@erase "$(OUTDIR)\GRP2.ilk"
	-@erase "$(OUTDIR)\GRP2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /w /W0 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /Fp"$(INTDIR)\GRP2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\GRP2.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GRP2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\GRP2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\GRP2.exe"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\GRP2.obj" \
	"$(INTDIR)\GRP2.res" \
	"$(INTDIR)\GRP2diagrm1.obj" \
	"$(INTDIR)\GRP2diagrm2.obj" \
	"$(INTDIR)\GRP2diagrm3.obj" \
	"$(INTDIR)\GRP2diagrm4.obj" \
	"$(INTDIR)\GRP2diagrm5.obj" \
	"$(INTDIR)\GRP2diagrm6.obj" \
	"$(INTDIR)\GRP2Dlg.obj" \
	"$(INTDIR)\GRP2fn1.obj" \
	"$(INTDIR)\GRP2fn2.obj" \
	"$(INTDIR)\GRP2fn3.obj" \
	"$(INTDIR)\GRP2fn4.obj" \
	"$(INTDIR)\GRP2info.obj" \
	"$(INTDIR)\GRP2Koord.obj" \
	"$(INTDIR)\GRP2param1.obj" \
	"$(INTDIR)\GRP2param2.obj" \
	"$(INTDIR)\GRP2param2Bx.obj" \
	"$(INTDIR)\GRP2param2By.obj" \
	"$(INTDIR)\GRP2param3.obj" \
	"$(INTDIR)\GRP2param4.obj" \
	"$(INTDIR)\GRP2param5.obj" \
	"$(INTDIR)\GRP2prg.obj" \
	"$(INTDIR)\GRP2splash.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\GRP2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "GRP2 - Win32 Release" || "$(CFG)" == "GRP2 - Win32 Debug"
SOURCE=.\GRP2.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2_=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2.obj" : $(SOURCE) $(DEP_CPP_GRP2_) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2_=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	

"$(INTDIR)\GRP2.obj" : $(SOURCE) $(DEP_CPP_GRP2_) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2.rc
DEP_RSC_GRP2_R=\
	".\res\bitmap1.bmp"\
	".\res\bitmap_2.bmp"\
	".\res\bitmap_3.bmp"\
	".\res\bitmap_4.bmp"\
	".\res\bitmap_a.bmp"\
	".\res\bitmap_d.bmp"\
	".\res\bitmap_i.bmp"\
	".\res\bitmap_l.bmp"\
	".\res\bitmap_m.bmp"\
	".\res\bitmap_p.bmp"\
	".\res\bitmap_s.bmp"\
	".\res\bmp00001.bmp"\
	".\res\bmp00002.bmp"\
	".\res\bmp00003.bmp"\
	".\res\bmp00004.bmp"\
	".\res\bmp00005.bmp"\
	".\res\bmp00006.bmp"\
	".\res\bmp00007.bmp"\
	".\res\bmp00008.bmp"\
	".\res\bmp00009.bmp"\
	".\res\bmp00010.bmp"\
	".\res\bmp00011.bmp"\
	".\res\bmp00012.bmp"\
	".\res\bmp00013.bmp"\
	".\res\bmp00014.bmp"\
	".\res\bmp00015.bmp"\
	".\res\bmp00016.bmp"\
	".\res\bmp00017.bmp"\
	".\res\cursor1.cur"\
	".\res\cursor2.cur"\
	".\res\cursor3.cur"\
	".\res\GRP2.ico"\
	".\res\GRP2.rc2"\
	".\res\ico00001.ico"\
	".\res\ico00002.ico"\
	".\res\ico00003.ico"\
	".\res\icon1.ico"\
	".\res\icon_ax_.ico"\
	

"$(INTDIR)\GRP2.res" : $(SOURCE) $(DEP_RSC_GRP2_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\GRP2diagrm1.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2D=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2diagrm1.obj" : $(SOURCE) $(DEP_CPP_GRP2D) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2D=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	

"$(INTDIR)\GRP2diagrm1.obj" : $(SOURCE) $(DEP_CPP_GRP2D) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2diagrm2.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2DI=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2diagrm2.obj" : $(SOURCE) $(DEP_CPP_GRP2DI) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2DI=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	

"$(INTDIR)\GRP2diagrm2.obj" : $(SOURCE) $(DEP_CPP_GRP2DI) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2diagrm3.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2DIA=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2diagrm3.obj" : $(SOURCE) $(DEP_CPP_GRP2DIA) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2DIA=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	

"$(INTDIR)\GRP2diagrm3.obj" : $(SOURCE) $(DEP_CPP_GRP2DIA) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2diagrm4.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2DIAG=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2diagrm4.obj" : $(SOURCE) $(DEP_CPP_GRP2DIAG) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2DIAG=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	

"$(INTDIR)\GRP2diagrm4.obj" : $(SOURCE) $(DEP_CPP_GRP2DIAG) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2diagrm5.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2DIAGR=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2diagrm5.obj" : $(SOURCE) $(DEP_CPP_GRP2DIAGR) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2DIAGR=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	

"$(INTDIR)\GRP2diagrm5.obj" : $(SOURCE) $(DEP_CPP_GRP2DIAGR) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2diagrm6.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2DIAGRM=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2diagrm6.obj" : $(SOURCE) $(DEP_CPP_GRP2DIAGRM) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2DIAGRM=\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	

"$(INTDIR)\GRP2diagrm6.obj" : $(SOURCE) $(DEP_CPP_GRP2DIAGRM) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2Dlg.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2DL=\
	"..\..\__H_C++_\DATACONV.HPP"\
	"..\..\__H_C_\FN_PQ.h"\
	"..\..\__H_C_\FN_SORT.H"\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	".\GRP2info.hpp"\
	".\GRP2koord.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	".\GRP2prg.hpp"\
	".\GRP2splash.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2Dlg.obj" : $(SOURCE) $(DEP_CPP_GRP2DL) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2DL=\
	"..\..\__H_C++_\DATACONV.HPP"\
	"..\..\__H_C_\FN_PQ.h"\
	"..\..\__H_C_\FN_SORT.H"\
	".\GRP2.hpp"\
	".\GRP2diagrm1.hpp"\
	".\GRP2diagrm2.hpp"\
	".\GRP2diagrm3.hpp"\
	".\GRP2diagrm4.hpp"\
	".\GRP2diagrm5.hpp"\
	".\GRP2diagrm6.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	".\GRP2info.hpp"\
	".\GRP2koord.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	".\GRP2prg.hpp"\
	".\GRP2splash.hpp"\
	

"$(INTDIR)\GRP2Dlg.obj" : $(SOURCE) $(DEP_CPP_GRP2DL) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2fn1.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2F=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2fn1.obj" : $(SOURCE) $(DEP_CPP_GRP2F) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2F=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	

"$(INTDIR)\GRP2fn1.obj" : $(SOURCE) $(DEP_CPP_GRP2F) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2fn2.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2FN=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2fn2.obj" : $(SOURCE) $(DEP_CPP_GRP2FN) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2FN=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	

"$(INTDIR)\GRP2fn2.obj" : $(SOURCE) $(DEP_CPP_GRP2FN) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2fn3.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2FN3=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2fn3.obj" : $(SOURCE) $(DEP_CPP_GRP2FN3) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2FN3=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	

"$(INTDIR)\GRP2fn3.obj" : $(SOURCE) $(DEP_CPP_GRP2FN3) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2fn4.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2FN4=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2fn4.obj" : $(SOURCE) $(DEP_CPP_GRP2FN4) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2FN4=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2fn1.hpp"\
	".\GRP2fn2.hpp"\
	".\GRP2fn3.hpp"\
	".\GRP2fn4.hpp"\
	

"$(INTDIR)\GRP2fn4.obj" : $(SOURCE) $(DEP_CPP_GRP2FN4) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2info.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2I=\
	".\GRP2.hpp"\
	".\GRP2info.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2info.obj" : $(SOURCE) $(DEP_CPP_GRP2I) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2I=\
	".\GRP2.hpp"\
	".\GRP2info.hpp"\
	

"$(INTDIR)\GRP2info.obj" : $(SOURCE) $(DEP_CPP_GRP2I) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2Koord.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2K=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2koord.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2Koord.obj" : $(SOURCE) $(DEP_CPP_GRP2K) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2K=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2koord.hpp"\
	

"$(INTDIR)\GRP2Koord.obj" : $(SOURCE) $(DEP_CPP_GRP2K) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2param1.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2P=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2param1.obj" : $(SOURCE) $(DEP_CPP_GRP2P) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2P=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	

"$(INTDIR)\GRP2param1.obj" : $(SOURCE) $(DEP_CPP_GRP2P) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2param2.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2PA=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param2Bx.hpp"\
	".\GRP2param2By.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2param2.obj" : $(SOURCE) $(DEP_CPP_GRP2PA) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2PA=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param2Bx.hpp"\
	".\GRP2param2By.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	

"$(INTDIR)\GRP2param2.obj" : $(SOURCE) $(DEP_CPP_GRP2PA) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2param2Bx.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2PAR=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param2Bx.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2param2Bx.obj" : $(SOURCE) $(DEP_CPP_GRP2PAR) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2PAR=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param2Bx.hpp"\
	

"$(INTDIR)\GRP2param2Bx.obj" : $(SOURCE) $(DEP_CPP_GRP2PAR) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2param2By.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2PARA=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param2By.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2param2By.obj" : $(SOURCE) $(DEP_CPP_GRP2PARA) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2PARA=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param2By.hpp"\
	

"$(INTDIR)\GRP2param2By.obj" : $(SOURCE) $(DEP_CPP_GRP2PARA) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2param3.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2PARAM=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2param3.obj" : $(SOURCE) $(DEP_CPP_GRP2PARAM) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2PARAM=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	

"$(INTDIR)\GRP2param3.obj" : $(SOURCE) $(DEP_CPP_GRP2PARAM) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2param4.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2PARAM4=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2param4.obj" : $(SOURCE) $(DEP_CPP_GRP2PARAM4) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2PARAM4=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	

"$(INTDIR)\GRP2param4.obj" : $(SOURCE) $(DEP_CPP_GRP2PARAM4) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2param5.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2PARAM5=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2param5.obj" : $(SOURCE) $(DEP_CPP_GRP2PARAM5) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2PARAM5=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2param1.hpp"\
	".\GRP2param2.hpp"\
	".\GRP2param3.hpp"\
	".\GRP2param4.hpp"\
	".\GRP2param5.hpp"\
	

"$(INTDIR)\GRP2param5.obj" : $(SOURCE) $(DEP_CPP_GRP2PARAM5) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2prg.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2PR=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2prg.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2prg.obj" : $(SOURCE) $(DEP_CPP_GRP2PR) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2PR=\
	".\GRP2.hpp"\
	".\GRP2Dlg.hpp"\
	".\GRP2prg.hpp"\
	

"$(INTDIR)\GRP2prg.obj" : $(SOURCE) $(DEP_CPP_GRP2PR) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\GRP2splash.cpp

!IF  "$(CFG)" == "GRP2 - Win32 Release"

DEP_CPP_GRP2S=\
	".\GRP2.hpp"\
	".\GRP2splash.hpp"\
	".\StdAfx.h"\
	

"$(INTDIR)\GRP2splash.obj" : $(SOURCE) $(DEP_CPP_GRP2S) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

DEP_CPP_GRP2S=\
	".\GRP2.hpp"\
	".\GRP2splash.hpp"\
	

"$(INTDIR)\GRP2splash.obj" : $(SOURCE) $(DEP_CPP_GRP2S) "$(INTDIR)"\
 "$(INTDIR)\GRP2.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "GRP2 - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\GRP2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GRP2.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GRP2 - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /w /W0 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /Fp"$(INTDIR)\GRP2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GRP2.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

