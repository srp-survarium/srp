unsigned int __cdecl ec_GF2m_simple_point2oct(
        const ec_group_st *group,
        const ec_point_st *point,
        point_conversion_form_t form,
        unsigned __int8 *buf,
        unsigned int len,
        bignum_ctx *ctx)
{
  unsigned int v7; // ebp
  bignum_ctx *v8; // esi
  bignum_ctx *v9; // eax
  bignum_pool_item *v10; // ebx
  bignum_pool_item *v11; // edi
  int v12; // edi
  int v13; // eax
  unsigned int v14; // esi
  int v15; // edi
  int v16; // eax
  unsigned int v17; // esi
  unsigned int v18; // [esp+10h] [ebp-Ch]
  bignum_pool_item *y; // [esp+14h] [ebp-8h]
  bignum_ctx *v20; // [esp+18h] [ebp-4h]

  v20 = 0;
  if ( form != POINT_CONVERSION_COMPRESSED && form != POINT_CONVERSION_UNCOMPRESSED && form != POINT_CONVERSION_HYBRID )
  {
    ERR_put_error(0x10u, 161, 104, ".\\crypto\\ec\\ec2_smpl.c", 511);
    return 0;
  }
  if ( !EC_POINT_is_at_infinity(group, point) )
  {
    v7 = (EC_GROUP_get_degree(group) + 7) / 8;
    if ( form == POINT_CONVERSION_COMPRESSED )
      v18 = v7 + 1;
    else
      v18 = 2 * v7 + 1;
    if ( buf )
    {
      if ( len < v18 )
      {
        ERR_put_error(0x10u, 161, 100, ".\\crypto\\ec\\ec2_smpl.c", 540);
        return 0;
      }
      v8 = ctx;
      if ( !ctx )
      {
        v9 = BN_CTX_new();
        v20 = v9;
        ctx = v9;
        if ( !v9 )
          return 0;
        v8 = v9;
      }
      BN_CTX_start(v8);
      v10 = BN_CTX_get(v8);
      y = BN_CTX_get(v8);
      v11 = BN_CTX_get(v8);
      if ( !v11 || !EC_POINT_get_affine_coordinates_GF2m(group, point, v10->vals, y->vals, v8) )
        goto LABEL_45;
      *buf = form;
      if ( form != POINT_CONVERSION_UNCOMPRESSED && v10->vals[0].top )
      {
        if ( !group->meth->field_div(group, (bignum_st *)v11, (const bignum_st *)y, (const bignum_st *)v10, v8) )
        {
LABEL_45:
          BN_CTX_end(v8);
          if ( v20 )
            BN_CTX_free(v20);
          return 0;
        }
        if ( v11->vals[0].top > 0 && (*(_BYTE *)v11->vals[0].d & 1) != 0 )
          ++*buf;
      }
      v12 = 1;
      v13 = (BN_num_bits(v10->vals) + 7) / 8;
      v14 = v7 - v13;
      if ( v7 - v13 > v7 )
      {
        ERR_put_error(0x10u, 161, 68, ".\\crypto\\ec\\ec2_smpl.c", 572);
LABEL_44:
        v8 = ctx;
        goto LABEL_45;
      }
      if ( v14 )
      {
        memset((int)(buf + 1), 0, v7 - v13);
        v12 = v14 + 1;
      }
      v15 = BN_bn2bin(v10->vals, &buf[v12]) + v12;
      if ( v15 != v7 + 1 )
      {
        ERR_put_error(0x10u, 161, 68, ".\\crypto\\ec\\ec2_smpl.c", 584);
        goto LABEL_44;
      }
      if ( form == POINT_CONVERSION_UNCOMPRESSED || form == POINT_CONVERSION_HYBRID )
      {
        v16 = (BN_num_bits(y->vals) + 7) / 8;
        v17 = v7 - v16;
        if ( v7 - v16 > v7 )
        {
          ERR_put_error(0x10u, 161, 68, ".\\crypto\\ec\\ec2_smpl.c", 593);
          goto LABEL_44;
        }
        if ( v17 )
        {
          memset((int)&buf[v15], 0, v7 - v16);
          v15 += v17;
        }
        v15 += BN_bn2bin(y->vals, &buf[v15]);
      }
      if ( v15 != v18 )
      {
        ERR_put_error(0x10u, 161, 68, ".\\crypto\\ec\\ec2_smpl.c", 607);
        goto LABEL_44;
      }
      BN_CTX_end(ctx);
      if ( v20 )
        BN_CTX_free(v20);
    }
    return v18;
  }
  if ( buf )
  {
    if ( !len )
    {
      ERR_put_error(0x10u, 161, 100, ".\\crypto\\ec\\ec2_smpl.c", 522);
      return 0;
    }
    *buf = 0;
  }
  return 1;
}
