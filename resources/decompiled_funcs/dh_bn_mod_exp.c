int __cdecl dh_bn_mod_exp(
        const dh_st *dh,
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *m_ctx)
{
  if ( a->top == 1 && (dh->flags & 2) != 0 )
    return BN_mod_exp_mont_word(r, *a->d, p, m, ctx, m_ctx);
  else
    return BN_mod_exp_mont(r, a, p, m, ctx, m_ctx);
}
