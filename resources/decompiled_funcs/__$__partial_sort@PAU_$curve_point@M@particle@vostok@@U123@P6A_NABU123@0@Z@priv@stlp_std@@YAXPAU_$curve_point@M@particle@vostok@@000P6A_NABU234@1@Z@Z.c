void __cdecl stlp_std::priv::__partial_sort<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__middle,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> *i; // [esp+4h] [ebp-20h]
  vostok::particle::curve_point<float> v6; // [esp+8h] [ebp-1Ch]
  vostok::particle::curve_point<float> *__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(__i, __first) )
    {
      v6 = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::particle::curve_point<float> *,int,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        __first,
        0,
        __middle - __first,
        v6,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first,
      i,
      __comp);
}
