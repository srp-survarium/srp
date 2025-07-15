int __cdecl BN_mod_mul_montgomery(
        bignum_st *r,
        bignum_pool_item *a,
        bignum_pool_item *b,
        bn_mont_ctx_st *mont,
        bignum_ctx *ctx)
{
  bn_mont_ctx_st *v5; // ecx
  int top; // esi
  int result; // eax
  int v8; // edx
  int v9; // eax
  unsigned int *v10; // esi
  bignum_pool_item *v12; // eax
  bignum_st *v13; // esi
  int v14; // eax
  int v15; // [esp+10h] [ebp-4h]

  v5 = mont;
  top = mont->N.top;
  v15 = 0;
  if ( top > 1 && a->vals[0].top == top && b->vals[0].top == top )
  {
    if ( top > r->dmax )
    {
      result = (int)bn_expand2(r, top);
      v5 = mont;
    }
    else
    {
      result = (int)r;
    }
    if ( !result )
      return result;
    if ( bn_mul_mont(r->d, a->vals[0].d, b->vals[0].d, v5->N.d, v5->n0, top) )
    {
      v8 = b->vals[0].neg ^ a->vals[0].neg;
      r->top = top;
      r->neg = v8;
      v9 = top;
      v10 = &r->d[top - 1];
      do
      {
        if ( *v10-- )
          break;
        --v9;
      }
      while ( v9 > 0 );
      r->top = v9;
      return 1;
    }
  }
  BN_CTX_start((int)a, ctx);
  v12 = BN_CTX_get((int)a, ctx);
  v13 = (bignum_st *)v12;
  if ( v12 )
  {
    v14 = a == b ? BN_sqr(v12, a, ctx) : BN_mul(v12, a, b, ctx);
    if ( v14 && BN_from_montgomery_word(r, v13, mont) )
      v15 = 1;
  }
  BN_CTX_end(ctx);
  return v15;
}
