int __cdecl EC_GROUP_set_curve_GF2m(ec_group_st *group)
{
  int (*group_set_curve)(void); // eax

  group_set_curve = (int (*)(void))group->meth->group_set_curve;
  if ( group_set_curve )
    return group_set_curve();
  ERR_put_error(0x10u, 176, 66, ".\\crypto\\ec\\ec_lib.c", 433);
  return 0;
}
