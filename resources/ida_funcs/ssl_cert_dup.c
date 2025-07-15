cert_st *__usercall ssl_cert_dup@<eax>(unsigned int a1@<edi>, cert_st *cert)
{
  char *v2; // eax
  char *v3; // esi
  dh_st *dh_tmp; // eax
  dh_st *v6; // eax
  bignum_st *v7; // eax
  dh_st *v8; // edx
  bignum_st *v9; // eax
  ec_key_st *v10; // eax
  evp_pkey_st **v11; // esi
  int v12; // edi
  int i; // edi
  x509_st *x509; // eax
  evp_pkey_st *privatekey; // eax

  v2 = (char *)CRYPTO_malloc(116, ".\\ssl\\ssl_cert.c", 186);
  v3 = v2;
  if ( !v2 )
  {
    ERR_put_error(0x14u, 221, 65, ".\\ssl\\ssl_cert.c", 189);
    return 0;
  }
  memset((int)v2, 0, 0x74u);
  *(_DWORD *)v3 = &v3[8 * (((char *)cert->key - (char *)cert - 48) >> 3) + 48];
  *((_DWORD *)v3 + 1) = cert->valid;
  *((_DWORD *)v3 + 2) = cert->mask_k;
  *((_DWORD *)v3 + 3) = cert->mask_a;
  *((_DWORD *)v3 + 4) = cert->export_mask_k;
  *((_DWORD *)v3 + 5) = cert->export_mask_a;
  if ( cert->rsa_tmp )
  {
    RSA_up_ref(cert->rsa_tmp);
    *((_DWORD *)v3 + 6) = cert->rsa_tmp;
  }
  *((_DWORD *)v3 + 7) = cert->rsa_tmp_cb;
  dh_tmp = cert->dh_tmp;
  if ( dh_tmp )
  {
    v6 = DHparams_dup(dh_tmp);
    *((_DWORD *)v3 + 8) = v6;
    if ( !v6 )
    {
      ERR_put_error(0x14u, 221, 5, ".\\ssl\\ssl_cert.c", 220);
LABEL_19:
      if ( *((_DWORD *)v3 + 6) )
        RSA_free(a1, *((rsa_st **)v3 + 6));
      if ( *((_DWORD *)v3 + 8) )
        DH_free(a1, *((dh_st **)v3 + 8));
      if ( *((_DWORD *)v3 + 10) )
        EC_KEY_free(*((ec_key_st **)v3 + 10));
      v11 = (evp_pkey_st **)(v3 + 52);
      v12 = 8;
      do
      {
        if ( *(v11 - 1) )
          X509_free((x509_st *)*(v11 - 1));
        if ( *v11 )
          EVP_PKEY_free(*v11);
        v11 += 2;
        --v12;
      }
      while ( v12 );
      return 0;
    }
    if ( cert->dh_tmp->priv_key )
    {
      v7 = BN_dup(cert->dh_tmp->priv_key);
      if ( !v7 )
      {
        ERR_put_error(0x14u, 221, 3, ".\\ssl\\ssl_cert.c", 228);
        goto LABEL_19;
      }
      *(_DWORD *)(*((_DWORD *)v3 + 8) + 24) = v7;
    }
    v8 = cert->dh_tmp;
    if ( v8->pub_key )
    {
      v9 = BN_dup(v8->pub_key);
      if ( !v9 )
      {
        ERR_put_error(0x14u, 221, 3, ".\\ssl\\ssl_cert.c", 238);
        goto LABEL_19;
      }
      *(_DWORD *)(*((_DWORD *)v3 + 8) + 20) = v9;
    }
  }
  *((_DWORD *)v3 + 9) = cert->dh_tmp_cb;
  if ( cert->ecdh_tmp )
  {
    v10 = EC_KEY_dup(cert->ecdh_tmp);
    *((_DWORD *)v3 + 10) = v10;
    if ( !v10 )
    {
      ERR_put_error(0x14u, 221, 16, ".\\ssl\\ssl_cert.c", 253);
      goto LABEL_19;
    }
  }
  *((_DWORD *)v3 + 11) = cert->ecdh_tmp_cb;
  for ( i = 0; i < 8; ++i )
  {
    x509 = cert->pkeys[i].x509;
    if ( x509 )
    {
      *(_DWORD *)&v3[8 * i + 48] = x509;
      CRYPTO_add_lock(&x509->references, 1, 3, ".\\ssl\\ssl_cert.c", 266);
    }
    privatekey = cert->pkeys[i].privatekey;
    if ( privatekey )
    {
      *(_DWORD *)&v3[8 * i + 52] = privatekey;
      CRYPTO_add_lock(&privatekey->references, 1, 10, ".\\ssl\\ssl_cert.c", 273);
      if ( (unsigned int)i > 5 )
        ERR_put_error(0x14u, 221, 274, ".\\ssl\\ssl_cert.c", 301);
    }
  }
  *((_DWORD *)v3 + 28) = 1;
  return (cert_st *)v3;
}
