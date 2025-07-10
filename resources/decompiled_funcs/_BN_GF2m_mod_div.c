BOOL __cdecl BN_GF2m_mod_div(bignum_st *r, const bignum_st *y, const bignum_st *x, const bignum_st *p, bignum_ctx *ctx)
{
  BOOL v5; // ebp
  bignum_pool_item *v6; // edi

  v5 = 0;
  BN_CTX_start(ctx);
  v6 = BN_CTX_get(ctx);
  if ( v6 && BN_GF2m_mod_inv(v6->vals, x, p, ctx) )
    v5 = BN_GF2m_mod_mul(r, y, v6->vals, p, ctx) != 0;
  BN_CTX_end(ctx);
  return v5;
}
