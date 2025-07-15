const X509_VERIFY_PARAM_st *__cdecl X509_VERIFY_PARAM_lookup(const char *name)
{
  int v1; // eax
  char data[40]; // [esp+0h] [ebp-28h] BYREF

  *(_DWORD *)data = name;
  if ( !param_table )
    return (const X509_VERIFY_PARAM_st *)OBJ_bsearch_(
                                           data,
                                           (char *)default_table,
                                           5,
                                           40,
                                           (int (__cdecl *)(const void *, const void *))table_cmp_BSEARCH_CMP_FN);
  v1 = sk_find(&param_table->stack, data);
  if ( v1 == -1 )
    return (const X509_VERIFY_PARAM_st *)OBJ_bsearch_(
                                           data,
                                           (char *)default_table,
                                           5,
                                           40,
                                           (int (__cdecl *)(const void *, const void *))table_cmp_BSEARCH_CMP_FN);
  else
    return (const X509_VERIFY_PARAM_st *)sk_value(&param_table->stack, v1);
}
