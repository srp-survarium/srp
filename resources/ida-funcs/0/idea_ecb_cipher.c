int __cdecl idea_ecb_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  unsigned int block_size; // edi
  const unsigned __int8 *v5; // esi
  unsigned int v6; // ebx
  unsigned int v8; // [esp+14h] [ebp+10h]

  block_size = ctx->cipher->block_size;
  if ( inl >= block_size )
  {
    v8 = inl - block_size;
    v5 = in;
    v6 = 0;
    do
    {
      idea_ecb_encrypt(v5, (unsigned __int8 *)&v5[out - in], (idea_key_st *)ctx->cipher_data);
      v6 += block_size;
      v5 += block_size;
    }
    while ( v6 <= v8 );
  }
  return 1;
}
