void __usercall stlp_std::priv::__insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<eax>,
        vostok::physics::closest_ray_result *__last,
        int a3)
{
  vostok::physics::closest_ray_result *i; // edi
  vostok::physics::distance_predicate v5; // [esp-Ch] [ebp-1Ch]

  for ( i = __first + 1; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_from.x = *(_QWORD *)a3;
    v5.m_from.z = *(float *)(a3 + 8);
    stlp_std::priv::__linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      i,
      *i,
      v5);
  }
}
