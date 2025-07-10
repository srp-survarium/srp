void __usercall stlp_std::__make_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate,vostok::physics::closest_ray_result,int>(
        vostok::physics::closest_ray_result *__last@<eax>,
        vostok::physics::closest_ray_result *__first,
        int a3)
{
  int v3; // esi
  int v4; // edi
  vostok::physics::closest_ray_result *v5; // ebx
  __int64 v6; // xmm0_8
  vostok::physics::closest_ray_result v7; // [esp-3Ch] [ebp-44h]
  vostok::physics::distance_predicate v8; // [esp-14h] [ebp-1Ch]
  vostok::physics::distance_predicate v9; // [esp-14h] [ebp-1Ch]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  *(_QWORD *)&v8.m_from.x = *(_QWORD *)a3;
  v8.m_from.z = *(float *)(a3 + 8);
  stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
    __first,
    v4,
    v3,
    *v5,
    v8);
  while ( v4 )
  {
    *(_QWORD *)&v9.m_from.x = *(_QWORD *)a3;
    v6 = *(_QWORD *)&v5[-1].object;
    v9.m_from.z = *(float *)(a3 + 8);
    --v5;
    *(_QWORD *)&v7.object = v6;
    *(_QWORD *)&v7.hit_point_world.elements[1] = *(_QWORD *)&v5->hit_point_world.elements[1];
    *(_QWORD *)&v7.hit_normal_world.x = *(_QWORD *)&v5->hit_normal_world.x;
    *(_QWORD *)&v7.hit_normal_world.elements[2] = *(_QWORD *)&v5->hit_normal_world.elements[2];
    --v4;
    *(_QWORD *)&v7.is_shape_index = *(_QWORD *)&v5->is_shape_index;
    stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      v4,
      v3,
      v7,
      v9);
  }
}
