X509_name_entry_st *__cdecl X509_NAME_ENTRY_create_by_OBJ(
        X509_name_entry_st **ne,
        asn1_object_st *obj,
        int type,
        unsigned __int8 *bytes,
        int len)
{
  X509_name_entry_st *v5; // edi

  if ( !ne || (v5 = *ne) == 0 )
  {
    v5 = X509_NAME_ENTRY_new();
    if ( !v5 )
      return 0;
  }
  if ( !X509_NAME_ENTRY_set_object(v5, obj) || !X509_NAME_ENTRY_set_data(v5, type, bytes, len) )
  {
    if ( !ne || v5 != *ne )
      X509_NAME_ENTRY_free(v5);
    return 0;
  }
  if ( ne && !*ne )
    *ne = v5;
  return v5;
}
