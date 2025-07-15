int __usercall EC_GROUP_set_curve_GF2m@<eax>(int a1@<ebx>, ec_group_st *group)
{
  int (*group_set_curve)(void); // eax

  group_set_curve = (int (*)(void))group->meth->group_set_curve;
  if ( group_set_curve )
    return group_set_curve();
  ERR_put_error(a1, 0x10u, 176, 66, ".\\crypto\\ec\\ec_lib.c", 433);
  return 0;
}
