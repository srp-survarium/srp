void __cdecl EC_GROUP_set_curve_name(ec_group_st *group, int nid)
{
  group->curve_name = nid;
}
