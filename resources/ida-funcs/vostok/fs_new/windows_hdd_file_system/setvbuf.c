void __thiscall vostok::fs_new::windows_hdd_file_system::setvbuf(
        vostok::fs_new::windows_hdd_file_system *this,
        int handle,
        char *buffer,
        int mode,
        unsigned __int64 size)
{
  char v5; // bl
  int v6; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool has_passed_filters; // al
  bool v9; // zf
  _iobuf *v10; // eax
  bool v11; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v15; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v5 = 0;
  v6 = _open_osfhandle(handle, 0);
  v7 = v12;
  if ( v6 == -1 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_7FC1E4,
                                 (const char *)2),
          v7 = v13,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v7,
        &log_callback);
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\windows_hdd_file_system.cpp",
        0xABu,
        "void __thiscall vostok::fs_new::windows_hdd_file_system::setvbuf(void *,char *,int,unsigned __int64)",
        (char *)&stru_7FC1E4,
        error,
        "_open_osfhandle: failed");
    }
    v9 = (v5 & 1) == 0;
  }
  else
  {
    v10 = _fdopen(v6, "r+b");
    v7 = v14;
    if ( v10 )
    {
      setvbuf(v10, buffer, mode, size);
      return;
    }
    if ( !vostok::core::g_log_filter_tree
      || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_7FC1E4, (const char *)2),
          v7 = v15,
          v11) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v7,
        &log_callback);
      v5 = 2;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\windows_hdd_file_system.cpp",
        0xB2u,
        "void __thiscall vostok::fs_new::windows_hdd_file_system::setvbuf(void *,char *,int,unsigned __int64)",
        (char *)&stru_7FC1E4,
        error,
        "_fdopen: failed");
    }
    v9 = (v5 & 2) == 0;
  }
  if ( !v9 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
      (int *)&log_callback);
}
