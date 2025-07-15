void __thiscall survarium::breath_state_shortbreathing::tick(
        survarium::breath_state_shortbreathing *this,
        const float dispersion,
        const float dt)
{
  float *m_penalty_factor; // eax
  float v4; // xmm0_4

  m_penalty_factor = this->m_penalty_factor;
  v4 = (float)(dt / this->m_user->m_breath_vibration_params.time_to_get_penalty_for_shortbreathing) + *m_penalty_factor;
  if ( s_bm_current_air_resistance <= v4 )
    v4 = s_bm_current_air_resistance;
  *m_penalty_factor = v4;
}
