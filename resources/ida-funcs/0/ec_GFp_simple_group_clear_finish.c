void __cdecl ec_GFp_simple_group_clear_finish(ec_group_st *group)
{
  BN_clear_free(&group->field);
  BN_clear_free(&group->a);
  BN_clear_free(&group->b);
}
