int __usercall X509_get_pubkey_parameters@<eax>(int a1@<ebx>, evp_pkey_st *pkey, stack_st_X509 *chain)
{
  int v4; // edi
  char *v5; // eax
  const evp_pkey_st *pubkey; // eax
  evp_pkey_st *v7; // esi
  int i; // ebx
  char *v9; // eax
  evp_pkey_st *v10; // edi

  if ( pkey && !EVP_PKEY_missing_parameters(pkey) )
    return 1;
  v4 = 0;
  if ( sk_num(&chain->stack) <= 0 )
  {
LABEL_8:
    ERR_put_error(a1, 0xBu, 110, 107, ".\\crypto\\x509\\x509_vfy.c", 1809);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = sk_value(&chain->stack, v4);
      pubkey = X509_get_pubkey((x509_st *)v5);
      v7 = (evp_pkey_st *)pubkey;
      if ( !pubkey )
      {
        ERR_put_error(a1, 0xBu, 110, 108, ".\\crypto\\x509\\x509_vfy.c", 1796);
        return 0;
      }
      if ( !EVP_PKEY_missing_parameters(pubkey) )
        break;
      EVP_PKEY_free(v7);
      if ( ++v4 >= sk_num(&chain->stack) )
        goto LABEL_8;
    }
    for ( i = v4 - 1; i >= 0; --i )
    {
      v9 = sk_value(&chain->stack, i);
      v10 = X509_get_pubkey((x509_st *)v9);
      EVP_PKEY_copy_parameters(v10, v7);
      EVP_PKEY_free(v10);
    }
    if ( pkey )
      EVP_PKEY_copy_parameters(pkey, v7);
    EVP_PKEY_free(v7);
    return 1;
  }
}
