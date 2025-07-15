int __usercall ssl_set_pkey@<eax>(cert_st *c@<esi>, evp_pkey_st *pkey@<edi>)
{
  int v2; // eax
  int v3; // ebx
  x509_st *x509; // eax
  cert_pkey_st *v6; // ebp
  evp_pkey_st *v7; // [esp+0h] [ebp-Ch]
  evp_pkey_st *x; // [esp+8h] [ebp-4h]

  v2 = ssl_cert_type(0, v7);
  v3 = v2;
  if ( v2 >= 0 )
  {
    x509 = c->pkeys[v2].x509;
    v6 = &c->pkeys[v3];
    if ( !x509
      || (x = X509_get_pubkey(x509),
          EVP_PKEY_copy_parameters(v3, x, pkey),
          EVP_PKEY_free((int)pkey, x),
          ERR_clear_error(v3),
          pkey->type == 6)
      && ((unsigned __int8)RSA_flags(pkey->pkey.rsa) & 1) != 0
      || X509_check_private_key(v3, v6->x509, pkey) )
    {
      if ( c->pkeys[v3].privatekey )
        EVP_PKEY_free((int)pkey, c->pkeys[v3].privatekey);
      CRYPTO_add_lock(&pkey->references, 1, 10, ".\\ssl\\ssl_rsa.c", 219);
      c->pkeys[v3].privatekey = pkey;
      c->key = v6;
      c->valid = 0;
      return 1;
    }
    else
    {
      X509_free(v6->x509);
      v6->x509 = 0;
      return 0;
    }
  }
  else
  {
    ERR_put_error(v2, 0x14u, 193, 247, ".\\ssl\\ssl_rsa.c", 189);
    return 0;
  }
}
