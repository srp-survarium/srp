void __cdecl EVP_EncodeFinal(evp_Encode_Ctx_st *ctx, unsigned __int8 *out, int *outl)
{
  int v3; // eax

  if ( ctx->num )
  {
    v3 = EVP_EncodeBlock(out, ctx->enc_data, ctx->num);
    out[v3] = 10;
    out[++v3] = 0;
    ctx->num = 0;
    *outl = v3;
  }
  else
  {
    *outl = 0;
  }
}
