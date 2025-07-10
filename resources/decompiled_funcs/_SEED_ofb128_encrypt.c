void __cdecl SEED_ofb128_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int len,
        const seed_key_st *ks,
        unsigned __int8 *ivec,
        int *num)
{
  CRYPTO_ofb128_encrypt(
    in,
    out,
    len,
    ks,
    ivec,
    num,
    (void (__cdecl *)(const unsigned __int8 *, unsigned __int8 *, const void *))SEED_encrypt);
}
