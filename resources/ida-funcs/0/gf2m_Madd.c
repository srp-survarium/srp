int __usercall gf2m_Madd@<eax>(
        const ec_group_st *group@<ecx>,
        bignum_st *z1@<ebx>,
        bignum_ctx *ctx@<esi>,
        const bignum_st *x,
        bignum_st *x1,
        const bignum_st *x2,
        const bignum_st *z2)
{
  int v8; // edi
  bignum_ctx *v10; // [esp+0h] [ebp-18h]
  bignum_pool_item *a; // [esp+Ch] [ebp-Ch]
  bignum_pool_item *v12; // [esp+10h] [ebp-8h]

  BN_CTX_start((int)z1, v10);
  a = BN_CTX_get((int)z1, ctx);
  v12 = BN_CTX_get((int)z1, ctx);
  if ( !v12
    || !BN_copy(a->vals, x)
    || !group->meth->field_mul(group, x1, x1, z2, ctx)
    || !group->meth->field_mul(group, z1, z1, x2, ctx)
    || !group->meth->field_mul(group, (bignum_st *)v12, x1, z1, ctx)
    || !BN_GF2m_add(z1, z1, x1)
    || !group->meth->field_sqr(group, z1, z1, ctx)
    || !group->meth->field_mul(group, x1, z1, (const bignum_st *)a, ctx)
    || (v8 = 1, !BN_GF2m_add(x1, x1, v12->vals)) )
  {
    v8 = 0;
  }
  BN_CTX_end(ctx);
  return v8;
}
