int __cdecl ec_GFp_simple_points_make_affine(
        const ec_group_st *group,
        unsigned int num,
        ec_point_st **points,
        bignum_ctx *ctx)
{
  bignum_pool_item *v5; // eax
  unsigned int i; // eax
  bignum_st **v7; // eax
  bignum_st **v8; // ebx
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  bignum_st **v12; // ecx
  int v13; // edi
  bignum_st *v14; // eax
  const bignum_st *v15; // edx
  const bignum_st *v16; // ecx
  bignum_st *v17; // eax
  bignum_st *v18; // eax
  int (__cdecl *field_encode)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  unsigned int v20; // ebp
  bignum_st **v21; // ebx
  bignum_st *v22; // eax
  const bignum_st **v23; // edi
  bignum_st *v24; // eax
  unsigned int v25; // eax
  ec_point_st *v26; // edi
  int (__cdecl *field_set_to_one)(const ec_group_st *, bignum_st *, bignum_ctx *); // eax
  int v29; // esi
  bignum_st **str; // [esp+8h] [ebp-20h]
  unsigned int v31; // [esp+Ch] [ebp-1Ch]
  bignum_pool_item *b; // [esp+10h] [ebp-18h]
  unsigned int v33; // [esp+14h] [ebp-14h]
  unsigned int v34; // [esp+14h] [ebp-14h]
  bignum_st *v35; // [esp+18h] [ebp-10h]
  bignum_ctx *v36; // [esp+1Ch] [ebp-Ch]
  int v37; // [esp+20h] [ebp-8h]

  v36 = 0;
  v31 = 0;
  str = 0;
  v37 = 0;
  if ( !num )
    return 1;
  if ( !ctx )
  {
    v36 = BN_CTX_new();
    ctx = v36;
    if ( !v36 )
      return 0;
  }
  BN_CTX_start(ctx);
  b = BN_CTX_get(ctx);
  v5 = BN_CTX_get(ctx);
  v35 = (bignum_st *)v5;
  if ( b && v5 )
  {
    for ( i = 1; num > i; i *= 2 )
      ;
    v31 = 2 * i;
    v7 = (bignum_st **)CRYPTO_malloc(8 * i, ".\\crypto\\ec\\ecp_smpl.c", 1576);
    str = v7;
    if ( v7 )
    {
      v8 = v7;
      *v7 = 0;
      v9 = v31 >> 1;
      v10 = (v31 >> 1) - 1;
      if ( v31 >> 1 != 1 )
      {
        do
          v8[v10--] = 0;
        while ( v10 );
      }
      v11 = 0;
      v12 = &v8[v9];
      do
        *v12++ = &points[v11++]->Z;
      while ( v11 < num );
      v33 = v9 + num;
      if ( v9 + num < v31 )
        memset(&v8[v9] + num, 0, 4 * (v31 - (v9 + num)));
      v13 = (v31 >> 1) - 1;
      if ( v31 >> 1 != 1 )
      {
        do
        {
          v14 = BN_new();
          v8[v13] = v14;
          if ( !v14 )
            goto err_206;
          v15 = str[2 * v13];
          if ( v15 )
          {
            v16 = str[2 * v13 + 1];
            if ( v16 && v16->top )
              v17 = v15->top ? (bignum_st *)group->meth->field_mul(group, v14, v15, v16, ctx) : BN_copy(v14, v16);
            else
              v17 = BN_copy(v14, str[2 * v13]);
            if ( !v17 )
              goto err_206;
          }
          --v13;
          v8 = str;
        }
        while ( v13 );
      }
      v18 = v8[1];
      if ( !v18->top || BN_mod_inverse(v18, v18, &group->field, ctx) )
      {
        field_encode = group->meth->field_encode;
        if ( field_encode )
        {
          if ( !field_encode(group, v8[1], v8[1], ctx) || !group->meth->field_encode(group, str[1], str[1], ctx) )
            goto err_206;
          v8 = str;
        }
        v20 = 2;
        if ( v33 > 2 )
        {
          v21 = v8 + 3;
          do
          {
            v22 = *v21;
            if ( *v21 && v22->top )
            {
              v23 = (const bignum_st **)&str[v20 >> 1];
              if ( !group->meth->field_mul(group, (bignum_st *)b, *v23, v22, ctx)
                || !group->meth->field_mul(group, v35, *v23, *(v21 - 1), ctx)
                || !BN_copy(*(v21 - 1), b->vals) )
              {
                goto err_206;
              }
              v24 = BN_copy(*v21, v35);
            }
            else
            {
              v24 = BN_copy(*(v21 - 1), str[v20 >> 1]);
            }
            if ( !v24 )
              goto err_206;
            v20 += 2;
            v21 += 2;
          }
          while ( v20 < v33 );
        }
        v25 = 0;
        v34 = 0;
        do
        {
          v26 = points[v25];
          if ( v26->Z.top )
          {
            if ( !group->meth->field_sqr(group, v35, &v26->Z, ctx)
              || !group->meth->field_mul(group, &v26->X, &v26->X, v35, ctx)
              || !group->meth->field_mul(group, v35, v35, &v26->Z, ctx)
              || !group->meth->field_mul(group, &v26->Y, &v26->Y, v35, ctx) )
            {
              goto err_206;
            }
            field_set_to_one = group->meth->field_set_to_one;
            if ( !(field_set_to_one ? field_set_to_one(group, &v26->Z, ctx) : BN_set_word(&v26->Z, 1u)) )
              goto err_206;
            v25 = v34;
            v26->Z_is_one = 1;
          }
          v34 = ++v25;
        }
        while ( v25 < num );
        v37 = 1;
        goto err_206;
      }
      ERR_put_error(0x10u, 137, 3, ".\\crypto\\ec\\ecp_smpl.c", 1633);
    }
  }
err_206:
  BN_CTX_end(ctx);
  if ( v36 )
    BN_CTX_free(v36);
  if ( str )
  {
    v29 = (v31 >> 1) - 1;
    if ( v31 >> 1 != 1 )
    {
      do
      {
        if ( str[v29] )
          BN_clear_free(str[v29]);
        --v29;
      }
      while ( v29 );
    }
    CRYPTO_free(str);
  }
  return v37;
}
