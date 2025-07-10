int __cdecl int_update(env_md_ctx_st *ctx)
{
  HMAC_Update((hmac_ctx_st *)((char *)ctx->pctx->data + 20));
  return 1;
}
