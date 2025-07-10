void __cdecl ASN1_ENUMERATED_free(asn1_string_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_16);
}
