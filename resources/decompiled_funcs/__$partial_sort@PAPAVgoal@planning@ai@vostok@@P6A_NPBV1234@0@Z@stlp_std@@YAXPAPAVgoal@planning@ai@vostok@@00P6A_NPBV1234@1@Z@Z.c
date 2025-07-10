void __cdecl stlp_std::partial_sort<vostok::ai::planning::goal * *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__middle,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  stlp_std::priv::__partial_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
    __first,
    __middle,
    __last,
    0,
    __comp);
}
