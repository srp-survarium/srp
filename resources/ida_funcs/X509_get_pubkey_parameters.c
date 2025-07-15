int __cdecl X509_get_pubkey_parameters(evp_pkey_st *pkey, stack_st_X509 *chain)
{
  int v3; // edi
  x509_st *v4; // eax
  const evp_pkey_st *pubkey; // eax
  evp_pkey_st *v6; // esi
  int i; // ebx
  x509_st *v8; // eax
  evp_pkey_st *v9; // edi

  if ( pkey && !EVP_PKEY_missing_parameters(pkey) )
    return 1;
  v3 = 0;
  if ( sk_num(&chain->stack) <= 0 )
  {
LABEL_8:
    ERR_put_error(0xBu, 110, 107, ".\\crypto\\x509\\x509_vfy.c", 1809);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = (x509_st *)sk_value(&chain->stack, v3);
      pubkey = X509_get_pubkey(v4);
      v6 = (evp_pkey_st *)pubkey;
      if ( !pubkey )
      {
        ERR_put_error(0xBu, 110, 108, ".\\crypto\\x509\\x509_vfy.c", 1796);
        return 0;
      }
      if ( !EVP_PKEY_missing_parameters(pubkey) )
        break;
      EVP_PKEY_free(v6);
      if ( ++v3 >= sk_num(&chain->stack) )
        goto LABEL_8;
    }
    for ( i = v3 - 1; i >= 0; --i )
    {
      v8 = (x509_st *)sk_value(&chain->stack, i);
      v9 = X509_get_pubkey(v8);
      EVP_PKEY_copy_parameters(v9, v6);
      EVP_PKEY_free(v9);
    }
    if ( pkey )
      EVP_PKEY_copy_parameters(pkey, v6);
    EVP_PKEY_free(v6);
    return 1;
  }
}
