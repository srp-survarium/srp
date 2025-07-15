void __cdecl ASN1_item_free(struct ASN1_VALUE_st *val, const ASN1_ITEM_st *it)
{
  asn1_item_combine_free(&val, it, 0);
}
