int __cdecl rc2_cbc_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, const unsigned __int8 *in, unsigned int inl)
{
  int v5; // ebp
  unsigned int inla; // [esp+20h] [ebp+10h]

  v5 = inl;
  if ( inl >= 0x40000000 )
  {
    inla = inl >> 30;
    do
    {
      RC2_cbc_encrypt(in, out, 0x40000000, (rc2_key_st *)((char *)ctx->cipher_data + 4), ctx->iv, ctx->encrypt);
      v5 -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --inla;
    }
    while ( inla );
  }
  if ( v5 )
    RC2_cbc_encrypt(in, out, v5, (rc2_key_st *)((char *)ctx->cipher_data + 4), ctx->iv, ctx->encrypt);
  return 1;
}
