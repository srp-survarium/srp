void *__cdecl X509_get_ext_d2i(x509_st *x, int nid, int *crit, int *idx)
{
  return X509V3_get_d2i(x->cert_info->extensions, nid, crit, idx);
}
