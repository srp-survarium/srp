void __usercall EVP_MD_CTX_destroy(int a1@<edi>, int a2@<ebx>, env_md_ctx_st *ctx)
{
  EVP_MD_CTX_cleanup(a1, a2, ctx);
  CRYPTO_free(ctx);
}
