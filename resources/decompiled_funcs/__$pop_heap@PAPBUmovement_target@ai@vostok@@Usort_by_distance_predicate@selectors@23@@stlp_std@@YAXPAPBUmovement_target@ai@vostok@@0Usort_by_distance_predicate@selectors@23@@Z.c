void __cdecl stlp_std::pop_heap<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__first,
        const vostok::ai::movement_target **__last,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  const vostok::ai::movement_target *__val; // [esp+0h] [ebp-4h]

  __val = *(__last - 1);
  *(__last - 1) = *__first;
  stlp_std::__adjust_heap<vostok::ai::movement_target const * *,int,vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>(
    __first,
    0,
    __last - 1 - __first,
    __val,
    __comp);
}
