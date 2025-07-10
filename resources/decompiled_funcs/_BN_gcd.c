int __cdecl BN_gcd(bignum_st *r, const bignum_st *in_a, const bignum_st *in_b, bignum_ctx *ctx)
{
  int v4; // ebp
  bignum_pool_item *v5; // esi
  bignum_pool_item *v6; // eax
  bignum_st *v7; // edi
  bignum_pool_item *v8; // eax
  bignum_st *v9; // eax

  v4 = 0;
  BN_CTX_start(ctx);
  v5 = BN_CTX_get(ctx);
  v6 = BN_CTX_get(ctx);
  v7 = (bignum_st *)v6;
  if ( v5 && v6 && BN_copy(v5->vals, in_a) && BN_copy(v7, in_b) )
  {
    v5->vals[0].neg = 0;
    v7->neg = 0;
    if ( BN_cmp(v5->vals, v7) < 0 )
    {
      v8 = v5;
      v5 = (bignum_pool_item *)v7;
      v7 = (bignum_st *)v8;
    }
    v9 = euclid(v7, v5->vals);
    if ( v9 && BN_copy(r, v9) )
      v4 = 1;
  }
  BN_CTX_end(ctx);
  return v4;
}
