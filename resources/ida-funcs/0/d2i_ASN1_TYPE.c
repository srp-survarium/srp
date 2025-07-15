asn1_type_st *__cdecl d2i_ASN1_TYPE(asn1_type_st **a, unsigned __int8 **in, const unsigned __int8 *len)
{
  return (asn1_type_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_24);
}
