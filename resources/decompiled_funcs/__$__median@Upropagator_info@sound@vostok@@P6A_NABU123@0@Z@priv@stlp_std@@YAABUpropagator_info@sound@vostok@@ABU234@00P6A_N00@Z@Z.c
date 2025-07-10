const vostok::sound::propagator_info *__cdecl stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        const vostok::sound::propagator_info *__a,
        const vostok::sound::propagator_info *__b,
        const vostok::sound::propagator_info *__c,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  if ( __comp(__a, __b) )
  {
    if ( __comp(__b, __c) )
    {
      return __b;
    }
    else if ( __comp(__a, __c) )
    {
      return __c;
    }
    else
    {
      return __a;
    }
  }
  else if ( __comp(__a, __c) )
  {
    return __a;
  }
  else if ( __comp(__b, __c) )
  {
    return __c;
  }
  else
  {
    return __b;
  }
}
