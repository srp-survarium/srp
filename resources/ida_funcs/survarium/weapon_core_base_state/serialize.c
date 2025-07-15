void __thiscall survarium::weapon_core_base_state::serialize(
        survarium::weapon_core_base_state *this,
        vostok::network_core::udp_match_packet *packet)
{
  survarium::game_camera *m_serialize_animation_state; // ecx
  survarium::weapon_core *v3; // ecx
  vostok::animation::animation_playback_state playback_state; // [esp+28h] [ebp-10h] BYREF
  const survarium::base_player *user; // [esp+30h] [ebp-8h]

  m_serialize_animation_state = (survarium::game_camera *)this->m_serialize_animation_state;
  if ( m_serialize_animation_state )
  {
    playback_state.interval_id = 0;
    playback_state.interval_time = *(float *)&FLOAT_0_0;
    survarium::weapon_user_dead_state::finalize(m_serialize_animation_state);
    user = survarium::weapon_core::get_user(v3, (int)this->m_weapon);
    if ( !user->get_animation_playback_state((survarium::base_player *)user, this->m_weapon, -3u, &playback_state) )
    {
      playback_state.interval_id = 0;
      playback_state.interval_time = *(float *)&FLOAT_0_0;
    }
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
      packet,
      *(float *)&playback_state.interval_id);
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, playback_state.interval_time);
  }
}
