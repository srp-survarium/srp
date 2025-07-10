void __cdecl stlp_std::priv::__insertion_sort<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item *__val; // [esp+0h] [ebp-14h]
  const vostok::ai::sound_item **__i; // [esp+10h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      __val = *__i;
      if ( __comp(*__i, *__first) )
      {
        stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__i,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)(__i + 1));
        *__first = __val;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
          __i,
          __val,
          __comp);
      }
    }
  }
}
