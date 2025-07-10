const evp_pkey_method_st *__cdecl EVP_PKEY_meth_find(int type)
{
  int v1; // eax
  const evp_pkey_method_st *result; // eax
  char *v3; // eax
  char *key; // [esp+0h] [ebp-70h] BYREF
  char data[108]; // [esp+4h] [ebp-6Ch] BYREF

  key = data;
  *(_DWORD *)data = type;
  if ( app_pkey_methods )
  {
    v1 = sk_find(&app_pkey_methods->stack, data);
    if ( v1 >= 0 )
      return (const evp_pkey_method_st *)sk_value(&app_pkey_methods->stack, v1);
  }
  v3 = OBJ_bsearch_(&key, (char *)standard_methods_0, 5, 4, (int (__cdecl *)(const void *, const void *))sk_comp_cmp);
  if ( !v3 )
    return 0;
  result = *(const evp_pkey_method_st **)v3;
  if ( !result )
    return 0;
  return result;
}
