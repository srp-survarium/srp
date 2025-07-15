int __usercall BN_GF2m_mod_exp_arr@<eax>(
        int a1@<ebx>,
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *b,
        int *p,
        bignum_ctx *ctx)
{
  int top; // eax
  bignum_pool_item *v8; // eax
  bignum_st *v9; // esi
  int v10; // ebp
  int v11; // [esp+4h] [ebp-4h]

  top = b->top;
  v11 = 0;
  if ( !top )
    return BN_set_word(a1, r, 1u);
  if ( top == 1 && *b->d == 1 )
    return BN_copy(r, a) != 0;
  BN_CTX_start(a1, ctx);
  v8 = BN_CTX_get(a1, ctx);
  v9 = (bignum_st *)v8;
  if ( v8 && BN_GF2m_mod_arr((int)p, v8->vals, a, p) )
  {
    v10 = BN_num_bits(b) - 2;
    if ( v10 < 0 )
    {
LABEL_13:
      if ( BN_copy(r, v9) )
        v11 = 1;
    }
    else
    {
      while ( BN_GF2m_mod_sqr_arr(v9, v9, p, ctx) && (!BN_is_bit_set(b, v10) || BN_GF2m_mod_mul_arr(v9, v9, a, p, ctx)) )
      {
        if ( --v10 < 0 )
          goto LABEL_13;
      }
    }
  }
  BN_CTX_end(ctx);
  return v11;
}
