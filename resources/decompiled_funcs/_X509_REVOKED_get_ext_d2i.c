void *__cdecl X509_REVOKED_get_ext_d2i(x509_revoked_st *x, int nid, int *crit, int *idx)
{
  return X509V3_get_d2i(x->extensions, nid, crit, idx);
}
