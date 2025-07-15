int __cdecl ec_wNAF_precompute_mult(ec_group_st *group, bignum_ctx *ctx)
{
  ec_point_st **v3; // ebx
  ec_pre_comp_st *v4; // ebp
  bignum_pool_item *v6; // eax
  const bignum_st *v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // eax
  int v10; // esi
  ec_point_st **v11; // eax
  int v12; // esi
  ec_point_st **v13; // ebx
  ec_point_st *v14; // eax
  ec_point_st *v15; // eax
  int v16; // eax
  unsigned int v17; // esi
  int v18; // esi
  ec_point_st *v19; // eax
  ec_point_st **i; // esi
  ec_point_st **points; // [esp+10h] [ebp-28h]
  const ec_point_st *a; // [esp+14h] [ebp-24h]
  ec_point_st *r; // [esp+18h] [ebp-20h]
  unsigned int v24; // [esp+1Ch] [ebp-1Ch]
  const ec_point_st *src; // [esp+20h] [ebp-18h]
  const ec_point_st *srca; // [esp+20h] [ebp-18h]
  unsigned int num; // [esp+24h] [ebp-14h]
  unsigned int v28; // [esp+28h] [ebp-10h]
  bignum_ctx *v29; // [esp+2Ch] [ebp-Ch]
  int v30; // [esp+30h] [ebp-8h]
  ec_extra_data_st **p_extra_data; // [esp+34h] [ebp-4h]
  int groupa; // [esp+3Ch] [ebp+4h]

  v3 = 0;
  r = 0;
  a = 0;
  v29 = 0;
  points = 0;
  v30 = 0;
  p_extra_data = &group->extra_data;
  EC_EX_DATA_free_data(
    &group->extra_data,
    (void *(__cdecl *)(void *))ec_pre_comp_dup,
    ec_pre_comp_free,
    ec_pre_comp_clear_free);
  v4 = ec_pre_comp_new(group, 0);
  if ( !v4 )
    return 0;
  src = (const ec_point_st *)EVP_CIPHER_block_size((const env_md_st *)group);
  if ( !src )
  {
    ERR_put_error(0, 0x10u, 188, 113, ".\\crypto\\ec\\ec_mult.c", 785);
err_165:
    if ( ctx )
      BN_CTX_end(ctx);
    if ( v29 )
      BN_CTX_free(v29);
    v3 = points;
    goto LABEL_48;
  }
  if ( ctx || (v29 = BN_CTX_new(0), (ctx = v29) != 0) )
  {
    BN_CTX_start((int)ctx, ctx);
    v6 = BN_CTX_get((int)ctx, ctx);
    v7 = (const bignum_st *)v6;
    if ( v6 && EC_GROUP_get_order(group, v6->vals) )
    {
      if ( v7->top )
      {
        v8 = BN_num_bits(v7);
        groupa = 4;
        if ( v8 >= 0x7D0 )
        {
          groupa = 6;
        }
        else if ( v8 >= 0x320 )
        {
          groupa = 5;
        }
        else if ( v8 <= 0x45 && 2 - (unsigned int)(v8 < 0x14) > 4 )
        {
          groupa = 2 - (v8 < 0x14);
        }
        v9 = (v8 + 7) >> 3;
        v28 = 1 << (groupa - 1);
        v10 = v9 * v28;
        v24 = v9;
        num = v9 * v28;
        v11 = (ec_point_st **)CRYPTO_malloc(4 * v9 * v28 + 4, ".\\crypto\\ec\\ec_mult.c", 828);
        points = v11;
        if ( v11 )
        {
          v11[v10] = 0;
          v12 = 0;
          v13 = v11;
          if ( num )
          {
            while ( 1 )
            {
              v14 = EC_POINT_new((int)v13, group);
              points[v12] = v14;
              if ( !v14 )
                break;
              if ( ++v12 >= num )
                goto LABEL_23;
            }
            ERR_put_error((int)v13, 0x10u, 188, 65, ".\\crypto\\ec\\ec_mult.c", 841);
          }
          else
          {
LABEL_23:
            r = EC_POINT_new((int)v13, group);
            if ( r && (v15 = EC_POINT_new((int)v13, group), (a = v15) != 0) )
            {
              if ( EC_POINT_copy((int)v13, v15, src) )
              {
                srca = 0;
                if ( v24 )
                {
                  while ( EC_POINT_dbl((int)v13, group, r, a, ctx) )
                  {
                    v16 = EC_POINT_copy((int)v13, *v13, a);
                    ++v13;
                    if ( !v16 )
                      break;
                    v17 = 1;
                    if ( v28 > 1 )
                    {
                      while ( EC_POINT_add(group, *v13, r, *(v13 - 1), ctx) )
                      {
                        ++v17;
                        ++v13;
                        if ( v17 >= v28 )
                          goto LABEL_32;
                      }
                      goto err_165;
                    }
LABEL_32:
                    if ( (unsigned int)srca < v24 - 1 )
                    {
                      if ( EC_POINT_dbl((int)v13, group, a, r, ctx) )
                      {
                        v18 = 2;
                        while ( EC_POINT_dbl((int)v13, group, a, a, ctx) )
                        {
                          if ( (unsigned int)++v18 >= 8 )
                            goto LABEL_37;
                        }
                      }
                      goto err_165;
                    }
LABEL_37:
                    srca = (const ec_point_st *)((char *)srca + 1);
                    if ( (unsigned int)srca >= v24 )
                      goto LABEL_38;
                  }
                }
                else
                {
LABEL_38:
                  if ( EC_POINTs_make_affine(group, num, points, ctx) )
                  {
                    v4->numblocks = v24;
                    v4->group = group;
                    v4->blocksize = 8;
                    v4->w = groupa;
                    v4->points = points;
                    points = 0;
                    v4->num = num;
                    if ( EC_EX_DATA_set_data(
                           p_extra_data,
                           v4,
                           (void *(__cdecl *)(void *))ec_pre_comp_dup,
                           ec_pre_comp_free,
                           ec_pre_comp_clear_free) )
                    {
                      v4 = 0;
                      v30 = 1;
                    }
                  }
                }
              }
            }
            else
            {
              ERR_put_error((int)v13, 0x10u, 188, 65, ".\\crypto\\ec\\ec_mult.c", 848);
            }
          }
        }
        else
        {
          ERR_put_error((int)ctx, 0x10u, 188, 65, ".\\crypto\\ec\\ec_mult.c", 831);
        }
      }
      else
      {
        ERR_put_error((int)ctx, 0x10u, 188, 114, ".\\crypto\\ec\\ec_mult.c", 803);
      }
    }
    goto err_165;
  }
LABEL_48:
  if ( v4 )
    ec_pre_comp_free(v4);
  if ( v3 )
  {
    v19 = *v3;
    for ( i = v3; v19; ++i )
    {
      EC_POINT_free(v19);
      v19 = i[1];
    }
    CRYPTO_free(v3);
  }
  if ( r )
    EC_POINT_free(r);
  if ( a )
    EC_POINT_free(a);
  return v30;
}
