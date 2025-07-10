void __usercall stlp_std::priv::__linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first@<edi>,
        vostok::math::curve_point<float> *__last@<eax>,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  bool (__cdecl *v4)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // ebx

  v4 = __comp;
  if ( ((unsigned __int8 (__cdecl *)(vostok::math::curve_point<float> *))__comp)(&__val) )
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)&__first[1], (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
  else
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __last,
      __val,
      v4);
  }
}
