int __cdecl final(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return WHIRLPOOL_Final(md, (WHIRLPOOL_CTX *)ctx->md_data);
}
