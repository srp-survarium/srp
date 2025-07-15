void __thiscall survarium::player_stamina::increase_value(survarium::player_stamina *this, float amount)
{
  __int128 m_value_low; // xmm1

  m_value_low = LODWORD(this->m_value);
  *(float *)&m_value_low = *(float *)&m_value_low + amount;
  LODWORD(this->m_value) = vostok::math::clamp_r<float>(
                             (__m128)*(unsigned int *)&FLOAT_0_0,
                             m_value_low,
                             this->m_max_value * this->m_max_value_factor).m128_u32[0];
  if ( this->m_value > this->m_spending_threshold )
    this->m_lower_threshold_was_reached = 0;
}
