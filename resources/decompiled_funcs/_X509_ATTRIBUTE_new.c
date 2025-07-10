x509_attributes_st *__cdecl X509_ATTRIBUTE_new()
{
  return (x509_attributes_st *)ASN1_item_new(&local_it_43);
}
