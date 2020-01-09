VERSION 5.00
Begin VB.Form frmMain 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "TSqlite测试"
   ClientHeight    =   7620
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   9705
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7620
   ScaleWidth      =   9705
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton cmdExec2 
      Caption         =   "查询(ForEach)"
      Height          =   345
      Left            =   1380
      TabIndex        =   7
      Top             =   1470
      Width           =   1725
   End
   Begin VB.CommandButton cmdBrowseDb 
      Caption         =   "选择数据库..."
      Height          =   345
      Left            =   8190
      TabIndex        =   6
      Top             =   300
      Width           =   1395
   End
   Begin VB.TextBox txtDatabase 
      Height          =   315
      Left            =   180
      TabIndex        =   5
      Top             =   300
      Width           =   7935
   End
   Begin VB.CommandButton cmdExec 
      Caption         =   "查询"
      Height          =   345
      Left            =   180
      TabIndex        =   3
      Top             =   1470
      Width           =   1125
   End
   Begin VB.TextBox txtSql 
      Height          =   315
      Left            =   180
      TabIndex        =   1
      Text            =   "SELECT * FROM [Order Details]"
      Top             =   1050
      Width           =   9405
   End
   Begin VB.ListBox lstLog 
      Height          =   5130
      Left            =   180
      TabIndex        =   0
      Top             =   1920
      Width           =   9405
   End
   Begin VB.Label lblTime 
      Height          =   285
      Left            =   180
      TabIndex        =   8
      Top             =   7290
      Width           =   2235
   End
   Begin VB.Label lbl 
      AutoSize        =   -1  'True
      Caption         =   "SQLite 数据库:"
      Height          =   195
      Index           =   1
      Left            =   210
      TabIndex        =   4
      Top             =   60
      Width           =   1110
   End
   Begin VB.Label lbl 
      AutoSize        =   -1  'True
      Caption         =   "SQL语句:"
      Height          =   195
      Index           =   0
      Left            =   180
      TabIndex        =   2
      Top             =   810
      Width           =   705
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private cn As TSqlite.Connection
Attribute cn.VB_VarHelpID = -1

Private Sub cmdBrowseDb_Click()
    Dim strFilename As String
    
    strFilename = txtDatabase.Text
    If modOpen.VBGetOpenFileName(strFilename, Filter:="Sqlite database (*.db)|*.db", DlgTitle:="Select SQLite database", DefaultExt:="db", Owner:=Me.hwnd) Then
        txtDatabase.Text = strFilename
        cn.Close
        cn.Db = txtDatabase.Text
        cn.Open
    End If
    
End Sub

'查询，类似ADO方式
Private Sub cmdExec_Click()
    Dim rs As TSqlite.Resultset
    Dim strTemp As String
    Dim v As Variant
    Dim i As Long
    
    Timing True
    
    Set rs = cn.Execute(txtSql.Text)

    '或者:
    'Set rs = New TSqlite.Resultset
    'rs.ActiveConnection = cn
    'rs.Prepare txtSql.Text
    'rs.Execute
    
    lstLog.Clear
    lstLog.AddItem "sqlite版本 " & cn.Version
    lstLog.AddItem "返回的记录行数 " & rs.RowCount
    
    lblTime.Caption = "消耗时间:" & Timing
    
    
    '说明，由于Sqlite的局限性，以下功能存在一些问题：
    '1,RowCount: 系统在获取记录行数时会循坏移动记录进行计数统计，大数据量的时候会影响性能.
    '2,MoveFirst: 系统会重新执行查询，并定位到第一条记录.
    '3,MoveLast: 系统会循坏移动记录，定位到最后一条记录，大数据量的时候会影响性能.
    '在实际业务中，以上功能不常用，所以一般不要使用。
    
    strTemp = ""
    For i = 0 To rs.ColumnCount - 1
        strTemp = strTemp & rs.ColumnName(i) & ","
    Next
    If Right(strTemp, 1) = "," Then
        strTemp = Left(strTemp, Len(strTemp) - 1)
    End If
    lstLog.AddItem "返回的字段名称:"
    lstLog.AddItem strTemp
    lstLog.AddItem ""
    lstLog.AddItem "返回的字段数据:"
    
    If Not rs.EOF Then
    
        Do While Not rs.EOF
            strTemp = ""
            For i = 0 To rs.ColumnCount - 1
                
                'VB通过索引取数错误
                'v = i
                'strTemp = strTemp & rs.ColumnValue(v) & ","
                
                strTemp = strTemp & rs.ColumnValue(rs.ColumnName(i)) & ","
                
            Next
            If Right(strTemp, 1) = "," Then
                strTemp = Left(strTemp, Len(strTemp) - 1)
            End If
            lstLog.AddItem strTemp
            
            rs.MoveNext
        Loop
        
    End If
    
    rs.Close
    Set rs = Nothing
    
End Sub

'查询，ForEach方式
'调试debug dll速度较慢, release dll速度无影响
'虽然支持ForEach，但开发时应采用高效的ADO方式编写代码
Private Sub cmdExec2_Click()
    Dim rs As TSqlite.Resultset
    Dim oCol As TSqlite.Column
    Dim oRow As TSqlite.Row
    Dim strTemp As String
    Dim v As Variant
    Dim i As Long
    
    Timing True
    
    Set rs = cn.Execute(txtSql.Text)
    '或者:
    'Set rs = New TSqlite.Resultset
    'rs.ActiveConnection = cn
    'rs.Prepare txtSql.Text
    'rs.Execute
    
    lstLog.Clear
    lstLog.AddItem "sqlite版本 " & cn.Version
    lstLog.AddItem "返回的记录行数 " & rs.RowCount
    
    lblTime.Caption = "消耗时间:" & Timing
    
    strTemp = ""
    For Each oCol In rs.Columns
        strTemp = strTemp & oCol & ","
    Next
    If Right(strTemp, 1) = "," Then
        strTemp = Left(strTemp, Len(strTemp) - 1)
    End If
    lstLog.AddItem "返回的字段名称:"
    lstLog.AddItem strTemp
    lstLog.AddItem ""
    lstLog.AddItem "返回的字段数据:"

    If Not rs.EOF Then
        For Each oRow In rs.Rows()
            
            strTemp = ""
            For Each v In oRow
                strTemp = strTemp & v & ","
            Next
            
            If Right(strTemp, 1) = "," Then
                strTemp = Left(strTemp, Len(strTemp) - 1)
            End If
            lstLog.AddItem strTemp
            
        Next
        
    End If
    
    rs.Close
    Set rs = Nothing
    
End Sub

Private Sub Form_Load()
    Dim lRet As Long
    Dim strDir As String
    
    strDir = CurDir
    ChDir App.Path
    
    Set cn = New TSqlite.Connection
    txtDatabase.Text = App.Path & "\Nwind.db"
    cn.Db = txtDatabase.Text
    cn.Open

    lRet = SendMessage(lstLog.hwnd, LB_SETHORIZONTALEXTENT, 2000, 0)
    
End Sub
