int __cdecl final_0(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return RIPEMD160_Final(md, (RIPEMD160state_st *)ctx->md_data);
}
