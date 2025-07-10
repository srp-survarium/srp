void __cdecl stlp_std::make_heap<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__first,
        const vostok::ai::movement_target **__last,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  int __holeIndex; // [esp+0h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::ai::movement_target const * *,int,vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}
