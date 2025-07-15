void __thiscall survarium::weapon_core_shotgun_reload_base_substate::execute(
        survarium::weapon_core_shotgun_reload_base_substate *this)
{
  vostok::animation::animation_playback_state *m_animation_playback_state; // eax

  m_animation_playback_state = this->m_animation_playback_state;
  m_animation_playback_state->interval_id = 0;
  m_animation_playback_state->interval_time = 0.0;
}
