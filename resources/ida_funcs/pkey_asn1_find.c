const evp_pkey_asn1_method_st *__thiscall pkey_asn1_find(void *type)
{
  int v1; // eax
  const evp_pkey_asn1_method_st *result; // eax
  char *v3; // eax
  char *key; // [esp+0h] [ebp-64h] BYREF
  char data[96]; // [esp+4h] [ebp-60h] BYREF

  key = data;
  *(_DWORD *)data = type;
  if ( app_methods )
  {
    v1 = sk_find(&app_methods->stack, data);
    if ( v1 >= 0 )
      return (const evp_pkey_asn1_method_st *)sk_value(&app_methods->stack, v1);
  }
  v3 = OBJ_bsearch_(&key, (char *)standard_methods, 10, 4, (int (__cdecl *)(const void *, const void *))sk_comp_cmp);
  if ( !v3 )
    return 0;
  result = *(const evp_pkey_asn1_method_st **)v3;
  if ( !result )
    return 0;
  return result;
}
