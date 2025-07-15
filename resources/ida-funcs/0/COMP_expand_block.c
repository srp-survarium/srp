int __cdecl COMP_expand_block(
        comp_ctx_st *ctx,
        unsigned __int8 *out,
        unsigned int olen,
        unsigned __int8 *in,
        unsigned int ilen)
{
  int (__cdecl *expand)(comp_ctx_st *, unsigned __int8 *, unsigned int, unsigned __int8 *, unsigned int); // eax
  int result; // eax

  expand = ctx->meth->expand;
  if ( !expand )
    return -1;
  result = expand(ctx, out, olen, in, ilen);
  if ( result > 0 )
  {
    ctx->expand_in += ilen;
    ctx->expand_out += result;
  }
  return result;
}
