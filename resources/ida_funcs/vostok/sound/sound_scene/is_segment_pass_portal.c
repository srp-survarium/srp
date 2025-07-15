bool __thiscall vostok::sound::sound_scene::is_segment_pass_portal(
        vostok::sound::sound_scene *this,
        unsigned int portal_id,
        vostok::math::float3 segment_start,
        vostok::math::float3 segment_end)
{
  const vostok::math::float3 *v4; // eax
  const vostok::math::float3 *v5; // eax
  bool v7; // [esp+Ch] [ebp-C4h]
  float v8; // [esp+20h] [ebp-B0h]
  float v9; // [esp+84h] [ebp-4Ch]
  vostok::math::float3 v10; // [esp+94h] [ebp-3Ch] BYREF
  vostok::math::float3 v11; // [esp+A0h] [ebp-30h] BYREF
  vostok::math::float3 v12; // [esp+ACh] [ebp-24h] BYREF
  vostok::math::float3 v13; // [esp+B8h] [ebp-18h] BYREF
  float result_b; // [esp+C4h] [ebp-Ch] BYREF
  const vostok::render::culling::portal *portal; // [esp+C8h] [ebp-8h]
  float result_a; // [esp+CCh] [ebp-4h] BYREF

  portal = &this->m_graph.m_object->m_portals.m_begin[portal_id];
  result_b = *(float *)&FLOAT_0_0;
  vostok::math::float3::float3(
    &v13,
    COERCE_UNSIGNED_INT(segment_end.x - segment_start.x),
    COERCE_UNSIGNED_INT(segment_end.y - segment_start.y),
    segment_end.z - segment_start.z);
  v9 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v13);
  vostok::math::float3::float3(
    &v12,
    COERCE_UNSIGNED_INT(segment_start.x - segment_end.x),
    COERCE_UNSIGNED_INT(segment_start.y - segment_end.y),
    segment_start.z - segment_end.z);
  v4 = vostok::math::float3_pod::normalize(&v12);
  v7 = 1;
  if ( !vostok::collision::test_triangle(
          portal->m_points,
          &portal->m_points[1],
          &portal->m_points[2],
          &segment_end,
          v4,
          fsqrt(v9),
          &result_a) )
  {
    vostok::math::float3::float3(
      &v11,
      COERCE_UNSIGNED_INT(segment_end.x - segment_start.x),
      COERCE_UNSIGNED_INT(segment_end.y - segment_start.y),
      segment_end.z - segment_start.z);
    v8 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v11);
    vostok::math::float3::float3(
      &v10,
      COERCE_UNSIGNED_INT(segment_start.x - segment_end.x),
      COERCE_UNSIGNED_INT(segment_start.y - segment_end.y),
      segment_start.z - segment_end.z);
    v5 = vostok::math::float3_pod::normalize(&v10);
    if ( !vostok::collision::test_triangle(
            portal->m_points,
            &portal->m_points[2],
            &portal->m_points[3],
            &segment_end,
            v5,
            fsqrt(v8),
            &result_b) )
      return 0;
  }
  return v7;
}
