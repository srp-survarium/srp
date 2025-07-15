int __cdecl BN_mod_mul_reciprocal(
        bignum_pool_item *r,
        bignum_pool_item *x,
        bignum_pool_item *y,
        bignum_pool_item *recp,
        bignum_ctx *ctx)
{
  int v5; // ebx
  bignum_pool_item *v6; // edi
  int v7; // eax

  v5 = 0;
  BN_CTX_start(ctx);
  v6 = BN_CTX_get(ctx);
  if ( v6 )
  {
    if ( !y )
    {
      v6 = x;
LABEL_9:
      v5 = BN_div_recp(0, r, v6->vals, recp, ctx);
      goto err_189;
    }
    if ( x == y )
      v7 = BN_sqr(v6, x, ctx);
    else
      v7 = BN_mul(v6, x, y, ctx);
    if ( v7 )
      goto LABEL_9;
  }
err_189:
  BN_CTX_end(ctx);
  return v5;
}
