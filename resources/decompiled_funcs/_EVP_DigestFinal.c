unsigned int __usercall EVP_DigestFinal@<eax>(
        unsigned int a1@<edi>,
        env_md_ctx_st *ctx,
        unsigned __int8 *md,
        unsigned int *size)
{
  unsigned int v4; // edi

  v4 = EVP_DigestFinal_ex(a1, ctx, md, size);
  EVP_MD_CTX_cleanup(v4, ctx);
  return v4;
}
