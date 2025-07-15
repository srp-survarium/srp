int __cdecl init_2(env_md_ctx_st *ctx)
{
  return MD5_Init((MD5state_st *)ctx->md_data);
}
