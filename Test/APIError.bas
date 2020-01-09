Attribute VB_Name = "APIError"
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'@Module Name:  APIError(.bas)
'@Main Func:    API错误信息
'@Author:       denglf
'@Last Modify:  2011-05-26
'@Interface:
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Option Explicit

Private Const LOAD_LIBRARY_AS_DATAFILE As Long = 2&

Private Const FORMAT_MESSAGE_FROM_SYSTEM = &H1000
Private Const FORMAT_MESSAGE_IGNORE_INSERTS As Long = &H200&
Private Const FORMAT_MESSAGE_FROM_HMODULE As Long = &H800&
Private Const FORMAT_MESSAGE_MAX_WIDTH_MASK = &HFF
' Upper and lower bounds of network errors
Private Const NERR_BASE As Long = 2100&
Private Const MAX_NERR As Long = NERR_BASE + 899&
' Upper and lower bounds of Internet errors
Private Const INTERNET_ERROR_BASE  As Long = 12000&
Private Const INTERNET_ERROR_LAST As Long = INTERNET_ERROR_BASE + 171&

Private Const VER_PLATFORM_WIN32s = 0
Private Const VER_PLATFORM_WIN32_WINDOWS = 1
Private Const VER_PLATFORM_WIN32_NT = 2

Private Type OSVERSIONINFO
    dwOSVersionInfoSize As Long
    dwMajorVersion As Long
    dwMinorVersion As Long
    dwBuildNumber As Long
    dwPlatformId As Long
    szCSDVersion As String * 128
End Type

Private Declare Function FormatMessage Lib "kernel32" Alias "FormatMessageA" (ByVal dwFlags As Long, lpSource As Any, ByVal dwMessageId As Long, ByVal dwLanguageId As Long, lpBuffer As Any, ByVal nSize As Long, Arguments As Long) As Long
Private Declare Function LoadLibraryEx Lib "kernel32" Alias "LoadLibraryExA" (ByVal lpLibFileName As String, ByVal hFile As Long, ByVal dwFlags As Long) As Long
Private Declare Function FreeLibrary Lib "kernel32" (ByVal hLibModule As Long) As Long
Private Declare Function GetVersionEx Lib "kernel32" Alias "GetVersionExA" (lpVersionInformation As OSVERSIONINFO) As Long

'//
'// 获取API错误信息
'//
Public Function ApiErrorText(ByVal lngErrNumber As Long) As String
    On Error GoTo ErrHandler
    Dim OSI As OSVERSIONINFO
    Dim lngFlags As Long
    Dim hModule As Long
    Dim strMessage As String
    Dim lngRet As Long
   
    Select Case lngErrNumber
    Case NERR_BASE To MAX_NERR
        OSI.dwOSVersionInfoSize = Len(OSI)
        GetVersionEx OSI
        If OSI.dwPlatformId = VER_PLATFORM_WIN32_NT Then
            hModule = LoadLibraryEx("netmsg.dll", 0&, LOAD_LIBRARY_AS_DATAFILE)
        End If
    Case INTERNET_ERROR_BASE To INTERNET_ERROR_LAST
        hModule = LoadLibraryEx("wininet.dll", 0&, LOAD_LIBRARY_AS_DATAFILE)
    'Case Else
    '    hModule = LoadLibraryEx("W:\eLungFan\TSqlite\Project\tsqlite\Debug\tsqlited.dll", 0&, LOAD_LIBRARY_AS_DATAFILE)
    End Select
   
    lngFlags = FORMAT_MESSAGE_FROM_SYSTEM Or FORMAT_MESSAGE_IGNORE_INSERTS Or FORMAT_MESSAGE_MAX_WIDTH_MASK
    If hModule Then lngFlags = lngFlags Or FORMAT_MESSAGE_FROM_HMODULE
   
    strMessage = Space$(1024)
    lngRet = FormatMessage(lngFlags, ByVal hModule, lngErrNumber, 0&, ByVal strMessage, Len(strMessage), ByVal 0&)
    If lngRet Then ApiErrorText = Left$(strMessage, InStr(1, strMessage, vbNullChar) - 1)
   
    If hModule Then
        FreeLibrary hModule
    End If
    
    Exit Function
ErrHandler:
    
End Function


