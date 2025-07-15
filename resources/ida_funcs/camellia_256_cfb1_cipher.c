int __cdecl camellia_256_cfb1_cipher(
        evp_cipher_ctx_st *ctx,
        unsigned __int8 *out,
        const unsigned __int8 *in,
        unsigned int inl)
{
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v7; // eax

  v4 = inl;
  v5 = 0x8000000;
  if ( inl < 0x8000000 )
    v5 = inl;
  if ( inl )
  {
    do
    {
      if ( v4 < v5 )
        break;
      v7 = 8 * v4;
      if ( (ctx->flags & 0x2000) != 0 )
        v7 = v4;
      Camellia_cfb1_encrypt(in, out, v7, (const camellia_key_st *)ctx->cipher_data, ctx->iv, &ctx->num, ctx->encrypt);
      out += v5;
      v4 -= v5;
      in += v5;
      if ( v4 < v5 )
        v5 = v4;
    }
    while ( v4 );
  }
  return 1;
}
