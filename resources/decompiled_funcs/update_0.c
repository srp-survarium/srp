int __cdecl update_0(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return SHA1_Update((SHAstate_st *)ctx->md_data, data, count);
}
