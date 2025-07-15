void __thiscall survarium::jump_logic_state_prepare::finalize(survarium::jump_logic_state_prepare *this)
{
  survarium::weapon_user_animations_selector::remove_animation_callback(
    (survarium::weapon_user_animations_selector *)this,
    (int)this->m_jump_logic->m_owner,
    channel_id_on_animation_interval_end,
    (int)this);
  this->m_time_scale = s_bm_current_air_resistance;
}
