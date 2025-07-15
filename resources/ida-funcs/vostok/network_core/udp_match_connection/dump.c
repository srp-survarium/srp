void __thiscall vostok::network_core::udp_match_connection::dump(
        vostok::network_core::udp_match_connection *this,
        const char *caption,
        survarium::game_camera *current_time_in_ms)
{
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(current_time_in_ms);
}
