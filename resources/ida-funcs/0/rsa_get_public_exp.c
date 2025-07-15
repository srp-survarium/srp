bignum_st *__usercall rsa_get_public_exp@<eax>(
        bignum_ctx *ctx@<esi>,
        const bignum_st *d,
        const bignum_st *p,
        const bignum_st *q)
{
  bignum_pool_item *v4; // ebx
  bignum_pool_item *v5; // ebp
  bignum_pool_item *v6; // edi
  const bignum_st *v7; // eax
  const bignum_st *v8; // eax
  bignum_st *v9; // edi

  if ( !d || !p || !q )
    return 0;
  BN_CTX_start(ctx);
  v4 = BN_CTX_get(ctx);
  v5 = BN_CTX_get(ctx);
  v6 = BN_CTX_get(ctx);
  if ( v6
    && (v7 = BN_value_one(), BN_sub(v5->vals, p, v7))
    && (v8 = BN_value_one(), BN_sub(v6->vals, q, v8))
    && BN_mul(v4, v5, v6, ctx) )
  {
    v9 = BN_mod_inverse(0, d, v4->vals, ctx);
    BN_CTX_end(ctx);
    return v9;
  }
  else
  {
    BN_CTX_end(ctx);
    return 0;
  }
}
