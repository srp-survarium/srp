void __cdecl COMP_CTX_free(comp_ctx_st *ctx)
{
  void (__cdecl *finish)(comp_ctx_st *); // eax

  if ( ctx )
  {
    finish = ctx->meth->finish;
    if ( finish )
      finish(ctx);
    CRYPTO_free(ctx);
  }
}
