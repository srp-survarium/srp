// local variable allocation has failed, the output may be wrong!
vostok::math::float4x4 *__cdecl vostok::render::get_decal_view_matrix(
        vostok::math::float4x4 *result,
        vostok::render::decal_instance *decal)
{
  float z; // eax
  vostok::math::float3 v4; // [esp+0h] [ebp-ACh] BYREF
  vostok::math::float4_pod scale; // [esp+Ch] [ebp-A0h] OVERLAPPED
  vostok::math::float3 decal_direction; // [esp+1Ch] [ebp-90h] BYREF
  vostok::math::float4x4 decal_world_matrix; // [esp+28h] [ebp-84h] BYREF
  vostok::math::float4x4 v8; // [esp+68h] [ebp-44h] BYREF

  qmemcpy((void *)&decal_world_matrix, &decal->m_properties, sizeof(decal_world_matrix));
  LODWORD(v4.x) = clear_value;
  LODWORD(v4.y) = clear_value;
  LODWORD(v4.z) = clear_value;
  vostok::math::float4x4::set_scale(&decal_world_matrix, &v4);
  z = decal->m_properties.width_height_far_distance.z;
  *(_QWORD *)&scale.x = *(_QWORD *)&decal->m_properties.width_height_far_distance.x;
  *(_QWORD *)&v4.x = 0;
  scale.z = z;
  LODWORD(v4.z) = clear_value;
  vostok::math::normalize_safe((const vostok::math::float3_pod *)&decal_world_matrix.lines[2], &decal_direction, &v4);
  scale.w = decal_world_matrix.c.w;
  scale.x = decal_world_matrix.c.x - (float)(scale.z * decal_direction.x);
  scale.y = decal_world_matrix.c.y - (float)(scale.z * decal_direction.y);
  scale.z = decal_world_matrix.c.z - (float)(scale.z * decal_direction.z);
  decal_world_matrix.c = scale;
  qmemcpy((void *)result, vostok::math::float4x4::identity(&v8), sizeof(vostok::math::float4x4));
  vostok::math::float4x4::try_invert(result, &decal_world_matrix);
  return result;
}
