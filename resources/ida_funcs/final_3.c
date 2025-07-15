int __cdecl final_3(env_md_ctx_st *ctx, unsigned __int8 *md)
{
  return SHA_Final(md, (SHAstate_st *)ctx->md_data);
}
