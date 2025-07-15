// attributes: thunk
BOOL __cdecl ec_GF2m_have_precompute_mult(const ec_group_st *group)
{
  return ec_wNAF_have_precompute_mult(group);
}
