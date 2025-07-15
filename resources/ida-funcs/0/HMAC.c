unsigned __int8 *__cdecl HMAC(
        const env_md_st *evp_md,
        unsigned __int8 *key,
        unsigned int key_len,
        const unsigned __int8 *d,
        unsigned int n,
        unsigned __int8 *md,
        unsigned int *md_len)
{
  unsigned __int8 *v7; // esi
  hmac_ctx_st ctx; // [esp+14h] [ebp-D4h] BYREF

  v7 = md;
  if ( !md )
    v7 = m;
  EVP_MD_CTX_init(&ctx.i_ctx);
  EVP_MD_CTX_init(&ctx.o_ctx);
  EVP_MD_CTX_init(&ctx.md_ctx);
  if ( key && evp_md )
  {
    EVP_MD_CTX_init(&ctx.i_ctx);
    EVP_MD_CTX_init(&ctx.o_ctx);
    EVP_MD_CTX_init(&ctx.md_ctx);
  }
  if ( !HMAC_Init_ex((unsigned int)evp_md, &ctx, key, key_len, evp_md, 0)
    || !EVP_DigestUpdate(&ctx.md_ctx)
    || !HMAC_Final(&ctx, v7, md_len) )
  {
    return 0;
  }
  HMAC_CTX_cleanup((unsigned int)evp_md, &ctx);
  return v7;
}
