void __cdecl stlp_std::priv::__insertion_sort<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> v4; // [esp+0h] [ebp-28h] BYREF
  vostok::particle::curve_point<float> *__i; // [esp+24h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v4 = *__i;
      if ( __comp(&v4, __first) )
      {
        stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__i,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)&__i[1]);
        *__first = v4;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
          __i,
          v4,
          __comp);
      }
    }
  }
}
