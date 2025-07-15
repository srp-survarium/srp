void __usercall X509_STORE_CTX_cleanup(int a1@<ebx>, x509_store_ctx_st *ctx)
{
  int (__cdecl *cleanup)(x509_store_ctx_st *); // eax
  stack_st_X509 *chain; // eax

  cleanup = ctx->cleanup;
  if ( cleanup )
    cleanup(ctx);
  if ( ctx->param )
  {
    if ( !ctx->parent )
      X509_VERIFY_PARAM_free(ctx->param);
    ctx->param = 0;
  }
  if ( ctx->tree )
  {
    X509_policy_tree_free(ctx->tree);
    ctx->tree = 0;
  }
  chain = ctx->chain;
  if ( chain )
  {
    sk_pop_free(&chain->stack, (void (__cdecl *)(void *))X509_free);
    ctx->chain = 0;
  }
  CRYPTO_free_ex_data((int)&ctx->ex_data, a1);
  ctx->ex_data.sk = 0;
  ctx->ex_data.dummy = 0;
}
