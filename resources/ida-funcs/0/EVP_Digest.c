int __usercall EVP_Digest@<eax>(
        int a1@<edi>,
        engine_st *a2@<ebx>,
        void *data,
        unsigned int count,
        unsigned __int8 *md,
        unsigned int *size,
        const env_md_st *type,
        engine_st *impl)
{
  env_md_ctx_st ctx; // [esp+4h] [ebp-18h] BYREF

  memset(&ctx, 0, sizeof(ctx));
  EVP_MD_CTX_set_flags(&ctx, 1);
  if ( EVP_DigestInit_ex(a2, &ctx, type, impl)
    && ctx.update(&ctx, data, count)
    && EVP_DigestFinal_ex(a1, (int)a2, &ctx, md, size) )
  {
    EVP_MD_CTX_cleanup(a1, (int)a2, &ctx);
    return 1;
  }
  else
  {
    EVP_MD_CTX_cleanup(a1, (int)a2, &ctx);
    return 0;
  }
}
