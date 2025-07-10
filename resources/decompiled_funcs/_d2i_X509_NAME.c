X509_name_st *__cdecl d2i_X509_NAME(X509_name_st **a, const unsigned __int8 **in, int len)
{
  return (X509_name_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_37);
}
