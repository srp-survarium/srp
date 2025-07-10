void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<eax>,
        vostok::physics::closest_ray_result *__last@<edi>,
        __int64 __formal,
        float __comp_8)
{
  vostok::physics::closest_ray_result *i; // esi
  vostok::physics::distance_predicate v5; // [esp-Ch] [ebp-10h]

  for ( i = __first; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_from.x = __formal;
    v5.m_from.z = __comp_8;
    stlp_std::priv::__unguarded_linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      i,
      *i,
      v5);
  }
}
