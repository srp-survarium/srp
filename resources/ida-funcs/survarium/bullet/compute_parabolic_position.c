vostok::math::float3 *__userpurge survarium::bullet::compute_parabolic_position@<eax>(
        const vostok::math::float3 *gravity@<edx>,
        vostok::math::float3 *result@<eax>,
        survarium::bullet *this,
        float time)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm4_4

  if ( fabs(
         (float)(this->m_start_velocity.z * this->m_start_velocity.z)
       + (float)(this->m_start_velocity.x * this->m_start_velocity.x)) >= 0.0000099999997 )
  {
    LODWORD(v7) = LODWORD(this->m_air_resistance) ^ _mask__NegFloat_;
    v8 = (float)(time * time) * 0.5;
    v9 = (float)(this->m_start_velocity.x * v7) * v8;
    v10 = (float)((float)(this->m_start_position.z + (float)(this->m_start_velocity.z * time))
                + (float)((float)(this->m_start_velocity.z * v7) * v8))
        + (float)(gravity->z * v8);
    v11 = (float)((float)(this->m_start_position.y + (float)(this->m_start_velocity.y * time))
                + (float)((float)(this->m_start_velocity.y * v7) * v8))
        + (float)(gravity->y * v8);
    result->x = (float)((float)(this->m_start_position.x + (float)(this->m_start_velocity.x * time)) + v9)
              + (float)(gravity->x * v8);
    result->y = v11;
    result->z = v10;
  }
  else
  {
    v4 = (float)(time * time) * 0.5;
    v5 = (float)(this->m_start_position.y + (float)(this->m_start_velocity.y * time)) + (float)(gravity->y * v4);
    v6 = (float)(this->m_start_position.z + (float)(this->m_start_velocity.z * time)) + (float)(gravity->z * v4);
    result->x = (float)(this->m_start_position.x + (float)(this->m_start_velocity.x * time)) + (float)(gravity->x * v4);
    result->y = v5;
    result->z = v6;
  }
  return result;
}
