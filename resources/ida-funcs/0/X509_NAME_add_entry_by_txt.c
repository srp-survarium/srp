X509_name_entry_st *__usercall X509_NAME_add_entry_by_txt@<eax>(
        int a1@<ebx>,
        X509_name_st *name,
        char *field,
        int type,
        __m128i *bytes,
        int len,
        int loc,
        int set)
{
  X509_name_entry_st *result; // eax
  X509_name_entry_st *v9; // esi
  int v10; // edi

  result = X509_NAME_ENTRY_create_by_txt(a1, 0, field, type, bytes, len);
  v9 = result;
  if ( result )
  {
    v10 = X509_NAME_add_entry(name, result, loc, set);
    X509_NAME_ENTRY_free(v9);
    return (X509_name_entry_st *)v10;
  }
  return result;
}
