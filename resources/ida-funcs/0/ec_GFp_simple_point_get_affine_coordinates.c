int __cdecl ec_GFp_simple_point_get_affine_coordinates(
        const ec_group_st *group,
        const ec_point_st *point,
        bignum_st *x,
        bignum_st *y,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // esi
  bignum_pool_item *v7; // ebx
  bignum_pool_item *v8; // ebp
  int (__cdecl *field_decode)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  const ec_point_st *v10; // edx
  bignum_st *p_Z; // eax
  int (__cdecl *v12)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  bignum_st *v13; // eax
  int v14; // eax
  int v15; // eax
  bignum_pool_item *r; // [esp+8h] [ebp-10h]
  bignum_pool_item *v17; // [esp+Ch] [ebp-Ch]
  bignum_ctx *v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v18 = 0;
  v19 = 0;
  if ( EC_POINT_is_at_infinity(group, point) )
  {
    ERR_put_error(0x10u, 167, 106, ".\\crypto\\ec\\ecp_smpl.c", 531);
    return 0;
  }
  v6 = ctx;
  if ( !ctx )
  {
    v18 = BN_CTX_new();
    v6 = v18;
    if ( !v18 )
      return 0;
  }
  BN_CTX_start(v6);
  v17 = BN_CTX_get(v6);
  v7 = BN_CTX_get(v6);
  v8 = BN_CTX_get(v6);
  r = BN_CTX_get(v6);
  if ( !r )
    goto err_200;
  field_decode = group->meth->field_decode;
  v10 = point;
  if ( field_decode )
  {
    if ( !field_decode(group, v17->vals, &point->Z, v6) )
      goto err_200;
    p_Z = (bignum_st *)v17;
    v10 = point;
  }
  else
  {
    p_Z = &point->Z;
  }
  if ( p_Z->top != 1 || *p_Z->d != 1 || p_Z->neg )
  {
    if ( !BN_mod_inverse(v7->vals, p_Z, &group->field, v6) )
    {
      ERR_put_error(0x10u, 167, 3, ".\\crypto\\ec\\ecp_smpl.c", 590);
      goto err_200;
    }
    if ( group->meth->field_encode )
      v14 = BN_mod_sqr(v8->vals, v7->vals, &group->field, v6);
    else
      v14 = group->meth->field_sqr(group, (bignum_st *)v8, (const bignum_st *)v7, v6);
    if ( !v14 || x && !group->meth->field_mul(group, x, &point->X, (const bignum_st *)v8, v6) )
      goto err_200;
    if ( !y )
      goto LABEL_40;
    if ( group->meth->field_encode )
      v15 = BN_mod_mul(r->vals, v8, v7, &group->field, v6);
    else
      v15 = group->meth->field_mul(group, (bignum_st *)r, (const bignum_st *)v8, (const bignum_st *)v7, v6);
    if ( !v15 )
      goto err_200;
    v13 = (bignum_st *)group->meth->field_mul(group, y, &point->Y, (const bignum_st *)r, v6);
    goto LABEL_39;
  }
  v12 = group->meth->field_decode;
  if ( v12 )
  {
    if ( x )
    {
      if ( !v12(group, x, &v10->X, v6) )
        goto err_200;
      v10 = point;
    }
    if ( y )
    {
      v13 = (bignum_st *)group->meth->field_decode(group, y, &v10->Y, v6);
      goto LABEL_39;
    }
LABEL_40:
    v19 = 1;
    goto err_200;
  }
  if ( x )
  {
    if ( !BN_copy(x, &v10->X) )
      goto err_200;
    v10 = point;
  }
  if ( !y )
    goto LABEL_40;
  v13 = BN_copy(y, &v10->Y);
LABEL_39:
  if ( v13 )
    goto LABEL_40;
err_200:
  BN_CTX_end(v6);
  if ( v18 )
    BN_CTX_free(v18);
  return v19;
}
