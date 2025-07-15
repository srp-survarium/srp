int __cdecl final_5(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return MD4_Final(md, (MD4state_st *)ctx->md_data);
}
