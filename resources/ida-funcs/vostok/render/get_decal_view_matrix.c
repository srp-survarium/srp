vostok::math::float4x4 *__cdecl vostok::render::get_decal_view_matrix(
        vostok::math::float4x4 *result,
        vostok::render::decal_instance *decal)
{
  float v2; // xmm3_4
  float v3; // xmm5_4
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float4x4 v6; // [esp+4h] [ebp-A8h] BYREF
  vostok::math::float4x4 v7; // [esp+44h] [ebp-68h] BYREF
  vostok::math::float3 v8; // [esp+84h] [ebp-28h] BYREF
  float v9; // [esp+90h] [ebp-1Ch]
  vostok::math::float3 width_height_far_distance; // [esp+94h] [ebp-18h]
  vostok::math::float3 scale; // [esp+A0h] [ebp-Ch] BYREF

  qmemcpy(&v7, &decal->m_properties, sizeof(v7));
  scale.x = s_bm_current_air_resistance;
  scale.y = s_bm_current_air_resistance;
  scale.z = s_bm_current_air_resistance;
  vostok::math::float4x4::set_scale(&v7, &scale);
  width_height_far_distance = decal->m_properties.width_height_far_distance;
  *(_QWORD *)&scale.x = 0;
  scale.z = s_bm_current_air_resistance;
  vostok::math::normalize_safe((const vostok::math::float3_pod *)&v7.lines[2], &scale, &v8);
  v2 = width_height_far_distance.z * (float)(v8.z * 0.0);
  v3 = width_height_far_distance.z * (float)(v8.y * 0.0);
  v9 = v7.c.x - (float)(width_height_far_distance.z * (float)(v8.x * 0.0));
  width_height_far_distance.z = v7.c.w;
  width_height_far_distance.x = v7.c.y - v3;
  width_height_far_distance.y = v7.c.z - v2;
  v7.c.x = v9;
  v7.c.y = v7.c.y - v3;
  v7.c.z = v7.c.z - v2;
  qmemcpy(result, vostok::math::float4x4::identity(v4, &v6), sizeof(vostok::math::float4x4));
  vostok::math::float4x4::try_invert(&v7, result);
  return result;
}
