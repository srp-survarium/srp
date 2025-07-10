const vostok::ai::sound_item **__cdecl stlp_std::priv::__unguarded_partition<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item *__pivot,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  while ( 1 )
  {
    while ( __comp(*__first, __pivot) )
      ++__first;
    for ( --__last; __comp(__pivot, *__last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<vostok::ai::sound_item const * *,vostok::ai::sound_item const * *>(
      (const vostok::ai::movement_target **)__first++,
      (const vostok::ai::movement_target **)__last);
  }
  return __first;
}
