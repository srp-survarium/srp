int __usercall witness@<eax>(
        bignum_pool_item *w@<esi>,
        const bignum_st *a@<ebx>,
        const bignum_st *a1_odd@<ecx>,
        bignum_ctx *ctx@<edi>,
        const bignum_st *a1,
        int k,
        bn_mont_ctx_st *mont)
{
  int ka; // [esp+8h] [ebp+8h]

  if ( !BN_mod_exp_mont(w->vals, w->vals, a1_odd, a, ctx, mont) )
    return -1;
  if ( w->vals[0].top == 1 && *w->vals[0].d == 1 && !w->vals[0].neg || !BN_cmp(w->vals, a1) )
    return 0;
  ka = k - 1;
  if ( !ka )
    return 1;
  while ( BN_mod_mul(w->vals, w, w, a, ctx) )
  {
    if ( w->vals[0].top != 1 || *w->vals[0].d != 1 || w->vals[0].neg )
    {
      if ( !BN_cmp(w->vals, a1) )
        return 0;
      if ( --ka )
        continue;
    }
    return 1;
  }
  return -1;
}
