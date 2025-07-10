float __usercall stlp_std::priv::__unguarded_partition<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>@<xmm0>(
        vostok::physics::closest_ray_result *__first@<eax>,
        vostok::physics::closest_ray_result *__last@<ecx>,
        vostok::physics::closest_ray_result __pivot,
        vostok::physics::distance_predicate __comp)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm3_4
  float *i; // edx
  float *j; // edx
  float result; // xmm0_4
  __int64 v11; // xmm0_8
  __int64 v12; // xmm1_8
  __int64 v13; // xmm3_8
  __int64 v14; // xmm2_8
  __int64 v15; // [esp+30h] [ebp-8h]

  v4 = __pivot.hit_point_world.x - __comp.m_from.x;
  v5 = __pivot.hit_point_world.y - __comp.m_from.y;
  v6 = __pivot.hit_point_world.z - __comp.m_from.z;
  while ( 1 )
  {
    v7 = (float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v4 * v4);
    for ( i = &__first->hit_point_world.z;
          v7 > (float)((float)((float)((float)(*i - __comp.m_from.z) * (float)(*i - __comp.m_from.z))
                             + (float)((float)(*(i - 1) - __comp.m_from.y) * (float)(*(i - 1) - __comp.m_from.y)))
                     + (float)((float)(*(i - 2) - __comp.m_from.x) * (float)(*(i - 2) - __comp.m_from.x)));
          i += 10 )
    {
      ++__first;
    }
    --__last;
    for ( j = &__last->hit_point_world.z; ; j -= 10 )
    {
      result = *(j - 2) - __comp.m_from.x;
      if ( (float)((float)((float)((float)(*j - __comp.m_from.z) * (float)(*j - __comp.m_from.z))
                         + (float)((float)(*(j - 1) - __comp.m_from.y) * (float)(*(j - 1) - __comp.m_from.y)))
                 + (float)(result * result)) <= (float)((float)((float)((float)(__pivot.hit_point_world.z
                                                                              - __comp.m_from.z)
                                                                      * (float)(__pivot.hit_point_world.z
                                                                              - __comp.m_from.z))
                                                              + (float)((float)(__pivot.hit_point_world.y
                                                                              - __comp.m_from.y)
                                                                      * (float)(__pivot.hit_point_world.y
                                                                              - __comp.m_from.y)))
                                                      + (float)((float)(__pivot.hit_point_world.x - __comp.m_from.x)
                                                              * (float)(__pivot.hit_point_world.x - __comp.m_from.x))) )
        break;
      --__last;
    }
    if ( __first >= __last )
      break;
    v11 = *(_QWORD *)&__first->object;
    v12 = *(_QWORD *)&__first->hit_point_world.elements[1];
    v13 = *(_QWORD *)&__first->hit_normal_world.elements[2];
    v14 = *(_QWORD *)&__first->hit_normal_world.x;
    v15 = *(_QWORD *)&__first->is_shape_index;
    *__first = *__last;
    *(_QWORD *)&__last->object = v11;
    *(_QWORD *)&__last->hit_point_world.elements[1] = v12;
    v5 = __pivot.hit_point_world.y - __comp.m_from.y;
    *(_QWORD *)&__last->hit_normal_world.x = v14;
    *(_QWORD *)&__last->hit_normal_world.elements[2] = v13;
    v6 = __pivot.hit_point_world.z - __comp.m_from.z;
    *(_QWORD *)&__last->is_shape_index = v15;
    v4 = __pivot.hit_point_world.x - __comp.m_from.x;
    ++__first;
  }
  return result;
}
