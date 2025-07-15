int __cdecl ssl_prepare_clienthello_tlsext(ssl_st *s)
{
  stack_st_SSL_CIPHER *ciphers; // ebp
  int v2; // edi
  char *v3; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned int i; // ecx

  ciphers = SSL_get_ciphers(s);
  v2 = 0;
  if ( sk_num(&ciphers->stack) > 0 )
  {
    while ( 1 )
    {
      v3 = sk_value(&ciphers->stack, v2);
      if ( (v3[12] & 0xE0) != 0 || (v3[16] & 0x40) != 0 )
        break;
      if ( ++v2 >= sk_num(&ciphers->stack) )
        return 1;
    }
    if ( s->version == 769 )
    {
      if ( s->tlsext_ecpointformatlist )
        CRYPTO_free(s->tlsext_ecpointformatlist);
      v5 = (unsigned __int8 *)CRYPTO_malloc(3, ".\\ssl\\t1_lib.c", 1243);
      s->tlsext_ecpointformatlist = v5;
      if ( !v5 )
      {
        ERR_put_error(0x14u, 281, 65, ".\\ssl\\t1_lib.c", 1245);
        return -1;
      }
      s->tlsext_ecpointformatlist_length = 3;
      *v5 = 0;
      s->tlsext_ecpointformatlist[1] = 1;
      s->tlsext_ecpointformatlist[2] = 2;
      if ( s->tlsext_ellipticcurvelist )
        CRYPTO_free(s->tlsext_ellipticcurvelist);
      s->tlsext_ellipticcurvelist_length = 50;
      v6 = (unsigned __int8 *)CRYPTO_malloc(50, ".\\ssl\\t1_lib.c", 1256);
      s->tlsext_ellipticcurvelist = v6;
      if ( !v6 )
      {
        s->tlsext_ellipticcurvelist_length = 0;
        ERR_put_error(0x14u, 281, 65, ".\\ssl\\t1_lib.c", 1259);
        return -1;
      }
      for ( i = 1; i <= 0x19; ++i )
      {
        v6[1] = i;
        *v6 = BYTE1(i);
        v6 += 2;
      }
    }
  }
  return 1;
}
