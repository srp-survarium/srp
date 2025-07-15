int __usercall SSL_get_ex_data_X509_STORE_CTX_idx@<eax>(unsigned int a1@<edi>)
{
  CRYPTO_lock(a1, 5, 12, ".\\ssl\\ssl_cert.c", 140);
  if ( ssl_x509_store_ctx_idx >= 0 )
  {
    CRYPTO_lock(a1, 6, 12, ".\\ssl\\ssl_cert.c", 158);
    return ssl_x509_store_ctx_idx;
  }
  else
  {
    CRYPTO_lock(a1, 6, 12, ".\\ssl\\ssl_cert.c", 144);
    CRYPTO_lock(a1, 9, 12, ".\\ssl\\ssl_cert.c", 145);
    if ( ssl_x509_store_ctx_idx < 0 )
      ssl_x509_store_ctx_idx = X509_STORE_CTX_get_ex_new_index(a1);
    CRYPTO_lock(a1, 10, 12, ".\\ssl\\ssl_cert.c", 156);
    return ssl_x509_store_ctx_idx;
  }
}
