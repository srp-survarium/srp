// attributes: thunk
int __cdecl X509at_get_attr_count(const stack_st_X509_ATTRIBUTE *x)
{
  return sk_num(&x->stack);
}
