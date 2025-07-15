void __cdecl X509_ATTRIBUTE_free(x509_attributes_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_43);
}
