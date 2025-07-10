x509_attributes_st *__cdecl X509_ATTRIBUTE_dup(x509_attributes_st *x)
{
  return (x509_attributes_st *)ASN1_item_dup(&local_it_43, (unsigned __int8 *)x);
}
