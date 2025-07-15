void __cdecl vostok::build::initialize()
{
  unsigned int v0; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v1; // ecx
  vostok::command_line::key *v2; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  unsigned int v5; // [esp-8h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // [esp-4h] [ebp-3Ch]
  const char *v7; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-28h] BYREF
  unsigned int v9; // [esp+34h] [ebp-4h]

  v9 = build_id((char *)s_build_date);
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v6,
    &log_callback);
  v7 = s_build_date;
  v5 = v9;
  v0 = vostok::build::build_station_build_id();
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::core::g_log_format,
    ".\\build_extensions.cpp",
    0x7Eu,
    "void __cdecl vostok::build::initialize(struct vostok::core::engine *)",
    (char *)&stru_802D94,
    info,
    "%s build %d(internal id %d), %s",
    "Vostok Engine v0.20e",
    v0,
    v5,
    v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v1,
    (int *)&log_callback);
  if ( vostok::command_line::key::is_set(v2, (int)&s_print_build_id) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v3,
      &log_callback);
    vostok::logging::append(
      &log_callback,
      (void *const)1,
      (vostok::logging::log_format *)&vostok::logging::format_message,
      ".\\build_extensions.cpp",
      0x8Au,
      "void __cdecl vostok::build::initialize(struct vostok::core::engine *)",
      "core:",
      info,
      "%d",
      v9);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&log_callback);
    vostok::debug::terminate((char *)uri);
  }
}
