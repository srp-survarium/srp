void __usercall stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        vostok::math::curve_point<float> *__last@<edx>,
        vostok::math::curve_point<float> *__result@<eax>,
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  unsigned int v5; // edx

  *__result = *__first;
  v5 = (int)((unsigned __int64)(715827883LL * ((char *)__last - (char *)__first)) >> 32) >> 2;
  stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}
