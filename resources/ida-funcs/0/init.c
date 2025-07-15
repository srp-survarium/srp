int __cdecl init(WHIRLPOOL_CTX *ctx)
{
  return WHIRLPOOL_Init((WHIRLPOOL_CTX *)HIDWORD(ctx->H.q[1]));
}
