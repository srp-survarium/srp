BOOL __thiscall survarium::weapon_core::throw_grenade_pred(survarium::weapon_core *this)
{
  survarium::base_player *m_user; // edx
  survarium::player_input *m_grenade_slot; // ecx
  int v3; // edx
  survarium::base_player *v4; // ecx
  BOOL result; // eax

  result = 0;
  if ( this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size != 3
    && !this->m_is_in_sprint_transition )
  {
    m_user = this->m_user;
    m_grenade_slot = (survarium::player_input *)m_user->m_inventory.m_object->m_grenade_slot;
    if ( m_grenade_slot != (survarium::player_input *)23
      && survarium::player_input::is_throwing_grenade(m_grenade_slot, (int)&m_user->m_input)
      && survarium::base_player::has_grenade(v4, v3) )
    {
      return 1;
    }
  }
  return result;
}
