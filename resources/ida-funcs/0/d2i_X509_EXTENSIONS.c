stack_st_X509_EXTENSION *__cdecl d2i_X509_EXTENSIONS(stack_st_X509_EXTENSION **a, const unsigned __int8 **in, int len)
{
  return (stack_st_X509_EXTENSION *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_83C620);
}
