int __usercall gf2m_Mdouble@<eax>(
        const ec_group_st *group@<ecx>,
        bignum_ctx *ctx@<edi>,
        int a3@<ebx>,
        bignum_st *x,
        bignum_st *z)
{
  bignum_pool_item *v6; // ebx
  int v7; // esi
  bignum_ctx *v9; // [esp+0h] [ebp-14h]

  BN_CTX_start(a3, v9);
  v6 = BN_CTX_get(a3, ctx);
  if ( !v6
    || !group->meth->field_sqr(group, x, x, ctx)
    || !group->meth->field_sqr(group, (bignum_st *)v6, z, ctx)
    || !group->meth->field_mul(group, z, x, (const bignum_st *)v6, ctx)
    || !group->meth->field_sqr(group, x, x, ctx)
    || !group->meth->field_sqr(group, (bignum_st *)v6, (const bignum_st *)v6, ctx)
    || !group->meth->field_mul(group, (bignum_st *)v6, &group->b, (const bignum_st *)v6, ctx)
    || (v7 = 1, !BN_GF2m_add(x, x, v6->vals)) )
  {
    v7 = 0;
  }
  BN_CTX_end(ctx);
  return v7;
}
