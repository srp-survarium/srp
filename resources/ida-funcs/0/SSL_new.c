ssl_st *__usercall SSL_new@<eax>(int *p_session@<edi>, int a2@<esi>, int a3@<ebx>, ssl_ctx_st *ctx)
{
  void *v5; // eax
  int v6; // ebx
  cert_st *v7; // eax
  unsigned int sid_ctx_length; // eax
  X509_VERIFY_PARAM_st *v9; // eax
  const ssl_method_st *method; // eax

  if ( !ctx )
  {
    ERR_put_error(a3, 0x14u, 186, 195, ".\\ssl\\ssl_lib.c", 278);
    return 0;
  }
  if ( !ctx->method )
  {
    ERR_put_error(a3, 0x14u, 186, 228, ".\\ssl\\ssl_lib.c", 283);
    return 0;
  }
  v5 = CRYPTO_malloc(372, ".\\ssl\\ssl_lib.c", 287);
  v6 = (int)v5;
  if ( !v5 )
    goto LABEL_19;
  memset((int)v5, 0, 372);
  *(_DWORD *)(v6 + 256) = ctx->options;
  *(_DWORD *)(v6 + 260) = ctx->mode;
  *(_DWORD *)(v6 + 264) = ctx->max_cert_list;
  if ( ctx->cert )
  {
    v7 = ssl_cert_dup((int)p_session, ctx->cert);
    *(_DWORD *)(v6 + 152) = v7;
    if ( !v7 )
    {
err_214:
      if ( *(_DWORD *)(v6 + 152) )
        ssl_cert_free((int)p_session, *(cert_st **)(v6 + 152));
      if ( *(_DWORD *)(v6 + 228) )
        SSL_CTX_free((int)p_session, v6, *(ssl_ctx_st **)(v6 + 228));
      CRYPTO_free((void *)v6);
LABEL_19:
      ERR_put_error(v6, 0x14u, 186, 65, ".\\ssl\\ssl_lib.c", 387);
      return 0;
    }
  }
  else
  {
    *(_DWORD *)(v6 + 152) = 0;
  }
  *(_DWORD *)(v6 + 96) = ctx->read_ahead;
  *(_DWORD *)(v6 + 100) = ctx->msg_callback;
  *(_DWORD *)(v6 + 104) = ctx->msg_callback_arg;
  *(_DWORD *)(v6 + 200) = ctx->verify_mode;
  sid_ctx_length = ctx->sid_ctx_length;
  *(_DWORD *)(v6 + 156) = sid_ctx_length;
  if ( sid_ctx_length > 0x20 )
    OpenSSLDie((int)p_session, a2, v6, ".\\ssl\\ssl_lib.c", 326, "s->sid_ctx_length <= sizeof s->sid_ctx");
  qmemcpy((void *)(v6 + 160), ctx->sid_ctx, 0x20u);
  p_session = (int *)(v6 + 192);
  *(_DWORD *)(v6 + 204) = ctx->default_verify_callback;
  *(_DWORD *)(v6 + 196) = ctx->generate_session_id;
  v9 = X509_VERIFY_PARAM_new();
  *(_DWORD *)(v6 + 112) = v9;
  if ( !v9 )
    goto err_214;
  X509_VERIFY_PARAM_inherit(v9, ctx->param);
  *(_DWORD *)(v6 + 44) = ctx->quiet_shutdown;
  p_session = &ctx->references;
  *(_DWORD *)(v6 + 276) = ctx->max_send_fragment;
  CRYPTO_add_lock(&ctx->references, 1, 12, ".\\ssl\\ssl_lib.c", 342);
  *(_DWORD *)(v6 + 228) = ctx;
  *(_DWORD *)(v6 + 280) = 0;
  *(_DWORD *)(v6 + 284) = 0;
  *(_DWORD *)(v6 + 320) = 0;
  *(_DWORD *)(v6 + 296) = -1;
  *(_DWORD *)(v6 + 300) = 0;
  *(_DWORD *)(v6 + 304) = 0;
  *(_DWORD *)(v6 + 308) = 0;
  *(_DWORD *)(v6 + 312) = 0;
  *(_DWORD *)(v6 + 316) = -1;
  CRYPTO_add_lock(&ctx->references, 1, 12, ".\\ssl\\ssl_lib.c", 354);
  *(_DWORD *)(v6 + 368) = ctx;
  *(_DWORD *)(v6 + 236) = 0;
  method = ctx->method;
  *(_DWORD *)(v6 + 8) = ctx->method;
  if ( !method->ssl_new((ssl_st *)v6) )
    goto err_214;
  *(_DWORD *)(v6 + 252) = 1;
  *(_DWORD *)(v6 + 36) = ctx->method->ssl_accept != (int (__cdecl *)(ssl_st *))ssl_undefined_function;
  SSL_clear(v6, (ssl_st *)v6);
  CRYPTO_new_ex_data((int)p_session, v6);
  *(_DWORD *)(v6 + 220) = ctx->psk_client_callback;
  *(_DWORD *)(v6 + 224) = ctx->psk_server_callback;
  return (ssl_st *)v6;
}
