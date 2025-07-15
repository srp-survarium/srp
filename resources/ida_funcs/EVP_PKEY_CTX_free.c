void __cdecl EVP_PKEY_CTX_free(evp_pkey_ctx_st *ctx)
{
  void (__cdecl *cleanup)(evp_pkey_ctx_st *); // eax

  if ( ctx )
  {
    if ( ctx->pmeth )
    {
      cleanup = ctx->pmeth->cleanup;
      if ( cleanup )
        cleanup(ctx);
    }
    if ( ctx->pkey )
      EVP_PKEY_free(ctx->pkey);
    if ( ctx->peerkey )
      EVP_PKEY_free(ctx->peerkey);
    if ( ctx->engine )
      ENGINE_finish(ctx->engine);
    CRYPTO_free(ctx);
  }
}
