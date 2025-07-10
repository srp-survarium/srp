void __cdecl stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        int __holeIndex,
        int __len,
        vostok::math::curve_point<vostok::math::float4_pod> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int v5; // ebp
  int v6; // ebx
  bool v7; // zf
  int v8; // eax
  vostok::math::curve_point<vostok::math::float4_pod> *v9; // esi
  vostok::math::curve_point<vostok::math::float4_pod> v10; // [esp-4Ch] [ebp-5Ch] BYREF

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  while ( v6 < __len )
  {
    if ( __comp(&__first[v6], &__first[v6 - 1]) )
      --v6;
    v8 = v5;
    v9 = &__first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
    v7 = v6 == __len;
    qmemcpy(&__first[v8], v9, sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
  }
  if ( v7 )
  {
    qmemcpy(&__first[v5], &__first[v6 - 1], sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
    v5 = v6 - 1;
  }
  qmemcpy(&v10, &__val, sizeof(v10));
  stlp_std::__push_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
    __first,
    v5,
    __holeIndex,
    v10,
    __comp);
}
