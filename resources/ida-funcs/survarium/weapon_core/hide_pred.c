BOOL __thiscall survarium::weapon_core::hide_pred(survarium::weapon_core *this)
{
  return this->m_user->m_is_alive
      && this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size != 3
      && !this->m_is_in_sprint_transition
      && survarium::weapon_core::inactive_pred(this);
}
