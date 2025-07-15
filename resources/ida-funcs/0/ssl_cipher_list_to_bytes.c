int __cdecl ssl_cipher_list_to_bytes(
        ssl_st *s,
        stack_st_SSL_CIPHER *sk,
        unsigned __int8 *p,
        int (__cdecl *put_cb)(const ssl_cipher_st *, unsigned __int8 *))
{
  unsigned __int8 *v5; // esi
  int v6; // edi
  char *v7; // eax
  int v8; // eax

  if ( !sk )
    return 0;
  v5 = p;
  v6 = 0;
  if ( sk_num(&sk->stack) > 0 )
  {
    do
    {
      v7 = sk_value(&sk->stack, v6);
      if ( (*((_DWORD *)v7 + 3) & 0x100) == 0 && v7[16] >= 0 || s->psk_client_callback )
      {
        if ( put_cb )
          v8 = put_cb((const ssl_cipher_st *)v7, v5);
        else
          v8 = s->method->put_cipher_by_char((const ssl_cipher_st *)v7, v5);
        v5 += v8;
      }
      ++v6;
    }
    while ( v6 < sk_num(&sk->stack) );
    if ( v5 != p && !s->new_session )
    {
      if ( put_cb )
        return &v5[put_cb(&scsv, v5)] - p;
      v5 += s->method->put_cipher_by_char(&scsv, v5);
    }
  }
  return v5 - p;
}
