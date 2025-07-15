void __thiscall survarium::weapon::set_user(survarium::weapon *this, survarium::base_player *user)
{
  survarium::weapon_core::set_user(this, user);
  if ( *((_BYTE *)&loc_1143B + (_DWORD)user) )
    this->m_portable_interactive_object->m_user_animations_selector.m_stand_state = (survarium::player_logic_base_state *)this->m_portable_interactive_object->m_user_animations_selector.survarium::weapon_core::m_logic.m_states.m_last;
}
