void __cdecl stlp_std::priv::__introsort_loop<vostok::render::grass_patch * *,vostok::render::grass_patch *,int,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first,
        vostok::render::grass_patch **__last,
        vostok::render::grass_patch **__formal,
        int __depth_limit,
        vostok::render::sort_grass_patch_predicate __comp)
{
  vostok::render::grass_patch **v5; // ebx
  vostok::render::grass_patch **v6; // eax
  vostok::render::grass_patch **v7; // esi
  __int128 v8; // [esp-Ch] [ebp-1Ch]

  v5 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( 1 )
    {
      *(vostok::render::sort_grass_patch_predicate *)&v8 = __comp;
      if ( !__depth_limit )
        break;
      --__depth_limit;
      v6 = (vostok::render::grass_patch **)stlp_std::priv::__median<vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
                                             __first,
                                             &__first[(v5 - __first) / 2],
                                             v5 - 1,
                                             __comp);
      v7 = stlp_std::priv::__unguarded_partition<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
             __first,
             v5,
             *v6,
             __comp);
      stlp_std::priv::__introsort_loop<vostok::render::grass_patch * *,vostok::render::grass_patch *,int,vostok::render::sort_grass_patch_predicate>(
        v7,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v7;
      if ( (int)(((char *)v7 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      v5,
      v5,
      (vostok::render::grass_patch **)LODWORD(__comp.m_view_pos.x),
      *(vostok::render::sort_grass_patch_predicate *)((char *)&v8 + 4));
  }
}
