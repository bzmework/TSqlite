/*
	unaccfn.h
*/

/*
** Make sure we can call this stuff from C++.
*/
#ifdef __cplusplus
extern "C" {
#endif 

void* sqlite3_register_unacc_functions(sqlite3*);
void sqlite3_unregister_unacc_functions(sqlite3*,void*);


#ifdef __cplusplus
}  /* End of the 'extern "C"' block */
#endif 
