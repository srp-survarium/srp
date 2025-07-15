int __cdecl init512(env_md_ctx_st *ctx)
{
  return SHA512_Init((SHA512state_st *)ctx->md_data);
}
