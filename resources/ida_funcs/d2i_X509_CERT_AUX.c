x509_cert_aux_st *__cdecl d2i_X509_CERT_AUX(x509_cert_aux_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  return (x509_cert_aux_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_83CC94);
}
