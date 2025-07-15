void __cdecl SEED_cbc_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int len,
        const seed_key_st *ks,
        unsigned __int8 *ivec,
        void (__cdecl *enc)(const unsigned __int8 *, unsigned __int8 *, const void *))
{
  if ( enc )
    CRYPTO_cbc128_encrypt(
      in,
      out,
      len,
      ks,
      ivec,
      (void (__cdecl *)(const unsigned __int8 *, unsigned __int8 *, const void *))SEED_encrypt);
  else
    CRYPTO_cbc128_decrypt(
      in,
      out,
      len,
      ks,
      ivec,
      (void (__cdecl *)(const unsigned __int8 *, unsigned __int8 *, const void *))SEED_decrypt);
}
