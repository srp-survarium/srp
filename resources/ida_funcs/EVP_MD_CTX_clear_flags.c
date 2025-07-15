void __cdecl EVP_MD_CTX_clear_flags(env_md_ctx_st *ctx, int flags)
{
  ctx->flags &= ~flags;
}
