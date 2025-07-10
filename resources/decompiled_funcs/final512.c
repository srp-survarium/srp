int __cdecl final512(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return SHA512_Final(md, (SHA512state_st *)ctx->md_data);
}
