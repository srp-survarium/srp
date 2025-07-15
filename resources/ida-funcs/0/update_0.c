int __cdecl update_0(env_md_ctx_st *ctx, const void *data, unsigned int count)
{
  return RIPEMD160_Update((RIPEMD160state_st *)ctx->md_data, data, count);
}
