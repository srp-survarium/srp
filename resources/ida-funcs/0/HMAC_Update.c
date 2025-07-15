int __cdecl HMAC_Update(hmac_ctx_st *ctx)
{
  return EVP_DigestUpdate(&ctx->md_ctx);
}
