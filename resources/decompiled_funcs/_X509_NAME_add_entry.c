int __cdecl X509_NAME_add_entry(X509_name_st *name, X509_name_entry_st *ne, int loc, int set)
{
  stack_st_X509_NAME_ENTRY *entries; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // esi
  X509_name_entry_st *v9; // eax
  X509_name_entry_st *v10; // ebp
  int v11; // ebp
  int i; // esi
  char *v13; // eax
  BOOL inc; // [esp+8h] [ebp+4h]

  if ( !name )
    return 0;
  entries = name->entries;
  v6 = sk_num(&name->entries->stack);
  v7 = loc;
  if ( loc > v6 || loc < 0 )
    v7 = v6;
  name->modified = 1;
  if ( set == -1 )
  {
    if ( v7 )
    {
      v8 = *((_DWORD *)sk_value(&entries->stack, v7 - 1) + 2);
      inc = 0;
    }
    else
    {
      v8 = 0;
      inc = 1;
    }
  }
  else
  {
    if ( v7 < v6 )
    {
      v8 = *((_DWORD *)sk_value(&entries->stack, v7) + 2);
    }
    else if ( v7 )
    {
      v8 = *((_DWORD *)sk_value(&entries->stack, v7 - 1) + 2) + 1;
    }
    else
    {
      v8 = 0;
    }
    inc = v8 == 0;
  }
  v9 = X509_NAME_ENTRY_dup(ne);
  v10 = v9;
  if ( !v9 )
    return 0;
  v9->set = v8;
  if ( !sk_insert(&entries->stack, (char *)v9, v7) )
  {
    ERR_put_error(0xBu, 113, 65, ".\\crypto\\x509\\x509name.c", 259);
    X509_NAME_ENTRY_free(v10);
    return 0;
  }
  if ( inc )
  {
    v11 = sk_num(&entries->stack);
    for ( i = v7 + 1; i < v11; ++i )
    {
      v13 = sk_value(&entries->stack, i - 1);
      ++*((_DWORD *)v13 + 2);
    }
  }
  return 1;
}
