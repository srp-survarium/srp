int __usercall EVP_DigestFinal@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        env_md_ctx_st *ctx,
        unsigned __int8 *md,
        unsigned int *size)
{
  int v5; // edi

  v5 = EVP_DigestFinal_ex(a1, a2, ctx, md, size);
  EVP_MD_CTX_cleanup(v5, a2, ctx);
  return v5;
}
