int __usercall check_crl_path@<eax>(x509_store_ctx_st *ctx@<edi>, x509_st *x@<ecx>)
{
  X509_VERIFY_PARAM_st *param; // esi
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // edx
  int v5; // esi
  x509_store_ctx_st v6; // [esp+0h] [ebp-88h] BYREF

  if ( ctx->parent )
    return 0;
  if ( !X509_STORE_CTX_init(&v6, ctx->ctx, x, ctx->untrusted) )
    return -1;
  param = ctx->param;
  v6.crls = ctx->crls;
  if ( v6.param )
    X509_VERIFY_PARAM_free(v6.param);
  verify_cb = ctx->verify_cb;
  v6.param = param;
  v6.parent = ctx;
  v6.verify_cb = verify_cb;
  v5 = X509_verify_cert(&v6);
  if ( v5 > 0 )
    v5 = check_crl_chain(ctx->chain, v6.chain);
  X509_STORE_CTX_cleanup(&v6);
  return v5;
}
