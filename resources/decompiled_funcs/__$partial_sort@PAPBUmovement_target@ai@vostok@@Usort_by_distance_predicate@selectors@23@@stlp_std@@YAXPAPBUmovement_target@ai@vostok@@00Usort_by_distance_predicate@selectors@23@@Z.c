void __cdecl stlp_std::partial_sort<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__first,
        const vostok::ai::movement_target **__middle,
        const vostok::ai::movement_target **__last,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  stlp_std::priv::__partial_sort<vostok::ai::movement_target const * *,vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>(
    __first,
    __middle,
    __last,
    0,
    __comp);
}
