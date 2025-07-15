int __cdecl ec_GFp_mont_group_init(ec_group_st *group)
{
  int result; // eax

  result = ec_GFp_simple_group_init(group);
  group->field_data1 = 0;
  group->field_data2 = 0;
  return result;
}
