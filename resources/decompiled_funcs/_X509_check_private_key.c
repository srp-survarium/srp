BOOL __cdecl X509_check_private_key(x509_st *x, evp_pkey_st *k)
{
  const evp_pkey_st *v2; // eax
  evp_pkey_st *v3; // esi
  int v4; // eax
  int v5; // edi

  if ( !x || !x->cert_info )
  {
    v3 = 0;
    goto LABEL_9;
  }
  v2 = X509_PUBKEY_get(x->cert_info->key);
  v3 = (evp_pkey_st *)v2;
  if ( !v2 )
  {
LABEL_9:
    v5 = -2;
    goto LABEL_10;
  }
  v4 = EVP_PKEY_cmp(v2, k);
  v5 = v4;
  switch ( v4 )
  {
    case -2:
LABEL_10:
      ERR_put_error(0xBu, 128, 117, ".\\crypto\\x509\\x509_cmp.c", 324);
      break;
    case -1:
      ERR_put_error(0xBu, 128, 115, ".\\crypto\\x509\\x509_cmp.c", 321);
      break;
    case 0:
      ERR_put_error(0xBu, 128, 116, ".\\crypto\\x509\\x509_cmp.c", 318);
      break;
  }
  if ( v3 )
    EVP_PKEY_free(v3);
  return v5 > 0;
}
