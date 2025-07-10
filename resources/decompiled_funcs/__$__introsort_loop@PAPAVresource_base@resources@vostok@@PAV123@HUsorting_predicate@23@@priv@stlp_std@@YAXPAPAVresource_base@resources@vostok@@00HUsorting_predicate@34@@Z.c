void __usercall stlp_std::priv::__introsort_loop<vostok::resources::resource_base * *,vostok::resources::resource_base *,int,vostok::resources::sorting_predicate>(
        vostok::resources::sorting_predicate a1@<dil>,
        vostok::resources::resource_base **__first,
        vostok::resources::resource_base **__last,
        vostok::resources::resource_base **__formal,
        int __depth_limit,
        vostok::resources::resource_base **__comp)
{
  vostok::resources::resource_base **v6; // ebx
  vostok::resources::resource_base **v7; // eax
  vostok::resources::resource_base **v8; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (vostok::resources::resource_base **)stlp_std::priv::__median<vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
                                                  __first,
                                                  &__first[(v6 - __first) / 2],
                                                  v6 - 1,
                                                  (vostok::resources::sorting_predicate)__comp);
      v8 = stlp_std::priv::__unguarded_partition<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
             __first,
             v6,
             *v7,
             (vostok::resources::sorting_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::resources::resource_base * *,vostok::resources::resource_base *,int,vostok::resources::sorting_predicate>(
        v8,
        v6,
        0,
        __depth_limit,
        (vostok::resources::sorting_predicate)__comp);
      v6 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      v6,
      v6,
      __comp,
      a1);
  }
}
