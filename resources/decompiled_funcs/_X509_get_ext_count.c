const stack_st_X509_EXTENSION *__cdecl X509_get_ext_count(x509_st *x)
{
  return X509v3_get_ext_count(x->cert_info->extensions);
}
