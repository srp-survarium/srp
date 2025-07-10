void __usercall SSL_SESSION_free(unsigned int a1@<edi>, ssl_session_st *ss)
{
  unsigned __int8 *tlsext_ecpointformatlist; // eax
  unsigned __int8 *tlsext_ellipticcurvelist; // eax

  if ( ss && CRYPTO_add_lock(&ss->references, -1, 14, ".\\ssl\\ssl_sess.c", 695) <= 0 )
  {
    CRYPTO_free_ex_data(a1);
    OPENSSL_cleanse(ss->key_arg, 8);
    OPENSSL_cleanse(ss->master_key, 48);
    OPENSSL_cleanse(ss->session_id, 32);
    if ( ss->sess_cert )
      ssl_sess_cert_free(ss->sess_cert);
    if ( ss->peer )
      X509_free(ss->peer);
    if ( ss->ciphers )
      sk_free(&ss->ciphers->stack);
    if ( ss->tlsext_hostname )
      CRYPTO_free(ss->tlsext_hostname);
    if ( ss->tlsext_tick )
      CRYPTO_free(ss->tlsext_tick);
    tlsext_ecpointformatlist = ss->tlsext_ecpointformatlist;
    ss->tlsext_ecpointformatlist_length = 0;
    if ( tlsext_ecpointformatlist )
      CRYPTO_free(tlsext_ecpointformatlist);
    tlsext_ellipticcurvelist = ss->tlsext_ellipticcurvelist;
    ss->tlsext_ellipticcurvelist_length = 0;
    if ( tlsext_ellipticcurvelist )
      CRYPTO_free(tlsext_ellipticcurvelist);
    if ( ss->psk_identity_hint )
      CRYPTO_free(ss->psk_identity_hint);
    if ( ss->psk_identity )
      CRYPTO_free(ss->psk_identity);
    OPENSSL_cleanse(ss, 240);
    CRYPTO_free(ss);
  }
}
