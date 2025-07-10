void __cdecl stlp_std::priv::__partial_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__middle,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *i; // esi
  int *v6; // [esp+0h] [ebp-10h]

  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),vostok::math::curve_point<float>,int>(
      __first,
      __middle,
      __comp);
  for ( i = __middle; i < __last; ++i )
  {
    if ( __comp(i, __first) )
      stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        __first,
        __middle,
        i,
        *i,
        __comp,
        v6);
  }
  stlp_std::sort_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    __middle,
    __comp);
}
