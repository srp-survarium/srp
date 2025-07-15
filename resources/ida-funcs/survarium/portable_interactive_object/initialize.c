void __thiscall survarium::portable_interactive_object::initialize(survarium::portable_interactive_object *this)
{
  survarium::weapon_user_animations_selector::initialize(
    (survarium::weapon_user_animations_selector *)this,
    &this->m_user_animations_selector.m_logic);
  this->m_hand_ik_solver.m_hands[0].is_active = 0;
  this->m_hand_ik_solver.m_hands[0].start_transition_time_in_ms = 0;
  this->m_hand_ik_solver.m_hands[1].is_active = 0;
  this->m_hand_ik_solver.m_hands[1].start_transition_time_in_ms = 0;
}
