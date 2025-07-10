BOOL __thiscall vostok::collision::capsule_geometry_instance::ray_test(
        vostok::collision::capsule_geometry_instance *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  float m_half_length; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float x; // xmm1_4
  float v10; // xmm0_4
  float y; // xmm2_4
  float v12; // xmm0_4
  float z; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  vostok::math::float3 p4; // [esp+8h] [ebp-24h] BYREF
  vostok::math::float3 p3; // [esp+14h] [ebp-18h] BYREF
  vostok::math::float3 p2; // [esp+20h] [ebp-Ch] BYREF

  m_half_length = this->m_half_length;
  v7 = this->m_matrix.j.z * m_half_length;
  v8 = this->m_matrix.j.y * m_half_length;
  x = this->m_matrix.j.x;
  p4.x = this->m_matrix.c.x + (float)(x * m_half_length);
  v10 = this->m_matrix.c.y + v8;
  y = this->m_matrix.j.y;
  p4.y = v10;
  v12 = this->m_matrix.c.z + v7;
  z = this->m_matrix.j.z;
  p4.z = v12;
  v14 = this->m_half_length;
  v15 = z * v14;
  v16 = y * v14;
  v17 = this->m_matrix.c.x - (float)(x * v14);
  v18 = direction->y;
  p3.x = v17;
  v19 = this->m_matrix.c.y - v16;
  v20 = direction->z;
  p3.y = v19;
  p3.z = this->m_matrix.c.z - v15;
  v21 = origin->x + (float)(direction->x * max_distance);
  p2.y = origin->y + (float)(v18 * max_distance);
  v22 = origin->z + (float)(v20 * max_distance);
  p2.x = v21;
  p2.z = v22;
  vostok::math::segment_to_segment_distance(origin, &p2, &p3, &p4);
  return this->m_radius >= v22;
}
