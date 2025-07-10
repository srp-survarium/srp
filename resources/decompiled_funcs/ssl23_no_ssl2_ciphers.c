int __cdecl ssl23_no_ssl2_ciphers(ssl_st *s)
{
  stack_st_SSL_CIPHER *ciphers; // edi
  int v2; // esi

  ciphers = SSL_get_ciphers(s);
  v2 = 0;
  if ( sk_num(&ciphers->stack) <= 0 )
    return 1;
  while ( *((_DWORD *)sk_value(&ciphers->stack, v2) + 7) != 1 )
  {
    if ( ++v2 >= sk_num(&ciphers->stack) )
      return 1;
  }
  return 0;
}
