int __cdecl EC_GROUP_get_degree(const ec_group_st *group)
{
  int (*group_get_degree)(void); // eax

  group_get_degree = (int (*)(void))group->meth->group_get_degree;
  if ( group_get_degree )
    return group_get_degree();
  ERR_put_error(0x10u, 173, 66, ".\\crypto\\ec\\ec_lib.c", 455);
  return 0;
}
