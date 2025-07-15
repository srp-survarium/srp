BOOL __thiscall survarium::weapon_core::inactive_pred(survarium::weapon_core *this)
{
  return this->m_user->m_current_active_object != this->m_user->m_target_active_object
      && *(&this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.gap4
         + 3);
}
