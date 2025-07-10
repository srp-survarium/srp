bool __thiscall survarium::weapon_core::is_trying_to_aim(survarium::weapon_core *this)
{
  survarium::base_player *user; // eax
  survarium::player_input *input; // [esp+8h] [ebp-8h]
  unsigned int just_toggled; // [esp+Ch] [ebp-4h]

  input = (survarium::player_input *)this->m_user->input(this->m_user);
  just_toggled = input->actions_mask & ~this->m_old_actions_mask;
  user = survarium::weapon_core::get_user(this, (int)this);
  return survarium::weapon_core::could_be_aimed(this, user)
      && (input->actions_mask & 0x80) != 0
      && (!survarium::player_input::is_sprinting(input) || (just_toggled & 0x200) == 0)
      && survarium::weapon_user_animations_selector::get_current_state_id(&this->m_user_animations_selector) != 3;
}
