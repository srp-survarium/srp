int __cdecl BN_GF2m_mod_exp_arr(bignum_st *r, const bignum_st *a, const bignum_st *b, int *p, bignum_ctx *ctx)
{
  int top; // eax
  bignum_pool_item *v7; // eax
  bignum_st *v8; // esi
  int v9; // ebp
  int v10; // [esp+4h] [ebp-4h]

  top = b->top;
  v10 = 0;
  if ( !top )
    return BN_set_word(r, 1u);
  if ( top == 1 && *b->d == 1 )
    return BN_copy(r, a) != 0;
  BN_CTX_start(ctx);
  v7 = BN_CTX_get(ctx);
  v8 = (bignum_st *)v7;
  if ( v7 && BN_GF2m_mod_arr(v7->vals, a, p) )
  {
    v9 = BN_num_bits(b) - 2;
    if ( v9 < 0 )
    {
LABEL_13:
      if ( BN_copy(r, v8) )
        v10 = 1;
    }
    else
    {
      while ( BN_GF2m_mod_sqr_arr(v8, v8, p, ctx) && (!BN_is_bit_set(b, v9) || BN_GF2m_mod_mul_arr(v8, v8, a, p, ctx)) )
      {
        if ( --v9 < 0 )
          goto LABEL_13;
      }
    }
  }
  BN_CTX_end(ctx);
  return v10;
}
