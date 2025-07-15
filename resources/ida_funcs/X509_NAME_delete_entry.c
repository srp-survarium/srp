X509_name_entry_st *__cdecl X509_NAME_delete_entry(X509_name_entry_st *name, int loc)
{
  int v3; // esi
  stack_st_X509_NAME_ENTRY *object; // edi
  int v5; // ebx
  int v6; // ebp
  char *v7; // eax
  char *ret; // [esp+Ch] [ebp+4h]

  if ( !name )
    return 0;
  v3 = loc;
  if ( sk_num((const stack_st *)name->object) <= loc || loc < 0 )
    return 0;
  object = (stack_st_X509_NAME_ENTRY *)name->object;
  ret = sk_delete((stack_st *)name->object, loc);
  v5 = sk_num(&object->stack);
  name->value = (asn1_string_st *)1;
  if ( loc != v5 )
  {
    if ( loc )
      v6 = *((_DWORD *)sk_value(&object->stack, loc - 1) + 2);
    else
      v6 = *((_DWORD *)ret + 2) - 1;
    if ( v6 + 1 < *((_DWORD *)sk_value(&object->stack, loc) + 2) && loc < v5 )
    {
      do
      {
        v7 = sk_value(&object->stack, v3);
        --*((_DWORD *)v7 + 2);
        ++v3;
      }
      while ( v3 < v5 );
    }
  }
  return (X509_name_entry_st *)ret;
}
