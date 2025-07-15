int __cdecl rc2_init_key(evp_cipher_ctx_st *ctx, const unsigned __int8 *key)
{
  int v2; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = *(_DWORD *)ctx->cipher_data;
  v2 = EVP_CIPHER_CTX_key_length(ctx);
  RC2_set_key((rc2_key_st *)((char *)ctx->cipher_data + 4), v2, key, v4);
  return 1;
}
