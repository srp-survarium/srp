int __cdecl EVP_EncryptInit_ex(
        evp_cipher_ctx_st *ctx,
        const evp_cipher_st *cipher,
        engine_st *impl,
        const unsigned __int8 *key,
        unsigned __int8 *iv)
{
  return EVP_CipherInit_ex(ctx, cipher, impl, key, iv, 1);
}
