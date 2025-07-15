void __thiscall survarium::player_logic_preview_state::finalize(survarium::player_logic_dead_state *this)
{
  survarium::weapon_user_animations_selector::remove_animation_callback(
    (survarium::weapon_user_animations_selector *)this,
    (int)this->m_owner,
    channel_id_on_animation_end,
    (int)this);
}
