unsigned __int8 *__cdecl HMAC(
        const env_md_st *evp_md,
        env_md_ctx_st *key,
        signed int key_len,
        const unsigned __int8 *d,
        unsigned int n,
        unsigned __int8 *md,
        unsigned int *md_len)
{
  unsigned __int8 *v7; // esi
  hmac_ctx_st v9; // [esp+14h] [ebp-D4h] BYREF

  v7 = md;
  if ( !md )
    v7 = m;
  EVP_MD_CTX_init(&v9.i_ctx);
  EVP_MD_CTX_init(&v9.o_ctx);
  EVP_MD_CTX_init(&v9.md_ctx);
  if ( key && evp_md )
  {
    EVP_MD_CTX_init(&v9.i_ctx);
    EVP_MD_CTX_init(&v9.o_ctx);
    EVP_MD_CTX_init(&v9.md_ctx);
  }
  if ( !HMAC_Init_ex((int)evp_md, key, &v9, (const __m128i *)key, key_len, evp_md, 0)
    || !EVP_DigestUpdate(&v9.md_ctx)
    || !HMAC_Final(&v9, v7, md_len) )
  {
    return 0;
  }
  HMAC_CTX_cleanup((int)evp_md, (int)key, &v9);
  return v7;
}
