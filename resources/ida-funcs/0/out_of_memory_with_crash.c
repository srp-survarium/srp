char __thiscall out_of_memory_with_crash(
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *this,
        void *const space,
        _DWORD *parameter,
        const int first_time)
{
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // [esp-4h] [ebp-3Ch]
  const char *v7; // [esp-4h] [ebp-3Ch]
  const char *v8; // [esp-4h] [ebp-3Ch]
  bool do_debug_break; // [esp+13h] [ebp-25h] BYREF
  int v10; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v10 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_802D94,
                               (const char *)2),
        this = v6,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      this,
      &log_callback);
    v7 = (const char *)parameter[3];
    v10 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\memory_doug_lea_allocator.cpp",
      0x30u,
      "char __stdcall out_of_memory_with_crash(void *const ,const void *const ,const int)",
      (char *)&stru_802D94,
      error,
      "out of memory in arena \"%s\"",
      v7);
  }
  if ( (v10 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&log_callback);
  vostok::memory::monitor::finalize((vostok::command_line::key *)this);
  vostok::memory::dump_statistics(0);
  if ( !debug_macro_helper_ignore_always_16 )
  {
    v8 = (const char *)parameter[3];
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\memory_doug_lea_allocator.cpp",
      "out_of_memory_with_crash",
      (const char *)0x35,
      "not enough memory for arena [%s]",
      v8);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  return 0;
}
