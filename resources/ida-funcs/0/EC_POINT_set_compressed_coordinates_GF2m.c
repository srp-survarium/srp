int __usercall EC_POINT_set_compressed_coordinates_GF2m@<eax>(
        int a1@<ebx>,
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
      ERR_put_error(a1, 0x10u, 186, 101, ".\\crypto\\ec\\ec_lib.c", 938);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 186, 66, ".\\crypto\\ec\\ec_lib.c", 933);
    return 0;
  }
}
