int __usercall ec_GFp_simple_points_make_affine@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        unsigned int num,
        ec_point_st **points,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // ebx
  bignum_pool_item *v7; // eax
  unsigned int i; // eax
  bignum_st **v9; // eax
  int v10; // ebx
  unsigned int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  bignum_st **v14; // ecx
  int v15; // edi
  bignum_st *v16; // eax
  const bignum_st *v17; // edx
  const bignum_st *v18; // ecx
  bignum_st *v19; // eax
  bignum_st *v20; // eax
  int (__cdecl *field_encode)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  unsigned int v22; // ebp
  bignum_st **v23; // ebx
  bignum_st *v24; // eax
  const bignum_st **v25; // edi
  bignum_st *v26; // eax
  unsigned int v27; // eax
  ec_point_st *v28; // edi
  int (__cdecl *field_set_to_one)(const ec_group_st *, bignum_st *, bignum_ctx *); // eax
  int v31; // esi
  bignum_st **str; // [esp+8h] [ebp-20h]
  unsigned int v33; // [esp+Ch] [ebp-1Ch]
  bignum_pool_item *b; // [esp+10h] [ebp-18h]
  unsigned int v35; // [esp+14h] [ebp-14h]
  unsigned int v36; // [esp+14h] [ebp-14h]
  bignum_st *v37; // [esp+18h] [ebp-10h]
  bignum_ctx *v38; // [esp+1Ch] [ebp-Ch]
  int v39; // [esp+20h] [ebp-8h]

  v38 = 0;
  v33 = 0;
  str = 0;
  v39 = 0;
  if ( !num )
    return 1;
  if ( !ctx )
  {
    v38 = BN_CTX_new(a1);
    ctx = v38;
    if ( !v38 )
      return 0;
  }
  v6 = ctx;
  BN_CTX_start((int)ctx, ctx);
  b = BN_CTX_get((int)v6, v6);
  v7 = BN_CTX_get((int)v6, v6);
  v37 = (bignum_st *)v7;
  if ( b && v7 )
  {
    for ( i = 1; num > i; i *= 2 )
      ;
    v33 = 2 * i;
    v9 = (bignum_st **)CRYPTO_malloc(8 * i, ".\\crypto\\ec\\ecp_smpl.c", 1576);
    str = v9;
    if ( v9 )
    {
      v10 = (int)v9;
      *v9 = 0;
      v11 = v33 >> 1;
      v12 = (v33 >> 1) - 1;
      if ( v33 >> 1 != 1 )
      {
        do
        {
          --v12;
          *(_DWORD *)(v10 + 4 * v12 + 4) = 0;
        }
        while ( v12 );
      }
      v13 = 0;
      v14 = (bignum_st **)(v10 + 4 * v11);
      do
        *v14++ = &points[v13++]->Z;
      while ( v13 < num );
      v35 = v11 + num;
      if ( v11 + num < v33 )
        memset((void *)(v10 + 4 * (v11 + num)), 0, 4 * (v33 - (v11 + num)));
      v15 = (v33 >> 1) - 1;
      if ( v33 >> 1 != 1 )
      {
        do
        {
          v16 = BN_new(v10);
          *(_DWORD *)(v10 + 4 * v15) = v16;
          if ( !v16 )
            goto err_208;
          v17 = str[2 * v15];
          if ( v17 )
          {
            v18 = str[2 * v15 + 1];
            if ( v18 && v18->top )
              v19 = v17->top ? (bignum_st *)group->meth->field_mul(group, v16, v17, v18, ctx) : BN_copy(v16, v18);
            else
              v19 = BN_copy(v16, str[2 * v15]);
            if ( !v19 )
              goto err_208;
          }
          --v15;
          v10 = (int)str;
        }
        while ( v15 );
      }
      v20 = *(bignum_st **)(v10 + 4);
      if ( !v20->top || BN_mod_inverse(v10, v20, v20, &group->field, ctx) )
      {
        field_encode = group->meth->field_encode;
        if ( field_encode )
        {
          if ( !field_encode(group, *(bignum_st **)(v10 + 4), *(const bignum_st **)(v10 + 4), ctx)
            || !group->meth->field_encode(group, str[1], str[1], ctx) )
          {
            goto err_208;
          }
          v10 = (int)str;
        }
        v22 = 2;
        if ( v35 > 2 )
        {
          v23 = (bignum_st **)(v10 + 12);
          do
          {
            v24 = *v23;
            if ( *v23 && v24->top )
            {
              v25 = (const bignum_st **)&str[v22 >> 1];
              if ( !group->meth->field_mul(group, (bignum_st *)b, *v25, v24, ctx)
                || !group->meth->field_mul(group, v37, *v25, *(v23 - 1), ctx)
                || !BN_copy(*(v23 - 1), b->vals) )
              {
                goto err_208;
              }
              v26 = BN_copy(*v23, v37);
            }
            else
            {
              v26 = BN_copy(*(v23 - 1), str[v22 >> 1]);
            }
            if ( !v26 )
              goto err_208;
            v22 += 2;
            v23 += 2;
          }
          while ( v22 < v35 );
        }
        v27 = 0;
        v36 = 0;
        do
        {
          v28 = points[v27];
          if ( v28->Z.top )
          {
            if ( !group->meth->field_sqr(group, v37, &v28->Z, ctx)
              || !group->meth->field_mul(group, &v28->X, &v28->X, v37, ctx)
              || !group->meth->field_mul(group, v37, v37, &v28->Z, ctx)
              || !group->meth->field_mul(group, &v28->Y, &v28->Y, v37, ctx) )
            {
              goto err_208;
            }
            field_set_to_one = group->meth->field_set_to_one;
            if ( !(field_set_to_one ? field_set_to_one(group, &v28->Z, ctx) : BN_set_word((int)v37, &v28->Z, 1u)) )
              goto err_208;
            v27 = v36;
            v28->Z_is_one = 1;
          }
          v36 = ++v27;
        }
        while ( v27 < num );
        v39 = 1;
        goto err_208;
      }
      ERR_put_error(v10, 0x10u, 137, 3, ".\\crypto\\ec\\ecp_smpl.c", 1633);
    }
  }
err_208:
  BN_CTX_end(ctx);
  if ( v38 )
    BN_CTX_free(v38);
  if ( str )
  {
    v31 = (v33 >> 1) - 1;
    if ( v33 >> 1 != 1 )
    {
      do
      {
        if ( str[v31] )
          BN_clear_free(str[v31]);
        --v31;
      }
      while ( v31 );
    }
    CRYPTO_free(str);
  }
  return v39;
}
