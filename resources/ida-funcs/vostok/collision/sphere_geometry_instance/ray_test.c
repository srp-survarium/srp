bool __thiscall vostok::collision::sphere_geometry_instance::ray_test(
        vostok::collision::sphere_geometry_instance *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm0_4

  v5 = this->m_matrix.c.x - origin->x;
  v6 = this->m_matrix.c.y - origin->y;
  v7 = this->m_matrix.c.z - origin->z;
  v8 = (float)((float)(direction->z * v7) + (float)(direction->y * v6)) + (float)(direction->x * v5);
  v9 = (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v5 * v5)) - (float)(v8 * v8);
  if ( v9 > s_bm_current_air_resistance )
    return 0;
  v11 = fsqrt(v8 * v8) - fsqrt(s_bm_current_air_resistance - v9);
  v12 = 0.0;
  if ( v11 > 0.0 )
    v12 = v11;
  *distance = v12;
  return max_distance >= v12;
}
