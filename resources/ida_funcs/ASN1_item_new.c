struct ASN1_VALUE_st *__cdecl ASN1_item_new(const ASN1_ITEM_st *it)
{
  int v1; // eax
  struct ASN1_VALUE_st *pval; // [esp+4h] [ebp-4h] BYREF

  pval = 0;
  v1 = asn1_item_ex_combine_new(&pval, it, 0);
  return v1 <= 0 ? 0 : pval;
}
