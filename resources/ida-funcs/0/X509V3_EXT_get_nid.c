const v3_ext_method *__usercall X509V3_EXT_get_nid@<eax>(int a1@<edi>, int nid)
{
  char *v3; // eax
  int v4; // eax
  char *v5; // [esp+0h] [ebp-3Ch] BYREF
  char v6[56]; // [esp+4h] [ebp-38h] BYREF

  v5 = v6;
  if ( nid < 0 )
    return 0;
  *(_DWORD *)v6 = nid;
  v3 = OBJ_bsearch_(&v5, (char *)standard_exts, 40, 4, (int (__cdecl *)(const void *, const void *))sk_comp_cmp);
  if ( v3 )
    return *(const v3_ext_method **)v3;
  if ( !ext_list )
    return 0;
  v4 = sk_find(a1, &ext_list->stack, v6);
  if ( v4 == -1 )
    return 0;
  return (const v3_ext_method *)sk_value(&ext_list->stack, v4);
}
