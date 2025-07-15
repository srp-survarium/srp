void __usercall EVP_PKEY_CTX_free(int a1@<edi>, evp_pkey_ctx_st *ctx)
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
      EVP_PKEY_free(a1, ctx->pkey);
    if ( ctx->peerkey )
      EVP_PKEY_free(a1, ctx->peerkey);
    if ( ctx->engine )
      ENGINE_finish(a1, ctx->engine);
    CRYPTO_free(ctx);
  }
}
