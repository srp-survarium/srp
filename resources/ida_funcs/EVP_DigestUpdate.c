int __cdecl EVP_DigestUpdate(env_md_ctx_st *ctx)
{
  return ((int (*)(void))ctx->update)();
}
