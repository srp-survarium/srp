X509_crl_st *__cdecl d2i_X509_CRL(X509_crl_st **a, const unsigned __int8 **in, int len)
{
  return (X509_crl_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_7);
}
