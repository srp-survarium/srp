int __thiscall survarium::weapon_core::melee_pred(survarium::weapon_core *this)
{
  int result; // eax

  if ( this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size == 3 )
    return 0;
  if ( this->m_is_in_sprint_transition )
    return 0;
  if ( this->m_aimed )
    return 0;
  result = 1;
  if ( (this->m_user->m_input.actions_mask & 0x20000000) == 0 )
    return 0;
  return result;
}
