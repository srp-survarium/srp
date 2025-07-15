void __cdecl Camellia_cfb128_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        const camellia_key_st *key,
        unsigned __int8 *ivec,
        int *num,
        int enc)
{
  CRYPTO_cfb128_encrypt(in, out, length, key, ivec, num, enc, Camellia_encrypt);
}
