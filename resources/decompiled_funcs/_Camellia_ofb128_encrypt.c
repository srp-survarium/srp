void __cdecl Camellia_ofb128_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        const camellia_key_st *key,
        unsigned __int8 *ivec,
        int *num)
{
  CRYPTO_ofb128_encrypt(in, out, length, key, ivec, num, Camellia_encrypt);
}
