int __cdecl des_cfb1_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, const unsigned __int8 *in, unsigned int inl)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v7; // edi
  char v8; // bl
  unsigned int v9; // esi
  unsigned __int8 ina; // [esp+2h] [ebp-6h] BYREF
  unsigned __int8 outa; // [esp+3h] [ebp-5h] BYREF
  unsigned int v13; // [esp+4h] [ebp-4h]

  v4 = inl;
  v5 = 0x8000000;
  v13 = 0x8000000;
  if ( inl < 0x8000000 )
  {
    v13 = inl;
    v5 = inl;
  }
  if ( inl )
  {
    do
    {
      if ( v4 < v5 )
        break;
      v7 = 0;
      if ( 8 * v5 )
      {
        do
        {
          v8 = v7 & 7;
          v9 = v7 >> 3;
          ina = (in[v7 >> 3] & (unsigned __int8)(1 << (7 - (v7 & 7)))) != 0 ? 0x80 : 0;
          DES_cfb_encrypt(&ina, &outa, 1, 1u, (DES_ks *)ctx->cipher_data, (unsigned __int8 (*)[8])ctx->iv, ctx->encrypt);
          ++v7;
          out[v9] = ((unsigned __int8)(outa & 0x80) >> v8) | out[v9] & ~(128 >> v8);
        }
        while ( v7 < 8 * v13 );
        v5 = v13;
        v4 = inl;
      }
      in += v5;
      v4 -= v5;
      out += v5;
      inl = v4;
      if ( v4 < v5 )
      {
        v13 = v4;
        v5 = v4;
      }
    }
    while ( v4 );
  }
  return 1;
}
