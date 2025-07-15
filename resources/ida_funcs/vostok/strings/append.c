char *__cdecl vostok::strings::append<512>(char (*result)[512], const char *source)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax

  strcat_s((char *)result, 0x200u, source);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize(v3);
  return *result;
}
