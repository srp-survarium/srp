void __cdecl ERR_STATE_free(err_state_st *s)
{
  char **err_data; // esi
  int v2; // edi

  if ( s )
  {
    err_data = s->err_data;
    v2 = 16;
    do
    {
      if ( *err_data )
      {
        if ( ((_BYTE)err_data[16] & 1) != 0 )
        {
          CRYPTO_free(*err_data);
          *err_data = 0;
        }
      }
      err_data[16] = 0;
      ++err_data;
      --v2;
    }
    while ( v2 );
    CRYPTO_free(s);
  }
}
