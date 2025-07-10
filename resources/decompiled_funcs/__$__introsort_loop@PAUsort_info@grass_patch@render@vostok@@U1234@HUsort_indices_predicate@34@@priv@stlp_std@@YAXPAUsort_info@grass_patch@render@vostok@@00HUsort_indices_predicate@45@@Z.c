void __cdecl stlp_std::priv::__introsort_loop<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,int,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first,
        vostok::render::grass_patch::sort_info *__last,
        vostok::render::grass_patch::sort_info *__formal,
        int __depth_limit,
        vostok::render::sort_indices_predicate __comp)
{
  vostok::render::grass_patch::sort_info *v5; // edi
  vostok::render::grass_patch::sort_info *v7; // eax
  vostok::render::grass_patch::sort_info *v8; // esi
  _BYTE v9[20]; // [esp-10h] [ebp-20h]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    while ( 1 )
    {
      *(vostok::render::sort_indices_predicate *)v9 = __comp;
      if ( !__depth_limit )
        break;
      --__depth_limit;
      v7 = (vostok::render::grass_patch::sort_info *)stlp_std::priv::__median<vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
                                                       __first,
                                                       &__first[(v5 - __first) / 2],
                                                       v5 - 1,
                                                       __comp);
      v8 = stlp_std::priv::__unguarded_partition<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
             __first,
             v5,
             *v7,
             __comp);
      stlp_std::priv::__introsort_loop<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,int,vostok::render::sort_indices_predicate>(
        v8,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v8;
      if ( v8 - __first <= 16 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      v5,
      v5,
      (vostok::render::grass_patch::sort_info *)__comp.m_patch,
      *(vostok::render::sort_indices_predicate *)&v9[4]);
  }
}
