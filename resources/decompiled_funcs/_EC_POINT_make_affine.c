int __cdecl EC_POINT_make_affine(const ec_group_st *group, ec_point_st *point, bignum_ctx *ctx)
{
  int (__cdecl *make_affine)(const ec_group_st *, ec_point_st *, bignum_ctx *); // ecx

  make_affine = group->meth->make_affine;
  if ( make_affine )
  {
    if ( group->meth == point->meth )
    {
      return make_affine(group, point, ctx);
    }
    else
    {
      ERR_put_error(0x10u, 120, 101, ".\\crypto\\ec\\ec_lib.c", 1084);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 120, 66, ".\\crypto\\ec\\ec_lib.c", 1079);
    return 0;
  }
}
