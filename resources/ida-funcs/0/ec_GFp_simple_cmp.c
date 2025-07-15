int __usercall ec_GFp_simple_cmp@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        const ec_point_st *a,
        const ec_point_st *b,
        bignum_ctx *ctx)
{
  int result; // eax
  bignum_ctx *v6; // esi
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // ebp
  bignum_pool_item *v8; // eax
  bignum_pool_item *v9; // ebx
  const ec_point_st *v10; // ecx
  const ec_point_st *v11; // eax
  const bignum_st *p_X; // ecx
  const ec_point_st *v13; // eax
  const ec_point_st *v14; // ebx
  const bignum_st *p_Y; // eax
  const bignum_st *v16; // [esp-10h] [ebp-34h]
  const bignum_st *aa; // [esp+8h] [ebp-1Ch]
  bignum_pool_item *v18; // [esp+Ch] [ebp-18h]
  bignum_pool_item *v19; // [esp+10h] [ebp-14h]
  bignum_pool_item *ba; // [esp+14h] [ebp-10h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+18h] [ebp-Ch]
  bignum_st *v22; // [esp+18h] [ebp-Ch]
  int v23; // [esp+1Ch] [ebp-8h]
  bignum_ctx *v24; // [esp+20h] [ebp-4h]

  v24 = 0;
  v23 = -1;
  if ( EC_POINT_is_at_infinity(a1, group, a) )
    return EC_POINT_is_at_infinity(a1, group, b) == 0;
  if ( EC_POINT_is_at_infinity((int)b, group, b) )
    return 1;
  if ( !a->Z_is_one || !b->Z_is_one )
  {
    v6 = ctx;
    field_mul = group->meth->field_mul;
    field_sqr = group->meth->field_sqr;
    if ( !ctx )
    {
      v24 = BN_CTX_new((int)b);
      v6 = v24;
      if ( !v24 )
        return -1;
    }
    BN_CTX_start((int)b, v6);
    v18 = BN_CTX_get((int)b, v6);
    ba = BN_CTX_get((int)b, v6);
    v19 = BN_CTX_get((int)b, v6);
    v8 = BN_CTX_get((int)b, v6);
    v9 = v8;
    if ( !v8 )
      goto end_10;
    v10 = b;
    if ( b->Z_is_one )
    {
      v11 = a;
      aa = &a->X;
    }
    else
    {
      if ( !field_sqr(group, v8->vals, &b->Z, v6) || !field_mul(group, v18->vals, &a->X, v9->vals, v6) )
        goto end_10;
      v10 = b;
      aa = (const bignum_st *)v18;
      v11 = a;
    }
    if ( v11->Z_is_one )
    {
      p_X = &v10->X;
    }
    else
    {
      if ( !field_sqr(group, v19->vals, &v11->Z, v6) || !field_mul(group, ba->vals, &b->X, v19->vals, v6) )
        goto end_10;
      p_X = (const bignum_st *)ba;
    }
    v22 = (bignum_st *)p_X;
    if ( BN_cmp(aa, p_X) )
    {
      v23 = 1;
    }
    else
    {
      v13 = b;
      if ( b->Z_is_one )
      {
        v14 = a;
        aa = &a->Y;
      }
      else
      {
        if ( !field_mul(group, v9->vals, v9->vals, &b->Z, v6) )
          goto end_10;
        v16 = (const bignum_st *)v9;
        v14 = a;
        if ( !field_mul(group, v18->vals, &a->Y, v16, v6) )
          goto end_10;
        v13 = b;
      }
      if ( v14->Z_is_one )
      {
        p_Y = &v13->Y;
      }
      else
      {
        if ( !field_mul(group, v19->vals, v19->vals, &v14->Z, v6) || !field_mul(group, ba->vals, &b->Y, v19->vals, v6) )
          goto end_10;
        p_Y = v22;
      }
      v23 = BN_cmp(aa, p_Y) != 0;
    }
end_10:
    BN_CTX_end(v6);
    if ( v24 )
      BN_CTX_free(v24);
    return v23;
  }
  if ( BN_cmp(&a->X, &b->X) )
    return 1;
  result = BN_cmp(&a->Y, &b->Y);
  if ( result )
    return 1;
  return result;
}
