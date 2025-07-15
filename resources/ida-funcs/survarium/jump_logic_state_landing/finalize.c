void __thiscall survarium::jump_logic_state_landing::finalize(survarium::jump_logic_state_landing *this)
{
  if ( !this->m_is_jump_finished )
    survarium::weapon_user_animations_selector::remove_animation_callback(
      (survarium::weapon_user_animations_selector *)this,
      (int)this->m_jump_logic->m_owner,
      channel_id_on_animation_interval_end,
      (int)this);
}
