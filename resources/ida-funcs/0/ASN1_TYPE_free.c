void __cdecl ASN1_TYPE_free(asn1_type_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_24);
}
