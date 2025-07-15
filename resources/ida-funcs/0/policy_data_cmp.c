unsigned int __cdecl policy_data_cmp(const void *a1, const void *a2)
{
  return OBJ_cmp(*(const asn1_object_st **)(*(_DWORD *)a1 + 4), *(const asn1_object_st **)(*(_DWORD *)a2 + 4));
}
