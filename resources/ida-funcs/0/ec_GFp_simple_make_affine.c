int __usercall ec_GFp_simple_make_affine@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *point,
        bignum_ctx *ctx)
{
  bignum_ctx *v4; // esi
  bignum_pool_item *v6; // ebx
  bignum_pool_item *v7; // eax
  const bignum_st *v8; // edi
  bignum_ctx *v9; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  v9 = 0;
  v10 = 0;
  if ( point->Z_is_one || EC_POINT_is_at_infinity(a1, group, point) )
    return 1;
  v4 = ctx;
  if ( !ctx )
  {
    v9 = BN_CTX_new(a1);
    v4 = v9;
    if ( !v9 )
      return 0;
  }
  BN_CTX_start(a1, v4);
  v6 = BN_CTX_get(a1, v4);
  v7 = BN_CTX_get((int)v6, v4);
  v8 = (const bignum_st *)v7;
  if ( v7
    && EC_POINT_get_affine_coordinates_GFp((int)v6, group, point, v6->vals, v7->vals, v4)
    && EC_POINT_set_affine_coordinates_GFp((int)v6, group, point, v6->vals, v8, v4) )
  {
    if ( point->Z_is_one )
      v10 = 1;
    else
      ERR_put_error((int)v6, 0x10u, 102, 68, ".\\crypto\\ec\\ecp_smpl.c", 1526);
  }
  BN_CTX_end(v4);
  if ( v9 )
    BN_CTX_free(v9);
  return v10;
}
