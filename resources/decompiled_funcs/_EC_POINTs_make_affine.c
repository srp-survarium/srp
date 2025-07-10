int __cdecl EC_POINTs_make_affine(const ec_group_st *group, unsigned int num, ec_point_st **points, bignum_ctx *ctx)
{
  int (__cdecl *points_make_affine)(const ec_group_st *, unsigned int, ec_point_st **, bignum_ctx *); // edi
  int v6; // eax

  points_make_affine = group->meth->points_make_affine;
  if ( points_make_affine )
  {
    v6 = 0;
    if ( num )
    {
      while ( group->meth == points[v6]->meth )
      {
        if ( ++v6 >= num )
          return points_make_affine(group, num, points, ctx);
      }
      ERR_put_error(0x10u, 136, 101, ".\\crypto\\ec\\ec_lib.c", 1104);
      return 0;
    }
    else
    {
      return points_make_affine(group, num, points, ctx);
    }
  }
  else
  {
    ERR_put_error(0x10u, 136, 66, ".\\crypto\\ec\\ec_lib.c", 1097);
    return 0;
  }
}
