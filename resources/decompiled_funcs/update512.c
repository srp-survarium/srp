int __cdecl update512(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return SHA512_Update((SHA512state_st *)ctx->md_data, data, count);
}
