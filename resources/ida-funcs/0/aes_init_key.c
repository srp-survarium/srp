int __usercall aes_init_key@<eax>(
        int a1@<ebx>,
        evp_cipher_ctx_st *ctx,
        const unsigned __int8 *key,
        const unsigned __int8 *iv,
        int enc)
{
  unsigned int v5; // ecx
  int v6; // eax

  v5 = ctx->cipher->flags & 0xF0007;
  if ( v5 == 3 || v5 == 4 || enc )
    v6 = AES_set_encrypt_key(key, 8 * ctx->key_len, ctx->cipher_data);
  else
    v6 = AES_set_decrypt_key(key, 8 * ctx->key_len, ctx->cipher_data);
  if ( v6 >= 0 )
    return 1;
  ERR_put_error(a1, 6u, 133, 143, ".\\crypto\\evp\\e_aes.c", 113);
  return 0;
}
