int __cdecl rc2_ofb_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  int v4; // ebp
  unsigned int length; // [esp+20h] [ebp+10h]

  v4 = inl;
  if ( inl >= 0x40000000 )
  {
    length = inl >> 30;
    do
    {
      RC2_ofb64_encrypt(in, out, 0x40000000, (rc2_key_st *)((char *)ctx->cipher_data + 4), ctx->iv, &ctx->num);
      v4 -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --length;
    }
    while ( length );
  }
  if ( v4 )
    RC2_ofb64_encrypt(in, out, v4, (rc2_key_st *)((char *)ctx->cipher_data + 4), ctx->iv, &ctx->num);
  return 1;
}
