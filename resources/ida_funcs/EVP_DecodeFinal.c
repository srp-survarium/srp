int __cdecl EVP_DecodeFinal(evp_Encode_Ctx_st *ctx, unsigned __int8 *out, int *outl)
{
  int v3; // eax

  *outl = 0;
  if ( ctx->num )
  {
    v3 = EVP_DecodeBlock(out, ctx->enc_data, ctx->num);
    if ( v3 < 0 )
      return -1;
    ctx->num = 0;
    *outl = v3;
  }
  return 1;
}
