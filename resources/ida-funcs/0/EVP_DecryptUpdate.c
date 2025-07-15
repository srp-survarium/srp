BOOL __cdecl EVP_DecryptUpdate(evp_cipher_ctx_st *ctx, unsigned __int8 *out, int *outl, const __m128i *in, int inl)
{
  BOOL result; // eax
  unsigned int block_size; // edi
  unsigned __int8 *v8; // ebp
  int v9; // [esp+18h] [ebp+14h]

  if ( inl > 0 )
  {
    if ( (ctx->flags & 0x100) != 0 )
    {
      return EVP_EncryptUpdate(ctx, out, outl, in, inl);
    }
    else
    {
      block_size = ctx->cipher->block_size;
      if ( block_size > 0x20 )
        OpenSSLDie(block_size, (int)ctx, inl, ".\\crypto\\evp\\evp_enc.c", 400, "b <= sizeof ctx->final");
      v8 = out;
      if ( ctx->final_used )
      {
        memcpy((int)out, (const __m128i *)ctx->final, block_size);
        v8 = &out[block_size];
        v9 = 1;
      }
      else
      {
        v9 = 0;
      }
      result = EVP_EncryptUpdate(ctx, v8, outl, in, inl);
      if ( result )
      {
        if ( block_size <= 1 || ctx->buf_len )
        {
          ctx->final_used = 0;
        }
        else
        {
          *outl -= block_size;
          ctx->final_used = 1;
          memcpy((int)ctx->final, (const __m128i *)&v8[*outl], block_size);
        }
        if ( v9 )
          *outl += block_size;
        return 1;
      }
    }
  }
  else
  {
    *outl = 0;
    return inl == 0;
  }
  return result;
}
