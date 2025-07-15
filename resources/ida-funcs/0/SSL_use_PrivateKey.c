int __cdecl SSL_use_PrivateKey(ssl_st *ssl, evp_pkey_st *pkey)
{
  if ( pkey )
  {
    if ( ssl_cert_inst(&ssl->cert) )
    {
      return ssl_set_pkey(ssl->cert, pkey);
    }
    else
    {
      ERR_put_error(0x14u, 201, 65, ".\\ssl\\ssl_rsa.c", 306);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x14u, 201, 67, ".\\ssl\\ssl_rsa.c", 301);
    return 0;
  }
}
