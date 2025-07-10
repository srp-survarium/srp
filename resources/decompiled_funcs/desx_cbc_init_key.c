int __cdecl desx_cbc_init_key(evp_cipher_ctx_st *ctx, unsigned __int8 *key)
{
  _DWORD *cipher_data; // eax
  _DWORD *v3; // edi

  DES_set_key_unchecked((unsigned __int8 (*)[8])key, (DES_ks *)ctx->cipher_data);
  cipher_data = ctx->cipher_data;
  cipher_data[32] = *((_DWORD *)key + 2);
  cipher_data[33] = *((_DWORD *)key + 3);
  v3 = ctx->cipher_data;
  v3[34] = *((_DWORD *)key + 4);
  v3[35] = *((_DWORD *)key + 5);
  return 1;
}
