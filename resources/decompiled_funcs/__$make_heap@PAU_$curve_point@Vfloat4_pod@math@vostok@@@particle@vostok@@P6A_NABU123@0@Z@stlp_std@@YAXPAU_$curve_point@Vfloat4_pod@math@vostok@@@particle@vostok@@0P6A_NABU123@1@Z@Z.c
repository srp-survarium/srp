void __cdecl stlp_std::make_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__first,
        vostok::particle::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<vostok::math::float4_pod> *, const vostok::particle::curve_point<vostok::math::float4_pod> *))
{
  vostok::particle::curve_point<vostok::math::float4_pod> v3; // [esp-4Ch] [ebp-A4h] BYREF
  _BYTE v4[72]; // [esp+8h] [ebp-50h] BYREF
  int __holeIndex; // [esp+50h] [ebp-8h]
  int __len; // [esp+54h] [ebp-4h]

  if ( __last - __first >= 2 )
  {
    __len = __last - __first;
    for ( __holeIndex = (__len - 2) / 2; ; --__holeIndex )
    {
      qmemcpy(v4, &__first[__holeIndex], sizeof(v4));
      qmemcpy(&v3, v4, sizeof(v3));
      stlp_std::__adjust_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,int,vostok::particle::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        __holeIndex,
        __len,
        v3,
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}
