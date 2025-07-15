x509_attributes_st *__usercall X509at_add1_attr_by_NID@<eax>(
        int a1@<ebx>,
        stack_st_X509_ATTRIBUTE **x,
        unsigned int nid,
        int type,
        __m128i *bytes,
        int len)
{
  x509_attributes_st *result; // eax
  x509_attributes_st *v7; // esi
  stack_st_X509_ATTRIBUTE *v8; // edi

  result = X509_ATTRIBUTE_create_by_NID(a1, 0, nid, type, bytes, len);
  v7 = result;
  if ( result )
  {
    v8 = X509at_add1_attr(x, result);
    X509_ATTRIBUTE_free(v7);
    return (x509_attributes_st *)v8;
  }
  return result;
}
