int __cdecl update_2(env_md_ctx_st *ctx, const unsigned __int8 *data, unsigned int count)
{
  return MDC2_Update((mdc2_ctx_st *)ctx->md_data, data, count);
}
