unsigned int __userpurge survarium::transition_helper::start_transition_with_time@<eax>(
        survarium::transition_helper *this@<ecx>,
        char a2@<efl>,
        float a3@<xmm0>,
        float transition_time,
        unsigned int current_time_in_ms,
        unsigned int a6)
{
  float m_target_value; // xmm1_4
  bool v7; // cf
  bool v8; // zf
  char v9; // sf
  char v10; // of
  char v11; // pf
  unsigned int result; // eax
  double m_current_value; // st7

  m_target_value = this->m_target_value;
  v7 = m_target_value < a3;
  v11 = 0;
  v8 = m_target_value == a3;
  v9 = 0;
  v10 = 0;
  BYTE1(result) = a2;
  if ( m_target_value != a3 )
  {
    m_current_value = this->m_current_value;
    result = current_time_in_ms;
    this->m_target_value = a3;
    this->m_start_value = m_current_value;
    this->m_transition_time = transition_time;
    this->m_start_transition_time_in_ms = current_time_in_ms;
  }
  return result;
}
