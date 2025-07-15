int __thiscall survarium::breath_vibration_calculator::not_holding_breath(survarium::breath_vibration_calculator *this)
{
  unsigned int actions_mask; // eax
  int result; // eax

  actions_mask = this->m_user->m_input.actions_mask;
  if ( (actions_mask & 0x400000) == 0 )
    return 1;
  if ( (actions_mask & 0x100) == 0 )
    return 1;
  result = 0;
  if ( !this->m_weapon->m_aimed )
    return 1;
  return result;
}
