void __cdecl stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}
