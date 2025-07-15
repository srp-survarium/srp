int __cdecl update(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return WHIRLPOOL_Update((WHIRLPOOL_CTX *)ctx->md_data, data, count);
}
