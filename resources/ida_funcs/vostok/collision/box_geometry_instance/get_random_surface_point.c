vostok::math::float3 *__thiscall vostok::collision::box_geometry_instance::get_random_surface_point(
        vostok::collision::box_geometry_instance *this,
        vostok::math::float3 *result,
        vostok::math::random32 *randomizer)
{
  unsigned int v3; // eax
  vostok::fixed_vector<float,6>::allign_helper *m_buffer; // ecx
  int v5; // edx
  int v6; // eax
  vostok::math::float2 v7; // xmm3_8
  float v8; // xmm0_4
  float v9; // xmm3_4
  int v10; // ecx
  stlp_std::pair<vostok::math::float3,vostok::math::float3> *v11; // eax
  double z; // st7
  float x; // xmm0_4
  double v14; // st7
  int v15; // edx
  double y; // st7
  int v17; // ecx
  float v18; // xmm0_4
  vostok::math::float3 *v20; // [esp-8h] [ebp-E0h]
  float *p_y; // [esp-4h] [ebp-DCh]
  vostok::math::float2 half_size; // [esp+Ch] [ebp-CCh] BYREF
  const vostok::math::float4x4 *v23; // [esp+14h] [ebp-C4h]
  vostok::math::float2 center; // [esp+18h] [ebp-C0h] BYREF
  int v25; // [esp+20h] [ebp-B8h]
  float random_area; // [esp+24h] [ebp-B4h] BYREF
  vostok::fixed_vector<float,6> box_planes; // [esp+28h] [ebp-B0h] BYREF
  stlp_std::pair<vostok::math::float3,vostok::math::float3> coords[6]; // [esp+48h] [ebp-90h] BYREF

  box_planes.m_begin = (float *)box_planes.m_buffer;
  v3 = 134775813 * randomizer->m_seed + 1;
  *(float *)box_planes.m_buffer = FLOAT_4_0;
  randomizer->m_seed = v3;
  box_planes.m_buffer[1] = (vostok::fixed_vector<float,6>::allign_helper)1090519040;
  box_planes.m_buffer[2] = (vostok::fixed_vector<float,6>::allign_helper)1094713344;
  box_planes.m_buffer[3] = (vostok::fixed_vector<float,6>::allign_helper)1098907648;
  box_planes.m_buffer[4] = (vostok::fixed_vector<float,6>::allign_helper)1101004800;
  LODWORD(half_size.x) = (unsigned __int64)v3 >> 12;
  box_planes.m_buffer[5] = (vostok::fixed_vector<float,6>::allign_helper)1103101952;
  box_planes.m_end = (float *)coords;
  m_buffer = box_planes.m_buffer;
  v5 = 6;
  random_area = (double)LODWORD(half_size.x) * 0.00000095367432 * 24.0;
  do
  {
    v6 = v5 >> 1;
    if ( random_area <= *(float *)&m_buffer[v5 >> 1] )
    {
      v5 >>= 1;
    }
    else
    {
      m_buffer += v6 + 1;
      v5 += -1 - v6;
    }
  }
  while ( v5 > 0 );
  half_size.x = -1.0;
  LODWORD(half_size.y) = clear_value;
  *(vostok::math::float2 *)&coords[0].first.x = half_size;
  *(_QWORD *)&coords[0].second.x = (unsigned int)clear_value | 0xBF80000000000000uLL;
  *(vostok::math::float2 *)&coords[1].first.x = half_size;
  *(_QWORD *)&coords[1].second.x = *(_QWORD *)&coords[0].second.x;
  half_size.x = -1.0;
  LODWORD(half_size.y) = clear_value;
  coords[0].first.z = -1.0;
  *(vostok::math::float2 *)&coords[2].first.x = half_size;
  coords[0].second.z = -1.0;
  LODWORD(coords[1].first.z) = clear_value;
  *(_QWORD *)&coords[2].second.x = 0xBF800000BF800000uLL;
  LODWORD(half_size.x) = clear_value;
  LODWORD(half_size.y) = clear_value;
  LODWORD(coords[1].second.z) = clear_value;
  *(vostok::math::float2 *)&coords[3].first.x = half_size;
  LODWORD(coords[2].first.z) = clear_value;
  half_size.x = -1.0;
  LODWORD(half_size.y) = clear_value;
  coords[2].second.z = -1.0;
  *(_QWORD *)&coords[3].second.x = *(_QWORD *)&coords[0].second.x;
  LODWORD(center.x) = clear_value;
  LODWORD(center.y) = clear_value;
  LODWORD(coords[3].first.z) = clear_value;
  v25 = -1082130432;
  *(vostok::math::float2 *)&coords[4].first.x = half_size;
  v7 = center;
  coords[3].second.z = -1.0;
  v23 = clear_value;
  center = *(vostok::math::float2 *)&coords[0].second.x;
  half_size = (vostok::math::float2)0xBF800000BF800000uLL;
  LODWORD(coords[4].first.z) = clear_value;
  *(vostok::math::float2 *)&coords[4].second.x = v7;
  coords[4].second.z = -1.0;
  *(_QWORD *)&coords[5].first.x = 0xBF800000BF800000uLL;
  LODWORD(coords[5].first.z) = clear_value;
  *(_QWORD *)&coords[5].second.x = *(_QWORD *)&coords[0].second.x;
  coords[5].second.z = -1.0;
  if ( m_buffer == box_planes.m_buffer )
    v8 = 0.0;
  else
    v8 = *(float *)&m_buffer[-1];
  v9 = *(float *)m_buffer;
  v10 = m_buffer - box_planes.m_buffer;
  random_area = (float)(random_area - v8) / (float)(v9 - v8);
  v11 = &coords[v10];
  switch ( v10 )
  {
    case 0:
    case 1:
      z = v11->first.z;
      center.x = v11->first.y;
      result->z = z;
      x = v11->first.x;
      LODWORD(half_size.x) = LODWORD(center.x) & 0x7FFFFFFF;
      LODWORD(center.x) = LODWORD(x) & 0x7FFFFFFF;
      center.y = half_size.x;
      half_size = 0;
      vostok::collision::random_point_inside_axis_aligned_rectangle(
        randomizer,
        &half_size,
        &center,
        &random_area,
        &result->x,
        &result->y);
      break;
    case 2:
    case 3:
      v14 = v11->first.x;
      half_size.x = v11->first.y;
      result->x = v14;
      v15 = LODWORD(half_size.x) & 0x7FFFFFFF;
      half_size.x = v11->first.z;
      LODWORD(center.x) = v15;
      p_y = &result->y;
      LODWORD(half_size.x) &= ~0x80000000;
      v20 = (vostok::math::float3 *)&result->elements[2];
      goto LABEL_13;
    case 4:
    case 5:
      y = v11->first.y;
      half_size.x = v11->first.z;
      result->y = y;
      v17 = LODWORD(half_size.x) & 0x7FFFFFFF;
      half_size.x = v11->first.x;
      p_y = &result->z;
      LODWORD(center.x) = v17;
      v20 = result;
      LODWORD(half_size.x) &= ~0x80000000;
LABEL_13:
      v18 = center.x;
      center = 0;
      half_size.y = v18;
      vostok::collision::random_point_inside_axis_aligned_rectangle(
        randomizer,
        &center,
        &half_size,
        &random_area,
        &v20->x,
        p_y);
      break;
    default:
      return result;
  }
  return result;
}
