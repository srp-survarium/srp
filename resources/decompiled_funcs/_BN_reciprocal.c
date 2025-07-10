int __cdecl BN_reciprocal(bignum_pool_item *r, const bignum_st *m, int len, bignum_ctx *ctx)
{
  int v4; // ebx
  bignum_pool_item *v5; // eax
  const bignum_st *v6; // esi

  v4 = -1;
  BN_CTX_start(ctx);
  v5 = BN_CTX_get(ctx);
  v6 = (const bignum_st *)v5;
  if ( v5 && BN_set_bit(v5->vals, len) && BN_div(r, 0, v6, m, ctx) )
    v4 = len;
  BN_CTX_end(ctx);
  return v4;
}
