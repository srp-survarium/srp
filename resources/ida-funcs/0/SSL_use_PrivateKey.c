int __usercall SSL_use_PrivateKey@<eax>(int a1@<ebx>, ssl_st *ssl, evp_pkey_st *pkey)
{
  if ( pkey )
  {
    if ( ssl_cert_inst(a1, &ssl->cert) )
    {
      return ssl_set_pkey(ssl->cert, pkey);
    }
    else
    {
      ERR_put_error(a1, 0x14u, 201, 65, ".\\ssl\\ssl_rsa.c", 306);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x14u, 201, 67, ".\\ssl\\ssl_rsa.c", 301);
    return 0;
  }
}
