void __cdecl stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        int __holeIndex,
        int __len,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v5; // edi
  int v6; // esi
  bool i; // zf
  vostok::math::curve_point<float> *v8; // eax
  vostok::math::curve_point<float> *v9; // ecx
  vostok::math::curve_point<float> *v10; // eax

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; *(_QWORD *)&v9->time = *(_QWORD *)&v8->time )
  {
    if ( __comp(&__first[v6], &__first[v6 - 1]) )
      --v6;
    v8 = &__first[v6];
    v9 = &__first[v5];
    *(_QWORD *)&v9->upper_value = *(_QWORD *)&v8->upper_value;
    v5 = v6;
    *(_QWORD *)&v9->tangent_in = *(_QWORD *)&v8->tangent_in;
    v6 = 2 * v6 + 2;
    i = v6 == __len;
  }
  if ( i )
  {
    v10 = &__first[v6 - 1];
    __first[v5] = *v10;
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}
