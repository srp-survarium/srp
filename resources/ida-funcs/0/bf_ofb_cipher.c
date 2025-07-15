int __cdecl bf_ofb_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  int v4; // ebp
  unsigned int v7; // ebp

  v4 = inl;
  if ( inl >= 0x40000000 )
  {
    v7 = inl >> 30;
    do
    {
      BF_ofb64_encrypt(in, out, 0x40000000, (const bf_key_st *)ctx->cipher_data, ctx->iv, &ctx->num);
      inl -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --v7;
    }
    while ( v7 );
    v4 = inl;
  }
  if ( v4 )
    BF_ofb64_encrypt(in, out, v4, (const bf_key_st *)ctx->cipher_data, ctx->iv, &ctx->num);
  return 1;
}
