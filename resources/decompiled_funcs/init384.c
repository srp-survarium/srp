int __cdecl init384(env_md_ctx_st *ctx)
{
  return SHA384_Init((SHA512state_st *)ctx->md_data);
}
