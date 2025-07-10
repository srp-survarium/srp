void __cdecl stlp_std::sort<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__first,
        const vostok::ai::movement_target **__last,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::ai::movement_target const * *,vostok::ai::movement_target const *,int,vostok::ai::selectors::sort_by_distance_predicate>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
      __first,
      __last,
      __comp);
  }
}
