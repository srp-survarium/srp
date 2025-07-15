X509_name_st *__cdecl X509_NAME_dup(X509_name_st *x)
{
  return (X509_name_st *)ASN1_item_dup(&local_it_37, (unsigned __int8 *)x);
}
