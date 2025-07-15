BOOL __usercall BN_GF2m_mod_div@<eax>(
        int a1@<ebx>,
        bignum_st *r,
        const bignum_st *y,
        const bignum_st *x,
        const bignum_st *p,
        bignum_ctx *ctx)
{
  BOOL v6; // ebp
  bignum_pool_item *v7; // edi

  v6 = 0;
  BN_CTX_start(a1, ctx);
  v7 = BN_CTX_get(a1, ctx);
  if ( v7 && BN_GF2m_mod_inv(v7->vals, x, p, ctx) )
    v6 = BN_GF2m_mod_mul(r, y, v7->vals, p, ctx) != 0;
  BN_CTX_end(ctx);
  return v6;
}
