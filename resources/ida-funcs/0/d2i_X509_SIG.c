X509_sig_st *__cdecl d2i_X509_SIG(X509_sig_st **a, unsigned __int8 **in, const unsigned __int8 **len)
{
  return (X509_sig_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_65);
}
