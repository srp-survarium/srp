void __thiscall survarium::breath_state_normal::tick(
        survarium::breath_state_normal *this,
        const float dispersion,
        const float dt)
{
  float *m_penalty_factor; // edx
  const survarium::character_breath_vibration_params *p_m_breath_vibration_params; // eax
  float v5; // xmm1_4
  float *m_speed_factor; // ecx
  float v7; // xmm0_4

  m_penalty_factor = this->m_penalty_factor;
  p_m_breath_vibration_params = &this->m_user->m_breath_vibration_params;
  v5 = *m_penalty_factor - (float)(dt / this->m_user->m_breath_vibration_params.time_to_recover_after_shortbreathing);
  if ( v5 <= 0.0 )
    v5 = 0.0;
  m_speed_factor = this->m_speed_factor;
  *m_penalty_factor = v5;
  v7 = (float)(dt / p_m_breath_vibration_params->time_to_speed_up_after_breath_holding) + *m_speed_factor;
  if ( s_bm_current_air_resistance <= v7 )
    v7 = s_bm_current_air_resistance;
  *m_speed_factor = v7;
}
