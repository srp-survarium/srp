float __usercall survarium::weapon_core::horizontal_recoil_value@<xmm0>(
        survarium::weapon_core *this@<esi>,
        unsigned int current_time_in_ms@<edx>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4

  LODWORD(v3) = survarium::weapon_recoil_calculator::get_side_value_impl(
                  &this->m_recoil_calculator.m_weapon_calculator,
                  current_time_in_ms,
                  this->m_recoil_calculator.m_weapon_calculator.m_horizontal_target,
                  this->m_recoil_calculator.m_weapon_calculator.m_horizontal_value_at_last_shoot).m128_u32[0];
  if ( this->m_aimed )
    v3 = v3 + this->m_breath_vibration_calculator.m_vibration.x;
  v4 = epsilon - 0.5;
  if ( (float)(epsilon - 0.5) < v3 )
  {
    if ( (float)(0.5 - epsilon) < v3 )
      v4 = 0.5 - epsilon;
    else
      v4 = v3;
  }
  return 0.5 - v4;
}
