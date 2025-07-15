int __cdecl EVP_DecodeUpdate(
        evp_Encode_Ctx_st *ctx,
        unsigned __int8 *out,
        int *outl,
        const unsigned __int8 *in,
        int inl)
{
  int num; // ecx
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  int v10; // eax
  int result; // eax
  int expect_nl; // [esp+10h] [ebp-14h]
  int v13; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int v15; // [esp+20h] [ebp-4h]
  int line_num; // [esp+28h] [ebp+4h]

  num = ctx->num;
  line_num = ctx->line_num;
  expect_nl = ctx->expect_nl;
  v7 = 0;
  v13 = -1;
  v15 = 0;
  if ( !inl || !num && data_ascii2bin[*in & 0x7F] == 0xF2 )
  {
LABEL_41:
    result = 0;
    goto end_12;
  }
  for ( i = 0; i < inl; ++i )
  {
    if ( line_num >= 80 )
    {
LABEL_40:
      result = -1;
      goto end_12;
    }
    v8 = *in++;
    v9 = data_ascii2bin[v8 & 0x7F];
    if ( (v9 | 0x13) == 0xF3 )
    {
      if ( v9 == 255 )
        goto LABEL_40;
    }
    else
    {
      if ( num >= 80 )
        OpenSSLDie(v7, v9, v8, ".\\crypto\\evp\\encode.c", 262, "n < (int)sizeof(ctx->enc_data)");
      ctx->enc_data[num++] = v8;
      ++line_num;
    }
    if ( v8 == 61 )
    {
      if ( v13 == -1 )
        v13 = num;
      ++v7;
    }
    if ( v9 == 241 )
    {
      line_num = 0;
      if ( expect_nl )
        continue;
    }
    else if ( v9 == 240 )
    {
      line_num = 0;
      if ( expect_nl )
      {
        expect_nl = 0;
        continue;
      }
    }
    expect_nl = 0;
    if ( i + 1 == inl && ((num & 3) == 0 || v7) )
    {
      v9 = 242;
      v7 = *((_BYTE *)&ctx->length + num + 3) == 61;
      if ( *((_BYTE *)&ctx->length + num + 2) == 61 )
        ++v7;
    }
    else if ( v9 != 242 )
    {
      goto LABEL_27;
    }
    if ( (num & 3) != 0 )
    {
LABEL_27:
      if ( num < 64 )
        continue;
      if ( v9 != 242 )
        expect_nl = 1;
    }
    if ( num <= 0 )
    {
      v7 = 1;
      v10 = 0;
    }
    else
    {
      v10 = EVP_DecodeBlock(out, ctx->enc_data, num);
      num = 0;
      if ( v10 < 0 )
        goto LABEL_41;
      v15 += v10 - v7;
    }
    if ( v10 < ctx->length && v7 )
      goto LABEL_41;
    ctx->length = v10;
    if ( v13 >= 0 )
      goto LABEL_41;
    out += v10;
  }
  result = 1;
end_12:
  *outl = v15;
  ctx->num = num;
  ctx->line_num = line_num;
  ctx->expect_nl = expect_nl;
  return result;
}
