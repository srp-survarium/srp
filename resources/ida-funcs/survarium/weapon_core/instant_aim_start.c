void __thiscall survarium::weapon_core::instant_aim_start(survarium::weapon_core *this)
{
  survarium::breath_vibration_calculator *p_m_breath_vibration_calculator; // esi
  vostok::ai::fsm_state *m_first; // edi
  float v4; // xmm1_4
  const survarium::weapon_core *m_weapon; // eax
  vostok::ai::fsm_state *v6; // esi
  survarium::weapon_breath_vibration_params *p_m_breath_vibration_params; // eax
  unsigned int m_last_tick_time_in_ms; // edx

  p_m_breath_vibration_calculator = &this->m_breath_vibration_calculator;
  this->m_aimed = 1;
  m_first = this->m_breath_vibration_calculator.m_logic.m_states.m_first;
  this->m_breath_vibration_calculator.m_phase_time = FLOAT_0_25;
  vostok::ai::fsm::set_initial_state(&this->m_breath_vibration_calculator.m_logic, m_first, ignore_current_state);
  v4 = s_bm_current_air_resistance;
  p_m_breath_vibration_calculator->m_breath_holding_reserve = p_m_breath_vibration_calculator->m_user->m_breath_vibration_params.max_breath_holding_time;
  p_m_breath_vibration_calculator->m_vibration.x = 0.0;
  p_m_breath_vibration_calculator->m_vibration.y = 0.0;
  m_weapon = p_m_breath_vibration_calculator->m_weapon;
  p_m_breath_vibration_calculator->m_amplitude = 0.0;
  p_m_breath_vibration_calculator->m_speed_factor = v4;
  p_m_breath_vibration_calculator->m_penalty_factor = 0.0;
  v6 = p_m_breath_vibration_calculator->m_logic.m_states.m_first;
  p_m_breath_vibration_params = &m_weapon->m_breath_vibration_params;
  while ( v6 )
  {
    v6[1].transitions.m_size = (unsigned int)p_m_breath_vibration_params;
    v6 = v6->next;
  }
  m_last_tick_time_in_ms = this->m_last_tick_time_in_ms;
  if ( this->m_aim_progress.m_target_value != v4 )
  {
    this->m_aim_progress.m_start_value = this->m_aim_progress.m_current_value;
    this->m_aim_progress.m_target_value = v4;
    this->m_aim_progress.m_transition_time = s_aim_transition_time;
    this->m_aim_progress.m_start_transition_time_in_ms = m_last_tick_time_in_ms;
  }
}
