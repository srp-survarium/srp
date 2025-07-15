int __usercall BN_mod_sqr@<eax>(
        int a1@<ebx>,
        bignum_pool_item *r,
        bignum_pool_item *a,
        const bignum_st *m,
        bignum_ctx *ctx)
{
  int result; // eax

  result = BN_sqr(r, a, ctx);
  if ( result )
    return BN_div(a1, 0, r->vals, r->vals, m, ctx);
  return result;
}
