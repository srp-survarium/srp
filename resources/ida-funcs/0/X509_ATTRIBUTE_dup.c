x509_attributes_st *__usercall X509_ATTRIBUTE_dup@<eax>(int a1@<ebx>, x509_attributes_st *x)
{
  return (x509_attributes_st *)ASN1_item_dup(a1, &local_it_43, (struct ASN1_VALUE_st *)x);
}
