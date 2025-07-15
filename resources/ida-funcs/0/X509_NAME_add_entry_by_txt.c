X509_name_entry_st *__cdecl X509_NAME_add_entry_by_txt(
        X509_name_st *name,
        char *field,
        int type,
        unsigned __int8 *bytes,
        int len,
        int loc,
        int set)
{
  X509_name_entry_st *result; // eax
  X509_name_entry_st *v8; // esi
  int v9; // edi

  result = X509_NAME_ENTRY_create_by_txt(0, field, type, bytes, len);
  v8 = result;
  if ( result )
  {
    v9 = X509_NAME_add_entry(name, result, loc, set);
    X509_NAME_ENTRY_free(v8);
    return (X509_name_entry_st *)v9;
  }
  return result;
}
