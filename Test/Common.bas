Attribute VB_Name = "Common"
Option Explicit

Public Const LB_SETHORIZONTALEXTENT = &H194
Public Const Start As Boolean = True 'used for the Demo-Stopwatch

Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hwnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Any) As Long

Private Declare Function QueryPerformanceFrequency& Lib "kernel32" (x@)
Private Declare Function QueryPerformanceCounter& Lib "kernel32" (x@)

'some Helper-Functions for all the Demos
Public Function HPTimer#()
    Dim x@: Static Frq@
    
    If Frq = 0 Then QueryPerformanceFrequency Frq
    If QueryPerformanceCounter(x) Then HPTimer = x / Frq
    
End Function

Public Function Timing(Optional ByVal Start As Boolean) As String
    
    Static T#
    If Start Then T = HPTimer: Exit Function
    Timing = " " & Format$((HPTimer - T) * 1000, "Standard") & "∫¡√Î"
    
End Function


