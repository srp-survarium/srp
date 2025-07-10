void __thiscall survarium::weapon_core_shotgun_reload_finish_substate::finalize(
        survarium::weapon_core_shotgun_reload_finish_substate *this)
{
  BOOL v1; // ecx
  bool m_deserializing; // [esp+6h] [ebp-2h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::animation::animation_playback_state::reset(
    (vostok::animation::animation_playback_state *)this,
    &this->m_animation_playback_state->interval_id);
  survarium::weapon_core::remove_animation_callback(this->m_weapon, channel_id_on_animation_end, this);
  m_deserializing = this->m_weapon->m_deserializing;
  v1 = m_deserializing;
  if ( !m_deserializing && this->m_weapon->m_chamber_a_round_on_reload )
  {
    LOBYTE(v1) = this->m_weapon->m_chamber_a_round_on_reload;
    if ( survarium::weapon_core::ammo_in_magazine((survarium::weapon_core *)v1, (int)this->m_weapon) )
      survarium::weapon_core::instant_chamber_a_round(this->m_weapon);
  }
}
