int __usercall ec_GFp_simple_point_set_affine_coordinates@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y,
        bignum_ctx *ctx)
{
  const bignum_st *v6; // eax

  if ( x && y )
  {
    v6 = BN_value_one();
    return EC_POINT_set_Jprojective_coordinates_GFp(a1, group, point, x, y, v6, ctx);
  }
  else
  {
    ERR_put_error(a1, 0x10u, 168, 67, ".\\crypto\\ec\\ecp_smpl.c", 513);
    return 0;
  }
}
