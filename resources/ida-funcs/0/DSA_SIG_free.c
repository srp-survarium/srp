void __cdecl DSA_SIG_free(DSA_SIG_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &stru_6CF538);
}
