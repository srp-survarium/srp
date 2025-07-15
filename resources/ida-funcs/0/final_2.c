int __cdecl final_2(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return SHA1_Final(md, (SHAstate_st *)ctx->md_data);
}
