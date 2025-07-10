void __cdecl ec_GF2m_simple_group_clear_finish(ec_group_st *group)
{
  BN_clear_free(&group->field);
  BN_clear_free(&group->a);
  BN_clear_free(&group->b);
  group->poly[0] = 0;
  group->poly[1] = 0;
  group->poly[2] = 0;
  group->poly[3] = 0;
  group->poly[4] = 0;
  group->poly[5] = -1;
}
