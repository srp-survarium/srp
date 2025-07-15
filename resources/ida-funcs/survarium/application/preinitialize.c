void __thiscall survarium::application::preinitialize(survarium::application *this, int a2)
{
  unsigned int v2; // eax
  wchar_t *v3; // eax
  char *CommandLineA; // eax
  vostok::engine::engine_world *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  boost::function<void __cdecl(void)> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  const char *v10; // [esp+0h] [ebp-284h]
  int v11; // [esp+0h] [ebp-284h]
  char _Dest[256]; // [esp+8h] [ebp-27Ch] BYREF
  wchar_t output[64]; // [esp+108h] [ebp-17Ch] BYREF
  _OSVERSIONINFOA dst; // [esp+188h] [ebp-FCh] BYREF
  char s[64]; // [esp+220h] [ebp-64h] BYREF
  boost::function<void __cdecl(void)> function_to_call; // [esp+260h] [ebp-24h] BYREF

  memset((int)&dst, 0, sizeof(dst));
  dst.dwOSVersionInfoSize = 148;
  GetVersionExA(&dst);
  if ( dst.dwMajorVersion < 6 )
    vostok::debug::terminate("Your OS doesn't meet minimal system requirements of Survarium.");
  decode_finger_print((char (*)[64])s);
  if ( s_finger_print_0.m_begin != s )
  {
    s_finger_print_0.m_end = s_finger_print_0.m_begin;
    *s_finger_print_0.m_begin = 0;
    vostok::buffer_string::operator+=(&s_finger_print_0, s);
  }
  v2 = vostok::build::build_station_build_id();
  sprintf_s<256>((char (*)[256])_Dest, "%s (%d)", "0.20e", v2);
  strcpy_s(s_application_version, 0x40u, _Dest);
  if ( s_BT_SetAppVersion )
  {
    v3 = convert_to_unicode_if_needed(output, s_application_version, 64);
    s_BT_SetAppVersion((const char *)v3);
  }
  CommandLineA = GetCommandLineA();
  vostok::engine::engine_world::engine_world(
    v5,
    (vostok::core::engine *)&s_world_0,
    (const char *)(a2 + 4),
    CommandLineA,
    v10);
  _InterlockedExchange(&s_world_0.m_initialized, 1);
  if ( !vostok::command_line::key::is_set(
          (vostok::command_line::key *)&s_world_0.m_initialized,
          (int)&vostok::command_line::s_show_help)
    && !vostok::testing::run_tests_command_line(v6)
    && !vostok::command_line::key::is_set(v7, (int)&s_no_splash_screen_key) )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v8,
      &function_to_call,
      (void (__cdecl *)())splash_screen_main,
      v11);
    vostok::threading::spawn(&function_to_call, "splash", "splash screen", 0, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)&function_to_call);
  }
}
