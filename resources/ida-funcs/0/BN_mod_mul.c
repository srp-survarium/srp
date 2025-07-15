int __cdecl BN_mod_mul(bignum_st *r, bignum_pool_item *a, bignum_pool_item *b, const bignum_st *m, bignum_ctx *ctx)
{
  int v5; // ebx
  bignum_pool_item *v6; // edi
  int v7; // eax

  v5 = 0;
  BN_CTX_start(0, ctx);
  v6 = BN_CTX_get(0, ctx);
  if ( v6 )
  {
    if ( a == b )
      v7 = BN_sqr(v6, a, ctx);
    else
      v7 = BN_mul(v6, a, b, ctx);
    if ( v7 && BN_nnmod(0, r, v6->vals, m, ctx) )
      v5 = 1;
  }
  BN_CTX_end(ctx);
  return v5;
}
