void __fastcall vostok::animation::legs_ik_solver::set_toe_on_ground(
        vostok::animation::legs_ik_solver::leg_params *params,
        bool value,
        vostok::animation::legs_ik_solver *this)
{
  bool v3; // zf
  unsigned int m_current_time_in_ms; // esi
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int toe_transition_time_in_ms; // ecx

  if ( params->m_toe_on_ground == value )
    return;
  v3 = !params->m_heel_on_ground;
  m_current_time_in_ms = this->m_current_time_in_ms;
  params->m_toe_on_ground = value;
  if ( v3 )
    goto LABEL_5;
  if ( value )
  {
    params->m_last_stance_time_in_ms = m_current_time_in_ms;
LABEL_5:
    if ( value )
      return;
  }
  v5 = this->m_current_time_in_ms - this->m_last_time_toe_was_on_the_ground_in_ms;
  this->m_toe_transition_time_in_ms = v5;
  if ( v5 > 1 )
  {
    if ( v5 > 0x1F4 )
      v5 = 500;
  }
  else
  {
    v5 = 1;
  }
  v6 = v5;
  this->m_toe_transition_time_in_ms = v5;
  toe_transition_time_in_ms = this->m_right_leg_params.toe_transition_time_in_ms;
  this->m_left_leg_params.toe_transition_time_in_ms = v6
                                                    + (this->m_left_leg_params.toe_transition_time_in_ms < v6
                                                     ? this->m_left_leg_params.toe_transition_time_in_ms - v6
                                                     : 0);
  this->m_right_leg_params.toe_transition_time_in_ms = v6
                                                     + (toe_transition_time_in_ms < v6
                                                      ? toe_transition_time_in_ms - v6
                                                      : 0);
  this->m_toe_interpolator.m_epsilon = FLOAT_0_0049999999;
  this->m_toe_interpolator.m_total_transition_time = (double)v6 * 0.001;
}
