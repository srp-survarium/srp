void __cdecl NAME_CONSTRAINTS_check(x509_st *x, NAME_CONSTRAINTS_st *nc)
{
  x509_st *v2; // esi
  X509_name_st *subject_name; // ebp
  int v4; // eax
  int index_by_NID; // esi
  ui_string_st *entry; // eax
  const char *v7; // eax
  bool v8; // zf
  int v9; // eax
  int i; // ebp
  char *v11; // eax
  int v12; // eax
  GENERAL_NAME_st gen; // [esp+10h] [ebp-8h] BYREF

  v2 = x;
  subject_name = X509_get_subject_name(x);
  if ( X509_NAME_entry_count(subject_name) <= 0 )
  {
LABEL_8:
    for ( i = 0; i < sk_num(&v2->altname->stack); ++i )
    {
      v11 = sk_value(&v2->altname->stack, i);
      nc_match((GENERAL_NAME_st *)v11, nc);
      if ( v12 )
        break;
    }
    return;
  }
  gen.type = 4;
  gen.d.ptr = (char *)subject_name;
  nc_match(&gen, nc);
  if ( v4 )
    return;
  gen.type = 1;
  index_by_NID = X509_NAME_get_index_by_NID(subject_name, 48, -1);
  if ( index_by_NID == -1 )
  {
LABEL_7:
    v2 = x;
    goto LABEL_8;
  }
  while ( 1 )
  {
    entry = (ui_string_st *)X509_NAME_get_entry(subject_name, index_by_NID);
    v7 = UI_get0_output_string(entry);
    v8 = *((_DWORD *)v7 + 1) == 22;
    gen.d.ptr = (char *)v7;
    if ( !v8 )
      break;
    nc_match(&gen, nc);
    if ( v9 )
      break;
    index_by_NID = X509_NAME_get_index_by_NID(subject_name, 48, index_by_NID);
    if ( index_by_NID == -1 )
      goto LABEL_7;
  }
}
