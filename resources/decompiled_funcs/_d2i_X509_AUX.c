x509_st *__cdecl d2i_X509_AUX(x509_st **a, const unsigned __int8 **pp, int length)
{
  const unsigned __int8 *v3; // ebx
  x509_st *result; // eax
  struct ASN1_VALUE_st *v5; // edi
  int v6; // ebp

  v3 = *pp;
  result = (x509_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, pp, length, &local_it_10);
  v5 = (struct ASN1_VALUE_st *)result;
  if ( !result )
    return 0;
  v6 = v3 - *pp + length;
  if ( !v6 )
    return result;
  if ( !d2i_X509_CERT_AUX(&result->aux, pp, v6) )
  {
    ASN1_item_free(v5, &local_it_10);
    return 0;
  }
  return (x509_st *)v5;
}
