int __cdecl rc2_ecb_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  unsigned int block_size; // edi
  const unsigned __int8 *v5; // esi
  unsigned int v6; // ebx
  int i; // eax
  unsigned int v9; // [esp+18h] [ebp+10h]

  block_size = ctx->cipher->block_size;
  if ( inl >= block_size )
  {
    v9 = inl - block_size;
    v5 = in;
    v6 = 0;
    for ( i = out - in; ; i = out - in )
    {
      RC2_ecb_encrypt(v5, (unsigned __int8 *)&v5[i], (rc2_key_st *)((char *)ctx->cipher_data + 4), ctx->encrypt);
      v6 += block_size;
      v5 += block_size;
      if ( v6 > v9 )
        break;
    }
  }
  return 1;
}
