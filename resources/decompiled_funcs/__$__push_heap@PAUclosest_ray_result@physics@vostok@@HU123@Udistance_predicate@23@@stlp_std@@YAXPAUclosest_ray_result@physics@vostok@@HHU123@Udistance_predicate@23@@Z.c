void __usercall stlp_std::__push_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<edi>,
        int __holeIndex@<eax>,
        int __topIndex,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  int v5; // esi
  int i; // eax
  vostok::physics::closest_ray_result *v7; // ecx
  vostok::physics::closest_ray_result *v8; // edx

  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex; i = (i - 1) / 2 )
  {
    v7 = &__first[i];
    if ( (float)((float)((float)((float)(__val.hit_point_world.z - __comp.m_from.z)
                               * (float)(__val.hit_point_world.z - __comp.m_from.z))
                       + (float)((float)(__val.hit_point_world.y - __comp.m_from.y)
                               * (float)(__val.hit_point_world.y - __comp.m_from.y)))
               + (float)((float)(__val.hit_point_world.x - __comp.m_from.x)
                       * (float)(__val.hit_point_world.x - __comp.m_from.x))) <= (float)((float)((float)((float)(v7->hit_point_world.z - __comp.m_from.z) * (float)(v7->hit_point_world.z - __comp.m_from.z))
                                                                                               + (float)((float)(v7->hit_point_world.x - __comp.m_from.x) * (float)(v7->hit_point_world.x - __comp.m_from.x)))
                                                                                       + (float)((float)(v7->hit_point_world.y - __comp.m_from.y)
                                                                                               * (float)(v7->hit_point_world.y - __comp.m_from.y))) )
      break;
    *(_QWORD *)&__first[v5].object = *(_QWORD *)&v7->object;
    v8 = &__first[v5];
    *(_QWORD *)&v8->hit_point_world.elements[1] = *(_QWORD *)&v7->hit_point_world.elements[1];
    *(_QWORD *)&v8->hit_normal_world.x = *(_QWORD *)&v7->hit_normal_world.x;
    v5 = i;
    *(_QWORD *)&v8->hit_normal_world.elements[2] = *(_QWORD *)&v7->hit_normal_world.elements[2];
    *(_QWORD *)&v8->is_shape_index = *(_QWORD *)&v7->is_shape_index;
  }
  __first[v5] = __val;
}
