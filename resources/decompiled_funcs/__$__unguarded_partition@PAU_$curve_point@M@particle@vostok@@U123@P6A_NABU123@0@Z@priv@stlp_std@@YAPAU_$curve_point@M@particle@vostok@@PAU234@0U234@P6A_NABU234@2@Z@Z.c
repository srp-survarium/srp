vostok::particle::curve_point<float> *__cdecl stlp_std::priv::__unguarded_partition<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> __pivot,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float> *>(
      __first++,
      __last);
  }
  return __first;
}
