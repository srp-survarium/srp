void __cdecl EVP_CIPHER_CTX_init(evp_cipher_ctx_st *ctx)
{
  memset((int)ctx, 0, sizeof(evp_cipher_ctx_st));
}
