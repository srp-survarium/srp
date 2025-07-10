void __cdecl EC_EX_DATA_free_data(
        ec_extra_data_st **ex_data,
        void *(__cdecl *dup_func)(void *),
        void (__cdecl *free_func)(void *),
        void (__cdecl *clear_free_func)(void *))
{
  void **v4; // esi
  void (__cdecl **v5)(void *); // eax
  void (__cdecl *v6)(void *); // edi

  v4 = (void **)ex_data;
  if ( ex_data && *ex_data )
  {
    while ( 1 )
    {
      v5 = (void (__cdecl **)(void *))*v4;
      if ( *((void *(__cdecl **)(void *))*v4 + 2) == dup_func && v5[3] == free_func && v5[4] == clear_free_func )
        break;
      v4 = (void **)*v4;
      if ( !*v5 )
        return;
    }
    v6 = *v5;
    v5[3](v5[1]);
    CRYPTO_free(*v4);
    *v4 = v6;
  }
}
