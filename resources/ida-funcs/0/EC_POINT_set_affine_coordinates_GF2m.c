int __cdecl EC_POINT_set_affine_coordinates_GF2m(
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y,
        bignum_ctx *ctx)
{
  int (__cdecl *point_set_affine_coordinates)(const ec_group_st *, ec_point_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // ecx

  point_set_affine_coordinates = group->meth->point_set_affine_coordinates;
  if ( point_set_affine_coordinates )
  {
    if ( group->meth == point->meth )
    {
      return point_set_affine_coordinates(group, point, x, y, ctx);
    }
    else
    {
      ERR_put_error(0x10u, 185, 101, ".\\crypto\\ec\\ec_lib.c", 870);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 185, 66, ".\\crypto\\ec\\ec_lib.c", 865);
    return 0;
  }
}
