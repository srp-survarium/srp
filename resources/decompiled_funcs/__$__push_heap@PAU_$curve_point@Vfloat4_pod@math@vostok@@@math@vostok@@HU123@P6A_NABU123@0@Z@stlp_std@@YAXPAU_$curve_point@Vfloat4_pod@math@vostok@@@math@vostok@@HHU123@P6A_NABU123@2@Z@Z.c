void __usercall stlp_std::__push_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        int __holeIndex@<eax>,
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        int __topIndex,
        vostok::math::curve_point<vostok::math::float4_pod> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int v5; // edi
  int v6; // ebx
  bool v7; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      if ( !__comp(&__first[v6], &__val) )
        break;
      qmemcpy(&__first[v5], &__first[v6], sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
      v5 = v6;
      v7 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v7 );
  }
  qmemcpy(&__first[v5], &__val, sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
}
