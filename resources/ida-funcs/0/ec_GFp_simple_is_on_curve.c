int __usercall ec_GFp_simple_is_on_curve@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        const ec_point_st *point,
        bignum_ctx *ctx)
{
  bignum_ctx *v5; // esi
  bignum_pool_item *v6; // ebx
  bignum_pool_item *v7; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // edi
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // [esp+4h] [ebp-18h]
  bignum_pool_item *a; // [esp+8h] [ebp-14h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+Ch] [ebp-10h]
  bignum_pool_item *v14; // [esp+10h] [ebp-Ch]
  bignum_ctx *v15; // [esp+14h] [ebp-8h]

  v15 = 0;
  if ( EC_POINT_is_at_infinity(a1, group, point) )
    return 1;
  v5 = ctx;
  field_mul = group->meth->field_mul;
  field_sqr = group->meth->field_sqr;
  if ( !ctx )
  {
    v15 = BN_CTX_new(a1);
    v5 = v15;
    if ( !v15 )
      return -1;
  }
  BN_CTX_start(a1, v5);
  v6 = BN_CTX_get(a1, v5);
  v7 = BN_CTX_get((int)v6, v5);
  a = BN_CTX_get((int)v6, v5);
  v14 = BN_CTX_get((int)v6, v5);
  if ( !v14 || !field_sqr(group, v6->vals, &point->X, v5) )
    goto LABEL_28;
  if ( point->Z_is_one )
  {
    if ( !BN_mod_add_quick(v6->vals, v6->vals, &group->a, &group->field)
      || !field_mul(group, v6->vals, v6->vals, &point->X, v5) )
    {
      goto LABEL_28;
    }
    v9 = BN_mod_add_quick(v6->vals, v6->vals, &group->b, &group->field);
  }
  else
  {
    if ( !field_sqr(group, v7->vals, &point->Z, v5)
      || !field_sqr(group, a->vals, v7->vals, v5)
      || !field_mul(group, v14->vals, a->vals, v7->vals, v5) )
    {
      goto LABEL_28;
    }
    if ( group->a_is_minus3 )
    {
      if ( !BN_mod_lshift1_quick(v7->vals, a->vals, &group->field)
        || !BN_mod_add_quick(v7->vals, v7->vals, a->vals, &group->field) )
      {
        goto LABEL_28;
      }
      v8 = BN_mod_sub_quick(v6->vals, v6->vals, v7->vals, &group->field);
    }
    else
    {
      if ( !field_mul(group, v7->vals, a->vals, &group->a, v5) )
      {
LABEL_28:
        v10 = -1;
        goto err_206;
      }
      v8 = BN_mod_add_quick(v6->vals, v6->vals, v7->vals, &group->field);
    }
    if ( !v8
      || !field_mul(group, v6->vals, v6->vals, &point->X, v5)
      || !field_mul(group, v7->vals, &group->b, v14->vals, v5) )
    {
      goto LABEL_28;
    }
    v9 = BN_mod_add_quick(v6->vals, v6->vals, v7->vals, &group->field);
  }
  if ( !v9 || !field_sqr(group, v7->vals, &point->Y, v5) )
    goto LABEL_28;
  v10 = BN_ucmp(v7->vals, v6->vals) == 0;
err_206:
  BN_CTX_end(v5);
  if ( v15 )
    BN_CTX_free(v15);
  return v10;
}
