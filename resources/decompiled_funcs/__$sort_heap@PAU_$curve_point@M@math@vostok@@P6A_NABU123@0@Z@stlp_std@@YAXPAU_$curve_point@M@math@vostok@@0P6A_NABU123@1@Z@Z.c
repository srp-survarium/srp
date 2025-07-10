void __usercall stlp_std::sort_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first@<edi>,
        vostok::math::curve_point<float> *__last@<eax>,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *v3; // esi

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        v3,
        v3,
        __first,
        *v3,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 24 - (int)__first) / 24 > 1 );
  }
}
