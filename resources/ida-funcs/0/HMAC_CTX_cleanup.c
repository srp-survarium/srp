void __usercall HMAC_CTX_cleanup(int a1@<edi>, int a2@<ebx>, hmac_ctx_st *ctx)
{
  EVP_MD_CTX_cleanup(a1, a2, &ctx->i_ctx);
  EVP_MD_CTX_cleanup(a1, a2, &ctx->o_ctx);
  EVP_MD_CTX_cleanup(a1, a2, &ctx->md_ctx);
  memset((int)ctx, 0, sizeof(hmac_ctx_st));
}
