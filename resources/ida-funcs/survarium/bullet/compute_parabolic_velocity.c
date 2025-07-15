vostok::math::float3 *__userpurge survarium::bullet::compute_parabolic_velocity@<eax>(
        const vostok::math::float3 *gravity@<edx>,
        vostok::math::float3 *result@<eax>,
        survarium::bullet *this,
        float time)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  if ( fabs(
         (float)(this->m_start_velocity.z * this->m_start_velocity.z)
       + (float)(this->m_start_velocity.x * this->m_start_velocity.x)) >= 0.0000099999997 )
  {
    v7 = 0.0;
    v8 = this->m_air_resistance * time;
    if ( (float)(s_bm_current_air_resistance - v8) >= 0.0 )
      v7 = s_bm_current_air_resistance - v8;
    v9 = (float)(this->m_start_velocity.y * v7) + (float)(gravity->y * time);
    v10 = (float)(this->m_start_velocity.z * v7) + (float)(gravity->z * time);
    result->x = (float)(this->m_start_velocity.x * v7) + (float)(gravity->x * time);
    result->y = v9;
    result->z = v10;
  }
  else
  {
    v4 = gravity->z * time;
    v5 = this->m_start_velocity.x + (float)(gravity->x * time);
    result->y = this->m_start_velocity.y + (float)(gravity->y * time);
    v6 = this->m_start_velocity.z + v4;
    result->x = v5;
    result->z = v6;
  }
  return result;
}
