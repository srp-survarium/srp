void __cdecl EC_EX_DATA_free_all_data(ec_extra_data_st **ex_data)
{
  void (__cdecl **v1)(_DWORD); // esi
  void (__cdecl *v2)(_DWORD); // edi

  if ( ex_data )
  {
    v1 = (void (__cdecl **)(_DWORD))*ex_data;
    if ( *ex_data )
    {
      do
      {
        v2 = *v1;
        v1[3](v1[1]);
        CRYPTO_free(v1);
        v1 = (void (__cdecl **)(_DWORD))v2;
      }
      while ( v2 );
    }
    *ex_data = 0;
  }
}
