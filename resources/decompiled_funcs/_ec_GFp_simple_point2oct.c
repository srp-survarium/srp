unsigned int __cdecl ec_GFp_simple_point2oct(
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
  bignum_pool_item *v11; // esi
  int v12; // edi
  int v13; // eax
  unsigned int v14; // esi
  int v15; // edi
  int v16; // eax
  unsigned int v17; // esi
  unsigned int v18; // [esp+10h] [ebp-Ch]
  bignum_ctx *v19; // [esp+14h] [ebp-8h]
  bignum_st *a; // [esp+18h] [ebp-4h]

  v19 = 0;
  if ( form != POINT_CONVERSION_COMPRESSED && form != POINT_CONVERSION_UNCOMPRESSED && form != POINT_CONVERSION_HYBRID )
  {
    ERR_put_error(0x10u, 104, 104, ".\\crypto\\ec\\ecp_smpl.c", 779);
    return 0;
  }
  if ( !EC_POINT_is_at_infinity(group, point) )
  {
    v7 = (BN_num_bits(&group->field) + 7) / 8;
    if ( form == POINT_CONVERSION_COMPRESSED )
      v18 = v7 + 1;
    else
      v18 = 2 * v7 + 1;
    if ( buf )
    {
      if ( len < v18 )
      {
        ERR_put_error(0x10u, 104, 100, ".\\crypto\\ec\\ecp_smpl.c", 808);
        return 0;
      }
      v8 = ctx;
      if ( !ctx )
      {
        v9 = BN_CTX_new();
        v19 = v9;
        ctx = v9;
        if ( !v9 )
          return 0;
        v8 = v9;
      }
      BN_CTX_start(v8);
      v10 = BN_CTX_get(v8);
      v11 = BN_CTX_get(v8);
      a = (bignum_st *)v11;
      if ( !v11 || !EC_POINT_get_affine_coordinates_GFp(group, point, v10->vals, v11->vals, ctx) )
        goto LABEL_44;
      if ( (form == POINT_CONVERSION_COMPRESSED || form == POINT_CONVERSION_HYBRID)
        && v11->vals[0].top > 0
        && (*(_BYTE *)v11->vals[0].d & 1) != 0 )
      {
        *buf = form + 1;
      }
      else
      {
        *buf = form;
      }
      v12 = 1;
      v13 = (BN_num_bits(v10->vals) + 7) / 8;
      v14 = v7 - v13;
      if ( v7 - v13 > v7 )
      {
        ERR_put_error(0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 837);
LABEL_44:
        BN_CTX_end(ctx);
        if ( v19 )
          BN_CTX_free(v19);
        return 0;
      }
      if ( v14 )
      {
        memset((int)(buf + 1), 0, v7 - v13);
        v12 = v14 + 1;
      }
      v15 = BN_bn2bin(v10->vals, &buf[v12]) + v12;
      if ( v15 != v7 + 1 )
      {
        ERR_put_error(0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 849);
        goto LABEL_44;
      }
      if ( form == POINT_CONVERSION_UNCOMPRESSED || form == POINT_CONVERSION_HYBRID )
      {
        v16 = (BN_num_bits(a) + 7) / 8;
        v17 = v7 - v16;
        if ( v7 - v16 > v7 )
        {
          ERR_put_error(0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 858);
          goto LABEL_44;
        }
        if ( v17 )
        {
          memset((int)&buf[v15], 0, v7 - v16);
          v15 += v17;
        }
        v15 += BN_bn2bin(a, &buf[v15]);
      }
      if ( v15 != v18 )
      {
        ERR_put_error(0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 872);
        goto LABEL_44;
      }
      BN_CTX_end(ctx);
      if ( v19 )
        BN_CTX_free(v19);
    }
    return v18;
  }
  if ( buf )
  {
    if ( !len )
    {
      ERR_put_error(0x10u, 104, 100, ".\\crypto\\ec\\ecp_smpl.c", 790);
      return 0;
    }
    *buf = 0;
  }
  return 1;
}
