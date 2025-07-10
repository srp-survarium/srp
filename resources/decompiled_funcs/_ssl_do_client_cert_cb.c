int __cdecl ssl_do_client_cert_cb(ssl_st *s, x509_st **px509, evp_pkey_st **ppkey)
{
  int result; // eax
  stack_st_X509_NAME *client_CA_list; // eax
  int (__cdecl *client_cert_cb)(ssl_st *, x509_st **, evp_pkey_st **); // ecx

  result = 0;
  if ( !s->ctx->client_cert_engine
    || (client_CA_list = SSL_get_client_CA_list(s),
        (result = ENGINE_load_ssl_client_cert(s->ctx->client_cert_engine, s, client_CA_list, px509, ppkey, 0, 0, 0)) == 0) )
  {
    client_cert_cb = s->ctx->client_cert_cb;
    if ( client_cert_cb )
      return client_cert_cb(s, px509, ppkey);
  }
  return result;
}
