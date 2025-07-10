unsigned int *__fastcall stlp_std::priv::__unguarded_partition<void const * *,void const *,stlp_std::less<void const *>>(
        unsigned int *__last,
        unsigned int __pivot,
        unsigned int *__first)
{
  unsigned int *result; // eax
  unsigned int v4; // esi

  for ( result = __first; ; ++result )
  {
    for ( ; *result < __pivot; ++result )
      ;
    for ( --__last; __pivot < *__last; --__last )
      ;
    if ( result >= __last )
      break;
    v4 = *result;
    *result = *__last;
    *__last = v4;
  }
  return result;
}
