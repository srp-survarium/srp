char __cdecl vostok::strings::iterate_items<vostok::logging::logger_predicate,char *>(
        char *const string,
        unsigned int length,
        vostok::logging::logger_predicate *predicate,
        char separator)
{
  survarium::game_camera *v4; // ecx
  void *v5; // esp
  char *v6; // eax
  unsigned int v9[261]; // [esp+0h] [ebp-42Ch] BYREF
  char v10; // [esp+417h] [ebp-15h]
  char *j; // [esp+418h] [ebp-14h]
  const char *I; // [esp+41Ch] [ebp-10h]
  char *temp_string; // [esp+420h] [ebp-Ch]
  int index; // [esp+424h] [ebp-8h]
  char *i; // [esp+428h] [ebp-4h]

  v10 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  I = string;
  v5 = alloca(length + 1);
  v9[1] = (unsigned int)v9;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)string);
  temp_string = v6;
  i = v6;
  j = v6;
  index = 0;
  while ( *I )
  {
    if ( *I == separator )
    {
      *i = 0;
      v9[0] = index;
      if ( !vostok::logging::logger_predicate::operator()(predicate, index++, j, i - j, 0) )
        return 0;
      j = i + 1;
    }
    else
    {
      *i = *I;
    }
    ++I;
    ++i;
  }
  if ( !index )
    return vostok::logging::logger_predicate::operator()(predicate, 0, string, length, 1);
  *i = 0;
  return vostok::logging::logger_predicate::operator()(predicate, index, j, i - j, 1);
}
