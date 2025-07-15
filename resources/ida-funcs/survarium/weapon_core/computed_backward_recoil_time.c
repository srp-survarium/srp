double __userpurge survarium::weapon_core::computed_backward_recoil_time@<st0>(
        survarium::weapon_core *this@<ecx>,
        float a2@<xmm4>,
        const float animation_length,
        const float animation_time_before_time_scale_starts,
        const unsigned int time_scale_start_time_in_ms,
        const unsigned int current_time_in_ms,
        unsigned int target_time_in_ms,
        const float __formal)
{
  survarium::base_player *m_user; // eax
  float v11; // xmm0_4
  float v13; // [esp+14h] [ebp-4h]

  m_user = this->m_user;
  if ( !m_user || !m_user->m_is_alive )
    return 0.0;
  if ( this->m_aimed )
    survarium::breath_vibration_calculator::tick(
      (survarium::breath_vibration_calculator *)this,
      (int)&this->m_breath_vibration_calculator,
      a2,
      this->m_dispersion_calculator.m_weapon_dispersion.m_current_value
    + this->m_dispersion_calculator.m_character_dispersion.m_current_value,
      target_time_in_ms - current_time_in_ms);
  v11 = survarium::weapon_recoil_calculator::get_back_value(
          &this->m_recoil_calculator.m_weapon_calculator,
          target_time_in_ms).m128_f32[0];
  if ( epsilon < v11 )
  {
    if ( (float)(s_bm_current_air_resistance - epsilon) < v11 )
      v13 = s_bm_current_air_resistance - epsilon;
    else
      v13 = v11;
  }
  else
  {
    v13 = epsilon;
  }
  return v13 * animation_length;
}
