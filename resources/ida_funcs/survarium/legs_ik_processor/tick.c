void __thiscall survarium::legs_ik_processor::tick(survarium::legs_ik_processor *this, unsigned int current_time_in_ms)
{
  float dt_sec; // [esp+18h] [ebp-4h]

  if ( this->m_last_time_in_ms )
  {
    dt_sec = (double)(current_time_in_ms - this->m_last_time_in_ms) * 0.001;
    survarium::legs_ik_processor::leg_params::tick(&this->m_left_leg_params, dt_sec);
    survarium::legs_ik_processor::leg_params::tick(&this->m_right_leg_params, dt_sec);
    this->m_heel_transition_time_calculator.m_value = this->m_heel_transition_time_calculator.m_value + dt_sec;
    this->m_toe_transition_time_calculator.m_value = this->m_toe_transition_time_calculator.m_value + dt_sec;
  }
  this->m_last_time_in_ms = current_time_in_ms;
}
