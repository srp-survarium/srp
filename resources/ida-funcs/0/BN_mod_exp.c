int __usercall BN_mod_exp@<eax>(
        int a1@<ebx>,
        bignum_pool_item *r,
        bignum_pool_item *a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx)
{
  if ( m->top <= 0 || (*(_BYTE *)m->d & 1) == 0 )
    return BN_mod_exp_recp(a1, r, a->vals, p, m, ctx);
  if ( a->vals[0].top != 1 || a->vals[0].neg || (p->flags & 4) != 0 )
    return BN_mod_exp_mont(a1, r->vals, a, p, m, ctx, 0);
  return BN_mod_exp_mont_word(a1, r->vals, *a->vals[0].d, p, m, ctx, 0);
}
