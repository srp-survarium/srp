int __cdecl final256(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return SHA256_Final(md, (SHA256state_st *)ctx->md_data);
}
