int __cdecl aes_init_key(evp_cipher_ctx_st *ctx, const unsigned __int8 *key, const unsigned __int8 *iv, int enc)
{
  unsigned int v4; // ecx
  int v5; // eax

  v4 = (unsigned int)&loc_F0007 & ctx->cipher->flags;
  if ( v4 == 3 || v4 == 4 || enc )
    v5 = AES_set_encrypt_key(key, 8 * ctx->key_len, ctx->cipher_data);
  else
    v5 = AES_set_decrypt_key(key, 8 * ctx->key_len, ctx->cipher_data);
  if ( v5 >= 0 )
    return 1;
  ERR_put_error(6u, 133, 143, ".\\crypto\\evp\\e_aes.c", 113);
  return 0;
}
