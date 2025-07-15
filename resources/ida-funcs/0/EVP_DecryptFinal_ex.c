int __usercall EVP_DecryptFinal_ex@<eax>(int a1@<ebx>, evp_cipher_ctx_st *ctx, unsigned __int8 *out, int *outl)
{
  unsigned int block_size; // edi
  signed int v6; // eax
  int v7; // edx
  unsigned __int8 *v8; // ecx
  int v9; // edi
  int v10; // ecx
  int i; // eax

  *outl = 0;
  block_size = ctx->cipher->block_size;
  if ( (ctx->flags & 0x100) != 0 )
  {
    if ( ctx->buf_len )
    {
      ERR_put_error(a1, 6u, 101, 138, ".\\crypto\\evp\\evp_enc.c", 450);
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
    ERR_put_error(a1, 6u, 101, 109, ".\\crypto\\evp\\evp_enc.c", 460);
    return 0;
  }
  if ( block_size > 0x20 )
    OpenSSLDie(block_size, (int)ctx, a1, ".\\crypto\\evp\\evp_enc.c", 463, "b <= sizeof ctx->final");
  v6 = *((unsigned __int8 *)&ctx->block_mask + block_size + 3);
  if ( !*((_BYTE *)&ctx->block_mask + block_size + 3) || v6 > (int)block_size )
  {
    ERR_put_error(a1, 6u, 101, 100, ".\\crypto\\evp\\evp_enc.c", 467);
    return 0;
  }
  v7 = 0;
  if ( *((_BYTE *)&ctx->block_mask + block_size + 3) )
  {
    v8 = &ctx->final[block_size];
    while ( 1 )
    {
      v9 = *--v8;
      if ( v9 != v6 )
        break;
      if ( ++v7 >= v6 )
        goto LABEL_15;
    }
    ERR_put_error(a1, 6u, 101, 100, ".\\crypto\\evp\\evp_enc.c", 474);
    return 0;
  }
LABEL_15:
  v10 = ctx->cipher->block_size - v6;
  for ( i = 0; i < v10; ++i )
    out[i] = ctx->final[i];
  *outl = v10;
  return 1;
}
