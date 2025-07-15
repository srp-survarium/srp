asn1_string_st *__cdecl d2i_ASN1_OCTET_STRING(asn1_string_st **a, const unsigned __int8 **in, int len)
{
  return (asn1_string_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_18);
}
