int __usercall EC_POINT_set_to_infinity@<eax>(int a1@<ebx>, const ec_group_st *group, ec_point_st *point)
{
  int (__cdecl *point_set_to_infinity)(const ec_group_st *, ec_point_st *); // ecx

  point_set_to_infinity = group->meth->point_set_to_infinity;
  if ( point_set_to_infinity )
  {
    if ( group->meth == point->meth )
    {
      return point_set_to_infinity(group, point);
    }
    else
    {
      ERR_put_error(a1, 0x10u, 127, 101, ".\\crypto\\ec\\ec_lib.c", 802);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 127, 66, ".\\crypto\\ec\\ec_lib.c", 797);
    return 0;
  }
}
