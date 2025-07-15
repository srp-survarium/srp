x509_st *__cdecl d2i_X509(x509_st **a, unsigned __int8 **in, const unsigned __int8 *len)
{
  return (x509_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_10);
}
