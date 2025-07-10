void __usercall SSL_free(unsigned int a1@<edi>, ssl_st *s)
{
  bio_st *bbio; // eax
  bio_st *wbio; // eax
  stack_st_X509_EXTENSION *tlsext_ocsp_exts; // eax
  stack_st_OCSP_RESPID *tlsext_ocsp_ids; // eax
  stack_st_X509_NAME *client_CA; // eax
  const ssl_method_st *method; // eax

  if ( s && CRYPTO_add_lock(&s->references, -1, 16, ".\\ssl\\ssl_lib.c", 506) <= 0 )
  {
    if ( s->param )
      X509_VERIFY_PARAM_free(s->param);
    CRYPTO_free_ex_data(a1);
    bbio = s->bbio;
    if ( bbio )
    {
      if ( bbio == s->wbio )
        s->wbio = BIO_pop(s->wbio);
      BIO_free(a1, s->bbio);
      s->bbio = 0;
    }
    if ( s->rbio )
      BIO_free_all(s->rbio);
    wbio = s->wbio;
    if ( wbio && wbio != s->rbio )
      BIO_free_all(s->wbio);
    if ( s->init_buf )
      BUF_MEM_free(s->init_buf);
    if ( s->cipher_list )
      sk_free(&s->cipher_list->stack);
    if ( s->cipher_list_by_id )
      sk_free(&s->cipher_list_by_id->stack);
    if ( s->session )
    {
      ssl_clear_bad_session(s);
      SSL_SESSION_free(s->session);
    }
    ssl_clear_cipher_ctx(s);
    if ( s->read_hash )
      EVP_MD_CTX_destroy(a1, s->read_hash);
    s->read_hash = 0;
    if ( s->write_hash )
      EVP_MD_CTX_destroy(a1, s->write_hash);
    s->write_hash = 0;
    if ( s->cert )
      ssl_cert_free(s->cert);
    if ( s->tlsext_hostname )
      CRYPTO_free(s->tlsext_hostname);
    if ( s->initial_ctx )
      SSL_CTX_free(a1, s->initial_ctx);
    if ( s->tlsext_ecpointformatlist )
      CRYPTO_free(s->tlsext_ecpointformatlist);
    if ( s->tlsext_ellipticcurvelist )
      CRYPTO_free(s->tlsext_ellipticcurvelist);
    if ( s->tlsext_opaque_prf_input )
      CRYPTO_free(s->tlsext_opaque_prf_input);
    tlsext_ocsp_exts = s->tlsext_ocsp_exts;
    if ( tlsext_ocsp_exts )
      sk_pop_free(&tlsext_ocsp_exts->stack, (void (__cdecl *)(void *))X509_EXTENSION_free);
    tlsext_ocsp_ids = s->tlsext_ocsp_ids;
    if ( tlsext_ocsp_ids )
      sk_pop_free(&tlsext_ocsp_ids->stack, (void (__cdecl *)(void *))OCSP_RESPID_free);
    if ( s->tlsext_ocsp_resp )
      CRYPTO_free(s->tlsext_ocsp_resp);
    client_CA = s->client_CA;
    if ( client_CA )
      sk_pop_free(&client_CA->stack, (void (__cdecl *)(void *))X509_NAME_free);
    method = s->method;
    if ( method )
      method->ssl_free(s);
    if ( s->ctx )
      SSL_CTX_free(a1, s->ctx);
    CRYPTO_free(s);
  }
}
