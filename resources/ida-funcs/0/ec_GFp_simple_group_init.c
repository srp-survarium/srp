int __cdecl ec_GFp_simple_group_init(ec_group_st *group)
{
  BN_init(&group->field);
  BN_init(&group->a);
  BN_init(&group->b);
  group->a_is_minus3 = 0;
  return 1;
}
