int __cdecl des_cfb64_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  int v5; // ebp
  unsigned int v7; // ebp

  v5 = inl;
  if ( inl >= 0x40000000 )
  {
    v7 = inl >> 30;
    do
    {
      DES_cfb64_encrypt(
        in,
        out,
        0x40000000,
        (DES_ks *)ctx->cipher_data,
        (unsigned __int8 (*)[8])ctx->iv,
        &ctx->num,
        ctx->encrypt);
      inl -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --v7;
    }
    while ( v7 );
    v5 = inl;
  }
  if ( v5 )
    DES_cfb64_encrypt(in, out, v5, (DES_ks *)ctx->cipher_data, (unsigned __int8 (*)[8])ctx->iv, &ctx->num, ctx->encrypt);
  return 1;
}
