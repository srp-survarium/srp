void *__cdecl EC_EX_DATA_get_data(
        const ec_extra_data_st *ex_data,
        void *(__cdecl *dup_func)(void *),
        void (__cdecl *free_func)(void *),
        void (__cdecl *clear_free_func)(void *))
{
  const ec_extra_data_st *v4; // eax

  v4 = ex_data;
  if ( !ex_data )
    return 0;
  while ( v4->dup_func != dup_func || v4->free_func != free_func || v4->clear_free_func != clear_free_func )
  {
    v4 = v4->next;
    if ( !v4 )
      return 0;
  }
  return v4->data;
}
