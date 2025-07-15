int __cdecl ec_GFp_simple_make_affine(const ec_group_st *group, ec_point_st *point, bignum_ctx *ctx)
{
  bignum_ctx *v3; // esi
  bignum_pool_item *v5; // ebx
  bignum_pool_item *v6; // eax
  const bignum_st *v7; // edi
  bignum_ctx *v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v8 = 0;
  v9 = 0;
  if ( point->Z_is_one || EC_POINT_is_at_infinity(group, point) )
    return 1;
  v3 = ctx;
  if ( !ctx )
  {
    v8 = BN_CTX_new();
    v3 = v8;
    if ( !v8 )
      return 0;
  }
  BN_CTX_start(v3);
  v5 = BN_CTX_get(v3);
  v6 = BN_CTX_get(v3);
  v7 = (const bignum_st *)v6;
  if ( v6
    && EC_POINT_get_affine_coordinates_GFp(group, point, v5->vals, v6->vals, v3)
    && EC_POINT_set_affine_coordinates_GFp(group, point, v5->vals, v7, v3) )
  {
    if ( point->Z_is_one )
      v9 = 1;
    else
      ERR_put_error(0x10u, 102, 68, ".\\crypto\\ec\\ecp_smpl.c", 1526);
  }
  BN_CTX_end(v3);
  if ( v8 )
    BN_CTX_free(v8);
  return v9;
}
