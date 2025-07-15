int __cdecl BN_gcd(bignum_st *r, const bignum_st *in_a, const bignum_st *in_b, bignum_ctx *ctx)
{
  int v5; // ebp
  bignum_pool_item *v6; // esi
  bignum_pool_item *v7; // eax
  bignum_st *v8; // edi
  bignum_pool_item *v9; // eax
  bignum_st *v10; // eax

  v5 = 0;
  BN_CTX_start((int)ctx, ctx);
  v6 = BN_CTX_get((int)ctx, ctx);
  v7 = BN_CTX_get((int)ctx, ctx);
  v8 = (bignum_st *)v7;
  if ( v6 && v7 && BN_copy(v6->vals, in_a) && BN_copy(v8, in_b) )
  {
    v6->vals[0].neg = 0;
    v8->neg = 0;
    if ( BN_cmp(v6->vals, v8) < 0 )
    {
      v9 = v6;
      v6 = (bignum_pool_item *)v8;
      v8 = (bignum_st *)v9;
    }
    v10 = euclid(v8, v6->vals);
    if ( v10 && BN_copy(r, v10) )
      v5 = 1;
  }
  BN_CTX_end(ctx);
  return v5;
}
