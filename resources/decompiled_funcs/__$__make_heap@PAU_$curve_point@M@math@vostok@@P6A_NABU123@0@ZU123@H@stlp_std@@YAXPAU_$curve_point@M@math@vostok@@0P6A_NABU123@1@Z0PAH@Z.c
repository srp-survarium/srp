void __usercall stlp_std::__make_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),vostok::math::curve_point<float>,int>(
        vostok::math::curve_point<float> *__last@<eax>,
        vostok::math::curve_point<float> *__first,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v3; // edi
  int v4; // esi
  vostok::math::curve_point<float> *v5; // ebx
  __int64 v6; // xmm0_8
  vostok::math::curve_point<float> v7; // [esp-1Ch] [ebp-2Ch]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    v4,
    v3,
    *v5,
    __comp);
  while ( v4 )
  {
    v6 = *(_QWORD *)&v5[-1].upper_value;
    --v5;
    *(_QWORD *)&v7.upper_value = v6;
    --v4;
    *(_QWORD *)&v7.tangent_in = *(_QWORD *)&v5->tangent_in;
    *(_QWORD *)&v7.time = *(_QWORD *)&v5->time;
    stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      v4,
      v3,
      v7,
      __comp);
  }
}
