unsigned int __cdecl policy_data_cmp(const X509_POLICY_DATA_st *const *a, const X509_POLICY_DATA_st *const *b)
{
  return OBJ_cmp((*a)->valid_policy, (*b)->valid_policy);
}
