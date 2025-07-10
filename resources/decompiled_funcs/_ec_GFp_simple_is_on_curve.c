int __cdecl ec_GFp_simple_is_on_curve(const ec_group_st *group, const ec_point_st *point, bignum_ctx *ctx)
{
  bignum_ctx *v4; // esi
  bignum_pool_item *v5; // ebx
  bignum_pool_item *v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // [esp+4h] [ebp-18h]
  bignum_pool_item *a; // [esp+8h] [ebp-14h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+Ch] [ebp-10h]
  bignum_pool_item *v13; // [esp+10h] [ebp-Ch]
  bignum_ctx *v14; // [esp+14h] [ebp-8h]

  v14 = 0;
  if ( EC_POINT_is_at_infinity(group, point) )
    return 1;
  v4 = ctx;
  field_mul = group->meth->field_mul;
  field_sqr = group->meth->field_sqr;
  if ( !ctx )
  {
    v14 = BN_CTX_new();
    v4 = v14;
    if ( !v14 )
      return -1;
  }
  BN_CTX_start(v4);
  v5 = BN_CTX_get(v4);
  v6 = BN_CTX_get(v4);
  a = BN_CTX_get(v4);
  v13 = BN_CTX_get(v4);
  if ( !v13 || !field_sqr(group, v5->vals, &point->X, v4) )
    goto LABEL_28;
  if ( point->Z_is_one )
  {
    if ( !BN_mod_add_quick(v5->vals, v5->vals, &group->a, &group->field)
      || !field_mul(group, v5->vals, v5->vals, &point->X, v4) )
    {
      goto LABEL_28;
    }
    v8 = BN_mod_add_quick(v5->vals, v5->vals, &group->b, &group->field);
  }
  else
  {
    if ( !field_sqr(group, v6->vals, &point->Z, v4)
      || !field_sqr(group, a->vals, v6->vals, v4)
      || !field_mul(group, v13->vals, a->vals, v6->vals, v4) )
    {
      goto LABEL_28;
    }
    if ( group->a_is_minus3 )
    {
      if ( !BN_mod_lshift1_quick(v6->vals, a->vals, &group->field)
        || !BN_mod_add_quick(v6->vals, v6->vals, a->vals, &group->field) )
      {
        goto LABEL_28;
      }
      v7 = BN_mod_sub_quick(v5->vals, v5->vals, v6->vals, &group->field);
    }
    else
    {
      if ( !field_mul(group, v6->vals, a->vals, &group->a, v4) )
      {
LABEL_28:
        v9 = -1;
        goto err_204;
      }
      v7 = BN_mod_add_quick(v5->vals, v5->vals, v6->vals, &group->field);
    }
    if ( !v7
      || !field_mul(group, v5->vals, v5->vals, &point->X, v4)
      || !field_mul(group, v6->vals, &group->b, v13->vals, v4) )
    {
      goto LABEL_28;
    }
    v8 = BN_mod_add_quick(v5->vals, v5->vals, v6->vals, &group->field);
  }
  if ( !v8 || !field_sqr(group, v6->vals, &point->Y, v4) )
    goto LABEL_28;
  v9 = BN_ucmp(v6->vals, v5->vals) == 0;
err_204:
  BN_CTX_end(v4);
  if ( v14 )
    BN_CTX_free(v14);
  return v9;
}
