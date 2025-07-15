void *__cdecl X509_get_ext_d2i(stack_st_X509_EXTENSION *x, int nid, int *crit, int *idx)
{
  return X509V3_get_d2i(*(stack_st_X509_EXTENSION **)(x->stack.num + 36), nid, crit, idx);
}
