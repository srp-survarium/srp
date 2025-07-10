void __usercall stlp_std::priv::__partial_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        vostok::resources::query_result **__first@<eax>,
        vostok::resources::query_result **__middle,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal)
{
  vostok::resources::query_result **v4; // ebx
  int v6; // ebp
  vostok::resources::query_result *v7; // [esp-8h] [ebp-20h]
  vostok::resources::query_result *v8; // [esp+0h] [ebp-18h]

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::resources::query_result * *,vostok::resources::hdd_manager_sorting_predicate,vostok::resources::query_result *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      if ( vostok::resources::hdd_manager_sorting_predicate::operator()(
             *v4,
             (vostok::resources::hdd_manager_sorting_predicate *)*__first,
             v8) )
      {
        v7 = *v4;
        *v4 = *__first;
        stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
          __first,
          0,
          v6,
          v7,
          (vostok::resources::hdd_manager_sorting_predicate)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<vostok::resources::query_result * *,vostok::resources::hdd_manager_sorting_predicate>(
    __first,
    __middle,
    (vostok::resources::hdd_manager_sorting_predicate)__formal);
}
