unsigned int __cdecl EVP_CIPHER_CTX_flags(const evp_cipher_ctx_st *ctx)
{
  return ctx->cipher->flags;
}
