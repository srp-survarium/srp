int __cdecl EC_POINT_set_Jprojective_coordinates_GFp(
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y,
        const bignum_st *z,
        bignum_ctx *ctx)
{
  int (__cdecl *point_set_Jprojective_coordinates_GFp)(const ec_group_st *, ec_point_st *, const bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // ecx

  point_set_Jprojective_coordinates_GFp = group->meth->point_set_Jprojective_coordinates_GFp;
  if ( point_set_Jprojective_coordinates_GFp )
  {
    if ( group->meth == point->meth )
    {
      return point_set_Jprojective_coordinates_GFp(group, point, x, y, z, ctx);
    }
    else
    {
      ERR_put_error(0x10u, 126, 101, ".\\crypto\\ec\\ec_lib.c", 819);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 126, 66, ".\\crypto\\ec\\ec_lib.c", 814);
    return 0;
  }
}
