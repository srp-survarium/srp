int __usercall ssl_prepare_clienthello_tlsext@<eax>(int a1@<ebx>, ssl_st *s)
{
  stack_st_SSL_CIPHER *ciphers; // ebp
  int v3; // edi
  char *v4; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  unsigned int i; // ecx

  ciphers = SSL_get_ciphers(s);
  v3 = 0;
  if ( sk_num(&ciphers->stack) > 0 )
  {
    while ( 1 )
    {
      v4 = sk_value(&ciphers->stack, v3);
      if ( (v4[12] & 0xE0) != 0 || (v4[16] & 0x40) != 0 )
        break;
      if ( ++v3 >= sk_num(&ciphers->stack) )
        return 1;
    }
    if ( s->version == 769 )
    {
      if ( s->tlsext_ecpointformatlist )
        CRYPTO_free(s->tlsext_ecpointformatlist);
      v6 = (unsigned __int8 *)CRYPTO_malloc(3, ".\\ssl\\t1_lib.c", 1243);
      s->tlsext_ecpointformatlist = v6;
      if ( !v6 )
      {
        ERR_put_error(a1, 0x14u, 281, 65, ".\\ssl\\t1_lib.c", 1245);
        return -1;
      }
      s->tlsext_ecpointformatlist_length = 3;
      *v6 = 0;
      s->tlsext_ecpointformatlist[1] = 1;
      s->tlsext_ecpointformatlist[2] = 2;
      if ( s->tlsext_ellipticcurvelist )
        CRYPTO_free(s->tlsext_ellipticcurvelist);
      s->tlsext_ellipticcurvelist_length = 50;
      v7 = (unsigned __int8 *)CRYPTO_malloc(50, ".\\ssl\\t1_lib.c", 1256);
      s->tlsext_ellipticcurvelist = v7;
      if ( !v7 )
      {
        s->tlsext_ellipticcurvelist_length = 0;
        ERR_put_error(a1, 0x14u, 281, 65, ".\\ssl\\t1_lib.c", 1259);
        return -1;
      }
      for ( i = 1; i <= 0x19; ++i )
      {
        v7[1] = i;
        *v7 = BYTE1(i);
        v7 += 2;
      }
    }
  }
  return 1;
}
