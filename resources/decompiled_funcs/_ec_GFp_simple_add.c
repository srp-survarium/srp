int __cdecl ec_GFp_simple_add(
        const ec_group_st *group,
        ec_point_st *r,
        const ec_point_st *a,
        const ec_point_st *b,
        bignum_ctx *ctx)
{
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // ebp
  bignum_ctx *v7; // esi
  bignum_pool_item *v8; // edi
  bignum_st *v9; // eax
  bignum_st *v10; // eax
  bignum_st *v11; // eax
  bignum_st *v12; // eax
  bignum_st *p_Z; // ecx
  const bignum_st *m; // [esp+Ch] [ebp-28h]
  bignum_pool_item *ba; // [esp+10h] [ebp-24h]
  bignum_pool_item *v16; // [esp+14h] [ebp-20h]
  bignum_pool_item *v17; // [esp+18h] [ebp-1Ch]
  bignum_pool_item *v18; // [esp+1Ch] [ebp-18h]
  bignum_pool_item *v19; // [esp+20h] [ebp-14h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+24h] [ebp-10h]
  bignum_pool_item *v21; // [esp+28h] [ebp-Ch]
  int v22; // [esp+2Ch] [ebp-8h]
  bignum_ctx *v23; // [esp+30h] [ebp-4h]

  v23 = 0;
  v22 = 0;
  if ( a == b )
    return EC_POINT_dbl(group, r, a, ctx);
  if ( EC_POINT_is_at_infinity(group, a) )
    return EC_POINT_copy(r, b);
  if ( EC_POINT_is_at_infinity(group, b) )
    return EC_POINT_copy(r, a);
  field_mul = group->meth->field_mul;
  v7 = ctx;
  field_sqr = group->meth->field_sqr;
  m = &group->field;
  if ( !ctx )
  {
    v23 = BN_CTX_new();
    v7 = v23;
    if ( !v23 )
      return 0;
  }
  BN_CTX_start(v7);
  v8 = BN_CTX_get(v7);
  v18 = BN_CTX_get(v7);
  v19 = BN_CTX_get(v7);
  ba = BN_CTX_get(v7);
  v16 = BN_CTX_get(v7);
  v17 = BN_CTX_get(v7);
  v21 = BN_CTX_get(v7);
  if ( !v21 )
    goto end_9;
  if ( b->Z_is_one )
  {
    if ( !BN_copy(v18->vals, &a->X) )
      goto end_9;
    v9 = BN_copy(v19->vals, &a->Y);
  }
  else
  {
    if ( !field_sqr(group, v8->vals, &b->Z, v7)
      || !field_mul(group, v18->vals, &a->X, v8->vals, v7)
      || !field_mul(group, v8->vals, v8->vals, &b->Z, v7) )
    {
      goto end_9;
    }
    v9 = (bignum_st *)field_mul(group, v19->vals, &a->Y, v8->vals, v7);
  }
  if ( !v9 )
    goto end_9;
  if ( a->Z_is_one )
  {
    if ( !BN_copy(ba->vals, &b->X) )
      goto end_9;
    v10 = BN_copy(v16->vals, &b->Y);
  }
  else
  {
    if ( !field_sqr(group, v8->vals, &a->Z, v7)
      || !field_mul(group, ba->vals, &b->X, v8->vals, v7)
      || !field_mul(group, v8->vals, v8->vals, &a->Z, v7) )
    {
      goto end_9;
    }
    v10 = (bignum_st *)field_mul(group, v16->vals, &b->Y, v8->vals, v7);
  }
  if ( !v10
    || !BN_mod_sub_quick(v17->vals, v18->vals, ba->vals, m)
    || !BN_mod_sub_quick(v21->vals, v19->vals, v16->vals, m) )
  {
    goto end_9;
  }
  if ( v17->vals[0].top )
  {
    if ( !BN_mod_add_quick(v18->vals, v18->vals, ba->vals, m) || !BN_mod_add_quick(v19->vals, v19->vals, v16->vals, m) )
      goto end_9;
    if ( a->Z_is_one )
    {
      if ( b->Z_is_one )
      {
        v11 = BN_copy(&r->Z, v17->vals);
        goto LABEL_44;
      }
      v12 = BN_copy(v8->vals, &b->Z);
    }
    else
    {
      p_Z = &a->Z;
      if ( b->Z_is_one )
        v12 = BN_copy(v8->vals, p_Z);
      else
        v12 = (bignum_st *)field_mul(group, v8->vals, p_Z, &b->Z, v7);
    }
    if ( !v12 )
      goto end_9;
    v11 = (bignum_st *)field_mul(group, &r->Z, v8->vals, v17->vals, v7);
LABEL_44:
    if ( v11 )
    {
      r->Z_is_one = 0;
      if ( field_sqr(group, v8->vals, v21->vals, v7) )
      {
        if ( field_sqr(group, v16->vals, v17->vals, v7)
          && field_mul(group, ba->vals, v18->vals, v16->vals, v7)
          && BN_mod_sub_quick(&r->X, v8->vals, ba->vals, m)
          && BN_mod_lshift1_quick(v8->vals, &r->X, m)
          && BN_mod_sub_quick(v8->vals, ba->vals, v8->vals, m)
          && field_mul(group, v8->vals, v8->vals, v21->vals, v7)
          && field_mul(group, v17->vals, v16->vals, v17->vals, v7)
          && field_mul(group, v18->vals, v19->vals, v17->vals, v7)
          && BN_mod_sub_quick(v8->vals, v8->vals, v18->vals, m)
          && (v8->vals[0].top <= 0 || (*(_BYTE *)v8->vals[0].d & 1) == 0 || BN_add(v8->vals, v8->vals, m)) )
        {
          if ( BN_rshift1(&r->Y, v8->vals) )
            goto LABEL_59;
        }
      }
    }
end_9:
    if ( v7 )
      BN_CTX_end(v7);
    goto LABEL_62;
  }
  if ( v21->vals[0].top )
  {
    BN_set_word(&r->Z, 0);
    r->Z_is_one = 0;
LABEL_59:
    v22 = 1;
    goto end_9;
  }
  BN_CTX_end(v7);
  v22 = EC_POINT_dbl(group, r, a, v7);
LABEL_62:
  if ( v23 )
    BN_CTX_free(v23);
  return v22;
}
