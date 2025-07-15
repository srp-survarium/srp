asn1_string_table_st *__usercall ASN1_STRING_TABLE_get@<eax>(int a1@<edi>, int nid)
{
  asn1_string_table_st *result; // eax
  int v3; // eax
  char v4[20]; // [esp+0h] [ebp-14h] BYREF

  *(_DWORD *)v4 = nid;
  result = (asn1_string_table_st *)OBJ_bsearch_(
                                     v4,
                                     (char *)tbl_standard,
                                     19,
                                     20,
                                     (int (__cdecl *)(const void *, const void *))nid_cmp_BSEARCH_CMP_FN);
  if ( !result )
  {
    if ( stable && (v3 = sk_find(a1, &stable->stack, v4), v3 >= 0) )
      return (asn1_string_table_st *)sk_value(&stable->stack, v3);
    else
      return 0;
  }
  return result;
}
