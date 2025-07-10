void *__cdecl X509_CRL_get_ext_d2i(X509_crl_st *x, int nid, int *crit, int *idx)
{
  return X509V3_get_d2i(x->crl->extensions, nid, crit, idx);
}
