void __usercall ssl_cert_free(int a1@<edi>, cert_st *c)
{
  evp_pkey_st **p_privatekey; // esi
  int v3; // edi

  if ( c && CRYPTO_add_lock(&c->references, -1, 13, ".\\ssl\\ssl_cert.c", 348) <= 0 )
  {
    if ( c->rsa_tmp )
      RSA_free(a1, (int)c, c->rsa_tmp);
    if ( c->dh_tmp )
      DH_free(a1, (int)c, c->dh_tmp);
    if ( c->ecdh_tmp )
      EC_KEY_free(c->ecdh_tmp);
    p_privatekey = &c->pkeys[0].privatekey;
    v3 = 8;
    do
    {
      if ( *(p_privatekey - 1) )
        X509_free((x509_st *)*(p_privatekey - 1));
      if ( *p_privatekey )
        EVP_PKEY_free(v3, *p_privatekey);
      p_privatekey += 2;
      --v3;
    }
    while ( v3 );
    CRYPTO_free(c);
  }
}
