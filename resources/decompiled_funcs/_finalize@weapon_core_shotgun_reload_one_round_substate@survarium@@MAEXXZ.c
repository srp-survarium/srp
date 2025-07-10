void __thiscall survarium::weapon_core_shotgun_reload_one_round_substate::finalize(
        survarium::weapon_core_shotgun_reload_one_round_substate *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::animation::animation_playback_state::reset(
    (vostok::animation::animation_playback_state *)this,
    &this->m_animation_playback_state->interval_id);
  survarium::weapon_core::remove_animation_callback(this->m_weapon, channel_id_on_animation_end, this);
}
