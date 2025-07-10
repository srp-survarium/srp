int __usercall gf2m_Mxy@<eax>(
        const ec_group_st *group@<ecx>,
        bignum_st *z2@<ebx>,
        bignum_ctx *ctx@<edi>,
        const bignum_st *x,
        const bignum_st *y,
        bignum_st *x1,
        bignum_st *z1,
        bignum_st *x2)
{
  int result; // eax
  bignum_pool_item *v10; // ebp
  bignum_pool_item *v11; // eax
  int v12; // esi
  bignum_pool_item *v13; // [esp+4h] [ebp-Ch]
  const bignum_st *v14; // [esp+8h] [ebp-8h]

  if ( z1->top )
  {
    if ( z2->top )
    {
      BN_CTX_start(ctx);
      v10 = BN_CTX_get(ctx);
      v13 = BN_CTX_get(ctx);
      v11 = BN_CTX_get(ctx);
      v14 = (const bignum_st *)v11;
      if ( !v11
        || !BN_set_word(v11->vals, 1u)
        || !group->meth->field_mul(group, (bignum_st *)v10, z1, z2, ctx)
        || !group->meth->field_mul(group, z1, z1, x, ctx)
        || !BN_GF2m_add(z1, z1, x1)
        || !group->meth->field_mul(group, z2, z2, x, ctx)
        || !group->meth->field_mul(group, x1, z2, x1, ctx)
        || !BN_GF2m_add(z2, z2, x2)
        || !group->meth->field_mul(group, z2, z2, z1, ctx)
        || !group->meth->field_sqr(group, (bignum_st *)v13, x, ctx)
        || !BN_GF2m_add(v13->vals, v13->vals, y)
        || !group->meth->field_mul(group, (bignum_st *)v13, (const bignum_st *)v13, (const bignum_st *)v10, ctx)
        || !BN_GF2m_add(v13->vals, v13->vals, z2)
        || !group->meth->field_mul(group, (bignum_st *)v10, (const bignum_st *)v10, x, ctx)
        || !group->meth->field_div(group, (bignum_st *)v10, v14, (const bignum_st *)v10, ctx)
        || !group->meth->field_mul(group, (bignum_st *)v13, (const bignum_st *)v10, (const bignum_st *)v13, ctx)
        || !group->meth->field_mul(group, x2, x1, (const bignum_st *)v10, ctx)
        || !BN_GF2m_add(z2, x2, x)
        || !group->meth->field_mul(group, z2, z2, (const bignum_st *)v13, ctx)
        || (v12 = 2, !BN_GF2m_add(z2, z2, y)) )
      {
        v12 = 0;
      }
      BN_CTX_end(ctx);
      return v12;
    }
    else
    {
      result = (int)BN_copy(x2, x);
      if ( result )
        return BN_GF2m_add(z2, x, y) != 0 ? 2 : 0;
    }
  }
  else
  {
    BN_set_word(x2, 0);
    BN_set_word(z2, 0);
    return 1;
  }
  return result;
}
