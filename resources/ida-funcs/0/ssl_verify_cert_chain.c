int __cdecl ssl_verify_cert_chain(ssl_st *s, stack_st_X509 *sk)
{
  char *v2; // eax
  int v4; // eax
  const char *v5; // eax
  X509_VERIFY_PARAM_st *conv_form; // eax
  ssl_ctx_st *v7; // eax
  int (__cdecl *app_verify_callback)(x509_store_ctx_st *, void *); // ecx
  int v9; // eax
  int v10; // edi
  X509_VERIFY_PARAM_st *param; // [esp-8h] [ebp-94h]
  x509_store_ctx_st ctx; // [esp+4h] [ebp-88h] BYREF

  if ( !sk || !sk_num(&sk->stack) )
    return 0;
  v2 = sk_value(&sk->stack, 0);
  if ( X509_STORE_CTX_init(&ctx, s->ctx->cert_store, (x509_st *)v2, sk) )
  {
    v4 = SSL_get_ex_data_X509_STORE_CTX_idx((unsigned int)sk);
    X509_STORE_CTX_set_ex_data((ssl_ctx_st *)&ctx, v4, s);
    v5 = "ssl_client";
    if ( !s->server )
      v5 = "ssl_server";
    X509_STORE_CTX_set_default(&ctx, v5);
    param = s->param;
    conv_form = (X509_VERIFY_PARAM_st *)EC_KEY_get_conv_form((const engine_st *)&ctx);
    X509_VERIFY_PARAM_set1(conv_form, param);
    if ( s->verify_callback )
      X509_STORE_CTX_set_verify_cb(&ctx, s->verify_callback);
    v7 = s->ctx;
    app_verify_callback = v7->app_verify_callback;
    if ( app_verify_callback )
      v9 = app_verify_callback(&ctx, v7->app_verify_arg);
    else
      v9 = X509_verify_cert(&ctx);
    v10 = v9;
    s->verify_result = ctx.error;
    X509_STORE_CTX_cleanup(&ctx);
    return v10;
  }
  else
  {
    ERR_put_error(0x14u, 207, 11, ".\\ssl\\ssl_cert.c", 502);
    return 0;
  }
}
