int __cdecl update_5(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return MD4_Update((MD4state_st *)ctx->md_data, data, count);
}
