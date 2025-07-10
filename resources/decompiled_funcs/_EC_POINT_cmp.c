int __cdecl EC_POINT_cmp(const ec_group_st *group, const ec_point_st *a, const ec_point_st *b, bignum_ctx *ctx)
{
  int (__cdecl *point_cmp)(const ec_group_st *, const ec_point_st *, const ec_point_st *, bignum_ctx *); // edx

  point_cmp = group->meth->point_cmp;
  if ( point_cmp )
  {
    if ( group->meth == a->meth && a->meth == b->meth )
    {
      return point_cmp(group, a, b, ctx);
    }
    else
    {
      ERR_put_error(0x10u, 113, 101, ".\\crypto\\ec\\ec_lib.c", 1068);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 113, 66, ".\\crypto\\ec\\ec_lib.c", 1063);
    return 0;
  }
}
