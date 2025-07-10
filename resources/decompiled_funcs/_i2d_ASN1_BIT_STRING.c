int __cdecl i2d_ASN1_BIT_STRING(asn1_string_st *a, unsigned __int8 **out)
{
  return ASN1_item_i2d((struct ASN1_VALUE_st *)a, out, &local_it_17);
}
