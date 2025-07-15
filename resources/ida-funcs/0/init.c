int __cdecl init(env_md_ctx_st *ctx)
{
  return WHIRLPOOL_Init((WHIRLPOOL_CTX *)ctx->md_data);
}
