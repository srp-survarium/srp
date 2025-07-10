int __cdecl COMP_compress_block(
        comp_ctx_st *ctx,
        unsigned __int8 *out,
        unsigned int olen,
        unsigned __int8 *in,
        unsigned int ilen)
{
  int (__cdecl *compress)(comp_ctx_st *, unsigned __int8 *, unsigned int, unsigned __int8 *, unsigned int); // eax
  int result; // eax

  compress = ctx->meth->compress;
  if ( !compress )
    return -1;
  result = compress(ctx, out, olen, in, ilen);
  if ( result > 0 )
  {
    ctx->compress_in += ilen;
    ctx->compress_out += result;
  }
  return result;
}
