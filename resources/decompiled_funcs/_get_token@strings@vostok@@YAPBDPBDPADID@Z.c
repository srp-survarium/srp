const char *__cdecl vostok::strings::get_token(char *string, char *result, unsigned int result_size, char separator)
{
  survarium::game_camera *v4; // ecx
  const char *v5; // eax
  const char *found; // [esp+10h] [ebp-4h]

  strchr((unsigned __int8 *)string, separator);
  found = v5;
  if ( v5 )
  {
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::memory::copy(result, result_size - 1, string, found - string);
    result[found - string] = 0;
    return found + 1;
  }
  else
  {
    vostok::strings::copy(result, result_size, string);
    return 0;
  }
}
