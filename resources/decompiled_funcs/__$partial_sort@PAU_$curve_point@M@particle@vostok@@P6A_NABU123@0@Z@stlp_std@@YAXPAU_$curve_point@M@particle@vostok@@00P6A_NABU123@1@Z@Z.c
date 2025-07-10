void __cdecl stlp_std::partial_sort<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__middle,
        vostok::particle::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  stlp_std::priv::__partial_sort<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
    __first,
    __middle,
    __last,
    0,
    __comp);
}
