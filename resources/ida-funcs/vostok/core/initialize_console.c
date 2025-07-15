char __cdecl vostok::core::initialize_console()
{
  char v0; // bl
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  bool has_passed_filters; // al
  HANDLE StdHandle; // eax
  int v5; // eax
  _iobuf *v6; // eax
  HANDLE v7; // eax
  int v8; // eax
  _iobuf *v9; // eax
  HANDLE v10; // eax
  int v11; // eax
  _iobuf *v12; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v0 = 0;
  if ( BYTE2(s_command_line_keys_creation.m_mutex[1]) )
    return BYTE1(s_command_line_keys_creation.m_mutex[1]);
  BYTE2(s_command_line_keys_creation.m_mutex[1]) = 1;
  if ( GetConsoleWindow() )
    goto LABEL_17;
  if ( AttachConsole(0xFFFFFFFF) || AllocConsole() )
  {
    StdHandle = GetStdHandle(0xFFFFFFF6);
    v5 = _open_osfhandle((int)StdHandle, 0x4000);
    if ( v5 != -1 )
    {
      qmemcpy(&log_callback, _fdopen(v5, "rt"), sizeof(log_callback));
      qmemcpy(&__iob_func()[2], &log_callback, sizeof(_iobuf));
      v6 = __iob_func();
      setvbuf(v6, 0, 4, 0);
    }
    v7 = GetStdHandle(0xFFFFFFF5);
    v8 = _open_osfhandle((int)v7, 0x4000);
    qmemcpy(&log_callback, _fdopen(v8, "wt"), sizeof(log_callback));
    qmemcpy(&__iob_func()[1], &log_callback, sizeof(_iobuf));
    v9 = __iob_func();
    setvbuf(v9 + 1, 0, 4, 0);
    v10 = GetStdHandle(0xFFFFFFF4);
    v11 = _open_osfhandle((int)v10, 0x4000);
    if ( v11 != -1 )
    {
      qmemcpy(&log_callback, _fdopen(v11, "wt"), sizeof(log_callback));
      qmemcpy(&__iob_func()[2], &log_callback, sizeof(_iobuf));
      v12 = __iob_func();
      setvbuf(v12 + 2, 0, 4, 0);
    }
    stlp_std::ios_base::sync_with_stdio(1);
LABEL_17:
    BYTE1(s_command_line_keys_creation.m_mutex[1]) = 1;
    return 1;
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_802D94,
                               (const char *)3),
        v2 = v13,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v2,
      &log_callback);
    v0 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\logging_extensions.cpp",
      0x152u,
      "bool __cdecl vostok::core::initialize_console(void)",
      (char *)&stru_802D94,
      warning,
      "cannot neither attach parent console, nor create new");
  }
  if ( (v0 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
      (int *)&log_callback);
  BYTE1(s_command_line_keys_creation.m_mutex[1]) = 0;
  return 0;
}
