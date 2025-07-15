void __cdecl BN_CTX_free(bignum_ctx *ctx)
{
  if ( ctx )
  {
    if ( ctx->stack.size )
      CRYPTO_free(ctx->stack.indexes);
    BN_POOL_finish(&ctx->pool);
    CRYPTO_free(ctx);
  }
}
