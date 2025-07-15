int __cdecl update(WHIRLPOOL_CTX *ctx, const void *data, unsigned int count)
{
  return WHIRLPOOL_Update((WHIRLPOOL_CTX *)HIDWORD(ctx->H.q[1]), data, count);
}
