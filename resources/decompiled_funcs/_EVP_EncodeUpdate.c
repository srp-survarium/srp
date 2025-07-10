void __usercall EVP_EncodeUpdate(
        unsigned int a1@<esi>,
        evp_Encode_Ctx_st *ctx,
        unsigned __int8 *out,
        int *outl,
        unsigned __int8 *in,
        unsigned int inl)
{
  int v6; // ebx
  int num; // eax
  int length; // esi
  unsigned __int8 *v9; // ebp
  unsigned int v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // esi
  int v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // esi
  int v16; // [esp+4h] [ebp-4h]

  v6 = inl;
  v16 = 0;
  *outl = 0;
  if ( inl )
  {
    if ( ctx->length > 80 )
      OpenSSLDie((unsigned int)ctx, a1, ".\\crypto\\evp\\encode.c", 139, "ctx->length <= (int)sizeof(ctx->enc_data)");
    num = ctx->num;
    length = ctx->length;
    if ( (int)(ctx->num + inl) >= length )
    {
      v9 = in;
      if ( num )
      {
        v10 = length - num;
        memcpy(&ctx->enc_data[num], in, v10);
        v9 = &in[v10];
        v6 = inl - v10;
        v11 = EVP_EncodeBlock(out, ctx->enc_data, ctx->length);
        ctx->num = 0;
        out[v11] = 10;
        v12 = &out[v11 + 1];
        *v12 = 0;
        v16 = v11 + 1;
      }
      else
      {
        v12 = out;
      }
      for ( ; v6 >= ctx->length; v16 += v13 + 1 )
      {
        v13 = EVP_EncodeBlock(v12, v9, ctx->length);
        v14 = ctx->length;
        v15 = &v12[v13];
        *v15 = 10;
        v12 = v15 + 1;
        v6 -= v14;
        v9 += v14;
        *v12 = 0;
      }
      if ( v6 )
        memcpy(ctx->enc_data, v9, v6);
      ctx->num = v6;
      *outl = v16;
    }
    else
    {
      memcpy(&ctx->enc_data[num], in, inl);
      ctx->num += inl;
    }
  }
}
