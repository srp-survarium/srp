int __cdecl EC_GROUP_get_curve_GF2m(const ec_group_st *group)
{
  int (*group_get_curve)(void); // eax

  group_get_curve = (int (*)(void))group->meth->group_get_curve;
  if ( group_get_curve )
    return group_get_curve();
  ERR_put_error(0x10u, 172, 66, ".\\crypto\\ec\\ec_lib.c", 444);
  return 0;
}
