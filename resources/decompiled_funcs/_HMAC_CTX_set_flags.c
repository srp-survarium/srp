void __cdecl HMAC_CTX_set_flags(hmac_ctx_st *ctx, unsigned int flags)
{
  EVP_MD_CTX_set_flags(&ctx->i_ctx, flags);
  EVP_MD_CTX_set_flags(&ctx->o_ctx, flags);
  EVP_MD_CTX_set_flags(&ctx->md_ctx, flags);
}
