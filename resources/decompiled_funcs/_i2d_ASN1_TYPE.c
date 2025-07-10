int __cdecl i2d_ASN1_TYPE(asn1_type_st *a, unsigned __int8 **out)
{
  return ASN1_item_i2d((struct ASN1_VALUE_st *)a, out, &local_it_24);
}
