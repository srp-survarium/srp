BOOL __thiscall survarium::weapon_core::is_ready_to_be_deactivated(survarium::weapon_core *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_logic->m_current_state[12].transitions.gap4 )
    return *(&this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.gap4
           + 3) != 0;
  return result;
}
