void __thiscall survarium::weapon_core_base_state::finalize(survarium::weapon_core_base_state *this)
{
  vostok::animation::animation_playback_state::reset(
    (vostok::animation::animation_playback_state *)this,
    &this->m_animation_playback_state.interval_id);
}
