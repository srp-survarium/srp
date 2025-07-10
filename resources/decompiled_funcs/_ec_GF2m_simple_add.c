BOOL __cdecl ec_GF2m_simple_add(
        const ec_group_st *group,
        ec_point_st *r,
        const ec_point_st *a,
        const ec_point_st *b,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // esi
  bignum_pool_item *v7; // ebp
  bignum_pool_item *v8; // ebx
  bignum_st *affine_coordinates_GF2m; // eax
  bignum_st *v10; // eax
  bignum_st *p_a; // ecx
  int v12; // eax
  bignum_pool_item *x; // [esp+Ch] [ebp-20h]
  bignum_pool_item *ba; // [esp+10h] [ebp-1Ch]
  bignum_pool_item *aa; // [esp+14h] [ebp-18h]
  bignum_pool_item *y; // [esp+18h] [ebp-14h]
  bignum_pool_item *ra; // [esp+1Ch] [ebp-10h]
  int v18; // [esp+20h] [ebp-Ch]
  bignum_pool_item *v19; // [esp+24h] [ebp-8h]
  bignum_ctx *v20; // [esp+28h] [ebp-4h]

  v20 = 0;
  v18 = 0;
  if ( EC_POINT_is_at_infinity(group, a) )
    return EC_POINT_copy(r, b) != 0;
  if ( EC_POINT_is_at_infinity(group, b) )
    return EC_POINT_copy(r, a) != 0;
  v6 = ctx;
  if ( !ctx )
  {
    v20 = BN_CTX_new();
    v6 = v20;
    if ( !v20 )
      return 0;
  }
  BN_CTX_start(v6);
  aa = BN_CTX_get(v6);
  y = BN_CTX_get(v6);
  x = BN_CTX_get(v6);
  ba = BN_CTX_get(v6);
  v7 = BN_CTX_get(v6);
  v19 = BN_CTX_get(v6);
  v8 = BN_CTX_get(v6);
  ra = BN_CTX_get(v6);
  if ( !ra )
    goto err_131;
  if ( a->Z_is_one )
  {
    if ( !BN_copy(aa->vals, &a->X) )
      goto err_131;
    affine_coordinates_GF2m = BN_copy(y->vals, &a->Y);
  }
  else
  {
    affine_coordinates_GF2m = (bignum_st *)EC_POINT_get_affine_coordinates_GF2m(group, a, aa->vals, y->vals, v6);
  }
  if ( !affine_coordinates_GF2m )
    goto err_131;
  if ( b->Z_is_one )
  {
    if ( !BN_copy(x->vals, &b->X) )
      goto err_131;
    v10 = BN_copy(ba->vals, &b->Y);
  }
  else
  {
    v10 = (bignum_st *)EC_POINT_get_affine_coordinates_GF2m(group, b, x->vals, ba->vals, v6);
  }
  if ( !v10 )
    goto err_131;
  if ( BN_ucmp(aa->vals, x->vals) )
  {
    if ( !BN_GF2m_add(ra->vals, aa->vals, x->vals)
      || !BN_GF2m_add(v8->vals, y->vals, ba->vals)
      || !group->meth->field_div(group, (bignum_st *)v8, (const bignum_st *)v8, (const bignum_st *)ra, v6)
      || !group->meth->field_sqr(group, (bignum_st *)v7, (const bignum_st *)v8, v6)
      || !BN_GF2m_add(v7->vals, v7->vals, &group->a)
      || !BN_GF2m_add(v7->vals, v7->vals, v8->vals) )
    {
      goto err_131;
    }
    p_a = (bignum_st *)ra;
    goto LABEL_34;
  }
  if ( BN_ucmp(y->vals, ba->vals) || !x->vals[0].top )
  {
    v12 = EC_POINT_set_to_infinity(group, r);
LABEL_41:
    if ( v12 )
      v18 = 1;
    goto err_131;
  }
  if ( group->meth->field_div(group, (bignum_st *)v8, (const bignum_st *)ba, (const bignum_st *)x, v6)
    && BN_GF2m_add(v8->vals, v8->vals, x->vals)
    && group->meth->field_sqr(group, (bignum_st *)v7, (const bignum_st *)v8, v6)
    && BN_GF2m_add(v7->vals, v7->vals, v8->vals) )
  {
    p_a = &group->a;
LABEL_34:
    if ( BN_GF2m_add(v7->vals, v7->vals, p_a)
      && BN_GF2m_add(v19->vals, x->vals, v7->vals)
      && group->meth->field_mul(group, (bignum_st *)v19, (const bignum_st *)v19, (const bignum_st *)v8, v6)
      && BN_GF2m_add(v19->vals, v19->vals, v7->vals)
      && BN_GF2m_add(v19->vals, v19->vals, ba->vals) )
    {
      v12 = EC_POINT_set_affine_coordinates_GF2m(group, r, v7->vals, v19->vals, v6);
      goto LABEL_41;
    }
  }
err_131:
  BN_CTX_end(v6);
  if ( v20 )
    BN_CTX_free(v20);
  return v18;
}
