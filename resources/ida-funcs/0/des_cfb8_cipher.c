int __cdecl des_cfb8_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  unsigned int v5; // ebp
  unsigned int length; // [esp+20h] [ebp+10h]

  v5 = inl;
  if ( inl >= 0x40000000 )
  {
    length = inl >> 30;
    do
    {
      DES_cfb_encrypt(
        in,
        out,
        8,
        0x40000000u,
        (DES_ks *)ctx->cipher_data,
        (unsigned __int8 (*)[8])ctx->iv,
        ctx->encrypt);
      v5 -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --length;
    }
    while ( length );
  }
  if ( v5 )
    DES_cfb_encrypt(in, out, 8, v5, (DES_ks *)ctx->cipher_data, (unsigned __int8 (*)[8])ctx->iv, ctx->encrypt);
  return 1;
}
