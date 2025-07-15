int __cdecl seed_cbc_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  unsigned int v5; // ebp
  unsigned int len; // [esp+20h] [ebp+10h]

  v5 = inl;
  if ( inl >= 0x40000000 )
  {
    len = inl >> 30;
    do
    {
      SEED_cbc_encrypt(
        in,
        out,
        0x40000000u,
        (const seed_key_st *)ctx->cipher_data,
        ctx->iv,
        (void (__cdecl *)(const unsigned __int8 *, unsigned __int8 *, const void *))ctx->encrypt);
      v5 -= 0x40000000;
      in += 0x40000000;
      out += 0x40000000;
      --len;
    }
    while ( len );
  }
  if ( v5 )
    SEED_cbc_encrypt(
      in,
      out,
      v5,
      (const seed_key_st *)ctx->cipher_data,
      ctx->iv,
      (void (__cdecl *)(const unsigned __int8 *, unsigned __int8 *, const void *))ctx->encrypt);
  return 1;
}
