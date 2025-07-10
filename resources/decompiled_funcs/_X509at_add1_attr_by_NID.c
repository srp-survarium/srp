x509_attributes_st *__cdecl X509at_add1_attr_by_NID(
        stack_st_X509_ATTRIBUTE **x,
        unsigned int nid,
        int type,
        unsigned __int8 *bytes,
        int len)
{
  x509_attributes_st *result; // eax
  x509_attributes_st *v6; // esi
  stack_st_X509_ATTRIBUTE *v7; // edi

  result = X509_ATTRIBUTE_create_by_NID(0, nid, type, bytes, len);
  v6 = result;
  if ( result )
  {
    v7 = X509at_add1_attr(x, result);
    X509_ATTRIBUTE_free(v6);
    return (x509_attributes_st *)v7;
  }
  return result;
}
