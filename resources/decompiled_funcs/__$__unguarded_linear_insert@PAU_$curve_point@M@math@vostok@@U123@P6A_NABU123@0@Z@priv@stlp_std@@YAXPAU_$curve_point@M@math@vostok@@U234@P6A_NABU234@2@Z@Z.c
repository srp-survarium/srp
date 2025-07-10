void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  bool (__cdecl *v3)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // ebx
  vostok::math::curve_point<float> *v4; // edi
  vostok::math::curve_point<float> *i; // esi

  v3 = __comp;
  v4 = __last;
  for ( i = __last - 1; v3(&__val, i); --i )
  {
    *(_QWORD *)&v4->upper_value = *(_QWORD *)&i->upper_value;
    *(_QWORD *)&v4->tangent_in = *(_QWORD *)&i->tangent_in;
    *(_QWORD *)&v4->time = *(_QWORD *)&i->time;
    v4 = i;
  }
  *v4 = __val;
}
