void __thiscall survarium::breath_state_holding::tick(
        survarium::breath_state_holding *this,
        const float dispersion,
        const float dt)
{
  float *m_breath_holding_reserve; // edx
  const survarium::character_breath_vibration_params *p_m_breath_vibration_params; // eax
  float v5; // xmm0_4
  float *m_speed_factor; // ecx
  float v7; // xmm0_4

  m_breath_holding_reserve = this->m_breath_holding_reserve;
  p_m_breath_vibration_params = &this->m_user->m_breath_vibration_params;
  v5 = *m_breath_holding_reserve - dt;
  if ( v5 <= 0.0 )
    v5 = 0.0;
  m_speed_factor = this->m_speed_factor;
  *m_breath_holding_reserve = v5;
  v7 = *m_speed_factor
     - (float)(dt
             / (float)((float)(p_m_breath_vibration_params->dispersion_to_time_to_hold_breath_ratio * dispersion)
                     + p_m_breath_vibration_params->base_time_to_hold_breath));
  if ( v7 <= 0.0 )
    v7 = 0.0;
  *m_speed_factor = v7;
}
