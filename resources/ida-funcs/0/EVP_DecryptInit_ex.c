int __cdecl EVP_DecryptInit_ex(
        evp_cipher_ctx_st *ctx,
        const evp_cipher_st *cipher,
        engine_st *impl,
        const unsigned __int8 *key,
        const __m128i *iv)
{
  return EVP_CipherInit_ex(ctx, cipher, impl, key, iv, 0);
}
