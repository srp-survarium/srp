void __fastcall survarium::transition_helper::tick(
        survarium::transition_helper *this,
        const unsigned int current_time_in_ms)
{
  float m_target_value; // xmm0_4
  float m_transition_time; // xmm2_4
  float v4; // [esp+0h] [ebp-4h]

  m_target_value = this->m_target_value;
  if ( this->m_current_value != m_target_value )
  {
    m_transition_time = this->m_transition_time;
    v4 = (double)(current_time_in_ms - this->m_start_transition_time_in_ms) * 0.001;
    if ( v4 < m_transition_time )
    {
      this->m_current_value = (float)((float)(m_target_value - this->m_start_value) * (float)(v4 / m_transition_time))
                            + this->m_start_value;
    }
    else
    {
      this->m_start_transition_time_in_ms = -1;
      this->m_current_value = m_target_value;
      this->m_start_value = m_target_value;
      this->m_transition_time = 0.0;
    }
  }
}
