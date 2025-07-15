vostok::sound::propagator_info *__cdecl stlp_std::copy_backward<vostok::sound::propagator_info *,vostok::sound::propagator_info *>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__result)
{
  int v3; // eax

  if ( (char *)__last - (char *)__first <= 0 )
    return __result;
  memmove(
    (unsigned __int8 *)__result - ((char *)__last - (char *)__first),
    (unsigned __int8 *)__first,
    (char *)__last - (char *)__first);
  return (vostok::sound::propagator_info *)v3;
}


void __cdecl stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__first,
        vostok::particle::curve_point<vostok::math::float4_pod> *__last,
        vostok::particle::curve_point<vostok::math::float4_pod> *__result)
{
  stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, __last, (char *)__result);
}
