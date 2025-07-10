X509_name_st *__cdecl X509_get_issuer_name(x509_st *a)
{
  return a->cert_info->issuer;
}
