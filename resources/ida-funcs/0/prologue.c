void __cdecl prologue(_EXCEPTION_POINTERS *const exception_information)
{
  vostok::debug::crash_handlers_guard *v1; // ecx
  vostok::debug::crash_handler *v2; // esi
  vostok::debug::crash_handler *v3; // ecx
  int next; // eax
  boost::function<void __cdecl(char const *)> *v5; // ecx
  vostok::debug::engine *v6; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(char const *),boost::_bi::list1<boost::arg<1> > > v8; // [esp-8h] [ebp-258h]
  int v9; // [esp+0h] [ebp-250h]
  char v10; // [esp+Fh] [ebp-241h] BYREF
  _SYSTEMTIME SystemTime; // [esp+10h] [ebp-240h] BYREF
  boost::function<void __cdecl(char const *)> v12; // [esp+20h] [ebp-230h] BYREF
  char _Dst[264]; // [esp+40h] [ebp-210h] BYREF
  char _Src[264]; // [esp+148h] [ebp-108h] BYREF

  vostok::debug::platform::format_message();
  vostok::debug::platform::prologue_dump_call_stack(exception_information);
  v1 = (vostok::debug::crash_handlers_guard *)s_debug_engine;
  if ( s_debug_engine )
    s_debug_engine->on_runtime_error(s_debug_engine);
  vostok::debug::crash_handlers_guard::crash_handlers_guard(v1, (int)&v10);
  if ( s_crash_handlers_chain )
  {
    v2 = s_crash_handlers_chain;
    ((void (*)(void))s_crash_handlers_chain->on_crash)();
    next = (int)v2->next;
    if ( next )
      vostok::debug::crash_handler::handle_crash(v3, next);
  }
  InterlockedExchange(&vostok::debug::crash_handlers_guard::crash_handlers_busy, 0);
  GetLocalTime(&SystemTime);
  v6 = s_debug_engine;
  if ( s_debug_engine )
  {
    *(_DWORD *)&v8.l_.boost::_bi::storage1<boost::arg<1> > = *(_DWORD *)&SystemTime.wDayOfWeek;
    v8.f_ = vostok::debug::bugtrap::add_file;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v5,
      (boost::_bi::bind_t<void,void (__cdecl*)(char const *),boost::_bi::list1<boost::arg<1> > > *)&v12,
      v8,
      v9);
    v6->add_crash_report_files(v6, &SystemTime, uri, &v12);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&v12);
    if ( s_debug_engine )
    {
      s_debug_engine->generate_debug_file_name(s_debug_engine, (char (*)[260])_Src, &SystemTime, uri, ".dmp");
      strcpy_s(_Dst, 0x104u, _Src);
      save_minidump(_Dst, exception_information);
      vostok::debug::bugtrap::add_file(_Dst);
    }
  }
  s_BT_SetFlags(5u);
}
