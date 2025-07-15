int __cdecl aes_256_cfb8_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  unsigned int v4; // edi
  unsigned int v5; // esi

  v4 = inl;
  v5 = 0x40000000;
  if ( inl < 0x40000000 )
    v5 = inl;
  if ( inl )
  {
    do
    {
      if ( v4 < v5 )
        break;
      AES_cfb8_encrypt(in, out, v4, (const aes_key_st *)ctx->cipher_data, ctx->iv, &ctx->num, ctx->encrypt);
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
