const v3_ext_method *__cdecl X509V3_EXT_get_nid(int nid)
{
  char *v2; // eax
  int v3; // eax
  char *key; // [esp+0h] [ebp-3Ch] BYREF
  char data[56]; // [esp+4h] [ebp-38h] BYREF

  key = data;
  if ( nid < 0 )
    return 0;
  *(_DWORD *)data = nid;
  v2 = OBJ_bsearch_(&key, (char *)standard_exts, 40, 4, (int (__cdecl *)(const void *, const void *))sk_comp_cmp);
  if ( v2 )
    return *(const v3_ext_method **)v2;
  if ( !ext_list )
    return 0;
  v3 = sk_find(&ext_list->stack, data);
  if ( v3 == -1 )
    return 0;
  return (const v3_ext_method *)sk_value(&ext_list->stack, v3);
}
