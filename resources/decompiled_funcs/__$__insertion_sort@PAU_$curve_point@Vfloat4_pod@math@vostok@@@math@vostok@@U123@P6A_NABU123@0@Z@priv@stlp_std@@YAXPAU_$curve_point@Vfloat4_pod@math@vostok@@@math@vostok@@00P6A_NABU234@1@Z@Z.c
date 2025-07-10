void __cdecl stlp_std::priv::__insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        vostok::math::curve_point<vostok::math::float4_pod> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  vostok::math::curve_point<vostok::math::float4_pod> *i; // ebx
  vostok::math::curve_point<vostok::math::float4_pod> v5; // [esp-48h] [ebp-58h] BYREF

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      qmemcpy(&v5, i, sizeof(v5));
      stlp_std::priv::__linear_insert<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        i,
        v5,
        __comp);
    }
  }
}
