int __cdecl des_ede_cfb64_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  unsigned __int8 *v4; // ebx
  int v5; // ebp
  unsigned __int8 *v6; // edi

  v4 = out;
  v5 = inl;
  v6 = in;
  if ( inl >= 0x40000000 )
  {
    DES_ede3_cfb64_encrypt(
      in,
      out,
      0x40000000,
      (DES_ks *)ctx->cipher_data,
      (DES_ks *)ctx->cipher_data + 1,
      (DES_ks *)ctx->cipher_data + 2,
      (unsigned __int8 (*)[8])ctx->iv,
      &ctx->num,
      ctx->encrypt);
    v5 = inl - 0x40000000;
    v6 = in + 0x40000000;
    v4 = out + 0x40000000;
  }
  if ( v5 )
    DES_ede3_cfb64_encrypt(
      v6,
      v4,
      v5,
      (DES_ks *)ctx->cipher_data,
      (DES_ks *)ctx->cipher_data + 1,
      (DES_ks *)ctx->cipher_data + 2,
      (unsigned __int8 (*)[8])ctx->iv,
      &ctx->num,
      ctx->encrypt);
  return 1;
}
