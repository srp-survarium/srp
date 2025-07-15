int __cdecl mem_usage(void *heap_handle)
{
  char v1; // bl
  vostok::command_line::key *v2; // ecx
  int v3; // edi
  int v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool v7; // al
  int *p_log_callback; // esi
  bool v9; // al
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-84h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-84h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-84h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // [esp-4h] [ebp-84h]
  _heapinfo _entry; // [esp+14h] [ebp-6Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v17; // [esp+40h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v18; // [esp+60h] [ebp-20h] BYREF

  v1 = 0;
  if ( !vostok::debug::is_debugger_present() || vostok::command_line::key::is_set(v2, (int)&s_no_memory_usage_stats) )
    return 0;
  _entry._pentry = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = heap_walk(heap_handle, &_entry);
    v5 = v11;
    if ( v4 != -2 )
      break;
    if ( _entry._useflag == 1 )
      v3 += _entry._size;
  }
  if ( v4 == -6 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_802D94,
                                 (const char *)3),
          v5 = v14,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v5,
        &v18);
      v1 = 1;
      vostok::logging::append(
        &v18,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\memory_crt_allocator_win.cpp",
        0x91u,
        "unsigned int __cdecl mem_usage(void *,unsigned int *,unsigned int *)",
        (char *)&stru_802D94,
        warning,
        "bad pointer to heap");
    }
    if ( (v1 & 1) == 0 )
      return 0;
    p_log_callback = (int *)&v18;
    goto LABEL_26;
  }
  if ( v4 == -4 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v9 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_802D94, (const char *)3),
          v5 = v13,
          v9) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v5,
        &v17);
      v1 = 4;
      vostok::logging::append(
        &v17,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\memory_crt_allocator_win.cpp",
        0x98u,
        "unsigned int __cdecl mem_usage(void *,unsigned int *,unsigned int *)",
        (char *)&stru_802D94,
        warning,
        "bad node in heap");
    }
    if ( (v1 & 4) == 0 )
      return 0;
    p_log_callback = (int *)&v17;
    goto LABEL_26;
  }
  if ( v4 != -3 )
    return v3;
  if ( !vostok::core::g_log_filter_tree
    || (v7 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_802D94, (const char *)3),
        v5 = v12,
        v7) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v5,
      &log_callback);
    v1 = 2;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\memory_crt_allocator_win.cpp",
      0x95u,
      "unsigned int __cdecl mem_usage(void *,unsigned int *,unsigned int *)",
      (char *)&stru_802D94,
      warning,
      "bad start of heap");
  }
  if ( (v1 & 2) != 0 )
  {
    p_log_callback = (int *)&log_callback;
LABEL_26:
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
      p_log_callback);
  }
  return 0;
}
