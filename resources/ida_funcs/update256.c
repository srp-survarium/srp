int __cdecl update256(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return SHA256_Update((SHA256state_st *)ctx->md_data, data, count);
}
