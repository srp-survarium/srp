int __cdecl BN_mod_exp(bignum_st *r, const bignum_st *a, const bignum_st *p, const bignum_st *m, bignum_ctx *ctx)
{
  if ( m->top <= 0 || (*(_BYTE *)m->d & 1) == 0 )
    return BN_mod_exp_recp(r, a, p, m, ctx);
  if ( a->top != 1 || a->neg || (p->flags & 4) != 0 )
    return BN_mod_exp_mont(r, a, p, m, ctx, 0);
  return BN_mod_exp_mont_word(r, *a->d, p, m, ctx, 0);
}
