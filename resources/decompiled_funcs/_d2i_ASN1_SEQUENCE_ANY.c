stack_st_ASN1_TYPE *__cdecl d2i_ASN1_SEQUENCE_ANY(stack_st_ASN1_TYPE **a, const unsigned __int8 **in, int len)
{
  return (stack_st_ASN1_TYPE *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &it);
}
