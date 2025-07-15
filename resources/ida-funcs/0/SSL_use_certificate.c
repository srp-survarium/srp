int __usercall SSL_use_certificate@<eax>(int a1@<ebx>, ssl_st *ssl, x509_st *x)
{
  if ( x )
  {
    if ( ssl_cert_inst(a1, &ssl->cert) )
    {
      return ssl_set_cert(ssl->cert, x);
    }
    else
    {
      ERR_put_error(a1, 0x14u, 198, 65, ".\\ssl\\ssl_rsa.c", 78);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x14u, 198, 67, ".\\ssl\\ssl_rsa.c", 73);
    return 0;
  }
}
