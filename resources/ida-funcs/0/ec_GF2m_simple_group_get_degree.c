int __cdecl ec_GF2m_simple_group_get_degree(const ec_group_st *group)
{
  return BN_num_bits(&group->field) - 1;
}
