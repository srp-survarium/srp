const evp_pkey_asn1_method_st *__usercall pkey_asn1_find@<eax>(void *type@<ecx>, int a2@<edi>)
{
  int v2; // eax
  const evp_pkey_asn1_method_st *result; // eax
  char *v4; // eax
  char *v5; // [esp+0h] [ebp-64h] BYREF
  char v6[96]; // [esp+4h] [ebp-60h] BYREF

  v5 = v6;
  *(_DWORD *)v6 = type;
  if ( app_methods )
  {
    v2 = sk_find(a2, &app_methods->stack, v6);
    if ( v2 >= 0 )
      return (const evp_pkey_asn1_method_st *)sk_value(&app_methods->stack, v2);
  }
  v4 = OBJ_bsearch_(&v5, (char *)standard_methods, 10, 4, (int (__cdecl *)(const void *, const void *))sk_comp_cmp);
  if ( !v4 )
    return 0;
  result = *(const evp_pkey_asn1_method_st **)v4;
  if ( !result )
    return 0;
  return result;
}
