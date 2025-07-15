unsigned int __userpurge survarium::transition_helper::start_transition_with_speed@<eax>(
        survarium::transition_helper *this@<ecx>,
        char a2@<efl>,
        float a3@<xmm0>,
        float transition_speed,
        unsigned int current_time_in_ms,
        unsigned int a6)
{
  float v7; // [esp+8h] [ebp-4h]

  v7 = fabs(a3 - this->m_current_value);
  return survarium::transition_helper::start_transition_with_time(
           this,
           a2,
           a3,
           v7 / transition_speed,
           current_time_in_ms,
           LODWORD(v7));
}
