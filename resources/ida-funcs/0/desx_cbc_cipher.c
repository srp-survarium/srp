int __cdecl desx_cbc_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, const unsigned __int8 *in, unsigned int inl)
{
  int v5; // ebp
  unsigned int inla; // [esp+20h] [ebp+10h]

  v5 = inl;
  if ( inl >= 0x40000000 )
  {
    inla = inl >> 30;
    do
    {
      DES_xcbc_encrypt(
        in,
        out,
        0x40000000,
        (DES_ks *)ctx->cipher_data,
        (unsigned __int8 (*)[8])ctx->iv,
        (unsigned __int8 (*)[8])((unsigned __int8 *)ctx->cipher_data + 16),
        (unsigned __int8 (*)[8])((unsigned __int8 *)ctx->cipher_data + 17),
        ctx->encrypt);
      v5 -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --inla;
    }
    while ( inla );
  }
  if ( v5 )
    DES_xcbc_encrypt(
      in,
      out,
      v5,
      (DES_ks *)ctx->cipher_data,
      (unsigned __int8 (*)[8])ctx->iv,
      (unsigned __int8 (*)[8])((unsigned __int8 *)ctx->cipher_data + 16),
      (unsigned __int8 (*)[8])((unsigned __int8 *)ctx->cipher_data + 17),
      ctx->encrypt);
  return 1;
}
