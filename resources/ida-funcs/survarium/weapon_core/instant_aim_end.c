void __thiscall survarium::weapon_core::instant_aim_end(survarium::weapon_core *this)
{
  float m_hide_time; // xmm1_4
  unsigned int m_last_tick_time_in_ms; // edx
  double m_current_value; // st7

  this->m_aimed = 0;
  vostok::ai::fsm::tick((vostok::ai::fsm *)this, (int)&this->m_breath_vibration_calculator);
  if ( this->m_logic->m_current_state[12].transitions.m_size == 2 )
  {
    m_hide_time = this->m_hide_time;
    if ( m_hide_time > 0.30000001 )
      m_hide_time = s_aim_transition_time;
  }
  else
  {
    m_hide_time = s_aim_transition_time;
  }
  m_last_tick_time_in_ms = this->m_last_tick_time_in_ms;
  if ( this->m_aim_progress.m_target_value != 0.0 )
  {
    m_current_value = this->m_aim_progress.m_current_value;
    this->m_aim_progress.m_target_value = 0.0;
    this->m_aim_progress.m_start_value = m_current_value;
    this->m_aim_progress.m_transition_time = m_hide_time;
    this->m_aim_progress.m_start_transition_time_in_ms = m_last_tick_time_in_ms;
  }
}
