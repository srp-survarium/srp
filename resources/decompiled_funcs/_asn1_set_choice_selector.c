int __cdecl asn1_set_choice_selector(struct ASN1_VALUE_st **pval, int value, const ASN1_ITEM_st *it)
{
  int *v3; // ecx
  int result; // eax

  v3 = (int *)((char *)*pval + it->utype);
  result = *v3;
  *v3 = value;
  return result;
}
