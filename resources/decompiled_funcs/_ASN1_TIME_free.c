void __cdecl ASN1_TIME_free(asn1_string_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_8);
}
