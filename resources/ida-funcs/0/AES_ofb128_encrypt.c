void __cdecl AES_ofb128_encrypt(
        unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        const aes_key_st *key,
        unsigned __int8 *ivec,
        int *num)
{
  CRYPTO_ofb128_encrypt(in, out, length, key, ivec, (unsigned int *)num, AES_encrypt);
}
