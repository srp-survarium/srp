int __cdecl EC_POINT_oct2point(
        const ec_group_st *group,
        ec_point_st *point,
        const unsigned __int8 *buf,
        unsigned int len,
        bignum_ctx *ctx)
{
  int (__cdecl *oct2point)(const ec_group_st *, ec_point_st *, const unsigned __int8 *, unsigned int, bignum_ctx *); // ecx

  oct2point = group->meth->oct2point;
  if ( oct2point )
  {
    if ( group->meth == point->meth )
    {
      return oct2point(group, point, buf, len, ctx);
    }
    else
    {
      ERR_put_error(0x10u, 122, 101, ".\\crypto\\ec\\ec_lib.c", 972);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 122, 66, ".\\crypto\\ec\\ec_lib.c", 967);
    return 0;
  }
}
