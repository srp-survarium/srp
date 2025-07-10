void __usercall stlp_std::__push_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        int __holeIndex@<eax>,
        vostok::math::curve_point<float> *__first,
        int __topIndex,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v5; // edi
  int v6; // esi
  const vostok::math::curve_point<float> *v7; // ebx
  bool v8; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v7 = &__first[v6];
      if ( !__comp(v7, &__val) )
        break;
      __first[v5] = *v7;
      v5 = v6;
      v8 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v8 );
  }
  __first[v5] = __val;
}
