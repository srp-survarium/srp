void __thiscall vostok::math::curve_line_points<vostok::math::float4_pod,1>::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this,
        vostok::configs::binary_config_value keys_config,
        int keys_config_20)
{
  unsigned int v3; // esi
  vostok::math::curve_line_points<vostok::math::float4_pod,1> *pointer; // esi
  int v5; // ebp
  int v6; // ebx
  _QWORD *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  float v9; // xmm0_4
  vostok::math::curve_point<vostok::math::float4_pod> *v10; // edi
  unsigned int num_points; // eax
  unsigned int v12; // [esp-8h] [ebp-90h]
  vostok::fixed_string<8> key_name; // [esp+14h] [ebp-74h] BYREF
  vostok::configs::binary_config_value it; // [esp+28h] [ebp-60h] BYREF
  vostok::math::curve_point<vostok::math::float4_pod> point; // [esp+40h] [ebp-48h] BYREF

  v3 = 0;
  key_name.m_begin = key_name.m_buffer;
  key_name.m_end = key_name.m_buffer;
  key_name.m_max_end = (char *)&it;
  key_name.m_buffer[0] = 0;
  vostok::buffer_string::assignf(&key_name, "key%d", 0);
  while ( vostok::configs::binary_config_value::value_exists(
            (vostok::configs::binary_config_value *)((char *)&keys_config.data.max_storage + 4),
            key_name.m_begin) )
  {
    it = *vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)((char *)&keys_config.data.max_storage + 4),
            key_name.m_begin);
    if ( !(24 * HIWORD(*(_DWORD *)&it.type) / 24) )
      break;
    vostok::buffer_string::assignf(&key_name, "key%d", ++v3);
  }
  v12 = v3;
  pointer = (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)keys_config.data.pointer;
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::reserve(
    (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)keys_config.data.pointer,
    v12,
    1);
  v5 = 0;
  vostok::buffer_string::assignf(&key_name, "key%d", 0);
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)((char *)&keys_config.data.max_storage + 4),
         key_name.m_begin) )
  {
    v6 = 0;
    do
    {
      it = *vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)((char *)&keys_config.data.max_storage + 4),
              key_name.m_begin);
      if ( !(24 * HIWORD(*(_DWORD *)&it.type) / 24) )
        break;
      ++v5;
      v7 = vostok::configs::binary_config_value::operator[](&it, (const char *)&stru_955964)->data.pointer;
      *(_QWORD *)&point.upper_value.x = *v7;
      *(_QWORD *)&point.upper_value.elements[2] = v7[1];
      point.lower_value = *(vostok::math::float4_pod *)v7;
      v8 = vostok::configs::binary_config_value::operator[](&it, (const char *)&stru_955964.id_crc);
      v9 = v8->type == 2 ? *(float *)&v8->data.pointer : (float)(int)v8->data.pointer;
      v10 = &pointer->points.pointer[v6];
      point.time = v9;
      point.interp_type = linear_interp_type;
      qmemcpy(v10, &point, sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
      ++v6;
      vostok::buffer_string::assignf(&key_name, "key%d", v5);
      pointer = (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)keys_config.data.pointer;
    }
    while ( vostok::configs::binary_config_value::value_exists(
              (vostok::configs::binary_config_value *)((char *)&keys_config.data.max_storage + 4),
              key_name.m_begin) );
  }
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(pointer);
  num_points = pointer->num_points;
  if ( num_points )
    stlp_std::sort<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      pointer->points.pointer,
      &pointer->points.pointer[num_points],
      vostok::math::curve_line_points_vostok::math::float4_pod_1_::sort_points_by_time_::_5_::predicate::compare_63);
}
