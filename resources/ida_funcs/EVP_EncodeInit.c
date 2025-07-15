void __cdecl EVP_EncodeInit(evp_Encode_Ctx_st *ctx)
{
  ctx->length = 48;
  ctx->num = 0;
  ctx->line_num = 0;
}
