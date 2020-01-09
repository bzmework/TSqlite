/*
	BlobFn.h
*/

/*
** Make sure we can call this stuff from C++.
*/
#ifdef __cplusplus
extern "C" {
#endif 

void sqlite3_register_blob_functions(sqlite3 *);

#ifdef __cplusplus
}  /* End of the 'extern "C"' block */
#endif 
