void __thiscall survarium::weapon_core_shotgun_reload_state::finalize(
        survarium::weapon_core_shotgun_reload_state *this)
{
  vostok::animation::animation_playback_state::reset(
    (vostok::animation::animation_playback_state *)this,
    &this->m_animation_playback_state.interval_id);
  vostok::ai::fsm::set_initial_state(this->m_logic, 0);
}
