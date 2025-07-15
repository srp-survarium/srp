int __usercall ec_GFp_simple_add@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *r,
        const ec_point_st *a,
        const ec_point_st *b,
        bignum_ctx *ctx)
{
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // ebp
  bignum_ctx *v8; // esi
  bignum_pool_item *v9; // edi
  bignum_st *v10; // eax
  bignum_st *v11; // eax
  bignum_st *v12; // eax
  bignum_st *v13; // eax
  bignum_st *p_Z; // ecx
  const bignum_st *m; // [esp+Ch] [ebp-28h]
  bignum_pool_item *ba; // [esp+10h] [ebp-24h]
  bignum_pool_item *v17; // [esp+14h] [ebp-20h]
  bignum_pool_item *v18; // [esp+18h] [ebp-1Ch]
  bignum_pool_item *v19; // [esp+1Ch] [ebp-18h]
  bignum_pool_item *v20; // [esp+20h] [ebp-14h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+24h] [ebp-10h]
  bignum_pool_item *v22; // [esp+28h] [ebp-Ch]
  int v23; // [esp+2Ch] [ebp-8h]
  bignum_ctx *v24; // [esp+30h] [ebp-4h]

  v24 = 0;
  v23 = 0;
  if ( a == b )
    return EC_POINT_dbl(a1, group, r, a, ctx);
  if ( EC_POINT_is_at_infinity((int)group, group, a) )
    return EC_POINT_copy((int)group, r, b);
  if ( EC_POINT_is_at_infinity((int)group, group, b) )
    return EC_POINT_copy((int)group, r, a);
  field_mul = group->meth->field_mul;
  v8 = ctx;
  field_sqr = group->meth->field_sqr;
  m = &group->field;
  if ( !ctx )
  {
    v24 = BN_CTX_new((int)group);
    v8 = v24;
    if ( !v24 )
      return 0;
  }
  BN_CTX_start((int)group, v8);
  v9 = BN_CTX_get((int)group, v8);
  v19 = BN_CTX_get((int)group, v8);
  v20 = BN_CTX_get((int)group, v8);
  ba = BN_CTX_get((int)group, v8);
  v17 = BN_CTX_get((int)group, v8);
  v18 = BN_CTX_get((int)group, v8);
  v22 = BN_CTX_get((int)group, v8);
  if ( !v22 )
    goto end_9;
  if ( b->Z_is_one )
  {
    if ( !BN_copy(v19->vals, &a->X) )
      goto end_9;
    v10 = BN_copy(v20->vals, &a->Y);
  }
  else
  {
    if ( !field_sqr(group, v9->vals, &b->Z, v8)
      || !field_mul(group, v19->vals, &a->X, v9->vals, v8)
      || !field_mul(group, v9->vals, v9->vals, &b->Z, v8) )
    {
      goto end_9;
    }
    v10 = (bignum_st *)field_mul(group, v20->vals, &a->Y, v9->vals, v8);
  }
  if ( !v10 )
    goto end_9;
  if ( a->Z_is_one )
  {
    if ( !BN_copy(ba->vals, &b->X) )
      goto end_9;
    v11 = BN_copy(v17->vals, &b->Y);
  }
  else
  {
    if ( !field_sqr(group, v9->vals, &a->Z, v8)
      || !field_mul(group, ba->vals, &b->X, v9->vals, v8)
      || !field_mul(group, v9->vals, v9->vals, &a->Z, v8) )
    {
      goto end_9;
    }
    v11 = (bignum_st *)field_mul(group, v17->vals, &b->Y, v9->vals, v8);
  }
  if ( !v11
    || !BN_mod_sub_quick(v18->vals, v19->vals, ba->vals, m)
    || !BN_mod_sub_quick(v22->vals, v20->vals, v17->vals, m) )
  {
    goto end_9;
  }
  if ( v18->vals[0].top )
  {
    if ( !BN_mod_add_quick(v19->vals, v19->vals, ba->vals, m) || !BN_mod_add_quick(v20->vals, v20->vals, v17->vals, m) )
      goto end_9;
    if ( a->Z_is_one )
    {
      if ( b->Z_is_one )
      {
        v12 = BN_copy(&r->Z, v18->vals);
        goto LABEL_44;
      }
      v13 = BN_copy(v9->vals, &b->Z);
    }
    else
    {
      p_Z = &a->Z;
      if ( b->Z_is_one )
        v13 = BN_copy(v9->vals, p_Z);
      else
        v13 = (bignum_st *)field_mul(group, v9->vals, p_Z, &b->Z, v8);
    }
    if ( !v13 )
      goto end_9;
    v12 = (bignum_st *)field_mul(group, &r->Z, v9->vals, v18->vals, v8);
LABEL_44:
    if ( v12 )
    {
      r->Z_is_one = 0;
      if ( field_sqr(group, v9->vals, v22->vals, v8) )
      {
        if ( field_sqr(group, v17->vals, v18->vals, v8)
          && field_mul(group, ba->vals, v19->vals, v17->vals, v8)
          && BN_mod_sub_quick(&r->X, v9->vals, ba->vals, m)
          && BN_mod_lshift1_quick(v9->vals, &r->X, m)
          && BN_mod_sub_quick(v9->vals, ba->vals, v9->vals, m)
          && field_mul(group, v9->vals, v9->vals, v22->vals, v8)
          && field_mul(group, v18->vals, v17->vals, v18->vals, v8)
          && field_mul(group, v19->vals, v20->vals, v18->vals, v8)
          && BN_mod_sub_quick(v9->vals, v9->vals, v19->vals, m)
          && (v9->vals[0].top <= 0 || (*(_BYTE *)v9->vals[0].d & 1) == 0 || BN_add(v9->vals, v9->vals, m)) )
        {
          if ( BN_rshift1(&r->Y, v9->vals) )
            goto LABEL_59;
        }
      }
    }
end_9:
    if ( v8 )
      BN_CTX_end(v8);
    goto LABEL_62;
  }
  if ( v22->vals[0].top )
  {
    BN_set_word((int)group, &r->Z, 0);
    r->Z_is_one = 0;
LABEL_59:
    v23 = 1;
    goto end_9;
  }
  BN_CTX_end(v8);
  v23 = EC_POINT_dbl((int)group, group, r, a, v8);
LABEL_62:
  if ( v24 )
    BN_CTX_free(v24);
  return v23;
}
