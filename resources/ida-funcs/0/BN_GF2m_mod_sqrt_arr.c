int __cdecl BN_GF2m_mod_sqrt_arr(bignum_st *r, const bignum_st *a, int *p, bignum_ctx *ctx)
{
  int v4; // ebp
  bignum_pool_item *v6; // eax
  const bignum_st *v7; // esi

  v4 = 0;
  if ( *p )
  {
    BN_CTX_start(ctx);
    v6 = BN_CTX_get(ctx);
    v7 = (const bignum_st *)v6;
    if ( v6 )
    {
      if ( BN_set_bit(v6->vals, *p - 1) )
        v4 = BN_GF2m_mod_exp_arr(r, a, v7, p, ctx);
    }
    BN_CTX_end(ctx);
    return v4;
  }
  else
  {
    BN_set_word(r, 0);
    return 1;
  }
}
