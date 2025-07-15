X509_name_entry_st *__cdecl X509_NAME_ENTRY_dup(X509_name_entry_st *x)
{
  return (X509_name_entry_st *)ASN1_item_dup(&local_it_35, x);
}
