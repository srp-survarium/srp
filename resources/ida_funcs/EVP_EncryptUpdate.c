BOOL __cdecl EVP_EncryptUpdate(evp_cipher_ctx_st *ctx, unsigned __int8 *out, int *outl, unsigned __int8 *in, int inl)
{
  unsigned int v5; // edi
  BOOL result; // eax
  int buf_len; // ebx
  signed int block_size; // ebp
  int v9; // ebx
  int *v10; // ebx
  int v11; // ebp
  signed int v12; // edi
  int inla; // [esp+18h] [ebp+14h]

  v5 = inl;
  if ( inl <= 0 )
  {
    *outl = 0;
    return inl == 0;
  }
  buf_len = ctx->buf_len;
  inla = buf_len;
  if ( !buf_len && (v5 & ctx->block_mask) == 0 )
  {
    if ( ctx->cipher->do_cipher(ctx, out, in, v5) )
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
    OpenSSLDie(v5, (unsigned int)ctx, ".\\crypto\\evp\\evp_enc.c", 304, "bl <= (int)sizeof(ctx->buf)");
  if ( buf_len )
  {
    if ( (int)(buf_len + v5) < block_size )
    {
      memcpy(&ctx->buf[buf_len], in, v5);
      ctx->buf_len += v5;
      *outl = 0;
      return 1;
    }
    v9 = block_size - buf_len;
    memcpy(&ctx->buf[inla], in, block_size - inla);
    if ( !ctx->cipher->do_cipher(ctx, out, ctx->buf, block_size) )
      return 0;
    in += v9;
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
    if ( !ctx->cipher->do_cipher(ctx, out, in, v12) )
      return 0;
    *v10 += v12;
  }
  if ( v11 )
    memcpy(ctx->buf, &in[v12], v11);
  ctx->buf_len = v11;
  return 1;
}
