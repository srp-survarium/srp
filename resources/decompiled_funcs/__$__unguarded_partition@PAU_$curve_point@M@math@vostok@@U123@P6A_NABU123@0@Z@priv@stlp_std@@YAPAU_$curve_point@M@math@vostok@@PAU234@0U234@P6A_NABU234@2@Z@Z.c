vostok::math::curve_point<float> *__cdecl stlp_std::priv::__unguarded_partition<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> __pivot,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  bool (__cdecl *v4)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // ebx
  __int64 v7; // xmm0_8
  __int64 v8; // xmm1_8
  __int64 v9; // xmm2_8

  v4 = __comp;
  while ( 1 )
  {
    for ( ; v4(__first, &__pivot); ++__first )
      ;
    for ( --__last; v4(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    v7 = *(_QWORD *)&__first->upper_value;
    v8 = *(_QWORD *)&__first->tangent_in;
    v9 = *(_QWORD *)&__first->time;
    *(_QWORD *)&__first->upper_value = *(_QWORD *)&__last->upper_value;
    *(_QWORD *)&__first->tangent_in = *(_QWORD *)&__last->tangent_in;
    *(_QWORD *)&__first->time = *(_QWORD *)&__last->time;
    *(_QWORD *)&__last->upper_value = v7;
    *(_QWORD *)&__last->tangent_in = v8;
    *(_QWORD *)&__last->time = v9;
    ++__first;
  }
  return __first;
}
