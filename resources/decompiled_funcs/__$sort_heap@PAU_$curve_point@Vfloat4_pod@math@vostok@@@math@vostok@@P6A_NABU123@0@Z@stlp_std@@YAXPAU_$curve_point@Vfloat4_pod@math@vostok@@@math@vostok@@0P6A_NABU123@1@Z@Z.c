void __cdecl stlp_std::sort_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int i; // ebx
  char *v4; // edi
  vostok::math::curve_point<vostok::math::float4_pod> v5; // [esp-4Ch] [ebp-A4h] BYREF
  bool (__cdecl *v6)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *); // [esp-4h] [ebp-5Ch]
  _BYTE v7[72]; // [esp+10h] [ebp-48h] BYREF

  for ( i = (char *)__last - (char *)__first;
        i / 72 > 1;
        stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
          __first,
          0,
          i / 72,
          v5,
          v6) )
  {
    v6 = __comp;
    qmemcpy(v7, (char *)&__first[-1] + i, sizeof(v7));
    v4 = (char *)&__first[-1] + i;
    i -= 72;
    qmemcpy(v4, __first, 0x48u);
    qmemcpy(&v5, v7, sizeof(v5));
  }
}
