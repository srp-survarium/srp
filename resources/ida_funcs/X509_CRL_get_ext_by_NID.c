int __cdecl X509_CRL_get_ext_by_NID(X509_crl_st *x, unsigned int nid, int lastpos)
{
  return X509at_get_attr_by_NID((const stack_st_X509_ATTRIBUTE *)x->crl->extensions, nid, lastpos);
}
