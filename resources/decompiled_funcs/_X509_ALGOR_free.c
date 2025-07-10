void __cdecl X509_ALGOR_free(X509_algor_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_40);
}
