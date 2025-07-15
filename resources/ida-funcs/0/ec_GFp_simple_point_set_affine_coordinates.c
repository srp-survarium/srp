int __cdecl ec_GFp_simple_point_set_affine_coordinates(
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y,
        bignum_ctx *ctx)
{
  const bignum_st *v5; // eax

  if ( x && y )
  {
    v5 = BN_value_one();
    return EC_POINT_set_Jprojective_coordinates_GFp(group, point, x, y, v5, ctx);
  }
  else
  {
    ERR_put_error(0x10u, 168, 67, ".\\crypto\\ec\\ecp_smpl.c", 513);
    return 0;
  }
}
