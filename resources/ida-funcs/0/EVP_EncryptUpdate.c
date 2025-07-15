BOOL __cdecl EVP_EncryptUpdate(evp_cipher_ctx_st *ctx, unsigned __int8 *out, int *outl, const __m128i *in, int inl)
{
  int v5; // edi
  BOOL result; // eax
  int buf_len; // ebx
  signed int block_size; // ebp
  int v9; // ebx
  int *v10; // ebx
  int v11; // ebp
  signed int v12; // edi
  unsigned int count; // [esp+18h] [ebp+14h]

  v5 = inl;
  if ( inl <= 0 )
  {
    *outl = 0;
    return inl == 0;
  }
  buf_len = ctx->buf_len;
  count = buf_len;
  if ( !buf_len && (v5 & ctx->block_mask) == 0 )
  {
    if ( ctx->cipher->do_cipher(ctx, out, (const unsigned __int8 *)in, v5) )
    {
      result = 1;
      *outl = v5;
    }
    else
    {
      *outl = 0;
      return 0;
    }
    return result;
  }
  block_size = ctx->cipher->block_size;
  if ( block_size > 32 )
    OpenSSLDie(v5, (int)ctx, buf_len, ".\\crypto\\evp\\evp_enc.c", 304, "bl <= (int)sizeof(ctx->buf)");
  if ( buf_len )
  {
    if ( buf_len + v5 < block_size )
    {
      memcpy((int)&ctx->buf[buf_len], in, v5);
      ctx->buf_len += v5;
      *outl = 0;
      return 1;
    }
    v9 = block_size - buf_len;
    memcpy((int)&ctx->buf[count], in, block_size - count);
    if ( !ctx->cipher->do_cipher(ctx, out, ctx->buf, block_size) )
      return 0;
    in = (const __m128i *)((char *)in + v9);
    v5 -= v9;
    v10 = outl;
    out += block_size;
    *outl = block_size;
  }
  else
  {
    v10 = outl;
    *outl = 0;
  }
  v11 = v5 & (block_size - 1);
  v12 = v5 - v11;
  if ( v12 > 0 )
  {
    if ( !ctx->cipher->do_cipher(ctx, out, (const unsigned __int8 *)in, v12) )
      return 0;
    *v10 += v12;
  }
  if ( v11 )
    memcpy((int)ctx->buf, (const __m128i *)((char *)in + v12), v11);
  ctx->buf_len = v11;
  return 1;
}
