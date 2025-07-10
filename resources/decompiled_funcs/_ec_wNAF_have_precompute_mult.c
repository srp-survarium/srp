BOOL __cdecl ec_wNAF_have_precompute_mult(const ec_group_st *group)
{
  return EC_EX_DATA_get_data(
           group->extra_data,
           (void *(__cdecl *)(void *))ec_pre_comp_dup,
           ec_pre_comp_free,
           ec_pre_comp_clear_free) != 0;
}
