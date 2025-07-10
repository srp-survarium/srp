void __cdecl stlp_std::priv::__introsort_loop<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,int,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  const vostok::sound::propagator_info *v5; // eax
  vostok::particle::curve_point<float> v6; // [esp-1Ch] [ebp-38h]
  vostok::particle::curve_point<float> *__cut; // [esp+18h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v5 = stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
           (const vostok::sound::propagator_info *)__first,
           (const vostok::sound::propagator_info *)&__first[(__last - __first) / 2],
           (const vostok::sound::propagator_info *)&__last[-1],
           (bool (__cdecl *)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))__comp);
    *(_QWORD *)&v6.upper_value = *(_QWORD *)&v5->in_graph_position.x;
    *(_QWORD *)&v6.tangent_in = *(_QWORD *)&v5->in_graph_position.elements[2];
    *(_QWORD *)&v6.time = *(_QWORD *)&v5->prop;
    __cut = stlp_std::priv::__unguarded_partition<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
              __first,
              __last,
              v6,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,int,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}
