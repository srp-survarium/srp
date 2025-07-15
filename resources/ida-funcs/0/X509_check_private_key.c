BOOL __usercall X509_check_private_key@<eax>(int a1@<ebx>, x509_st *x, evp_pkey_st *k)
{
  const evp_pkey_st *v3; // eax
  evp_pkey_st *v4; // esi
  int v5; // eax
  int v6; // edi

  if ( !x || !x->cert_info )
  {
    v4 = 0;
    goto LABEL_9;
  }
  v3 = X509_PUBKEY_get(x->cert_info->key);
  v4 = (evp_pkey_st *)v3;
  if ( !v3 )
  {
LABEL_9:
    v6 = -2;
    goto LABEL_10;
  }
  v5 = EVP_PKEY_cmp(v3, k);
  v6 = v5;
  switch ( v5 )
  {
    case -2:
LABEL_10:
      ERR_put_error(a1, 0xBu, 128, 117, ".\\crypto\\x509\\x509_cmp.c", 324);
      break;
    case -1:
      ERR_put_error(a1, 0xBu, 128, 115, ".\\crypto\\x509\\x509_cmp.c", 321);
      break;
    case 0:
      ERR_put_error(a1, 0xBu, 128, 116, ".\\crypto\\x509\\x509_cmp.c", 318);
      break;
  }
  if ( v4 )
    EVP_PKEY_free(v4);
  return v6 > 0;
}
