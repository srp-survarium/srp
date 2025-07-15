void __cdecl vostok::fs_new::log_last_error(const char *initiator, survarium::game_camera *header)
{
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize(v2);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(header);
}
