int __cdecl des_ede3_cfb1_cipher(
        evp_cipher_ctx_st *ctx,
        unsigned __int8 *out,
        const unsigned __int8 *in,
        unsigned int inl)
{
  unsigned int i; // edi
  char v5; // bl
  unsigned int v6; // esi
  int encrypt; // [esp-10h] [ebp-18h]
  unsigned __int8 ina; // [esp+6h] [ebp-2h] BYREF
  unsigned __int8 outa; // [esp+7h] [ebp-1h] BYREF

  for ( i = 0; i < inl; out[v6] = ((unsigned __int8)(outa & 0x80) >> v5) | out[v6] & ~(128 >> v5) )
  {
    v5 = i & 7;
    v6 = i >> 3;
    encrypt = ctx->encrypt;
    ina = (in[i >> 3] & (unsigned __int8)(1 << (7 - (i & 7)))) != 0 ? 0x80 : 0;
    DES_ede3_cfb_encrypt(
      &ina,
      &outa,
      1,
      1,
      (DES_ks *)ctx->cipher_data,
      (DES_ks *)ctx->cipher_data + 1,
      (DES_ks *)ctx->cipher_data + 2,
      (unsigned __int8 (*)[8])ctx->iv,
      encrypt);
    ++i;
  }
  return 1;
}
