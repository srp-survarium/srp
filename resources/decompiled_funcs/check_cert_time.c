int __usercall check_cert_time@<eax>(x509_store_ctx_st *ctx@<esi>, x509_st *x@<edi>)
{
  X509_VERIFY_PARAM_st *param; // eax
  __int64 *p_check_time; // ebx
  int v4; // eax
  int (__cdecl *v5)(int, x509_store_ctx_st *); // eax
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // ecx
  int v8; // eax
  int (__cdecl *v9)(int, x509_store_ctx_st *); // edx
  int (__cdecl *v10)(int, x509_store_ctx_st *); // eax

  param = ctx->param;
  if ( (param->flags & 2) != 0 )
    p_check_time = &param->check_time;
  else
    p_check_time = 0;
  v4 = X509_cmp_time(x->cert_info->validity->notBefore, p_check_time);
  if ( v4 )
  {
    if ( v4 > 0 )
    {
      verify_cb = ctx->verify_cb;
      ctx->error = 9;
      ctx->current_cert = x;
      if ( !verify_cb(0, ctx) )
        return 0;
    }
  }
  else
  {
    v5 = ctx->verify_cb;
    ctx->error = 13;
    ctx->current_cert = x;
    if ( !v5(0, ctx) )
      return 0;
  }
  v8 = X509_cmp_time(x->cert_info->validity->notAfter, p_check_time);
  if ( v8 )
  {
    if ( v8 < 0 )
    {
      v10 = ctx->verify_cb;
      ctx->error = 10;
      ctx->current_cert = x;
      if ( !v10(0, ctx) )
        return 0;
    }
  }
  else
  {
    v9 = ctx->verify_cb;
    ctx->error = 14;
    ctx->current_cert = x;
    if ( !v9(0, ctx) )
      return 0;
  }
  return 1;
}
