X509_name_entry_st *__cdecl X509_NAME_delete_entry(X509_name_st *name, int loc)
{
  int v3; // esi
  stack_st_X509_NAME_ENTRY *entries; // edi
  int v5; // ebx
  int v6; // ebp
  char *v7; // eax
  char *v9; // [esp+Ch] [ebp+4h]

  if ( !name )
    return 0;
  v3 = loc;
  if ( sk_num(&name->entries->stack) <= loc || loc < 0 )
    return 0;
  entries = name->entries;
  v9 = sk_delete(&name->entries->stack, loc);
  v5 = sk_num(&entries->stack);
  name->modified = 1;
  if ( loc != v5 )
  {
    if ( loc )
      v6 = *((_DWORD *)sk_value(&entries->stack, loc - 1) + 2);
    else
      v6 = *((_DWORD *)v9 + 2) - 1;
    if ( v6 + 1 < *((_DWORD *)sk_value(&entries->stack, loc) + 2) && loc < v5 )
    {
      do
      {
        v7 = sk_value(&entries->stack, v3);
        --*((_DWORD *)v7 + 2);
        ++v3;
      }
      while ( v3 < v5 );
    }
  }
  return (X509_name_entry_st *)v9;
}
