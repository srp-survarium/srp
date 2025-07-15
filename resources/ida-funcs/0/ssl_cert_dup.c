cert_st *__usercall ssl_cert_dup@<eax>(int a1@<edi>, int a2@<ebx>, const ec_key_st *cert)
{
  char *v3; // eax
  char *v4; // esi
  dh_st *version; // eax
  dh_st *v7; // eax
  bignum_st *v8; // eax
  dh_st *v9; // edx
  bignum_st *v10; // eax
  ec_key_st *v11; // eax
  evp_pkey_st **v12; // esi
  int v13; // edi
  int i; // edi
  x509_st *v15; // eax
  evp_pkey_st *v16; // eax

  v3 = (char *)CRYPTO_malloc(116, ".\\ssl\\ssl_cert.c", 186);
  v4 = v3;
  if ( !v3 )
  {
    ERR_put_error(a2, 0x14u, 221, 65, ".\\ssl\\ssl_cert.c", 189);
    return 0;
  }
  memset((int)v3, 0, 116);
  *(_DWORD *)v4 = &v4[8 * ((cert->version - (int)cert - 48) >> 3) + 48];
  *((_DWORD *)v4 + 1) = cert->group;
  *((_DWORD *)v4 + 2) = cert->pub_key;
  *((_DWORD *)v4 + 3) = cert->priv_key;
  *((_DWORD *)v4 + 4) = cert->enc_flag;
  *((_DWORD *)v4 + 5) = cert->conv_form;
  if ( cert->references )
  {
    RSA_up_ref((rsa_st *)cert->references);
    *((_DWORD *)v4 + 6) = cert->references;
  }
  *((_DWORD *)v4 + 7) = cert->method_data;
  version = (dh_st *)cert[1].version;
  if ( version )
  {
    v7 = DHparams_dup((int)cert, version);
    *((_DWORD *)v4 + 8) = v7;
    if ( !v7 )
    {
      ERR_put_error((int)cert, 0x14u, 221, 5, ".\\ssl\\ssl_cert.c", 220);
LABEL_19:
      if ( *((_DWORD *)v4 + 6) )
        RSA_free(a1, (int)cert, *((rsa_st **)v4 + 6));
      if ( *((_DWORD *)v4 + 8) )
        DH_free(a1, (int)cert, *((dh_st **)v4 + 8));
      if ( *((_DWORD *)v4 + 10) )
        EC_KEY_free(*((ec_key_st **)v4 + 10));
      v12 = (evp_pkey_st **)(v4 + 52);
      v13 = 8;
      do
      {
        if ( *(v12 - 1) )
          X509_free((x509_st *)*(v12 - 1));
        if ( *v12 )
          EVP_PKEY_free(v13, *v12);
        v12 += 2;
        --v13;
      }
      while ( v13 );
      return 0;
    }
    if ( *(_DWORD *)(cert[1].version + 24) )
    {
      v8 = BN_dup((int)cert, *(const bignum_st **)(cert[1].version + 24));
      if ( !v8 )
      {
        ERR_put_error((int)cert, 0x14u, 221, 3, ".\\ssl\\ssl_cert.c", 228);
        goto LABEL_19;
      }
      *(_DWORD *)(*((_DWORD *)v4 + 8) + 24) = v8;
    }
    v9 = (dh_st *)cert[1].version;
    if ( v9->pub_key )
    {
      v10 = BN_dup((int)cert, v9->pub_key);
      if ( !v10 )
      {
        ERR_put_error((int)cert, 0x14u, 221, 3, ".\\ssl\\ssl_cert.c", 238);
        goto LABEL_19;
      }
      *(_DWORD *)(*((_DWORD *)v4 + 8) + 20) = v10;
    }
  }
  *((_DWORD *)v4 + 9) = cert[1].group;
  if ( cert[1].pub_key )
  {
    v11 = EC_KEY_dup(cert, (const ec_key_st *)cert[1].pub_key);
    *((_DWORD *)v4 + 10) = v11;
    if ( !v11 )
    {
      ERR_put_error((int)cert, 0x14u, 221, 16, ".\\ssl\\ssl_cert.c", 253);
      goto LABEL_19;
    }
  }
  *((_DWORD *)v4 + 11) = cert[1].priv_key;
  for ( i = 0; i < 8; ++i )
  {
    v15 = (x509_st *)*(&cert[1].enc_flag + 2 * i);
    if ( v15 )
    {
      *(_DWORD *)&v4[8 * i + 48] = v15;
      CRYPTO_add_lock(&v15->references, 1, 3, ".\\ssl\\ssl_cert.c", 266);
    }
    v16 = (evp_pkey_st *)*((_DWORD *)&cert[1].conv_form + 2 * i);
    if ( v16 )
    {
      *(_DWORD *)&v4[8 * i + 52] = v16;
      CRYPTO_add_lock(&v16->references, 1, 10, ".\\ssl\\ssl_cert.c", 273);
      if ( (unsigned int)i > 5 )
        ERR_put_error((int)cert, 0x14u, 221, 274, ".\\ssl\\ssl_cert.c", 301);
    }
  }
  *((_DWORD *)v4 + 28) = 1;
  return (cert_st *)v4;
}
