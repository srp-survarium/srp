int __cdecl EVP_DigestInit(env_md_ctx_st *ctx, const env_md_st *type)
{
  ctx->digest = 0;
  ctx->engine = 0;
  ctx->flags = 0;
  ctx->md_data = 0;
  ctx->pctx = 0;
  ctx->update = 0;
  return EVP_DigestInit_ex(ctx, type, 0);
}
