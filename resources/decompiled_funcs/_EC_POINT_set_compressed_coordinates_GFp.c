int __cdecl EC_POINT_set_compressed_coordinates_GFp(
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        int y_bit,
        bignum_ctx *ctx)
{
  int (__cdecl *point_set_compressed_coordinates)(const ec_group_st *, ec_point_st *, const bignum_st *, int, bignum_ctx *); // ecx

  point_set_compressed_coordinates = group->meth->point_set_compressed_coordinates;
  if ( point_set_compressed_coordinates )
  {
    if ( group->meth == point->meth )
    {
      return point_set_compressed_coordinates(group, point, x, y_bit, ctx);
    }
    else
    {
      ERR_put_error(0x10u, 125, 101, ".\\crypto\\ec\\ec_lib.c", 921);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 125, 66, ".\\crypto\\ec\\ec_lib.c", 916);
    return 0;
  }
}
