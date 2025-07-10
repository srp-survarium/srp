void __cdecl stlp_std::pop_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__first,
        vostok::particle::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<vostok::math::float4_pod> *, const vostok::particle::curve_point<vostok::math::float4_pod> *))
{
  vostok::particle::curve_point<vostok::math::float4_pod> v3; // [esp-4Ch] [ebp-9Ch] BYREF
  _BYTE v4[72]; // [esp+8h] [ebp-48h] BYREF

  qmemcpy(v4, &__last[-1], sizeof(v4));
  qmemcpy(&__last[-1], __first, sizeof(vostok::particle::curve_point<vostok::math::float4_pod>));
  qmemcpy(&v3, v4, sizeof(v3));
  stlp_std::__adjust_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,int,vostok::particle::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
    __first,
    0,
    &__last[-1] - __first,
    v3,
    __comp);
}
