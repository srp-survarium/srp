int __usercall int_get_new_index@<eax>(
        int a1@<edi>,
        void *class_index,
        int argl,
        void *argp,
        int (__cdecl *new_func)(void *, void *, crypto_ex_data_st *, int, int, void *),
        int (__cdecl *dup_func)(crypto_ex_data_st *, crypto_ex_data_st *, void *, int, int, void *),
        void (__cdecl *free_func)(void *, void *, crypto_ex_data_st *, int, int, void *))
{
  st_ex_class_item *v7; // eax

  v7 = def_get_class(class_index, a1);
  if ( v7 )
    return def_add_index(v7, argl, argp, new_func, dup_func, free_func);
  else
    return -1;
}
