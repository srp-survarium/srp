int __cdecl X509_VERIFY_PARAM_set1(X509_VERIFY_PARAM_st *to, const X509_VERIFY_PARAM_st *from)
{
  unsigned int inh_flags; // edi
  int result; // eax

  inh_flags = to->inh_flags;
  to->inh_flags = inh_flags | 1;
  result = X509_VERIFY_PARAM_inherit(to, from);
  to->inh_flags = inh_flags;
  return result;
}
