void __thiscall vostok::math::curve_line_points<vostok::math::float4_pod,1>::copy_from(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this,
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *allocator,
        const vostok::math::curve_line_points<vostok::math::float4_pod,1> *other)
{
  vostok::math::curve_line_points<vostok::math::float4_pod,1> *v4; // ecx
  int v5; // edx
  vostok::math::curve_line_points<vostok::math::float4_pod,1> *v6; // [esp-4h] [ebp-5Ch]
  _BYTE v7[72]; // [esp+10h] [ebp-48h] BYREF
  unsigned int i; // [esp+64h] [ebp+Ch]

  allocator->curve_time_min = other->curve_time_min;
  allocator->curve_time_max = other->curve_time_max;
  *(_QWORD *)&allocator->curve_value_min.x = *(_QWORD *)&other->curve_value_min.x;
  v6 = (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)vostok::render::g_allocator;
  *(_QWORD *)&allocator->curve_value_min.elements[2] = *(_QWORD *)&other->curve_value_min.elements[2];
  allocator->curve_value_max = other->curve_value_max;
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::allocate_memory(allocator, other->num_points, v6);
  v5 = 0;
  for ( i = 0; i < other->num_points; ++v5 )
  {
    qmemcpy(v7, &other->points.pointer[v5], sizeof(v7));
    ++i;
    qmemcpy(&allocator->points.pointer[v5], v7, sizeof(allocator->points.pointer[v5]));
    v4 = 0;
  }
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(v4, (int)allocator);
}
