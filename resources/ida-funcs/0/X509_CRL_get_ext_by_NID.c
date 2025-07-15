int __cdecl X509_CRL_get_ext_by_NID(stack_st_X509_ATTRIBUTE *x, int nid, int lastpos)
{
  return X509at_get_attr_by_NID(*(const stack_st_X509_ATTRIBUTE **)(x->stack.num + 24), nid, lastpos);
}
