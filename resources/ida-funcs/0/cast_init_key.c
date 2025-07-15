int __cdecl cast_init_key(evp_cipher_ctx_st *ctx, unsigned __int8 *key)
{
  int v2; // eax

  v2 = EVP_CIPHER_CTX_key_length(ctx);
  CAST_set_key((cast_key_st *)ctx->cipher_data, v2, key);
  return 1;
}
