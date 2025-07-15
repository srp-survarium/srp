int __cdecl des_ede_cbc_cipher(
        evp_cipher_ctx_st *ctx,
        unsigned __int8 *out,
        const unsigned __int8 *in,
        unsigned int inl)
{
  unsigned __int8 *v4; // ebx
  unsigned int v5; // ebp
  const unsigned __int8 *v6; // edi

  v4 = out;
  v5 = inl;
  v6 = in;
  if ( inl >= 0x40000000 )
  {
    DES_ede3_cbc_encrypt(
      in,
      out,
      0x40000000,
      ctx->cipher_data,
      (char *)ctx->cipher_data + 128,
      (char *)ctx->cipher_data + 256,
      ctx->iv,
      ctx->encrypt);
    v5 = inl - 0x40000000;
    v6 = in + 0x40000000;
    v4 = out + 0x40000000;
  }
  if ( v5 )
    DES_ede3_cbc_encrypt(
      v6,
      v4,
      v5,
      ctx->cipher_data,
      (char *)ctx->cipher_data + 128,
      (char *)ctx->cipher_data + 256,
      ctx->iv,
      ctx->encrypt);
  return 1;
}
