int __cdecl init224(env_md_ctx_st *ctx)
{
  return SHA224_Init((SHA256state_st *)ctx->md_data);
}
