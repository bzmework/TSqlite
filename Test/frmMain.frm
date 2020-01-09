VERSION 5.00
Begin VB.Form frmMain 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "TSqlite����"
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
   StartUpPosition =   2  '��Ļ����
   Begin VB.CommandButton cmdExec2 
      Caption         =   "��ѯ(ForEach)"
      Height          =   345
      Left            =   1380
      TabIndex        =   7
      Top             =   1470
      Width           =   1725
   End
   Begin VB.CommandButton cmdBrowseDb 
      Caption         =   "ѡ�����ݿ�..."
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
      Caption         =   "��ѯ"
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
      Caption         =   "SQLite ���ݿ�:"
      Height          =   195
      Index           =   1
      Left            =   210
      TabIndex        =   4
      Top             =   60
      Width           =   1110
   End
   Begin VB.Label lbl 
      AutoSize        =   -1  'True
      Caption         =   "SQL���:"
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

'��ѯ������ADO��ʽ
Private Sub cmdExec_Click()
    Dim rs As TSqlite.Resultset
    Dim strTemp As String
    Dim v As Variant
    Dim i As Long
    
    Timing True
    
    Set rs = cn.Execute(txtSql.Text)

    '����:
    'Set rs = New TSqlite.Resultset
    'rs.ActiveConnection = cn
    'rs.Prepare txtSql.Text
    'rs.Execute
    
    lstLog.Clear
    lstLog.AddItem "sqlite�汾 " & cn.Version
    lstLog.AddItem "���صļ�¼���� " & rs.RowCount
    
    lblTime.Caption = "����ʱ��:" & Timing
    
    
    '˵��������Sqlite�ľ����ԣ����¹��ܴ���һЩ���⣺
    '1,RowCount: ϵͳ�ڻ�ȡ��¼����ʱ��ѭ���ƶ���¼���м���ͳ�ƣ�����������ʱ���Ӱ������.
    '2,MoveFirst: ϵͳ������ִ�в�ѯ������λ����һ����¼.
    '3,MoveLast: ϵͳ��ѭ���ƶ���¼����λ�����һ����¼������������ʱ���Ӱ������.
    '��ʵ��ҵ���У����Ϲ��ܲ����ã�����һ�㲻Ҫʹ�á�
    
    strTemp = ""
    For i = 0 To rs.ColumnCount - 1
        strTemp = strTemp & rs.ColumnName(i) & ","
    Next
    If Right(strTemp, 1) = "," Then
        strTemp = Left(strTemp, Len(strTemp) - 1)
    End If
    lstLog.AddItem "���ص��ֶ�����:"
    lstLog.AddItem strTemp
    lstLog.AddItem ""
    lstLog.AddItem "���ص��ֶ�����:"
    
    If Not rs.EOF Then
    
        Do While Not rs.EOF
            strTemp = ""
            For i = 0 To rs.ColumnCount - 1
                
                'VBͨ������ȡ������
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

'��ѯ��ForEach��ʽ
'����debug dll�ٶȽ���, release dll�ٶ���Ӱ��
'��Ȼ֧��ForEach��������ʱӦ���ø�Ч��ADO��ʽ��д����
Private Sub cmdExec2_Click()
    Dim rs As TSqlite.Resultset
    Dim oCol As TSqlite.Column
    Dim oRow As TSqlite.Row
    Dim strTemp As String
    Dim v As Variant
    Dim i As Long
    
    Timing True
    
    Set rs = cn.Execute(txtSql.Text)
    '����:
    'Set rs = New TSqlite.Resultset
    'rs.ActiveConnection = cn
    'rs.Prepare txtSql.Text
    'rs.Execute
    
    lstLog.Clear
    lstLog.AddItem "sqlite�汾 " & cn.Version
    lstLog.AddItem "���صļ�¼���� " & rs.RowCount
    
    lblTime.Caption = "����ʱ��:" & Timing
    
    strTemp = ""
    For Each oCol In rs.Columns
        strTemp = strTemp & oCol & ","
    Next
    If Right(strTemp, 1) = "," Then
        strTemp = Left(strTemp, Len(strTemp) - 1)
    End If
    lstLog.AddItem "���ص��ֶ�����:"
    lstLog.AddItem strTemp
    lstLog.AddItem ""
    lstLog.AddItem "���ص��ֶ�����:"

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
