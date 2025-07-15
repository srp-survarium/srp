void __cdecl HMAC_CTX_init(hmac_ctx_st *ctx)
{
  EVP_MD_CTX_init(&ctx->i_ctx);
  EVP_MD_CTX_init(&ctx->o_ctx);
  EVP_MD_CTX_init(&ctx->md_ctx);
}
