void __usercall stlp_std::priv::__partial_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<eax>,
        int *a2@<edi>,
        vostok::physics::closest_ray_result *__middle,
        vostok::physics::closest_ray_result *__last,
        __int64 __formal,
        float __comp_8)
{
  vostok::physics::closest_ray_result *v7; // esi
  float v8; // xmm6_4
  vostok::physics::distance_predicate v9; // [esp-18h] [ebp-28h]
  vostok::physics::distance_predicate v10; // [esp-18h] [ebp-28h]
  int *v11; // [esp-Ch] [ebp-1Ch]

  v11 = a2;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate,vostok::physics::closest_ray_result,int>(
      __first,
      __middle);
  v7 = __middle;
  if ( __middle < __last )
  {
    v8 = __comp_8;
    do
    {
      if ( (float)((float)((float)((float)(__first->hit_point_world.z - v8) * (float)(__first->hit_point_world.z - v8))
                         + (float)((float)(__first->hit_point_world.y - *((float *)&__formal + 1))
                                 * (float)(__first->hit_point_world.y - *((float *)&__formal + 1))))
                 + (float)((float)(__first->hit_point_world.x - *(float *)&__formal)
                         * (float)(__first->hit_point_world.x - *(float *)&__formal))) > (float)((float)((float)((float)(v7->hit_point_world.z - v8) * (float)(v7->hit_point_world.z - v8)) + (float)((float)(v7->hit_point_world.x - *(float *)&__formal) * (float)(v7->hit_point_world.x - *(float *)&__formal)))
                                                                                               + (float)((float)(v7->hit_point_world.y - *((float *)&__formal + 1)) * (float)(v7->hit_point_world.y - *((float *)&__formal + 1)))) )
      {
        *(_QWORD *)&v9.m_from.x = __formal;
        v9.m_from.z = __comp_8;
        stlp_std::__pop_heap<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate,int>(
          __first,
          __middle,
          v7,
          *v7,
          v9,
          v11);
        v8 = __comp_8;
      }
      ++v7;
    }
    while ( v7 < __last );
  }
  *(_QWORD *)&v10.m_from.x = __formal;
  v10.m_from.z = __comp_8;
  stlp_std::sort_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(__first, __middle, v10);
}
