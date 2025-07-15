int __cdecl des_init_key(evp_cipher_ctx_st *ctx, unsigned __int8 *key)
{
  DES_set_key_unchecked((unsigned __int8 (*)[8])key, (DES_ks *)ctx->cipher_data);
  return 1;
}
