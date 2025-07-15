int __usercall ssl_set_cert@<eax>(cert_st *c@<edi>, x509_st *x)
{
  evp_pkey_st *pubkey; // eax
  evp_pkey_st *v3; // ebx
  int v5; // eax
  int v6; // esi
  evp_pkey_st *privatekey; // eax
  x509_st *x509; // eax
  cert_pkey_st *v9; // esi

  pubkey = X509_get_pubkey(x);
  v3 = pubkey;
  if ( pubkey )
  {
    v5 = ssl_cert_type(x, pubkey);
    v6 = v5;
    if ( v5 >= 0 )
    {
      if ( c->pkeys[v5].privatekey )
      {
        EVP_PKEY_copy_parameters(v3, c->pkeys[v5].privatekey);
        ERR_clear_error();
        privatekey = c->pkeys[v6].privatekey;
        if ( (privatekey->type != 6 || ((unsigned __int8)RSA_flags(privatekey->pkey.rsa) & 1) == 0)
          && !X509_check_private_key(x, c->pkeys[v6].privatekey) )
        {
          EVP_PKEY_free(c->pkeys[v6].privatekey);
          c->pkeys[v6].privatekey = 0;
          ERR_clear_error();
        }
      }
      EVP_PKEY_free(v3);
      x509 = c->pkeys[v6].x509;
      v9 = &c->pkeys[v6];
      if ( x509 )
        X509_free(x509);
      CRYPTO_add_lock(&x->references, 1, 3, ".\\ssl\\ssl_rsa.c", 445);
      v9->x509 = x;
      c->key = v9;
      c->valid = 0;
      return 1;
    }
    else
    {
      ERR_put_error(0x14u, 191, 247, ".\\ssl\\ssl_rsa.c", 409);
      EVP_PKEY_free(v3);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x14u, 191, 268, ".\\ssl\\ssl_rsa.c", 402);
    return 0;
  }
}
