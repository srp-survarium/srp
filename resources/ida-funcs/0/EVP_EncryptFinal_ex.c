int __cdecl EVP_EncryptFinal_ex(evp_cipher_ctx_st *ctx, unsigned __int8 *out, int *outl)
{
  unsigned int block_size; // edi
  int result; // eax
  unsigned int buf_len; // ecx

  block_size = ctx->cipher->block_size;
  if ( block_size > 0x20 )
    OpenSSLDie(block_size, (unsigned int)ctx, ".\\crypto\\evp\\evp_enc.c", 354, "b <= sizeof ctx->buf");
  if ( block_size == 1 )
  {
    result = 1;
    *outl = 0;
  }
  else
  {
    buf_len = ctx->buf_len;
    if ( (ctx->flags & 0x100) != 0 )
    {
      if ( buf_len )
      {
        ERR_put_error(6u, 127, 138, ".\\crypto\\evp\\evp_enc.c", 365);
        return 0;
      }
      else
      {
        *outl = 0;
        return 1;
      }
    }
    else
    {
      if ( buf_len < block_size )
        memset((int)&ctx->buf[buf_len], (unsigned __int8 *)(block_size - buf_len), block_size - buf_len);
      result = ctx->cipher->do_cipher(ctx, out, ctx->buf, block_size);
      if ( result )
        *outl = block_size;
    }
  }
  return result;
}
