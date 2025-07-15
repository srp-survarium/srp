// local variable allocation has failed, the output may be wrong!
vostok::math::float4x4 *__usercall vostok::render::get_world_to_decal_matrix@<eax>(
        float a1@<ebx>,
        float a2@<ebp>,
        float a3@<edi>,
        float a4@<esi>,
        vostok::math::float4x4 *result,
        vostok::render::decal_instance *decal)
{
  float z; // eax
  vostok::math::float3 scale; // [esp+18h] [ebp-12Ch] BYREF
  vostok::math::float4_pod decal_direction; // [esp+24h] [ebp-120h] OVERLAPPED BYREF
  vostok::math::float3_pod result_in_case_of_zero; // [esp+34h] [ebp-110h] BYREF
  vostok::math::float4x4 decal_world_matrix; // [esp+40h] [ebp-104h] BYREF
  vostok::math::float4x4 decal_view_matrix; // [esp+80h] [ebp-C4h] BYREF
  vostok::math::float4x4 decal_projection_matrix; // [esp+C0h] [ebp-84h] BYREF
  vostok::math::float4x4 v14; // [esp+100h] [ebp-44h] BYREF

  qmemcpy((void *)&decal_world_matrix, &decal->m_properties, sizeof(decal_world_matrix));
  LODWORD(scale.x) = clear_value;
  LODWORD(scale.y) = clear_value;
  LODWORD(scale.z) = clear_value;
  vostok::math::float4x4::set_scale(&decal_world_matrix, &scale);
  z = decal->m_properties.width_height_far_distance.z;
  *(_QWORD *)&scale.x = *(_QWORD *)&decal->m_properties.width_height_far_distance.x;
  *(_QWORD *)&result_in_case_of_zero.x = 0;
  scale.z = z;
  LODWORD(result_in_case_of_zero.z) = clear_value;
  vostok::math::normalize_safe(
    (const vostok::math::float3_pod *)&decal_world_matrix.lines[2],
    (vostok::math::float3 *)&decal_direction,
    (vostok::math::float3 *)&result_in_case_of_zero);
  decal_direction.y = decal_world_matrix.c.y - (float)(decal_direction.y * scale.z);
  decal_direction.z = decal_world_matrix.c.z - (float)(decal_direction.z * scale.z);
  decal_direction.w = decal_world_matrix.c.w;
  decal_direction.x = decal_world_matrix.c.x - (float)(decal_direction.x * scale.z);
  decal_world_matrix.c = decal_direction;
  vostok::math::create_orthographic_projection(
    COERCE_VOSTOK_MATH_(scale.x * 2.0),
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(scale.y * 2.0),
    a3,
    a4,
    a2,
    a1);
  qmemcpy((void *)&decal_view_matrix, vostok::math::float4x4::identity(&v14), sizeof(decal_view_matrix));
  vostok::math::float4x4::try_invert(&decal_view_matrix, &decal_world_matrix);
  vostok::math::mul4x3(result, &decal_view_matrix, &decal_projection_matrix);
  return result;
}
