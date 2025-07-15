X509_extension_st *__cdecl X509v3_get_ext(const stack_st_X509_EXTENSION *x, int loc)
{
  if ( x && sk_num(&x->stack) > loc && loc >= 0 )
    return (X509_extension_st *)sk_value(&x->stack, loc);
  else
    return 0;
}
