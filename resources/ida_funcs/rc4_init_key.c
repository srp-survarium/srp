int __cdecl rc4_init_key(evp_cipher_ctx_st *ctx, const unsigned __int8 *key)
{
  int v2; // eax

  v2 = EVP_CIPHER_CTX_key_length(ctx);
  RC4_set_key(ctx->cipher_data, v2, key);
  return 1;
}
