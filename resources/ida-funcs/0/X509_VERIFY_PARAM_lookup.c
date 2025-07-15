const X509_VERIFY_PARAM_st *__usercall X509_VERIFY_PARAM_lookup@<eax>(int a1@<edi>, const char *name)
{
  int v2; // eax
  char v4[40]; // [esp+0h] [ebp-28h] BYREF

  *(_DWORD *)v4 = name;
  if ( !param_table )
    return (const X509_VERIFY_PARAM_st *)OBJ_bsearch_(
                                           v4,
                                           (char *)default_table,
                                           5,
                                           40,
                                           (int (__cdecl *)(const void *, const void *))table_cmp_BSEARCH_CMP_FN);
  v2 = sk_find(a1, &param_table->stack, v4);
  if ( v2 == -1 )
    return (const X509_VERIFY_PARAM_st *)OBJ_bsearch_(
                                           v4,
                                           (char *)default_table,
                                           5,
                                           40,
                                           (int (__cdecl *)(const void *, const void *))table_cmp_BSEARCH_CMP_FN);
  else
    return (const X509_VERIFY_PARAM_st *)sk_value(&param_table->stack, v2);
}
