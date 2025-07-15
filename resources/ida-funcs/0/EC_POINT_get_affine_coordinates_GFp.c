int __usercall EC_POINT_get_affine_coordinates_GFp@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        const ec_point_st *point,
        bignum_st *x,
        bignum_st *y,
        bignum_ctx *ctx)
{
  int (__cdecl *point_get_affine_coordinates)(const ec_group_st *, const ec_point_st *, bignum_st *, bignum_st *, bignum_ctx *); // ecx

  point_get_affine_coordinates = group->meth->point_get_affine_coordinates;
  if ( point_get_affine_coordinates )
  {
    if ( group->meth == point->meth )
    {
      return point_get_affine_coordinates(group, point, x, y, ctx);
    }
    else
    {
      ERR_put_error(a1, 0x10u, 116, 101, ".\\crypto\\ec\\ec_lib.c", 887);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 116, 66, ".\\crypto\\ec\\ec_lib.c", 882);
    return 0;
  }
}
