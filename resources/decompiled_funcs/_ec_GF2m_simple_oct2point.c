int __cdecl ec_GF2m_simple_oct2point(
        const ec_group_st *group,
        ec_point_st *point,
        const unsigned __int8 *buf,
        bignum_st *len,
        bignum_ctx *ctx)
{
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  bignum_ctx *v9; // esi
  bignum_pool_item *v10; // ebp
  const ec_point_st *v11; // edi
  int v12; // eax
  int v13; // eax
  int y_bit; // [esp+8h] [ebp-10h]
  bignum_ctx *v15; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+10h] [ebp-8h]
  bignum_pool_item *v17; // [esp+14h] [ebp-4h]
  bignum_pool_item *ret; // [esp+28h] [ebp+10h]

  v15 = 0;
  v16 = 0;
  if ( !len )
  {
    ERR_put_error(0x10u, 160, 100, ".\\crypto\\ec\\ec2_smpl.c", 642);
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
        ERR_put_error(0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 657);
        return 0;
      }
      break;
    case 6:
      break;
    default:
      ERR_put_error(0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 652);
      return 0;
  }
  if ( v6 )
  {
    v7 = (EC_GROUP_get_degree(group) + 7) / 8;
    v8 = v7 + 1;
    if ( v6 != 2 )
      v8 = 2 * v7 + 1;
    if ( len != (bignum_st *)v8 )
    {
      ERR_put_error(0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 677);
      return 0;
    }
    v9 = ctx;
    if ( !ctx )
    {
      v15 = BN_CTX_new();
      v9 = v15;
      if ( !v15 )
        return 0;
    }
    BN_CTX_start(v9);
    v10 = BN_CTX_get(v9);
    ret = BN_CTX_get(v9);
    v17 = BN_CTX_get(v9);
    if ( v17 && BN_bin2bn(buf + 1, v7, v10->vals) )
    {
      if ( BN_ucmp(v10->vals, &group->field) >= 0 )
      {
        ERR_put_error(0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 697);
        goto err_130;
      }
      if ( v6 == 2 )
      {
        v11 = point;
        v12 = EC_POINT_set_compressed_coordinates_GF2m(group, point, v10->vals, y_bit, v9);
        goto LABEL_42;
      }
      if ( BN_bin2bn(&buf[v7 + 1], v7, ret->vals) )
      {
        if ( BN_ucmp(ret->vals, &group->field) < 0 )
        {
          if ( v6 == 6 )
          {
            if ( !group->meth->field_div(group, (bignum_st *)v17, (const bignum_st *)ret, (const bignum_st *)v10, v9) )
              goto err_130;
            v13 = v17->vals[0].top > 0 && (*(_BYTE *)v17->vals[0].d & 1) != 0;
            if ( y_bit != v13 )
            {
              ERR_put_error(0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 718);
              goto err_130;
            }
          }
          v11 = point;
          v12 = EC_POINT_set_affine_coordinates_GF2m(group, point, v10->vals, ret->vals, v9);
LABEL_42:
          if ( v12 )
          {
            if ( EC_POINT_is_on_curve(group, v11, v9) )
              v16 = 1;
            else
              ERR_put_error(0x10u, 160, 107, ".\\crypto\\ec\\ec2_smpl.c", 728);
          }
          goto err_130;
        }
        ERR_put_error(0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 710);
      }
    }
err_130:
    BN_CTX_end(v9);
    if ( v15 )
      BN_CTX_free(v15);
    return v16;
  }
  if ( len != (bignum_st *)1 )
  {
    ERR_put_error(0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 665);
    return 0;
  }
  return EC_POINT_set_to_infinity(group, point);
}
