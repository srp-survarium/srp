int __cdecl EVP_CIPHER_CTX_key_length(const evp_cipher_ctx_st *ctx)
{
  return ctx->key_len;
}
