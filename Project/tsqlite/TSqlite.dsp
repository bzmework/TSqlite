# Microsoft Developer Studio Project File - Name="TSqlite" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=TSqlite - Win32 Debug No Unacc
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TSqlite.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TSqlite.mak" CFG="TSqlite - Win32 Debug No Unacc"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TSqlite - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TSqlite - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TSqlite - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TSqlite - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TSqlite - Win32 Release No Unacc" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TSqlite - Win32 Debug No Unacc" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TSqlite - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "..\inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /D "HAVE_I8" /D "_ATL_DEBUG_INTERFACES" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD MTL /nologo /no_robust /win32 /version_stamp
# ADD BASE RSC /l 0x415 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 sqlite3d.lib unaccd.lib advapi32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"Debug/TSqlited.dll" /implib:"../libdll/sqlite3d.lib" /pdbtype:sept /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\TSqlited.dll
InputPath=.\Debug\TSqlited.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "..\inc" /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /D "UNICODE" /D "HAVE_I8" /D "_ATL_DEBUG_INTERFACES" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD MTL /nologo /D "UNICODE" /D _WIN32_WINNT=0x0400 /no_robust /win32 /version_stamp
# ADD BASE RSC /l 0x415 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 advapi32.lib sqlite3d.lib unaccd.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"DebugU/sqlite3du.dll" /implib:"../libdll/sqlite3du.lib" /pdbtype:sept /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=.\DebugU\sqlite3du.dll
InputPath=.\DebugU\sqlite3du.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "TSqlite___Win32_Release"
# PROP BASE Intermediate_Dir "TSqlite___Win32_Release"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G6 /MT /W3 /Ot /Og /Oi /Ob2 /I "..\inc" /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G6 /MT /W3 /Ot /Og /Oi /Ob2 /I "..\inc" /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /no_robust /win32
# ADD MTL /nologo /D _WIN32_WINNT=0x0400 /no_robust /win32 /version_stamp
# ADD BASE RSC /l 0x415 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 sqlite3.lib unacc.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"ReleaseMinDependency/sqlite3.dll" /libpath:"..\lib"
# ADD LINK32 sqlite3.lib advapi32.lib unacc.lib /nologo /subsystem:windows /dll /machine:I386 /implib:"../libdll/sqlite3.lib" /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\Release
TargetPath=.\Release\TSqlite.dll
InputPath=.\Release\TSqlite.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "TSqlite___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "TSqlite___Win32_Unicode_Release"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseU"
# PROP Intermediate_Dir "ReleaseU"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G6 /MT /W3 /Ot /Og /Oi /I "..\inc" /D "NDEBUG" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /D "UNICODE" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G6 /MT /W3 /Ot /Og /Oi /Ob2 /I "..\inc" /D "NDEBUG" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /D "UNICODE" /D "HAVE_I8" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /D "UNICODE" /no_robust /win32
# ADD MTL /nologo /D "UNICODE" /D _WIN32_WINNT=0x0400 /no_robust /win32 /version_stamp
# ADD BASE RSC /l 0x415 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 sqlite3.lib unacc.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"ReleaseUMinDependency/sqlite3u.dll" /libpath:"..\lib"
# ADD LINK32 advapi32.lib sqlite3.lib unacc.lib /nologo /subsystem:windows /dll /machine:I386 /out:"ReleaseU/sqlite3u.dll" /implib:"../libdll/sqlite3u.lib" /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\ReleaseU
TargetPath=.\ReleaseU\sqlite3u.dll
InputPath=.\ReleaseU\sqlite3u.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release No Unacc"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "TSqlite___Win32_Release_No_Unacc"
# PROP BASE Intermediate_Dir "TSqlite___Win32_Release_No_Unacc"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseNoUnacc"
# PROP Intermediate_Dir "ReleaseNoUnacc"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G6 /MT /W3 /Ot /Og /Oi /Ob2 /I "..\inc" /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G6 /MT /W3 /Ot /Og /Oi /Ob2 /I "..\inc" /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /D "_NO_UNACC_STUFF" /D "HAVE_I8" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /no_robust /win32
# ADD MTL /nologo /D _WIN32_WINNT=0x0400 /no_robust /win32 /version_stamp
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 sqlite3.lib unacc.lib kernel32.lib advapi32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"Release/sqlite3.dll" /libpath:"..\lib"
# ADD LINK32 sqlite3.lib unacc.lib kernel32.lib advapi32.lib /nologo /subsystem:windows /dll /pdb:"../libdll/sqlite3.pdb" /machine:I386 /out:"ReleaseNoUnacc/sqlite3.dll" /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\ReleaseNoUnacc
TargetPath=.\ReleaseNoUnacc\sqlite3.dll
InputPath=.\ReleaseNoUnacc\sqlite3.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Debug No Unacc"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "TSqlite___Win32_Debug_No_Unacc"
# PROP BASE Intermediate_Dir "TSqlite___Win32_Debug_No_Unacc"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugNoUnacc"
# PROP Intermediate_Dir "DebugNoUnacc"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /I "..\inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "..\inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_MERGE_PROXYSTUB" /D "_NO_UNACC_STUFF" /D "HAVE_I8" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /no_robust /win32
# ADD MTL /nologo /D _WIN32_WINNT=0x0400 /no_robust /win32 /version_stamp
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 sqlite3d.lib unaccd.lib kernel32.lib advapi32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"Debug/sqlite3d.dll" /pdbtype:sept /libpath:"..\lib"
# ADD LINK32 sqlite3d.lib unaccd.lib kernel32.lib advapi32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"DebugNoUnacc/sqlite3d.dll" /implib:"../libdll/sqlite3d.lib" /pdbtype:sept /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\DebugNoUnacc
TargetPath=.\DebugNoUnacc\sqlite3d.dll
InputPath=.\DebugNoUnacc\sqlite3d.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "TSqlite - Win32 Debug"
# Name "TSqlite - Win32 Unicode Debug"
# Name "TSqlite - Win32 Release"
# Name "TSqlite - Win32 Unicode Release"
# Name "TSqlite - Win32 Release No Unacc"
# Name "TSqlite - Win32 Debug No Unacc"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BlobFn.c
# End Source File
# Begin Source File

SOURCE=.\Column.cpp
# End Source File
# Begin Source File

SOURCE=.\Columns.cpp
# End Source File
# Begin Source File

SOURCE=.\Connection.cpp
# End Source File
# Begin Source File

SOURCE=.\dlldatax.c
# PROP Exclude_From_Scan -1

!IF  "$(CFG)" == "TSqlite - Win32 Debug"

# PROP BASE Exclude_From_Build 1
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Debug"

# PROP BASE Exclude_From_Build 1
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Release"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release No Unacc"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Debug No Unacc"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Glob.cpp
# End Source File
# Begin Source File

SOURCE=.\Messages.mc

!IF  "$(CFG)" == "TSqlite - Win32 Debug"

# Begin Custom Build - Compiling $(InputPath)
InputDir=.
InputPath=.\Messages.mc
InputName=Messages

BuildCmds= \
	mc $(InputPath)

"$(InputDir)\$(InputName).rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Debug"

# Begin Custom Build - Compiling $(InputPath)
InputDir=.
InputPath=.\Messages.mc
InputName=Messages

BuildCmds= \
	mc $(InputPath)

"$(InputDir)\$(InputName).rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release"

# Begin Custom Build - Compiling $(InputPath)
InputDir=.
InputPath=.\Messages.mc
InputName=Messages

BuildCmds= \
	mc $(InputPath)

"$(InputDir)\$(InputName).rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Release"

# Begin Custom Build - Compiling $(InputPath)
InputDir=.
InputPath=.\Messages.mc
InputName=Messages

BuildCmds= \
	mc $(InputPath)

"$(InputDir)\$(InputName).rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release No Unacc"

# Begin Custom Build - Compiling $(InputPath)
InputDir=.
InputPath=.\Messages.mc
InputName=Messages

BuildCmds= \
	mc $(InputPath)

"$(InputDir)\$(InputName).rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Debug No Unacc"

# Begin Custom Build - Compiling $(InputPath)
InputDir=.
InputPath=.\Messages.mc
InputName=Messages

BuildCmds= \
	mc $(InputPath)

"$(InputDir)\$(InputName).rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Messages.rc
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Parameter.cpp
# End Source File
# Begin Source File

SOURCE=.\Parameters.cpp
# End Source File
# Begin Source File

SOURCE=.\Resultset.cpp
# End Source File
# Begin Source File

SOURCE=.\Row.cpp
# End Source File
# Begin Source File

SOURCE=.\Rows.cpp
# End Source File
# Begin Source File

SOURCE=.\RowsEnum.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TSqlite.cpp
# End Source File
# Begin Source File

SOURCE=.\TSqlite.idl

!IF  "$(CFG)" == "TSqlite - Win32 Debug"

# ADD MTL /nologo /D _WIN32_WINNT=0x0400 /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Debug"

# ADD MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release"

# ADD BASE MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf
# ADD MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Release"

# ADD BASE MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf
# ADD MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release No Unacc"

# ADD BASE MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf
# ADD MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Debug No Unacc"

# ADD BASE MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf
# ADD MTL /nologo /tlb ".\TSqlite.tlb" /h "TSqlite.h" /iid "TSqlite_i.c" /Oicf

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TSqlite.rc
# End Source File
# Begin Source File

SOURCE=.\unaccfn.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BlobFn.h
# End Source File
# Begin Source File

SOURCE=.\Column.h
# End Source File
# Begin Source File

SOURCE=.\Columns.h
# End Source File
# Begin Source File

SOURCE=.\Connection.h
# End Source File
# Begin Source File

SOURCE=.\dlldatax.h
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\ErrorMsg.h
# End Source File
# Begin Source File

SOURCE=.\Glob.h
# End Source File
# Begin Source File

SOURCE=.\IBusy_CP.H
# End Source File
# Begin Source File

SOURCE=.\IProgress_CP.H
# End Source File
# Begin Source File

SOURCE=.\Parameter.h
# End Source File
# Begin Source File

SOURCE=.\Parameters.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Resultset.h
# End Source File
# Begin Source File

SOURCE=.\Row.h
# End Source File
# Begin Source File

SOURCE=.\Rows.h
# End Source File
# Begin Source File

SOURCE=.\RowsEnum.h
# End Source File
# Begin Source File

SOURCE=.\SAEnum.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\unaccfn.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Connection.rgs
# End Source File
# Begin Source File

SOURCE=.\LargeInteger.rgs
# End Source File
# Begin Source File

SOURCE=.\Resultset.rgs
# End Source File
# End Group
# Begin Group "Def"

# PROP Default_Filter "def"
# Begin Source File

SOURCE=.\TSqlite.def

!IF  "$(CFG)" == "TSqlite - Win32 Debug"

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release"

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Unicode Release"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Release No Unacc"

!ELSEIF  "$(CFG)" == "TSqlite - Win32 Debug No Unacc"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
