void __thiscall survarium::weapon_core_shotgun_reload_base_substate::finalize(
        survarium::weapon_core_shotgun_reload_base_substate *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::animation::animation_playback_state::reset(
    (vostok::animation::animation_playback_state *)this,
    &this->m_animation_playback_state->interval_id);
}
