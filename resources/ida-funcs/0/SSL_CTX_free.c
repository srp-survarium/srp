void __usercall SSL_CTX_free(unsigned int a1@<edi>, ssl_ctx_st *a)
{
  stack_st_X509_NAME *client_CA; // eax
  stack_st_X509 *extra_certs; // eax
  char *psk_identity_hint; // eax
  ssl3_buf_freelist_st *wbuf_freelist; // edi
  ssl3_buf_freelist_st *rbuf_freelist; // edi

  if ( a && CRYPTO_add_lock(&a->references, -1, 12, ".\\ssl\\ssl_lib.c", 1730) <= 0 )
  {
    if ( a->param )
      X509_VERIFY_PARAM_free(a->param);
    if ( a->sessions )
      SSL_CTX_flush_sessions(a, 0);
    CRYPTO_free_ex_data(a1);
    if ( a->sessions )
      lh_free((lhash_st *)a->sessions);
    if ( a->cert_store )
      X509_STORE_free(a->cert_store);
    if ( a->cipher_list )
      sk_free(&a->cipher_list->stack);
    if ( a->cipher_list_by_id )
      sk_free(&a->cipher_list_by_id->stack);
    if ( a->cert )
      ssl_cert_free(a->cert);
    client_CA = a->client_CA;
    if ( client_CA )
      sk_pop_free(&client_CA->stack, (void (__cdecl *)(void *))X509_NAME_free);
    extra_certs = a->extra_certs;
    if ( extra_certs )
      sk_pop_free(&extra_certs->stack, (void (__cdecl *)(void *))X509_free);
    psk_identity_hint = a->psk_identity_hint;
    a->comp_methods = 0;
    if ( psk_identity_hint )
      CRYPTO_free(psk_identity_hint);
    if ( a->client_cert_engine )
      ENGINE_finish(a1, a->client_cert_engine);
    wbuf_freelist = a->wbuf_freelist;
    if ( wbuf_freelist )
      ssl_buf_freelist_free(wbuf_freelist);
    rbuf_freelist = a->rbuf_freelist;
    if ( rbuf_freelist )
      ssl_buf_freelist_free(rbuf_freelist);
    CRYPTO_free(a);
  }
}
