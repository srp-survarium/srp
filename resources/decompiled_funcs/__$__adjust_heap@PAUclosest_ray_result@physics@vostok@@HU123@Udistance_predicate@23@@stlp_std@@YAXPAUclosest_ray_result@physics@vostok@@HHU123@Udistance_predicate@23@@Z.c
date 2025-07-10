void __usercall stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<ecx>,
        int __holeIndex@<eax>,
        int __len@<esi>,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  int v6; // ecx
  bool v7; // zf
  int v8; // ebx
  float z; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  vostok::physics::closest_ray_result *v16; // edx
  int v17; // eax
  vostok::physics::closest_ray_result *v18; // eax
  vostok::physics::closest_ray_result *v19; // edx
  int v20; // eax
  vostok::physics::closest_ray_result *v21; // eax

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  v8 = __holeIndex;
  if ( v6 < __len )
  {
    z = __comp.m_from.z;
    do
    {
      v10 = __first[v6].hit_point_world.x - __comp.m_from.x;
      v11 = __first[v6].hit_point_world.z - z;
      v12 = v11 * v11;
      v13 = v10 * v10;
      v14 = __first[v6 - 1].hit_point_world.x - __comp.m_from.x;
      v15 = __first[v6].hit_point_world.y - __comp.m_from.y;
      if ( (float)((float)((float)((float)(__first[v6 - 1].hit_point_world.z - z)
                                 * (float)(__first[v6 - 1].hit_point_world.z - z))
                         + (float)((float)(__first[v6 - 1].hit_point_world.y - __comp.m_from.y)
                                 * (float)(__first[v6 - 1].hit_point_world.y - __comp.m_from.y)))
                 + (float)(v14 * v14)) > (float)((float)(v12 + v13) + (float)(v15 * v15)) )
        --v6;
      v16 = &__first[v6];
      v17 = __holeIndex;
      *(_QWORD *)&__first[v17].object = *(_QWORD *)&v16->object;
      v18 = &__first[v17];
      *(_QWORD *)&v18->hit_point_world.elements[1] = *(_QWORD *)&v16->hit_point_world.elements[1];
      *(_QWORD *)&v18->hit_normal_world.x = *(_QWORD *)&v16->hit_normal_world.x;
      *(_QWORD *)&v18->hit_normal_world.elements[2] = *(_QWORD *)&v16->hit_normal_world.elements[2];
      *(_QWORD *)&v18->is_shape_index = *(_QWORD *)&v16->is_shape_index;
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
    }
    while ( v6 < __len );
  }
  if ( v7 )
  {
    v19 = &__first[v6 - 1];
    v20 = __holeIndex;
    *(_QWORD *)&__first[v20].object = *(_QWORD *)&v19->object;
    v21 = &__first[v20];
    *(_QWORD *)&v21->hit_point_world.elements[1] = *(_QWORD *)&v19->hit_point_world.elements[1];
    *(_QWORD *)&v21->hit_normal_world.x = *(_QWORD *)&v19->hit_normal_world.x;
    *(_QWORD *)&v21->hit_normal_world.elements[2] = *(_QWORD *)&v19->hit_normal_world.elements[2];
    *(_QWORD *)&v21->is_shape_index = *(_QWORD *)&v19->is_shape_index;
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
    __first,
    __holeIndex,
    v8,
    __val,
    __comp);
}
