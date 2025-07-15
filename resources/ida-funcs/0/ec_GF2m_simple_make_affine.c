int __cdecl ec_GF2m_simple_make_affine(const ec_group_st *group, ec_point_st *point, bignum_ctx *ctx)
{
  bignum_ctx *v3; // esi
  bignum_pool_item *v5; // ebp
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
    && EC_POINT_get_affine_coordinates_GF2m(group, point, v5->vals, v6->vals, v3)
    && BN_copy(&point->X, v5->vals)
    && BN_copy(&point->Y, v7)
    && BN_set_word(&point->Z, 1u) )
  {
    v9 = 1;
  }
  if ( v3 )
    BN_CTX_end(v3);
  if ( v8 )
    BN_CTX_free(v8);
  return v9;
}
