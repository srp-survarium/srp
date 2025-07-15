int __cdecl final_4(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return MD5_Final(md, (MD5state_st *)ctx->md_data);
}
