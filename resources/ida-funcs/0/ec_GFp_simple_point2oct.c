unsigned int __usercall ec_GFp_simple_point2oct@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        const ec_point_st *point,
        point_conversion_form_t form,
        unsigned __int8 *buf,
        unsigned int len,
        bignum_ctx *ctx)
{
  unsigned int v8; // ebp
  bignum_ctx *v9; // esi
  bignum_ctx *v10; // eax
  bignum_pool_item *v11; // ebx
  bignum_pool_item *v12; // esi
  int v13; // edi
  int v14; // eax
  unsigned int v15; // esi
  int v16; // edi
  int v17; // eax
  unsigned int v18; // esi
  unsigned int v19; // [esp+10h] [ebp-Ch]
  bignum_ctx *v20; // [esp+14h] [ebp-8h]
  bignum_st *a; // [esp+18h] [ebp-4h]

  v20 = 0;
  if ( form != POINT_CONVERSION_COMPRESSED && form != POINT_CONVERSION_UNCOMPRESSED && form != POINT_CONVERSION_HYBRID )
  {
    ERR_put_error(a1, 0x10u, 104, 104, ".\\crypto\\ec\\ecp_smpl.c", 779);
    return 0;
  }
  if ( !EC_POINT_is_at_infinity(a1, group, point) )
  {
    v8 = (BN_num_bits(&group->field) + 7) / 8;
    if ( form == POINT_CONVERSION_COMPRESSED )
      v19 = v8 + 1;
    else
      v19 = 2 * v8 + 1;
    if ( buf )
    {
      if ( len < v19 )
      {
        ERR_put_error(a1, 0x10u, 104, 100, ".\\crypto\\ec\\ecp_smpl.c", 808);
        return 0;
      }
      v9 = ctx;
      if ( !ctx )
      {
        v10 = BN_CTX_new(a1);
        v20 = v10;
        ctx = v10;
        if ( !v10 )
          return 0;
        v9 = v10;
      }
      BN_CTX_start(a1, v9);
      v11 = BN_CTX_get(a1, v9);
      v12 = BN_CTX_get((int)v11, v9);
      a = (bignum_st *)v12;
      if ( !v12 || !EC_POINT_get_affine_coordinates_GFp((int)v11, group, point, v11->vals, v12->vals, ctx) )
        goto LABEL_44;
      if ( (form == POINT_CONVERSION_COMPRESSED || form == POINT_CONVERSION_HYBRID)
        && v12->vals[0].top > 0
        && (*(_BYTE *)v12->vals[0].d & 1) != 0 )
      {
        *buf = form + 1;
      }
      else
      {
        *buf = form;
      }
      v13 = 1;
      v14 = (BN_num_bits(v11->vals) + 7) / 8;
      v15 = v8 - v14;
      if ( v8 - v14 > v8 )
      {
        ERR_put_error((int)v11, 0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 837);
LABEL_44:
        BN_CTX_end(ctx);
        if ( v20 )
          BN_CTX_free(v20);
        return 0;
      }
      if ( v15 )
      {
        memset((int)(buf + 1), 0, v8 - v14);
        v13 = v15 + 1;
      }
      v16 = BN_bn2bin(v11->vals, &buf[v13]) + v13;
      if ( v16 != v8 + 1 )
      {
        ERR_put_error((int)v11, 0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 849);
        goto LABEL_44;
      }
      if ( form == POINT_CONVERSION_UNCOMPRESSED || form == POINT_CONVERSION_HYBRID )
      {
        v11 = (bignum_pool_item *)a;
        v17 = (BN_num_bits(a) + 7) / 8;
        v18 = v8 - v17;
        if ( v8 - v17 > v8 )
        {
          ERR_put_error((int)a, 0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 858);
          goto LABEL_44;
        }
        if ( v18 )
        {
          memset((int)&buf[v16], 0, v8 - v17);
          v16 += v18;
        }
        v16 += BN_bn2bin(a, &buf[v16]);
      }
      if ( v16 != v19 )
      {
        ERR_put_error((int)v11, 0x10u, 104, 68, ".\\crypto\\ec\\ecp_smpl.c", 872);
        goto LABEL_44;
      }
      BN_CTX_end(ctx);
      if ( v20 )
        BN_CTX_free(v20);
    }
    return v19;
  }
  if ( buf )
  {
    if ( !len )
    {
      ERR_put_error(a1, 0x10u, 104, 100, ".\\crypto\\ec\\ecp_smpl.c", 790);
      return 0;
    }
    *buf = 0;
  }
  return 1;
}
