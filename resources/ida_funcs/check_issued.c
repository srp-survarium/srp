int __cdecl check_issued(x509_store_ctx_st *ctx, x509_st *x, x509_st *issuer)
{
  int v3; // eax
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // eax

  v3 = X509_check_issued(issuer, x);
  if ( !v3 )
    return 1;
  if ( (ctx->param->flags & 1) == 0 )
    return 0;
  ctx->error = v3;
  verify_cb = ctx->verify_cb;
  ctx->current_cert = x;
  ctx->current_issuer = issuer;
  return verify_cb(0, ctx);
}
