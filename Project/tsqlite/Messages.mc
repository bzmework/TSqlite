; /* 
;   Messages.mc
; */

; // This is the header section. 

MessageIdTypedef = DWORD
LanguageNames =
(
    English = 0x0409:MSG00409
    Chinese = 0x0804:MSG00804
)

; // The following are message definitions.

MessageId=0x0
Severity=Success
Facility=Application
SymbolicName=S_SQLITE_OK
Language=English
Successful result.
.
Language=Chinese
����ɹ���
.

MessageId=0x1
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_ERROR
Language=English
SQL error or missing database.
.
Language=Chinese
SQL��������ݿⶪʧ��
.

MessageId=0x2
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_INTERNAL
Language=English
An internal logic error in SQLite.
.
Language=Chinese
���ݿ��ڲ��߼�����
.

MessageId=0x3
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_PERM
Language=English
Access permission denied.
.
Language=Chinese
û�з���Ȩ�ޡ�
.

MessageId=0x4
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_ABORT
Language=English
Callback routine requested an abort.
.
Language=Chinese
�ص�����������ֹ��
.

MessageId=0x5
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_BUSY
Language=English
The database file is locked.
.
Language=Chinese
���ݿⱻ������
.

MessageId=0x6
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_LOCKED
Language=English
A table in the database is locked.
.
Language=Chinese
���ݿ��������
.

MessageId=0x7
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOMEM
Language=English
A malloc() failed.
.
Language=Chinese
�ڴ����ʧ�ܡ�
.

MessageId=0x8
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_READONLY
Language=English
Attempt to write a readonly database.
.
Language=Chinese
����д��ֻ�����ݿ⡣
.

MessageId=0x9
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_INTERRUPT
Language=English
Operation terminated by sqlite3_interrupt().
.
Language=Chinese
�������նϡ�
.

MessageId=0xA
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_IOERR
Language=English
Some kind of disk I/O error occurred.
.
Language=Chinese
����I/O����
.

MessageId=0xB
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_CORRUPT
Language=English
The database disk image is malformed.
.
Language=Chinese
���ݿ����ӳ���ʽ����ȷ��
.

MessageId=0xC
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOTFOUND
Language=English
(Internal Only) Table or record not found.
.
Language=Chinese
δ�ҵ�����¼��
.

MessageId=0xD
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_FULL
Language=English
Insertion failed because database is full.
.
Language=Chinese
����ʧ�ܣ����ݿ�������
.

MessageId=0xE
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_CANTOPEN
Language=English
Unable to open the database file.
.
Language=Chinese
�����ݿ��ļ�ʧ�ܡ�
.

MessageId=0xF
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_PROTOCOL
Language=English
Database lock protocol error.
.
Language=Chinese
�������ݿ�ʧ�ܡ�
.

MessageId=0x10
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_EMPTY
Language=English
Database is empty.
.
Language=Chinese
�����ݿ⡣
.

MessageId=0x11
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_SCHEMA
Language=English
The database schema changed.
.
Language=Chinese
���ݿ����øı䡣
.

MessageId=0x12
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_TOOBIG
Language=English
Too much data for one row of a table.
.
Language=Chinese
��ļ�¼������̫�ࡣ
.

MessageId=0x13
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_CONSTRAINT
Language=English
Abort due to constraint violation.
.
Language=Chinese
Υ��ΩһԼ����
.

MessageId=0x14
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_MISMATCH
Language=English
Data type mismatch.
.
Language=Chinese
�������Ͳ�ƥ�䡣
.

MessageId=0x15
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_MISUSE
Language=English
Library used incorrectly.
.
Language=Chinese
��ʹ�ò�����
.

MessageId=0x16
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOLFS
Language=English
Uses OS features not supported on host.
.
Language=Chinese
ʹ�ò�֧�ֵĲ���ϵͳ���ԡ�
.

MessageId=0x17
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_AUTH
Language=English
Authorization denied.
.
Language=Chinese
��Ȩ���ܾ���
.

MessageId=0x18
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_FORMAT
Language=English
Auxiliary database format error.
.
Language=Chinese
�������ݿ��ʽ����
.

MessageId=0x19
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_RANGE
Language=English
2nd parameter to sqlite3_bind out of range.
.
Language=Chinese
sqlite3_bind�ĵڶ�������������Χ��
.

MessageId=0x1A
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOTADB
Language=English
File opened that is not a database file.
.
Language=Chinese
��Ч�����ݿ��ļ���
.

MessageId=100
Severity=Informational
Facility=Application
SymbolicName=S_SQLITE_ROW
Language=English
Another row ready.
.
Language=Chinese
��һ���Ѿ�����
.

MessageId=101
Severity=Informational
Facility=Application
SymbolicName=S_SQLITE_DONE
Language=English
Finished query execution.
.
Language=Chinese
��ѯִ����ɡ�
.

MessageId=200
Severity=Error
Facility=Application
SymbolicName=E_ALREADY_PREPARED
Language=English
Statement already prepared.
.
Language=Chinese
SQL�����׼���á�
.

MessageId=201
Severity=Error
Facility=Application
SymbolicName=E_NO_ACTIVE_CONNECTION
Language=English
Connection property not set.
.
Language=Chinese
δ���û���ӡ�
.

MessageId=202
Severity=Error
Facility=Application
SymbolicName=E_NO_COMMAND_STRING
Language=English
No SQL statement was given.
.
Language=Chinese
û������SQL��䡣
.

MessageId=203
Severity=Error
Facility=Application
SymbolicName=E_STMT_NOT_PREPARED
Language=English
Statement not prepared.
.
Language=Chinese
SQL���δ׼���á�
.

MessageId=204
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_BINARY_DATA
Language=English
Unknown binary data.
.
Language=Chinese
δ֪�Ķ��������ݡ�
.

MessageId=205
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_TYPE
Language=English
Cannot guess data type.
.
Language=Chinese
�����Ʋ��������͡�
.

MessageId=206
Severity=Error
Facility=Application
SymbolicName=E_NO_COLUMN_NAME
Language=English
Cannot get column name.
.
Language=Chinese
���ܻ�ȡ������
.

MessageId=207
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_COLUMN_TYPE
Language=English
Unknown column type or bad column index.
.
Language=Chinese
δ֪�������ͻ�������������
.


MessageId=208
Severity=Error
Facility=Application
SymbolicName=E_CANNOT_CREATE_STATEMENT
Language=English
Cannot create statement object.
.
Language=Chinese
���ܴ������������
.

MessageId=209
Severity=Error
Facility=Application
SymbolicName=E_COLUMN_OUT_OF_RANGE
Language=English
Column index out of range.
.
Language=Chinese
������������Χ��
.

MessageId=210
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_COLUMN_NAME
Language=English
Unknown column name.
.
Language=Chinese
δ֪��������
.

MessageId=211
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_COLUMN_INDEX_TYPE
Language=English
Unknown column index type. Only string or integer values are allowed.
.
Language=Chinese
δ֪�����������͡�ֻ�����ַ���������ֵ��
.

MessageId=212
Severity=Error
Facility=Application
SymbolicName=E_PARAM_OUT_OF_RANGE
Language=English
Parameter index out of range.
.
Language=Chinese
��������������Χ��
.

MessageId=213
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_PARAM_NAME
Language=English
Unknown parameter name.
.
Language=Chinese
δ֪�Ĳ������ơ�
.

MessageId=214
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_PARAM_INDEX_TYPE
Language=English
Unknown parameter index type. Only string or integer values are allowed.
.
Language=Chinese
δ֪�Ĳ����������͡�ֻ�����ַ���������ֵ��
.

MessageId=215
Severity=Error
Facility=Application
SymbolicName=E_DB_IS_OPEN
Language=English
Database file is open. 
.
Language=Chinese
���ݿ��ѱ��򿪡�
.

MessageId=216
Severity=Error
Facility=Application
SymbolicName=E_DB_IS_NOT_OPEN
Language=English
Database file isn't open. 
.
Language=Chinese
���ݿ�δ���򿪡�
.

MessageId=217
Severity=Error
Facility=Application
SymbolicName=E_STMT_BAD_STEP_PARAMETER
Language=English
Bad step parameter.
.
Language=Chinese
��Ч�Ĳ�����
.

MessageId=218
Severity=Error
Facility=Application
SymbolicName=E_STMT_NON_QUERY_RETURNS_ROW
Language=English
Non-query statement returns row.
.
Language=Chinese
�ǲ�ѯ��䷵���С�
.

MessageId=219
Severity=Error
Facility=Application
SymbolicName=E_UNUPPORTED_VALUE_TYPE
Language=English
Unsupported value type.
.
Language=Chinese
��֧�ֵ�ֵ���͡�
.

MessageId=220
Severity=Error
Facility=Application
SymbolicName=E_BAD_BINDING_VALUE
Language=English
Bad binding value.
.
Language=Chinese
��Ч�İ�ֵ��
.

MessageId=221
Severity=Error
Facility=Application
SymbolicName=E_TRANS_BEGIN_DISABLED
Language=English
Begin transaction disabled.
.
Language=Chinese
�����ѿ���������δ�ύ��δ�ع������ܿ�������
.

MessageId=222
Severity=Error
Facility=Application
SymbolicName=E_TRANS_COMMIT_DISABLED
Language=English
Begin transaction disabled.
.
Language=Chinese
��ǰδ��������������ѻع��������ύ����
.

MessageId=223
Severity=Error
Facility=Application
SymbolicName=E_TRANS_ROLLBACK_DISABLED
Language=English
Rollback transaction disabled.
.
Language=Chinese
��ǰδ����������������ύ�����ܻع�����
.
