void __usercall EVP_MD_CTX_destroy(unsigned int a1@<edi>, env_md_ctx_st *ctx)
{
  EVP_MD_CTX_cleanup(a1, ctx);
  CRYPTO_free(ctx);
}
