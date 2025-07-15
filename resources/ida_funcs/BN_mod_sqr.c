int __cdecl BN_mod_sqr(bignum_st *r, const bignum_st *a, const bignum_st *m, bignum_ctx *ctx)
{
  int result; // eax

  result = BN_sqr(r, a, ctx);
  if ( result )
    return BN_div(0, r, r, m, ctx);
  return result;
}
