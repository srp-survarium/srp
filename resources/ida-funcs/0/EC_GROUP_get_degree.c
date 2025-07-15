int __usercall EC_GROUP_get_degree@<eax>(int a1@<ebx>, const ec_group_st *group)
{
  int (*group_get_degree)(void); // eax

  group_get_degree = (int (*)(void))group->meth->group_get_degree;
  if ( group_get_degree )
    return group_get_degree();
  ERR_put_error(a1, 0x10u, 173, 66, ".\\crypto\\ec\\ec_lib.c", 455);
  return 0;
}
