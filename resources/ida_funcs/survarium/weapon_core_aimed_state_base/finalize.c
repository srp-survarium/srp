void __thiscall survarium::weapon_core_aimed_state_base::finalize(survarium::weapon_core_aimed_state_base *this)
{
  vostok::animation::animation_playback_state::reset(
    (vostok::animation::animation_playback_state *)this,
    &this->m_animation_playback_state.interval_id);
  this->m_weapon->instant_aim_end(this->m_weapon);
}
