void __cdecl X509_EXTENSION_free(X509_extension_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_38);
}
