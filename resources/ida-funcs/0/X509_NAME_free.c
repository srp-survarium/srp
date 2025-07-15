void __cdecl X509_NAME_free(X509_name_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_37);
}
