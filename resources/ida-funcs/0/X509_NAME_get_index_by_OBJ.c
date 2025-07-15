int __cdecl X509_NAME_get_index_by_OBJ(X509_name_st *name, asn1_object_st *obj, int lastpos)
{
  int v4; // esi
  stack_st_X509_NAME_ENTRY *entries; // edi
  int v6; // ebx
  int v7; // esi
  char *v8; // eax

  if ( !name )
    return -1;
  v4 = lastpos;
  if ( lastpos < 0 )
    v4 = -1;
  entries = name->entries;
  v6 = sk_num(&name->entries->stack);
  v7 = v4 + 1;
  if ( v7 >= v6 )
    return -1;
  while ( 1 )
  {
    v8 = sk_value(&entries->stack, v7);
    if ( !OBJ_cmp(*(const asn1_object_st **)v8, obj) )
      break;
    if ( ++v7 >= v6 )
      return -1;
  }
  return v7;
}
