void __thiscall survarium::body_part_parameters::increase_health(survarium::body_part_parameters *this, float amount)
{
  __int128 m_health_low; // xmm1

  m_health_low = LODWORD(this->m_health);
  *(float *)&m_health_low = *(float *)&m_health_low + amount;
  LODWORD(this->m_health) = vostok::math::clamp_r<float>(
                              (__m128)*(unsigned int *)&FLOAT_0_0,
                              m_health_low,
                              this->m_max_health).m128_u32[0];
}
