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
结果成功。
.

MessageId=0x1
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_ERROR
Language=English
SQL error or missing database.
.
Language=Chinese
SQL错误或数据库丢失。
.

MessageId=0x2
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_INTERNAL
Language=English
An internal logic error in SQLite.
.
Language=Chinese
数据库内部逻辑错误。
.

MessageId=0x3
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_PERM
Language=English
Access permission denied.
.
Language=Chinese
没有访问权限。
.

MessageId=0x4
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_ABORT
Language=English
Callback routine requested an abort.
.
Language=Chinese
回调例程请求中止。
.

MessageId=0x5
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_BUSY
Language=English
The database file is locked.
.
Language=Chinese
数据库被锁定。
.

MessageId=0x6
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_LOCKED
Language=English
A table in the database is locked.
.
Language=Chinese
数据库表被锁定。
.

MessageId=0x7
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOMEM
Language=English
A malloc() failed.
.
Language=Chinese
内存分配失败。
.

MessageId=0x8
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_READONLY
Language=English
Attempt to write a readonly database.
.
Language=Chinese
尝试写入只读数据库。
.

MessageId=0x9
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_INTERRUPT
Language=English
Operation terminated by sqlite3_interrupt().
.
Language=Chinese
操作被终断。
.

MessageId=0xA
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_IOERR
Language=English
Some kind of disk I/O error occurred.
.
Language=Chinese
磁盘I/O错误。
.

MessageId=0xB
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_CORRUPT
Language=English
The database disk image is malformed.
.
Language=Chinese
数据库磁盘映像格式不正确。
.

MessageId=0xC
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOTFOUND
Language=English
(Internal Only) Table or record not found.
.
Language=Chinese
未找到表或记录。
.

MessageId=0xD
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_FULL
Language=English
Insertion failed because database is full.
.
Language=Chinese
插入失败，数据库已满。
.

MessageId=0xE
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_CANTOPEN
Language=English
Unable to open the database file.
.
Language=Chinese
打开数据库文件失败。
.

MessageId=0xF
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_PROTOCOL
Language=English
Database lock protocol error.
.
Language=Chinese
锁定数据库失败。
.

MessageId=0x10
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_EMPTY
Language=English
Database is empty.
.
Language=Chinese
空数据库。
.

MessageId=0x11
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_SCHEMA
Language=English
The database schema changed.
.
Language=Chinese
数据库配置改变。
.

MessageId=0x12
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_TOOBIG
Language=English
Too much data for one row of a table.
.
Language=Chinese
表的记录行数据太多。
.

MessageId=0x13
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_CONSTRAINT
Language=English
Abort due to constraint violation.
.
Language=Chinese
违反惟一约束。
.

MessageId=0x14
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_MISMATCH
Language=English
Data type mismatch.
.
Language=Chinese
数据类型不匹配。
.

MessageId=0x15
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_MISUSE
Language=English
Library used incorrectly.
.
Language=Chinese
库使用不当。
.

MessageId=0x16
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOLFS
Language=English
Uses OS features not supported on host.
.
Language=Chinese
使用不支持的操作系统特性。
.

MessageId=0x17
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_AUTH
Language=English
Authorization denied.
.
Language=Chinese
授权被拒绝。
.

MessageId=0x18
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_FORMAT
Language=English
Auxiliary database format error.
.
Language=Chinese
辅助数据库格式错误。
.

MessageId=0x19
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_RANGE
Language=English
2nd parameter to sqlite3_bind out of range.
.
Language=Chinese
sqlite3_bind的第二个参数超出范围。
.

MessageId=0x1A
Severity=Error
Facility=Application
SymbolicName=E_SQLITE_NOTADB
Language=English
File opened that is not a database file.
.
Language=Chinese
无效的数据库文件。
.

MessageId=100
Severity=Informational
Facility=Application
SymbolicName=S_SQLITE_ROW
Language=English
Another row ready.
.
Language=Chinese
另一行已就绪。
.

MessageId=101
Severity=Informational
Facility=Application
SymbolicName=S_SQLITE_DONE
Language=English
Finished query execution.
.
Language=Chinese
查询执行完成。
.

MessageId=200
Severity=Error
Facility=Application
SymbolicName=E_ALREADY_PREPARED
Language=English
Statement already prepared.
.
Language=Chinese
SQL语句已准备好。
.

MessageId=201
Severity=Error
Facility=Application
SymbolicName=E_NO_ACTIVE_CONNECTION
Language=English
Connection property not set.
.
Language=Chinese
未设置活动连接。
.

MessageId=202
Severity=Error
Facility=Application
SymbolicName=E_NO_COMMAND_STRING
Language=English
No SQL statement was given.
.
Language=Chinese
没有设置SQL语句。
.

MessageId=203
Severity=Error
Facility=Application
SymbolicName=E_STMT_NOT_PREPARED
Language=English
Statement not prepared.
.
Language=Chinese
SQL语句未准备好。
.

MessageId=204
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_BINARY_DATA
Language=English
Unknown binary data.
.
Language=Chinese
未知的二进制数据。
.

MessageId=205
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_TYPE
Language=English
Cannot guess data type.
.
Language=Chinese
不能推测数据类型。
.

MessageId=206
Severity=Error
Facility=Application
SymbolicName=E_NO_COLUMN_NAME
Language=English
Cannot get column name.
.
Language=Chinese
不能获取列名。
.

MessageId=207
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_COLUMN_TYPE
Language=English
Unknown column type or bad column index.
.
Language=Chinese
未知的列类型或错误的列索引。
.


MessageId=208
Severity=Error
Facility=Application
SymbolicName=E_CANNOT_CREATE_STATEMENT
Language=English
Cannot create statement object.
.
Language=Chinese
不能创建结果集对象。
.

MessageId=209
Severity=Error
Facility=Application
SymbolicName=E_COLUMN_OUT_OF_RANGE
Language=English
Column index out of range.
.
Language=Chinese
列索引超出范围。
.

MessageId=210
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_COLUMN_NAME
Language=English
Unknown column name.
.
Language=Chinese
未知的列名。
.

MessageId=211
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_COLUMN_INDEX_TYPE
Language=English
Unknown column index type. Only string or integer values are allowed.
.
Language=Chinese
未知的列索引类型。只允许字符串或整数值。
.

MessageId=212
Severity=Error
Facility=Application
SymbolicName=E_PARAM_OUT_OF_RANGE
Language=English
Parameter index out of range.
.
Language=Chinese
参数索引超出范围。
.

MessageId=213
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_PARAM_NAME
Language=English
Unknown parameter name.
.
Language=Chinese
未知的参数名称。
.

MessageId=214
Severity=Error
Facility=Application
SymbolicName=E_UNKNOWN_PARAM_INDEX_TYPE
Language=English
Unknown parameter index type. Only string or integer values are allowed.
.
Language=Chinese
未知的参数索引类型。只允许字符串或整数值。
.

MessageId=215
Severity=Error
Facility=Application
SymbolicName=E_DB_IS_OPEN
Language=English
Database file is open. 
.
Language=Chinese
数据库已被打开。
.

MessageId=216
Severity=Error
Facility=Application
SymbolicName=E_DB_IS_NOT_OPEN
Language=English
Database file isn't open. 
.
Language=Chinese
数据库未被打开。
.

MessageId=217
Severity=Error
Facility=Application
SymbolicName=E_STMT_BAD_STEP_PARAMETER
Language=English
Bad step parameter.
.
Language=Chinese
无效的参数。
.

MessageId=218
Severity=Error
Facility=Application
SymbolicName=E_STMT_NON_QUERY_RETURNS_ROW
Language=English
Non-query statement returns row.
.
Language=Chinese
非查询语句返回行。
.

MessageId=219
Severity=Error
Facility=Application
SymbolicName=E_UNUPPORTED_VALUE_TYPE
Language=English
Unsupported value type.
.
Language=Chinese
不支持的值类型。
.

MessageId=220
Severity=Error
Facility=Application
SymbolicName=E_BAD_BINDING_VALUE
Language=English
Bad binding value.
.
Language=Chinese
无效的绑定值。
.

MessageId=221
Severity=Error
Facility=Application
SymbolicName=E_TRANS_BEGIN_DISABLED
Language=English
Begin transaction disabled.
.
Language=Chinese
存在已开启的事务未提交或未回滚，不能开启事务。
.

MessageId=222
Severity=Error
Facility=Application
SymbolicName=E_TRANS_COMMIT_DISABLED
Language=English
Begin transaction disabled.
.
Language=Chinese
当前未开启事务或事务已回滚，不能提交事务。
.

MessageId=223
Severity=Error
Facility=Application
SymbolicName=E_TRANS_ROLLBACK_DISABLED
Language=English
Rollback transaction disabled.
.
Language=Chinese
当前未开启事务或事务已提交，不能回滚事务。
.
