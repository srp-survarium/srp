int __cdecl init_1(env_md_ctx_st *ctx)
{
  return SHA_Init((RIPEMD160state_st *)ctx->md_data);
}
