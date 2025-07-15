DSA_SIG_st *__cdecl d2i_DSA_SIG(DSA_SIG_st **a, unsigned __int8 **in, const unsigned __int8 **len)
{
  return (DSA_SIG_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_6CF538);
}
