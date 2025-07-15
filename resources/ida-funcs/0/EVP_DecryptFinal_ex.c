int __cdecl EVP_DecryptFinal_ex(evp_cipher_ctx_st *ctx, unsigned __int8 *out, int *outl)
{
  unsigned int block_size; // edi
  signed int v5; // eax
  int v6; // edx
  unsigned __int8 *v7; // ecx
  int v8; // edi
  int v9; // ecx
  int i; // eax

  *outl = 0;
  block_size = ctx->cipher->block_size;
  if ( (ctx->flags & 0x100) != 0 )
  {
    if ( ctx->buf_len )
    {
      ERR_put_error(6u, 101, 138, ".\\crypto\\evp\\evp_enc.c", 450);
      return 0;
    }
    goto LABEL_22;
  }
  if ( block_size <= 1 )
  {
LABEL_22:
    *outl = 0;
    return 1;
  }
  if ( ctx->buf_len || !ctx->final_used )
  {
    ERR_put_error(6u, 101, 109, ".\\crypto\\evp\\evp_enc.c", 460);
    return 0;
  }
  if ( block_size > 0x20 )
    OpenSSLDie(block_size, (unsigned int)ctx, ".\\crypto\\evp\\evp_enc.c", 463, "b <= sizeof ctx->final");
  v5 = *((unsigned __int8 *)&ctx->block_mask + block_size + 3);
  if ( !*((_BYTE *)&ctx->block_mask + block_size + 3) || v5 > (int)block_size )
  {
    ERR_put_error(6u, 101, 100, ".\\crypto\\evp\\evp_enc.c", 467);
    return 0;
  }
  v6 = 0;
  if ( *((_BYTE *)&ctx->block_mask + block_size + 3) )
  {
    v7 = &ctx->final[block_size];
    while ( 1 )
    {
      v8 = *--v7;
      if ( v8 != v5 )
        break;
      if ( ++v6 >= v5 )
        goto LABEL_15;
    }
    ERR_put_error(6u, 101, 100, ".\\crypto\\evp\\evp_enc.c", 474);
    return 0;
  }
LABEL_15:
  v9 = ctx->cipher->block_size - v5;
  for ( i = 0; i < v9; ++i )
    out[i] = ctx->final[i];
  *outl = v9;
  return 1;
}
