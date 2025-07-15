int __cdecl ASN1_item_i2d(struct ASN1_VALUE_st *val, unsigned __int8 **out, const ASN1_ITEM_st *it)
{
  return asn1_item_flags_i2d(0, val, out, it);
}
