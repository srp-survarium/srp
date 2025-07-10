unsigned int __cdecl EVP_MD_CTX_test_flags(const env_md_ctx_st *ctx, int flags)
{
  return flags & ctx->flags;
}
