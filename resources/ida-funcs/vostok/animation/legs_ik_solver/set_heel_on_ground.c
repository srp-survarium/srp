void __usercall vostok::animation::legs_ik_solver::set_heel_on_ground(
        vostok::animation::legs_ik_solver *this@<eax>,
        vostok::animation::legs_ik_solver::leg_params *params@<esi>,
        bool value@<cl>)
{
  unsigned int m_current_time_in_ms; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned int heel_transition_time_in_ms; // ecx

  if ( params->m_heel_on_ground != value )
  {
    m_current_time_in_ms = this->m_current_time_in_ms;
    params->m_heel_on_ground = value;
    if ( value )
    {
      if ( params->m_toe_on_ground )
        params->m_last_stance_time_in_ms = m_current_time_in_ms;
      params->heel_transition_time_in_ms = this->m_heel_transition_time_in_ms;
      this->m_last_time_heel_was_on_the_ground_in_ms = this->m_current_time_in_ms;
    }
    else
    {
      v4 = this->m_current_time_in_ms - this->m_last_time_heel_was_on_the_ground_in_ms;
      this->m_heel_transition_time_in_ms = v4;
      if ( v4 > 1 )
      {
        if ( v4 > 0x1F4 )
          v4 = 500;
      }
      else
      {
        v4 = 1;
      }
      v5 = v4;
      this->m_heel_transition_time_in_ms = v4;
      heel_transition_time_in_ms = this->m_right_leg_params.heel_transition_time_in_ms;
      this->m_left_leg_params.heel_transition_time_in_ms = v5
                                                         + (this->m_left_leg_params.heel_transition_time_in_ms < v5
                                                          ? this->m_left_leg_params.heel_transition_time_in_ms - v5
                                                          : 0);
      this->m_right_leg_params.heel_transition_time_in_ms = v5
                                                          + (heel_transition_time_in_ms < v5
                                                           ? heel_transition_time_in_ms - v5
                                                           : 0);
      this->m_heel_interpolator.m_epsilon = FLOAT_0_0049999999;
      this->m_heel_interpolator.m_total_transition_time = (double)v5 * 0.001;
      params->toe_transition_time_in_ms = this->m_toe_transition_time_in_ms;
      this->m_last_time_toe_was_on_the_ground_in_ms = this->m_current_time_in_ms;
    }
  }
}
