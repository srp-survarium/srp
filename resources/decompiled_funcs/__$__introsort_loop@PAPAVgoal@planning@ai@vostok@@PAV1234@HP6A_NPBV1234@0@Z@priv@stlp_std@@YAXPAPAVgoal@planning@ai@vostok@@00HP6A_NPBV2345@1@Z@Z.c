void __cdecl stlp_std::priv::__introsort_loop<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,int,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item **v5; // eax
  const vostok::ai::sound_item **__cut; // [esp+0h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::ai::planning::goal * *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v5 = (const vostok::ai::sound_item **)stlp_std::priv::__median<survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
                                            __first,
                                            &__first[(__last - __first) / 2],
                                            __last - 1,
                                            __comp);
    __cut = stlp_std::priv::__unguarded_partition<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
              __first,
              __last,
              *v5,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,int,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}
