int __usercall EVP_MD_CTX_cleanup@<eax>(unsigned int a1@<edi>, env_md_ctx_st *ctx)
{
  if ( ctx->digest )
  {
    if ( ctx->digest->cleanup && !EVP_MD_CTX_test_flags(ctx, 2) )
      ctx->digest->cleanup(ctx);
    if ( ctx->digest && ctx->digest->ctx_size && ctx->md_data && !EVP_MD_CTX_test_flags(ctx, 4) )
    {
      OPENSSL_cleanse(ctx->md_data, ctx->digest->ctx_size);
      CRYPTO_free(ctx->md_data);
    }
  }
  if ( ctx->pctx )
    EVP_PKEY_CTX_free(ctx->pctx);
  if ( ctx->engine )
    ENGINE_finish(a1, ctx->engine);
  ctx->digest = 0;
  ctx->engine = 0;
  ctx->flags = 0;
  ctx->md_data = 0;
  ctx->pctx = 0;
  ctx->update = 0;
  return 1;
}
