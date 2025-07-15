void __thiscall survarium::weapon_core_fire_state_base::execute(survarium::weapon_core_fire_state_base *this)
{
  survarium::weapon_core *m_weapon; // eax
  survarium::weapon_core *actions_mask; // ecx

  m_weapon = this->m_weapon;
  if ( m_weapon->m_bullets_in_queue )
  {
    if ( (m_weapon->m_user->m_input.actions_mask & 0x20) != 0 )
      this->m_keep_shooting = 1;
  }
  else if ( !m_weapon->m_is_there_chamber_a_round_state )
  {
    actions_mask = (survarium::weapon_core *)m_weapon->m_user->m_input.actions_mask;
    if ( ((unsigned __int8)actions_mask & 0x20) == 0 || ((unsigned __int8)actions_mask & 0x40) != 0 )
      survarium::weapon_core::reset_fire_queue(actions_mask, (int)m_weapon);
  }
  this->m_animation_has_been_ended = 0;
}
