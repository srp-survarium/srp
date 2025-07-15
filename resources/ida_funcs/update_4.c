int __cdecl update_4(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return MD5_Update((MD5state_st *)ctx->md_data, data, count);
}
