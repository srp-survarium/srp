int __cdecl EVP_Cipher(evp_cipher_ctx_st *ctx)
{
  return ((int (*)(void))ctx->cipher->do_cipher)();
}
