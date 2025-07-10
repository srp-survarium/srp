int __cdecl init256(env_md_ctx_st *ctx)
{
  return SHA256_Init((SHA256state_st *)ctx->md_data);
}
