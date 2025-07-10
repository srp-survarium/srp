void __cdecl stlp_std::priv::__partial_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__middle,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item **i; // [esp+4h] [ebp-Ch]
  const vostok::ai::sound_item *__val; // [esp+8h] [ebp-8h]
  const vostok::ai::sound_item **__i; // [esp+Ch] [ebp-4h]

  stlp_std::make_heap<vostok::ai::planning::goal * *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(*__i, *__first) )
    {
      __val = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        __first,
        0,
        __middle - __first,
        __val,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
      __first,
      i,
      __comp);
}
