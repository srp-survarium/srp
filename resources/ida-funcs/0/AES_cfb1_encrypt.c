void __cdecl AES_cfb1_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        const aes_key_st *key,
        unsigned __int8 *ivec,
        int *num,
        int enc)
{
  CRYPTO_cfb128_1_encrypt(in, out, length, key, ivec, num, enc, AES_encrypt);
}
