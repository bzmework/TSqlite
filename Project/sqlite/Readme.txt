https://www.sqlite.org/download.html

Extract sqlite-amalgamation-*.zip here.

The file sqlite3.c need minor modifications 9 version 3.4.2).
All declarations of arrays must be without preceding SQLITE_PRIVATE macro.
This is a bug of VC 2005 compiler. I do not know another method to avoid it.

2019-01-11
����sqlite-amalgamation-3260000 version 3.26.0.����

2020-01-09
����sqlite-amalgamation-3300100 version 3.30.1.����