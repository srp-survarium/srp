int __cdecl des_ecb_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  evp_cipher_ctx_st *v4; // eax
  unsigned int block_size; // edi
  unsigned __int8 *v6; // esi
  unsigned int v7; // ebx
  unsigned int v9; // [esp+14h] [ebp+10h]

  v4 = ctx;
  block_size = ctx->cipher->block_size;
  if ( inl >= block_size )
  {
    v9 = inl - block_size;
    v6 = in;
    v7 = 0;
    while ( 1 )
    {
      DES_ecb_encrypt(
        (unsigned __int8 (*)[8])v6,
        (unsigned __int8 (*)[8])&v6[out - in],
        (DES_ks *)v4->cipher_data,
        v4->encrypt);
      v7 += block_size;
      v6 += block_size;
      if ( v7 > v9 )
        break;
      v4 = ctx;
    }
  }
  return 1;
}
