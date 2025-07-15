ec_extra_data_st *__cdecl EC_EX_DATA_set_data(
        ec_extra_data_st **ex_data,
        void *data,
        void *(__cdecl *dup_func)(void *),
        void (__cdecl *free_func)(void *),
        void (__cdecl *clear_free_func)(void *))
{
  ec_extra_data_st *result; // eax
  ec_extra_data_st *v6; // eax

  if ( !ex_data )
    return 0;
  v6 = *ex_data;
  if ( !*ex_data )
  {
LABEL_8:
    if ( data )
    {
      result = (ec_extra_data_st *)CRYPTO_malloc(20, ".\\crypto\\ec\\ec_lib.c", 570);
      if ( !result )
        return result;
      result->data = data;
      result->dup_func = dup_func;
      result->free_func = free_func;
      result->clear_free_func = clear_free_func;
      result->next = *ex_data;
      *ex_data = result;
    }
    return (ec_extra_data_st *)1;
  }
  while ( v6->dup_func != dup_func || v6->free_func != free_func || v6->clear_free_func != clear_free_func )
  {
    v6 = v6->next;
    if ( !v6 )
      goto LABEL_8;
  }
  ERR_put_error((int)clear_free_func, 0x10u, 211, 108, ".\\crypto\\ec\\ec_lib.c", 561);
  return 0;
}
