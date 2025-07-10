void __thiscall survarium::weapon_user_animations_selector::tick(survarium::weapon_user_animations_selector *this)
{
  survarium::player_input *v1; // eax

  if ( (this->m_user->input(this->m_user)->actions_mask & 0x200) != 0 )
  {
    v1 = (survarium::player_input *)this->m_user->input(this->m_user);
    if ( (!survarium::player_input::is_sprinting(v1)
       || !survarium::weapon_user_animations_selector::is_weapon_in_idle(this))
      && survarium::weapon_user_animations_selector::current_state(this)->m_weapon_user_state_id == type_sprint )
    {
      this->m_forced_not_to_sprint = 1;
    }
  }
  else
  {
    this->m_forced_not_to_sprint = 0;
  }
  vostok::ai::fsm::tick(&this->m_logic);
}
