void __cdecl Camellia_cfb1_encrypt(
        unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        const camellia_key_st *key,
        unsigned __int8 *ivec,
        int *num,
        int enc)
{
  CRYPTO_cfb128_1_encrypt(in, out, length, key, ivec, num, enc, Camellia_encrypt);
}
