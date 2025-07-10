int __cdecl X509_get_ext_by_NID(x509_st *x, unsigned int nid, int lastpos)
{
  return X509at_get_attr_by_NID((const stack_st_X509_ATTRIBUTE *)x->cert_info->extensions, nid, lastpos);
}
