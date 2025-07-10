ssl_st *__usercall SSL_new@<eax>(int *p_session@<edi>, unsigned int a2@<esi>, ssl_ctx_st *ctx)
{
  ssl_st *v4; // eax
  ssl_st *v5; // ebx
  cert_st *v6; // eax
  unsigned int sid_ctx_length; // eax
  X509_VERIFY_PARAM_st *v8; // eax
  const ssl_method_st *method; // eax

  if ( !ctx )
  {
    ERR_put_error(0x14u, 186, 195, ".\\ssl\\ssl_lib.c", 278);
    return 0;
  }
  if ( !ctx->method )
  {
    ERR_put_error(0x14u, 186, 228, ".\\ssl\\ssl_lib.c", 283);
    return 0;
  }
  v4 = (ssl_st *)CRYPTO_malloc(372, ".\\ssl\\ssl_lib.c", 287);
  v5 = v4;
  if ( !v4 )
    goto LABEL_19;
  memset((int)v4, 0, sizeof(ssl_st));
  v5->options = ctx->options;
  v5->mode = ctx->mode;
  v5->max_cert_list = ctx->max_cert_list;
  if ( ctx->cert )
  {
    v6 = ssl_cert_dup(ctx->cert);
    v5->cert = v6;
    if ( !v6 )
    {
err_212:
      if ( v5->cert )
        ssl_cert_free(v5->cert);
      if ( v5->ctx )
        SSL_CTX_free((unsigned int)p_session, v5->ctx);
      CRYPTO_free(v5);
LABEL_19:
      ERR_put_error(0x14u, 186, 65, ".\\ssl\\ssl_lib.c", 387);
      return 0;
    }
  }
  else
  {
    v5->cert = 0;
  }
  v5->read_ahead = ctx->read_ahead;
  v5->msg_callback = ctx->msg_callback;
  v5->msg_callback_arg = ctx->msg_callback_arg;
  v5->verify_mode = ctx->verify_mode;
  sid_ctx_length = ctx->sid_ctx_length;
  v5->sid_ctx_length = sid_ctx_length;
  if ( sid_ctx_length > 0x20 )
    OpenSSLDie((unsigned int)p_session, a2, ".\\ssl\\ssl_lib.c", 326, "s->sid_ctx_length <= sizeof s->sid_ctx");
  qmemcpy(v5->sid_ctx, ctx->sid_ctx, sizeof(v5->sid_ctx));
  p_session = (int *)&v5->session;
  v5->verify_callback = ctx->default_verify_callback;
  v5->generate_session_id = ctx->generate_session_id;
  v8 = X509_VERIFY_PARAM_new();
  v5->param = v8;
  if ( !v8 )
    goto err_212;
  X509_VERIFY_PARAM_inherit(v8, ctx->param);
  v5->quiet_shutdown = ctx->quiet_shutdown;
  p_session = &ctx->references;
  v5->max_send_fragment = ctx->max_send_fragment;
  CRYPTO_add_lock(&ctx->references, 1, 12, ".\\ssl\\ssl_lib.c", 342);
  v5->ctx = ctx;
  v5->tlsext_debug_cb = 0;
  v5->tlsext_debug_arg = 0;
  v5->tlsext_ticket_expected = 0;
  v5->tlsext_status_type = -1;
  v5->tlsext_status_expected = 0;
  v5->tlsext_ocsp_ids = 0;
  v5->tlsext_ocsp_exts = 0;
  v5->tlsext_ocsp_resp = 0;
  v5->tlsext_ocsp_resplen = -1;
  CRYPTO_add_lock(&ctx->references, 1, 12, ".\\ssl\\ssl_lib.c", 354);
  v5->initial_ctx = ctx;
  v5->verify_result = 0;
  method = ctx->method;
  v5->method = ctx->method;
  if ( !method->ssl_new(v5) )
    goto err_212;
  v5->references = 1;
  v5->server = ctx->method->ssl_accept != (int (__cdecl *)(ssl_st *))ssl_undefined_function;
  SSL_clear(v5);
  CRYPTO_new_ex_data((unsigned int)p_session);
  v5->psk_client_callback = ctx->psk_client_callback;
  v5->psk_server_callback = ctx->psk_server_callback;
  return v5;
}
