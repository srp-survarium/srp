void __usercall HMAC_CTX_cleanup(unsigned int a1@<edi>, hmac_ctx_st *ctx)
{
  EVP_MD_CTX_cleanup(a1, &ctx->i_ctx);
  EVP_MD_CTX_cleanup(a1, &ctx->o_ctx);
  EVP_MD_CTX_cleanup(a1, &ctx->md_ctx);
  memset((int)ctx, 0, sizeof(hmac_ctx_st));
}
