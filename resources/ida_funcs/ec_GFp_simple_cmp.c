int __cdecl ec_GFp_simple_cmp(const ec_group_st *group, const ec_point_st *a, const ec_point_st *b, bignum_ctx *ctx)
{
  int result; // eax
  bignum_ctx *v5; // esi
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // ebp
  bignum_pool_item *v7; // eax
  bignum_pool_item *v8; // ebx
  const ec_point_st *v9; // ecx
  const ec_point_st *v10; // eax
  const bignum_st *p_X; // ecx
  const ec_point_st *v12; // eax
  const ec_point_st *v13; // ebx
  const bignum_st *p_Y; // eax
  const bignum_st *v15; // [esp-10h] [ebp-34h]
  const bignum_st *aa; // [esp+8h] [ebp-1Ch]
  bignum_pool_item *v17; // [esp+Ch] [ebp-18h]
  bignum_pool_item *v18; // [esp+10h] [ebp-14h]
  bignum_pool_item *ba; // [esp+14h] [ebp-10h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+18h] [ebp-Ch]
  bignum_st *v21; // [esp+18h] [ebp-Ch]
  int v22; // [esp+1Ch] [ebp-8h]
  bignum_ctx *v23; // [esp+20h] [ebp-4h]

  v23 = 0;
  v22 = -1;
  if ( EC_POINT_is_at_infinity(group, a) )
    return EC_POINT_is_at_infinity(group, b) == 0;
  if ( EC_POINT_is_at_infinity(group, b) )
    return 1;
  if ( !a->Z_is_one || !b->Z_is_one )
  {
    v5 = ctx;
    field_mul = group->meth->field_mul;
    field_sqr = group->meth->field_sqr;
    if ( !ctx )
    {
      v23 = BN_CTX_new();
      v5 = v23;
      if ( !v23 )
        return -1;
    }
    BN_CTX_start(v5);
    v17 = BN_CTX_get(v5);
    ba = BN_CTX_get(v5);
    v18 = BN_CTX_get(v5);
    v7 = BN_CTX_get(v5);
    v8 = v7;
    if ( !v7 )
      goto end_10;
    v9 = b;
    if ( b->Z_is_one )
    {
      v10 = a;
      aa = &a->X;
    }
    else
    {
      if ( !field_sqr(group, v7->vals, &b->Z, v5) || !field_mul(group, v17->vals, &a->X, v8->vals, v5) )
        goto end_10;
      v9 = b;
      aa = (const bignum_st *)v17;
      v10 = a;
    }
    if ( v10->Z_is_one )
    {
      p_X = &v9->X;
    }
    else
    {
      if ( !field_sqr(group, v18->vals, &v10->Z, v5) || !field_mul(group, ba->vals, &b->X, v18->vals, v5) )
        goto end_10;
      p_X = (const bignum_st *)ba;
    }
    v21 = (bignum_st *)p_X;
    if ( BN_cmp(aa, p_X) )
    {
      v22 = 1;
    }
    else
    {
      v12 = b;
      if ( b->Z_is_one )
      {
        v13 = a;
        aa = &a->Y;
      }
      else
      {
        if ( !field_mul(group, v8->vals, v8->vals, &b->Z, v5) )
          goto end_10;
        v15 = (const bignum_st *)v8;
        v13 = a;
        if ( !field_mul(group, v17->vals, &a->Y, v15, v5) )
          goto end_10;
        v12 = b;
      }
      if ( v13->Z_is_one )
      {
        p_Y = &v12->Y;
      }
      else
      {
        if ( !field_mul(group, v18->vals, v18->vals, &v13->Z, v5) || !field_mul(group, ba->vals, &b->Y, v18->vals, v5) )
          goto end_10;
        p_Y = v21;
      }
      v22 = BN_cmp(aa, p_Y) != 0;
    }
end_10:
    BN_CTX_end(v5);
    if ( v23 )
      BN_CTX_free(v23);
    return v22;
  }
  if ( BN_cmp(&a->X, &b->X) )
    return 1;
  result = BN_cmp(&a->Y, &b->Y);
  if ( result )
    return 1;
  return result;
}
