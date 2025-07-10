void __cdecl EVP_MD_CTX_init(env_md_ctx_st *ctx)
{
  ctx->digest = 0;
  ctx->engine = 0;
  ctx->flags = 0;
  ctx->md_data = 0;
  ctx->pctx = 0;
  ctx->update = 0;
}
