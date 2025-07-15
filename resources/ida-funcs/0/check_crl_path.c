int __usercall check_crl_path@<eax>(x509_store_ctx_st *ctx@<edi>, x509_st *x@<ecx>, int a3@<ebx>)
{
  X509_VERIFY_PARAM_st *param; // esi
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // edx
  int v6; // esi
  x509_store_ctx_st v7; // [esp+0h] [ebp-88h] BYREF

  if ( ctx->parent )
    return 0;
  if ( !X509_STORE_CTX_init(&v7, ctx->ctx, x, ctx->untrusted) )
    return -1;
  param = ctx->param;
  v7.crls = ctx->crls;
  if ( v7.param )
    X509_VERIFY_PARAM_free(v7.param);
  verify_cb = ctx->verify_cb;
  v7.param = param;
  v7.parent = ctx;
  v7.verify_cb = verify_cb;
  v6 = X509_verify_cert(&v7);
  if ( v6 > 0 )
    v6 = check_crl_chain(ctx->chain, v7.chain);
  X509_STORE_CTX_cleanup(a3, &v7);
  return v6;
}
