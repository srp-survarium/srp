void __thiscall survarium::weapon_dispersion_calculator::tick(
        survarium::weapon_dispersion_calculator *this,
        unsigned int current_time_in_ms)
{
  float v2; // xmm2_4
  float m_target_coeff; // xmm0_4
  float v4; // xmm0_4
  float dt; // [esp+14h] [ebp-4h]

  if ( this->m_current_time )
  {
    if ( this->m_current_time < current_time_in_ms )
    {
      dt = (double)(current_time_in_ms - this->m_current_time) * 0.001;
      this->m_current_time = current_time_in_ms;
      v2 = this->m_target_coeff - (float)(this->m_aiming_speed * dt);
      vostok::math::max();
      this->m_target_coeff = v2;
      if ( dt != 0.0 && this->m_current_coeff != this->m_target_coeff )
      {
        if ( this->m_current_coeff <= this->m_target_coeff )
        {
          if ( this->m_target_coeff > this->m_current_coeff )
          {
            v4 = (float)(this->m_growth_speed * dt) + this->m_current_coeff;
            vostok::math::min();
            this->m_current_coeff = v4;
          }
        }
        else
        {
          m_target_coeff = this->m_target_coeff;
          vostok::math::max();
          this->m_current_coeff = m_target_coeff;
        }
      }
    }
  }
  else
  {
    this->m_current_time = current_time_in_ms;
  }
}
