int __cdecl camellia_256_cbc_cipher(
        evp_cipher_ctx_st *ctx,
        unsigned __int8 *out,
        const unsigned __int8 *in,
        unsigned int inl)
{
  unsigned int v5; // ebp
  unsigned int v8; // [esp+20h] [ebp+10h]

  v5 = inl;
  if ( inl >= 0x40000000 )
  {
    v8 = inl >> 30;
    do
    {
      Camellia_cbc_encrypt(in, out, 0x40000000, ctx->cipher_data, ctx->iv, ctx->encrypt);
      v5 -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --v8;
    }
    while ( v8 );
  }
  if ( v5 )
    Camellia_cbc_encrypt(in, out, v5, ctx->cipher_data, ctx->iv, ctx->encrypt);
  return 1;
}
