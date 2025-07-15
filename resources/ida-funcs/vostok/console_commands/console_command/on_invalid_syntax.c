void __thiscall vostok::console_commands::console_command::on_invalid_syntax(
        vostok::console_commands::console_command *this,
        void (__thiscall ***args)(const char **, char *),
        const char *a3)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool has_passed_filters; // al
  char v5; // bl
  bool v6; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp-4h] [ebp-234h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-234h]
  char v9; // [esp+Ch] [ebp-224h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-220h] BYREF
  char v11[512]; // [esp+30h] [ebp-200h] BYREF

  v9 = 0;
  (*args)[4]((const char **)args, v11);
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_802D94,
                               (const char *)3),
        v3 = v7,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v3,
      &log_callback);
    v9 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\console_command.cpp",
      0x3Cu,
      "void __thiscall vostok::console_commands::console_command::on_invalid_syntax(const char *)",
      (char *)&stru_802D94,
      warning,
      "Invalid syntax in call [%s %s]",
      (const char *)args[4],
      a3);
  }
  v5 = v9;
  if ( (v9 & 1) != 0 )
  {
    v5 = v9 & 0xFE;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
      (int *)&log_callback);
  }
  if ( !vostok::core::g_log_filter_tree
    || (v6 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_802D94, (const char *)3),
        v3 = v8,
        v6) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v3,
      &log_callback);
    v5 |= 2u;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\console_command.cpp",
      0x3Du,
      "void __thiscall vostok::console_commands::console_command::on_invalid_syntax(const char *)",
      (char *)&stru_802D94,
      warning,
      "Valid arguments: %s",
      v11);
  }
  if ( (v5 & 2) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
      (int *)&log_callback);
}
