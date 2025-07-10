int __cdecl ec_GF2m_simple_group_init(ec_group_st *group)
{
  BN_init(&group->field);
  BN_init(&group->a);
  BN_init(&group->b);
  return 1;
}
