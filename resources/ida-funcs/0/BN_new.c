BOOL __cdecl bn_new(struct ASN1_VALUE_st **pval)
{
  struct ASN1_VALUE_st *v1; // eax

  v1 = (struct ASN1_VALUE_st *)BN_new();
  *pval = v1;
  return v1 != 0;
}
