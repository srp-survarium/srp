bool __thiscall vostok::collision::sphere_geometry_instance::ray_test(
        vostok::collision::sphere_geometry_instance *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  long double v10; // st7
  float v11; // xmm0_4
  float projection_squared_length; // [esp+8h] [ebp+4h]
  float projection_squared_lengtha; // [esp+8h] [ebp+4h]
  float squared_distance; // [esp+Ch] [ebp+8h]

  v5 = this->m_matrix.c.x - origin->x;
  v6 = this->m_matrix.c.y - origin->y;
  v7 = this->m_matrix.c.z - origin->z;
  v8 = (float)((float)(direction->z * v7) + (float)(direction->y * v6)) + (float)(direction->x * v5);
  squared_distance = (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v5 * v5)) - (float)(v8 * v8);
  if ( squared_distance > *(float *)&clear_value )
    return 0;
  projection_squared_length = sqrtf(v8 * v8);
  v10 = projection_squared_length - sqrtf(*(float *)&clear_value - squared_distance);
  if ( v10 <= 0.0 )
  {
    v11 = 0.0;
  }
  else
  {
    projection_squared_lengtha = v10;
    v11 = projection_squared_lengtha;
  }
  *distance = v11;
  return max_distance >= v11;
}
