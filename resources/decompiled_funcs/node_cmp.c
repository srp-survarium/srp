unsigned int __cdecl node_cmp(const X509_POLICY_NODE_st *const *a, const X509_POLICY_NODE_st *const *b)
{
  return OBJ_cmp(*(const asn1_object_st **)(**(_DWORD **)a + 4), *(const asn1_object_st **)(**(_DWORD **)b + 4));
}
