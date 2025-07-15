int __cdecl ec_GFp_simple_oct2point(
        const ec_group_st *group,
        ec_point_st *point,
        const unsigned __int8 *buf,
        bignum_st *len,
        bignum_ctx *ctx)
{
  int v6; // esi
  int v7; // edi
  bignum_st *v8; // eax
  bignum_ctx *v9; // ebx
  bignum_pool_item *v10; // ebp
  const ec_point_st *v11; // esi
  int v12; // eax
  int v13; // eax
  int y_bit; // [esp+8h] [ebp-Ch]
  bignum_ctx *v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]
  bignum_pool_item *ret; // [esp+24h] [ebp+10h]

  v15 = 0;
  v16 = 0;
  if ( !len )
  {
    ERR_put_error(0, 0x10u, 103, 100, ".\\crypto\\ec\\ecp_smpl.c", 904);
    return 0;
  }
  v6 = *buf & 0xFE;
  y_bit = *buf & 1;
  switch ( v6 )
  {
    case 0:
      goto LABEL_9;
    case 2:
      break;
    case 4:
LABEL_9:
      if ( (*buf & 1) != 0 )
      {
        ERR_put_error((int)len, 0x10u, 103, 102, ".\\crypto\\ec\\ecp_smpl.c", 919);
        return 0;
      }
      break;
    case 6:
      break;
    default:
      ERR_put_error((int)len, 0x10u, 103, 102, ".\\crypto\\ec\\ecp_smpl.c", 914);
      return 0;
  }
  if ( v6 )
  {
    v7 = (BN_num_bits(&group->field) + 7) / 8;
    v8 = (bignum_st *)(v7 + 1);
    if ( v6 != 2 )
      v8 = (bignum_st *)(2 * v7 + 1);
    if ( len != v8 )
    {
      ERR_put_error((int)len, 0x10u, 103, 102, ".\\crypto\\ec\\ecp_smpl.c", 939);
      return 0;
    }
    v9 = ctx;
    if ( !ctx )
    {
      v15 = BN_CTX_new(0);
      v9 = v15;
      if ( !v15 )
        return 0;
    }
    BN_CTX_start((int)v9, v9);
    ret = BN_CTX_get((int)v9, v9);
    v10 = BN_CTX_get((int)v9, v9);
    if ( v10 && BN_bin2bn(buf + 1, v7, ret->vals) )
    {
      if ( BN_ucmp(ret->vals, &group->field) >= 0 )
      {
        ERR_put_error((int)v9, 0x10u, 103, 102, ".\\crypto\\ec\\ecp_smpl.c", 958);
        goto err_204;
      }
      if ( v6 == 2 )
      {
        v11 = point;
        v12 = EC_POINT_set_compressed_coordinates_GFp((int)v9, group, point, ret->vals, y_bit, v9);
        goto LABEL_41;
      }
      if ( BN_bin2bn(&buf[v7 + 1], v7, v10->vals) )
      {
        if ( BN_ucmp(v10->vals, &group->field) < 0 )
        {
          if ( v6 != 6
            || (v10->vals[0].top <= 0 || (*(_BYTE *)v10->vals[0].d & 1) == 0 ? (v13 = 0) : (v13 = 1), y_bit == v13) )
          {
            v11 = point;
            v12 = EC_POINT_set_affine_coordinates_GFp((int)v9, group, point, ret->vals, v10->vals, v9);
LABEL_41:
            if ( v12 )
            {
              if ( EC_POINT_is_on_curve((int)v9, group, v11, v9) )
                v16 = 1;
              else
                ERR_put_error((int)v9, 0x10u, 103, 107, ".\\crypto\\ec\\ecp_smpl.c", 988);
            }
            goto err_204;
          }
          ERR_put_error((int)v9, 0x10u, 103, 102, ".\\crypto\\ec\\ecp_smpl.c", 978);
        }
        else
        {
          ERR_put_error((int)v9, 0x10u, 103, 102, ".\\crypto\\ec\\ecp_smpl.c", 971);
        }
      }
    }
err_204:
    BN_CTX_end(v9);
    if ( v15 )
      BN_CTX_free(v15);
    return v16;
  }
  if ( len != (bignum_st *)1 )
  {
    ERR_put_error((int)len, 0x10u, 103, 102, ".\\crypto\\ec\\ecp_smpl.c", 927);
    return 0;
  }
  return EC_POINT_set_to_infinity(1, group, point);
}
