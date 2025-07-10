asn1_string_table_st *__cdecl ASN1_STRING_TABLE_get(int nid)
{
  asn1_string_table_st *result; // eax
  int v2; // eax
  char key[20]; // [esp+0h] [ebp-14h] BYREF

  *(_DWORD *)key = nid;
  result = (asn1_string_table_st *)OBJ_bsearch_(
                                     key,
                                     (char *)tbl_standard,
                                     19,
                                     20,
                                     (int (__cdecl *)(const void *, const void *))nid_cmp_BSEARCH_CMP_FN);
  if ( !result )
  {
    if ( stable && (v2 = sk_find(&stable->stack, key), v2 >= 0) )
      return (asn1_string_table_st *)sk_value(&stable->stack, v2);
    else
      return 0;
  }
  return result;
}
