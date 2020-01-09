 /* 
   Messages.mc
 */
 // This is the header section. 
 // The following are message definitions.
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: S_SQLITE_OK
//
// MessageText:
//
// Successful result.
//
#define S_SQLITE_OK                      ((DWORD)0x00000000L)

//
// MessageId: E_SQLITE_ERROR
//
// MessageText:
//
// SQL error or missing database.
//
#define E_SQLITE_ERROR                   ((DWORD)0xC0000001L)

//
// MessageId: E_SQLITE_INTERNAL
//
// MessageText:
//
// An internal logic error in SQLite.
//
#define E_SQLITE_INTERNAL                ((DWORD)0xC0000002L)

//
// MessageId: E_SQLITE_PERM
//
// MessageText:
//
// Access permission denied.
//
#define E_SQLITE_PERM                    ((DWORD)0xC0000003L)

//
// MessageId: E_SQLITE_ABORT
//
// MessageText:
//
// Callback routine requested an abort.
//
#define E_SQLITE_ABORT                   ((DWORD)0xC0000004L)

//
// MessageId: E_SQLITE_BUSY
//
// MessageText:
//
// The database file is locked.
//
#define E_SQLITE_BUSY                    ((DWORD)0xC0000005L)

//
// MessageId: E_SQLITE_LOCKED
//
// MessageText:
//
// A table in the database is locked.
//
#define E_SQLITE_LOCKED                  ((DWORD)0xC0000006L)

//
// MessageId: E_SQLITE_NOMEM
//
// MessageText:
//
// A malloc() failed.
//
#define E_SQLITE_NOMEM                   ((DWORD)0xC0000007L)

//
// MessageId: E_SQLITE_READONLY
//
// MessageText:
//
// Attempt to write a readonly database.
//
#define E_SQLITE_READONLY                ((DWORD)0xC0000008L)

//
// MessageId: E_SQLITE_INTERRUPT
//
// MessageText:
//
// Operation terminated by sqlite3_interrupt().
//
#define E_SQLITE_INTERRUPT               ((DWORD)0xC0000009L)

//
// MessageId: E_SQLITE_IOERR
//
// MessageText:
//
// Some kind of disk I/O error occurred.
//
#define E_SQLITE_IOERR                   ((DWORD)0xC000000AL)

//
// MessageId: E_SQLITE_CORRUPT
//
// MessageText:
//
// The database disk image is malformed.
//
#define E_SQLITE_CORRUPT                 ((DWORD)0xC000000BL)

//
// MessageId: E_SQLITE_NOTFOUND
//
// MessageText:
//
// (Internal Only) Table or record not found.
//
#define E_SQLITE_NOTFOUND                ((DWORD)0xC000000CL)

//
// MessageId: E_SQLITE_FULL
//
// MessageText:
//
// Insertion failed because database is full.
//
#define E_SQLITE_FULL                    ((DWORD)0xC000000DL)

//
// MessageId: E_SQLITE_CANTOPEN
//
// MessageText:
//
// Unable to open the database file.
//
#define E_SQLITE_CANTOPEN                ((DWORD)0xC000000EL)

//
// MessageId: E_SQLITE_PROTOCOL
//
// MessageText:
//
// Database lock protocol error.
//
#define E_SQLITE_PROTOCOL                ((DWORD)0xC000000FL)

//
// MessageId: E_SQLITE_EMPTY
//
// MessageText:
//
// Database is empty.
//
#define E_SQLITE_EMPTY                   ((DWORD)0xC0000010L)

//
// MessageId: E_SQLITE_SCHEMA
//
// MessageText:
//
// The database schema changed.
//
#define E_SQLITE_SCHEMA                  ((DWORD)0xC0000011L)

//
// MessageId: E_SQLITE_TOOBIG
//
// MessageText:
//
// Too much data for one row of a table.
//
#define E_SQLITE_TOOBIG                  ((DWORD)0xC0000012L)

//
// MessageId: E_SQLITE_CONSTRAINT
//
// MessageText:
//
// Abort due to constraint violation.
//
#define E_SQLITE_CONSTRAINT              ((DWORD)0xC0000013L)

//
// MessageId: E_SQLITE_MISMATCH
//
// MessageText:
//
// Data type mismatch.
//
#define E_SQLITE_MISMATCH                ((DWORD)0xC0000014L)

//
// MessageId: E_SQLITE_MISUSE
//
// MessageText:
//
// Library used incorrectly.
//
#define E_SQLITE_MISUSE                  ((DWORD)0xC0000015L)

//
// MessageId: E_SQLITE_NOLFS
//
// MessageText:
//
// Uses OS features not supported on host.
//
#define E_SQLITE_NOLFS                   ((DWORD)0xC0000016L)

//
// MessageId: E_SQLITE_AUTH
//
// MessageText:
//
// Authorization denied.
//
#define E_SQLITE_AUTH                    ((DWORD)0xC0000017L)

//
// MessageId: E_SQLITE_FORMAT
//
// MessageText:
//
// Auxiliary database format error.
//
#define E_SQLITE_FORMAT                  ((DWORD)0xC0000018L)

//
// MessageId: E_SQLITE_RANGE
//
// MessageText:
//
// 2nd parameter to sqlite3_bind out of range.
//
#define E_SQLITE_RANGE                   ((DWORD)0xC0000019L)

//
// MessageId: E_SQLITE_NOTADB
//
// MessageText:
//
// File opened that is not a database file.
//
#define E_SQLITE_NOTADB                  ((DWORD)0xC000001AL)

//
// MessageId: S_SQLITE_ROW
//
// MessageText:
//
// Another row ready.
//
#define S_SQLITE_ROW                     ((DWORD)0x40000064L)

//
// MessageId: S_SQLITE_DONE
//
// MessageText:
//
// Finished query execution.
//
#define S_SQLITE_DONE                    ((DWORD)0x40000065L)

//
// MessageId: E_ALREADY_PREPARED
//
// MessageText:
//
// Statement already prepared.
//
#define E_ALREADY_PREPARED               ((DWORD)0xC00000C8L)

//
// MessageId: E_NO_ACTIVE_CONNECTION
//
// MessageText:
//
// Connection property not set.
//
#define E_NO_ACTIVE_CONNECTION           ((DWORD)0xC00000C9L)

//
// MessageId: E_NO_COMMAND_STRING
//
// MessageText:
//
// No SQL statement was given.
//
#define E_NO_COMMAND_STRING              ((DWORD)0xC00000CAL)

//
// MessageId: E_STMT_NOT_PREPARED
//
// MessageText:
//
// Statement not prepared.
//
#define E_STMT_NOT_PREPARED              ((DWORD)0xC00000CBL)

//
// MessageId: E_UNKNOWN_BINARY_DATA
//
// MessageText:
//
// Unknown binary data.
//
#define E_UNKNOWN_BINARY_DATA            ((DWORD)0xC00000CCL)

//
// MessageId: E_UNKNOWN_TYPE
//
// MessageText:
//
// Cannot guess data type.
//
#define E_UNKNOWN_TYPE                   ((DWORD)0xC00000CDL)

//
// MessageId: E_NO_COLUMN_NAME
//
// MessageText:
//
// Cannot get column name.
//
#define E_NO_COLUMN_NAME                 ((DWORD)0xC00000CEL)

//
// MessageId: E_UNKNOWN_COLUMN_TYPE
//
// MessageText:
//
// Unknown column type or bad column index.
//
#define E_UNKNOWN_COLUMN_TYPE            ((DWORD)0xC00000CFL)

//
// MessageId: E_CANNOT_CREATE_STATEMENT
//
// MessageText:
//
// Cannot create statement object.
//
#define E_CANNOT_CREATE_STATEMENT        ((DWORD)0xC00000D0L)

//
// MessageId: E_COLUMN_OUT_OF_RANGE
//
// MessageText:
//
// Column index out of range.
//
#define E_COLUMN_OUT_OF_RANGE            ((DWORD)0xC00000D1L)

//
// MessageId: E_UNKNOWN_COLUMN_NAME
//
// MessageText:
//
// Unknown column name.
//
#define E_UNKNOWN_COLUMN_NAME            ((DWORD)0xC00000D2L)

//
// MessageId: E_UNKNOWN_COLUMN_INDEX_TYPE
//
// MessageText:
//
// Unknown column index type. Only string or integer values are allowed.
//
#define E_UNKNOWN_COLUMN_INDEX_TYPE      ((DWORD)0xC00000D3L)

//
// MessageId: E_PARAM_OUT_OF_RANGE
//
// MessageText:
//
// Parameter index out of range.
//
#define E_PARAM_OUT_OF_RANGE             ((DWORD)0xC00000D4L)

//
// MessageId: E_UNKNOWN_PARAM_NAME
//
// MessageText:
//
// Unknown parameter name.
//
#define E_UNKNOWN_PARAM_NAME             ((DWORD)0xC00000D5L)

//
// MessageId: E_UNKNOWN_PARAM_INDEX_TYPE
//
// MessageText:
//
// Unknown parameter index type. Only string or integer values are allowed.
//
#define E_UNKNOWN_PARAM_INDEX_TYPE       ((DWORD)0xC00000D6L)

//
// MessageId: E_DB_IS_OPEN
//
// MessageText:
//
// Database file is open. 
//
#define E_DB_IS_OPEN                     ((DWORD)0xC00000D7L)

//
// MessageId: E_DB_IS_NOT_OPEN
//
// MessageText:
//
// Database file isn't open. 
//
#define E_DB_IS_NOT_OPEN                 ((DWORD)0xC00000D8L)

//
// MessageId: E_STMT_BAD_STEP_PARAMETER
//
// MessageText:
//
// Bad step parameter.
//
#define E_STMT_BAD_STEP_PARAMETER        ((DWORD)0xC00000D9L)

//
// MessageId: E_STMT_NON_QUERY_RETURNS_ROW
//
// MessageText:
//
// Non-query statement returns row.
//
#define E_STMT_NON_QUERY_RETURNS_ROW     ((DWORD)0xC00000DAL)

//
// MessageId: E_UNUPPORTED_VALUE_TYPE
//
// MessageText:
//
// Unsupported value type.
//
#define E_UNUPPORTED_VALUE_TYPE          ((DWORD)0xC00000DBL)

//
// MessageId: E_BAD_BINDING_VALUE
//
// MessageText:
//
// Bad binding value.
//
#define E_BAD_BINDING_VALUE              ((DWORD)0xC00000DCL)

//
// MessageId: E_TRANS_BEGIN_DISABLED
//
// MessageText:
//
// Begin transaction disabled.
//
#define E_TRANS_BEGIN_DISABLED           ((DWORD)0xC00000DDL)

//
// MessageId: E_TRANS_COMMIT_DISABLED
//
// MessageText:
//
// Begin transaction disabled.
//
#define E_TRANS_COMMIT_DISABLED          ((DWORD)0xC00000DEL)

//
// MessageId: E_TRANS_ROLLBACK_DISABLED
//
// MessageText:
//
// Rollback transaction disabled.
//
#define E_TRANS_ROLLBACK_DISABLED        ((DWORD)0xC00000DFL)

