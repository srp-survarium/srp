void __cdecl SEED_cfb128_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int len,
        const seed_key_st *ks,
        unsigned __int8 *ivec,
        int *num,
        int enc)
{
  CRYPTO_cfb128_encrypt(
    in,
    out,
    len,
    ks,
    ivec,
    num,
    enc,
    (void (__cdecl *)(const unsigned __int8 *, unsigned __int8 *, const void *))SEED_encrypt);
}
