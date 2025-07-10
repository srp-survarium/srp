void __cdecl X509_NAME_ENTRY_free(X509_name_entry_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_35);
}
