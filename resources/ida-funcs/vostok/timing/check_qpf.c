void vostok::timing::check_qpf()
{
  LARGE_INTEGER v0; // kr00_8
  bool has_passed_filters; // al
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  int v3; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-30h] BYREF
  LARGE_INTEGER Frequency; // [esp+30h] [ebp-10h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  v9 = 0;
  QueryPerformanceFrequency(&Frequency);
  v0 = Frequency;
  if ( Frequency.QuadPart != *(_QWORD *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8) )
  {
    if ( vostok::core::g_log_filter_tree )
    {
      has_passed_filters = vostok::logging::has_passed_filters(
                             (vostok::logging::filter_tree *)&stru_802D94,
                             (const char *)2);
      v2 = v6;
      if ( !has_passed_filters )
      {
LABEL_9:
        if ( (v9 & 1) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            v2,
            (int *)&log_callback);
        return;
      }
      v0 = Frequency;
    }
    v3 = *(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer;
    v4 = *(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> **)(v3 + 8);
    if ( v0.QuadPart <= *(_QWORD *)(v3 + 8) )
    {
      v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v4 - v0.LowPart);
      v5 = v4;
    }
    else
    {
      v5 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(v0.LowPart - (_DWORD)v4);
    }
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v4,
      &log_callback);
    v9 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\timing_functions_win.cpp",
      0x40u,
      "void __cdecl vostok::timing::check_qpf(void)",
      (char *)&stru_802D94,
      error,
      "timer: QPF difference is %d",
      v5);
    goto LABEL_9;
  }
}
