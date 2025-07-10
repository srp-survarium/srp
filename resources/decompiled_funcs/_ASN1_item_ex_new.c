int __cdecl ASN1_item_ex_new(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  return asn1_item_ex_combine_new(pval, it, 0);
}
