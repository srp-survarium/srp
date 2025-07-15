void __cdecl EVP_DecodeInit(evp_Encode_Ctx_st *ctx)
{
  ctx->length = 30;
  ctx->num = 0;
  ctx->line_num = 0;
  ctx->expect_nl = 0;
}
