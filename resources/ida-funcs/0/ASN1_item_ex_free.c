void __cdecl ASN1_item_ex_free(stack_st **pval, const ASN1_ITEM_st *it)
{
  asn1_item_combine_free(pval, it, 0);
}
