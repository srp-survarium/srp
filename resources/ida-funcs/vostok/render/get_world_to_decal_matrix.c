vostok::math::float4x4 *__cdecl vostok::render::get_world_to_decal_matrix(
        vostok::math::float4x4 *result,
        vostok::render::decal_instance *decal)
{
  float v2; // xmm3_4
  unsigned int v3; // xmm4_4
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float4x4 v6; // [esp+1Ch] [ebp-128h] BYREF
  vostok::math::float4x4 v7; // [esp+5Ch] [ebp-E8h] BYREF
  vostok::math::float4x4 v8; // [esp+9Ch] [ebp-A8h] BYREF
  vostok::math::float4x4 v9; // [esp+DCh] [ebp-68h] BYREF
  vostok::math::float3 width_height_far_distance; // [esp+11Ch] [ebp-28h]
  unsigned int v11; // [esp+128h] [ebp-1Ch]
  vostok::math::float3 v12; // [esp+12Ch] [ebp-18h] BYREF
  vostok::math::float3 scale; // [esp+138h] [ebp-Ch] BYREF

  qmemcpy(&v9, &decal->m_properties, sizeof(v9));
  scale.x = s_bm_current_air_resistance;
  scale.y = s_bm_current_air_resistance;
  scale.z = s_bm_current_air_resistance;
  vostok::math::float4x4::set_scale(&v9, &scale);
  width_height_far_distance = decal->m_properties.width_height_far_distance;
  *(_QWORD *)&scale.x = 0;
  scale.z = s_bm_current_air_resistance;
  vostok::math::normalize_safe((const vostok::math::float3_pod *)&v9.lines[2], &scale, &v12);
  v2 = v12.z * 0.0;
  *(float *)&v3 = v9.c.x - (float)((float)(v12.x * 0.0) * width_height_far_distance.z);
  v12.x = v9.c.y - (float)((float)(v12.y * 0.0) * width_height_far_distance.z);
  v12.z = v9.c.w;
  v11 = v3;
  v12.y = v9.c.z - (float)(v2 * width_height_far_distance.z);
  *(_QWORD *)&v9.lines[3].x = __PAIR64__(LODWORD(v12.x), v3);
  v9.c.z = v12.y;
  vostok::math::create_orthographic_projection(
    (int)&v7,
    width_height_far_distance.z,
    (vostok::math *)LODWORD(width_height_far_distance.x),
    (struct vostok::math::float4x4 *)LODWORD(width_height_far_distance.y),
    0.0099999998);
  qmemcpy(&v8, vostok::math::float4x4::identity(v4, &v6), sizeof(v8));
  vostok::math::float4x4::try_invert(&v9, &v8);
  vostok::math::mul4x3(&v7, &v8, result);
  return result;
}
