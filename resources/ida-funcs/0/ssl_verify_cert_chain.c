int __usercall ssl_verify_cert_chain@<eax>(int a1@<ebx>, ssl_st *s, stack_st_X509 *sk)
{
  char *v3; // eax
  int v5; // eax
  char *v6; // eax
  X509_VERIFY_PARAM_st *conv_form; // eax
  ssl_ctx_st *v8; // eax
  int (__cdecl *app_verify_callback)(x509_store_ctx_st *, void *); // ecx
  int v10; // eax
  int v11; // edi
  X509_VERIFY_PARAM_st *param; // [esp-8h] [ebp-94h]
  x509_store_ctx_st ctx; // [esp+4h] [ebp-88h] BYREF

  if ( !sk || !sk_num(&sk->stack) )
    return 0;
  v3 = sk_value(&sk->stack, 0);
  if ( X509_STORE_CTX_init(&ctx, s->ctx->cert_store, (x509_st *)v3, sk) )
  {
    v5 = SSL_get_ex_data_X509_STORE_CTX_idx((int)sk, a1);
    X509_STORE_CTX_set_ex_data((ssl_ctx_st *)&ctx, v5, s);
    v6 = "ssl_client";
    if ( !s->server )
      v6 = "ssl_server";
    X509_STORE_CTX_set_default((X509_VERIFY_PARAM_st *)&ctx, v6);
    param = s->param;
    conv_form = (X509_VERIFY_PARAM_st *)EC_KEY_get_conv_form((const engine_st *)&ctx);
    X509_VERIFY_PARAM_set1(conv_form, param);
    if ( s->verify_callback )
      X509_STORE_CTX_set_verify_cb(&ctx, s->verify_callback);
    v8 = s->ctx;
    app_verify_callback = v8->app_verify_callback;
    if ( app_verify_callback )
      v10 = app_verify_callback(&ctx, v8->app_verify_arg);
    else
      v10 = X509_verify_cert(&ctx);
    v11 = v10;
    s->verify_result = ctx.error;
    X509_STORE_CTX_cleanup(a1, &ctx);
    return v11;
  }
  else
  {
    ERR_put_error(a1, 0x14u, 207, 11, ".\\ssl\\ssl_cert.c", 502);
    return 0;
  }
}
