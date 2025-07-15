unsigned int __cdecl vostok::threading::spawn_internal(
        vostok::threading::thread_entry_params *argument,
        SIZE_T stack_size)
{
  DWORD LastError; // ebx
  char *v3; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-30h] BYREF
  unsigned int ThreadId; // [esp+30h] [ebp-10h] BYREF
  HANDLE hObject; // [esp+34h] [ebp-Ch]
  HLOCAL hMem; // [esp+38h] [ebp-8h]
  int v13; // [esp+3Ch] [ebp-4h]

  v13 = 0;
  hObject = CreateThread(0, stack_size, vostok::threading::thread_entry_protected, argument, 0, &ThreadId);
  if ( !hObject )
  {
    LastError = GetLastError();
    v3 = vostok::debug::platform::fill_format_message(LastError);
    v4 = v7;
    hMem = v3;
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_802CB8,
                                 (const char *)2),
          v4 = v8,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &log_callback);
      v13 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\threading_functions_win_xbox360.cpp",
        0x98u,
        "unsigned int __cdecl vostok::threading::spawn_internal(struct vostok::threading::thread_entry_params &,const unsigned int)",
        (char *)&stru_802CB8,
        error,
        (char *)&stru_802CB8.initiator_tree,
        LastError,
        hMem);
    }
    if ( (v13 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&log_callback);
    LocalFree(hMem);
  }
  CloseHandle(hObject);
  return ThreadId;
}
