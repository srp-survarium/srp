X509_name_entry_st *__usercall X509_NAME_ENTRY_create_by_OBJ@<eax>(
        int a1@<ebx>,
        X509_name_entry_st **ne,
        asn1_object_st *obj,
        int type,
        __m128i *bytes,
        int len)
{
  X509_name_entry_st *v6; // edi

  if ( !ne || (v6 = *ne) == 0 )
  {
    v6 = X509_NAME_ENTRY_new();
    if ( !v6 )
      return 0;
  }
  if ( !X509_NAME_ENTRY_set_object(a1, v6, obj) || !X509_NAME_ENTRY_set_data(v6, type, bytes, len) )
  {
    if ( !ne || v6 != *ne )
      X509_NAME_ENTRY_free(v6);
    return 0;
  }
  if ( ne && !*ne )
    *ne = v6;
  return v6;
}
