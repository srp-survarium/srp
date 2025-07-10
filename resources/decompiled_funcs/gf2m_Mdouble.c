int __usercall gf2m_Mdouble@<eax>(const ec_group_st *group@<ecx>, bignum_ctx *ctx@<edi>, bignum_st *x, bignum_st *z)
{
  bignum_pool_item *v5; // ebx
  int v6; // esi
  bignum_ctx *v8; // [esp+0h] [ebp-14h]

  BN_CTX_start(v8);
  v5 = BN_CTX_get(ctx);
  if ( !v5
    || !group->meth->field_sqr(group, x, x, ctx)
    || !group->meth->field_sqr(group, (bignum_st *)v5, z, ctx)
    || !group->meth->field_mul(group, z, x, (const bignum_st *)v5, ctx)
    || !group->meth->field_sqr(group, x, x, ctx)
    || !group->meth->field_sqr(group, (bignum_st *)v5, (const bignum_st *)v5, ctx)
    || !group->meth->field_mul(group, (bignum_st *)v5, &group->b, (const bignum_st *)v5, ctx)
    || (v6 = 1, !BN_GF2m_add(x, x, v5->vals)) )
  {
    v6 = 0;
  }
  BN_CTX_end(ctx);
  return v6;
}
