const stack_st_X509_EXTENSION *__cdecl X509v3_get_ext_count(const stack_st_X509_EXTENSION *x)
{
  const stack_st_X509_EXTENSION *result; // eax

  result = x;
  if ( x )
    return (const stack_st_X509_EXTENSION *)sk_num(&x->stack);
  return result;
}
