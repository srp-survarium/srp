void __cdecl stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}
