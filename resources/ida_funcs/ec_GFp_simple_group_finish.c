void __cdecl ec_GFp_simple_group_finish(ec_group_st *group)
{
  BN_free(&group->field);
  BN_free(&group->a);
  BN_free(&group->b);
}
