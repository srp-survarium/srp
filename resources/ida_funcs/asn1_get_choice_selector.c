int __cdecl asn1_get_choice_selector(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  return *(_DWORD *)((char *)*pval + it->utype);
}
