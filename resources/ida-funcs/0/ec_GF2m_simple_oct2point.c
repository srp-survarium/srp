int __usercall ec_GF2m_simple_oct2point@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *point,
        const unsigned __int8 *buf,
        bignum_st *len,
        bignum_ctx *ctx)
{
  int v7; // edi
  int v8; // ebx
  bignum_st *v9; // eax
  bignum_ctx *v10; // esi
  bignum_pool_item *v11; // ebp
  const ec_point_st *v12; // edi
  int v13; // eax
  int v14; // eax
  int y_bit; // [esp+8h] [ebp-10h]
  bignum_ctx *v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  bignum_pool_item *v18; // [esp+14h] [ebp-4h]
  bignum_pool_item *ret; // [esp+28h] [ebp+10h]

  v16 = 0;
  v17 = 0;
  if ( !len )
  {
    ERR_put_error(a1, 0x10u, 160, 100, ".\\crypto\\ec\\ec2_smpl.c", 642);
    return 0;
  }
  v7 = *buf & 0xFE;
  y_bit = *buf & 1;
  switch ( v7 )
  {
    case 0:
      goto LABEL_9;
    case 2:
      break;
    case 4:
LABEL_9:
      if ( (*buf & 1) != 0 )
      {
        ERR_put_error(a1, 0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 657);
        return 0;
      }
      break;
    case 6:
      break;
    default:
      ERR_put_error(a1, 0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 652);
      return 0;
  }
  if ( v7 )
  {
    v8 = (EC_GROUP_get_degree(a1, group) + 7) / 8;
    v9 = (bignum_st *)(v8 + 1);
    if ( v7 != 2 )
      v9 = (bignum_st *)(2 * v8 + 1);
    if ( len != v9 )
    {
      ERR_put_error(v8, 0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 677);
      return 0;
    }
    v10 = ctx;
    if ( !ctx )
    {
      v16 = BN_CTX_new(v8);
      v10 = v16;
      if ( !v16 )
        return 0;
    }
    BN_CTX_start(v8, v10);
    v11 = BN_CTX_get(v8, v10);
    ret = BN_CTX_get(v8, v10);
    v18 = BN_CTX_get(v8, v10);
    if ( v18 && BN_bin2bn(buf + 1, v8, v11->vals) )
    {
      if ( BN_ucmp(v11->vals, &group->field) >= 0 )
      {
        ERR_put_error(v8, 0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 697);
        goto err_132;
      }
      if ( v7 == 2 )
      {
        v12 = point;
        v13 = EC_POINT_set_compressed_coordinates_GF2m(v8, group, point, v11->vals, y_bit, v10);
        goto LABEL_42;
      }
      if ( BN_bin2bn(&buf[v8 + 1], v8, ret->vals) )
      {
        if ( BN_ucmp(ret->vals, &group->field) < 0 )
        {
          v8 = (int)group;
          if ( v7 == 6 )
          {
            if ( !group->meth->field_div(group, (bignum_st *)v18, (const bignum_st *)ret, (const bignum_st *)v11, v10) )
              goto err_132;
            v14 = v18->vals[0].top > 0 && (*(_BYTE *)v18->vals[0].d & 1) != 0;
            if ( y_bit != v14 )
            {
              ERR_put_error((int)group, 0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 718);
              goto err_132;
            }
          }
          v12 = point;
          v13 = EC_POINT_set_affine_coordinates_GF2m((int)group, group, point, v11->vals, ret->vals, v10);
LABEL_42:
          if ( v13 )
          {
            if ( EC_POINT_is_on_curve(v8, group, v12, v10) )
              v17 = 1;
            else
              ERR_put_error(v8, 0x10u, 160, 107, ".\\crypto\\ec\\ec2_smpl.c", 728);
          }
          goto err_132;
        }
        ERR_put_error(v8, 0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 710);
      }
    }
err_132:
    BN_CTX_end(v10);
    if ( v16 )
      BN_CTX_free(v16);
    return v17;
  }
  if ( len != (bignum_st *)1 )
  {
    ERR_put_error(a1, 0x10u, 160, 102, ".\\crypto\\ec\\ec2_smpl.c", 665);
    return 0;
  }
  return EC_POINT_set_to_infinity(a1, group, point);
}
