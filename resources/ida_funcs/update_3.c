int __cdecl update_3(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return SHA_Update((SHAstate_st *)ctx->md_data, data, count);
}
