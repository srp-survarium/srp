int __cdecl EC_POINT_is_at_infinity(const ec_group_st *group, const ec_point_st *point)
{
  int (__cdecl *is_at_infinity)(const ec_group_st *, const ec_point_st *); // ecx

  is_at_infinity = group->meth->is_at_infinity;
  if ( is_at_infinity )
  {
    if ( group->meth == point->meth )
    {
      return is_at_infinity(group, point);
    }
    else
    {
      ERR_put_error(0x10u, 118, 101, ".\\crypto\\ec\\ec_lib.c", 1036);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 118, 66, ".\\crypto\\ec\\ec_lib.c", 1031);
    return 0;
  }
}
