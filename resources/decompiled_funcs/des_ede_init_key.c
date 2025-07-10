int __cdecl des_ede_init_key(evp_cipher_ctx_st *ctx, unsigned __int8 *key)
{
  DES_set_key_unchecked((unsigned __int8 (*)[8])key, (DES_ks *)ctx->cipher_data);
  DES_set_key_unchecked((unsigned __int8 (*)[8])(key + 1), (DES_ks *)ctx->cipher_data + 1);
  qmemcpy((char *)ctx->cipher_data + 256, ctx->cipher_data, 0x80u);
  return 1;
}
