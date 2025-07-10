int __cdecl BN_mod_add(bignum_st *r, const bignum_st *a, const bignum_st *b, const bignum_st *m, bignum_ctx *ctx)
{
  int result; // eax

  result = BN_add(r, a, b);
  if ( result )
    return BN_nnmod(r, r, m, ctx);
  return result;
}
