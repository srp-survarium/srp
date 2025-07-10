void __cdecl stlp_std::priv::__introsort_loop<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,int,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first,
        vostok::physics::closest_ray_result *__last,
        vostok::physics::closest_ray_result *__formal,
        int __depth_limit,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::closest_ray_result *v5; // edi
  vostok::physics::closest_ray_result *v7; // eax
  vostok::physics::closest_ray_result *v8; // esi
  __int128 v9; // [esp-Ch] [ebp-1Ch]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    while ( 1 )
    {
      *(_QWORD *)&v9 = *(_QWORD *)&__comp.m_from.x;
      if ( !__depth_limit )
        break;
      DWORD2(v9) = LODWORD(__comp.m_from.z);
      --__depth_limit;
      v7 = (vostok::physics::closest_ray_result *)stlp_std::priv::__median<vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
                                                    __first,
                                                    &__first[(v5 - __first) / 2],
                                                    v5 - 1,
                                                    (vostok::physics::distance_predicate)v9);
      v8 = stlp_std::priv::__unguarded_partition<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
             __first,
             v5,
             *v7,
             __comp);
      stlp_std::priv::__introsort_loop<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,int,vostok::physics::distance_predicate>(
        v8,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v8;
      if ( v8 - __first <= 16 )
        return;
    }
    DWORD2(v9) = LODWORD(__comp.m_from.z);
    stlp_std::priv::__partial_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      v5,
      v5,
      (vostok::physics::closest_ray_result *)LODWORD(__comp.m_from.x),
      *(vostok::physics::distance_predicate *)((char *)&v9 + 4));
  }
}
