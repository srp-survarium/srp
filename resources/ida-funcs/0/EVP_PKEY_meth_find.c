const evp_pkey_method_st *__usercall EVP_PKEY_meth_find@<eax>(int a1@<edi>, int type)
{
  int v2; // eax
  const evp_pkey_method_st *result; // eax
  char *v4; // eax
  char *v5; // [esp+0h] [ebp-70h] BYREF
  char v6[108]; // [esp+4h] [ebp-6Ch] BYREF

  v5 = v6;
  *(_DWORD *)v6 = type;
  if ( app_pkey_methods )
  {
    v2 = sk_find(a1, &app_pkey_methods->stack, v6);
    if ( v2 >= 0 )
      return (const evp_pkey_method_st *)sk_value(&app_pkey_methods->stack, v2);
  }
  v4 = OBJ_bsearch_(&v5, (char *)standard_methods_0, 5, 4, (int (__cdecl *)(const void *, const void *))sk_comp_cmp);
  if ( !v4 )
    return 0;
  result = *(const evp_pkey_method_st **)v4;
  if ( !result )
    return 0;
  return result;
}
