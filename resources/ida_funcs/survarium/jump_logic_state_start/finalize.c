void __thiscall survarium::jump_logic_state_start::finalize(survarium::jump_logic_state_start *this)
{
  survarium::weapon_user_animations_selector::remove_animation_callback(this->m_jump_logic->m_owner, "jump", this);
  survarium::weapon_user_animations_selector::remove_animation_callback(
    this->m_jump_logic->m_owner,
    channel_id_on_animation_interval_end,
    this);
}
