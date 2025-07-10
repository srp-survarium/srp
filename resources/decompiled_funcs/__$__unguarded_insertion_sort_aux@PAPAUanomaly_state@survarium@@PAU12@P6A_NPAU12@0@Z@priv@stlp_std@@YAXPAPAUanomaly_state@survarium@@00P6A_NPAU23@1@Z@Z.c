void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  while ( __first != __last )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __first,
      *__first,
      __comp);
    ++__first;
  }
}
