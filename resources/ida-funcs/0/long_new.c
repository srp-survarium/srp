int __cdecl long_new(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  *pval = (struct ASN1_VALUE_st *)it->size;
  return 1;
}
