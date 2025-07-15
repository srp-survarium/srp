void __thiscall survarium::weapon::on_user_sprint(survarium::weapon *this, bool user_is_sprinting)
{
  bool v3; // al
  unsigned int m_last_tick_time_in_ms; // edx
  bool v5; // cl
  unsigned int v6; // eax

  survarium::weapon_core::on_user_sprint(this, user_is_sprinting);
  v3 = this->m_is_double_handed || !user_is_sprinting;
  m_last_tick_time_in_ms = this->m_last_tick_time_in_ms;
  v5 = !user_is_sprinting;
  if ( this->m_fingers_corrector.m_hands[0].is_active != v3 )
  {
    this->m_fingers_corrector.m_hands[0].is_active = v3;
    this->m_fingers_corrector.m_hands[0].start_transition_time_in_ms = m_last_tick_time_in_ms;
  }
  v6 = this->m_last_tick_time_in_ms;
  if ( this->m_fingers_corrector.m_hands[1].is_active != v5 )
  {
    this->m_fingers_corrector.m_hands[1].is_active = v5;
    this->m_fingers_corrector.m_hands[1].start_transition_time_in_ms = v6;
  }
}
