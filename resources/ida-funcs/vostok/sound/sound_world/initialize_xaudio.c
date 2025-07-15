char __thiscall vostok::sound::sound_world::initialize_xaudio(vostok::sound::sound_world *this, int a2)
{
  bool has_passed_filters; // al
  LPVOID *v3; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  HRESULT v5; // eax
  bool v6; // al
  LPVOID v7; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  bool v9; // al
  bool v10; // al
  int v11; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // ecx
  bool v13; // al
  char *v14; // edx
  bool v15; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // ecx
  bool v17; // al
  bool v19; // al
  vostok::sound::sound_world *v20; // [esp-4h] [ebp-C90h]
  vostok::command_line::key *v21; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v22; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v23; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v24; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v25; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp-4h] [ebp-C90h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp-4h] [ebp-C90h]
  _BYTE v30[512]; // [esp+10h] [ebp-C7Ch] BYREF
  wchar_t v31[256]; // [esp+210h] [ebp-A7Ch] BYREF
  unsigned int v32; // [esp+410h] [ebp-87Ch]
  vostok::buffer_string v33; // [esp+440h] [ebp-84Ch] BYREF
  _BYTE v34[2048]; // [esp+44Ch] [ebp-840h] BYREF
  char v35; // [esp+C4Ch] [ebp-40h] BYREF
  HRESULT v36; // [esp+C54h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+C58h] [ebp-34h] BYREF
  unsigned int v38; // [esp+C78h] [ebp-14h] BYREF
  unsigned int Flags; // [esp+C7Ch] [ebp-10h]
  HRESULT i; // [esp+C80h] [ebp-Ch]
  int v41; // [esp+C84h] [ebp-8h]

  v41 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                               (const char *)4),
        this = v20,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &log_callback);
    v41 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\sound_world.cpp",
      0xB6u,
      "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
      (char *)&initiator_raw.filter_stack.m_last,
      info,
      "Sound initialization...");
  }
  if ( (v41 & 1) != 0 )
  {
    v41 &= ~1u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&log_callback);
  }
  Flags = vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_debug_audio);
  v3 = (LPVOID *)(a2 + 192);
  i = XAudio2Create((LPVOID *)(a2 + 192), Flags);
  if ( i < 0 )
  {
    if ( vostok::command_line::key::is_set(v21, (int)&s_debug_audio) )
    {
      v5 = XAudio2Create(v3, 0);
      v4 = v22;
      i = v5;
    }
    if ( i < 0 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v6 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                   (const char *)2),
            v4 = v23,
            v6) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &log_callback);
        v41 |= 2u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\sound_world.cpp",
          0xC7u,
          "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
          (char *)&initiator_raw.filter_stack.m_last,
          error,
          "Sound initialization FAILED. Can not create XAudio2 interface. %d",
          i);
      }
      if ( (v41 & 2) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&log_callback);
      vostok::debug::terminate("Sound initialization FAILED. Can not create XAudio2 interface.\r\n"
                               "\r\n"
                               "Try to reinstall DirectX and try again");
    }
  }
  v7 = *v3;
  v38 = 0;
  (*(void (__stdcall **)(LPVOID, unsigned int *))(*(_DWORD *)v7 + 12))(v7, &v38);
  if ( v38 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v9 = vostok::logging::has_passed_filters(
                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                 (const char *)4),
          v8 = v24,
          v9) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v8,
        &log_callback);
      v41 |= 4u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xCEu,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        (char *)&initiator_raw.filter_stack.m_last,
        info,
        "audio devices count: %d",
        v38);
    }
    if ( (v41 & 4) != 0 )
    {
      v41 &= ~4u;
LABEL_27:
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
        (int *)&log_callback);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v10 = vostok::logging::has_passed_filters(
                  (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                  (const char *)3),
          v8 = v25,
          v10) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v8,
        &log_callback);
      v41 |= 8u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xD0u,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        (char *)&initiator_raw.filter_stack.m_last,
        warning,
        "audio devices count: %d, try use default audio device",
        v38);
    }
    if ( (v41 & 8) != 0 )
    {
      v41 &= ~8u;
      goto LABEL_27;
    }
  }
  if ( vostok::command_line::key::is_set((vostok::command_line::key *)v8, (int)&s_debug_audio) )
  {
    *(_QWORD *)(&log_callback.functor.data + 12) = 0x100000001LL;
    v11 = *(_DWORD *)(a2 + 192);
    *(_QWORD *)&log_callback.functor.obj_ptr = 66;
    log_callback.functor.vostok_pointer_size_alignment[2] = 0;
    log_callback.functor.vostok_pointer_size_alignment[5] = 0;
    (*(void (__stdcall **)(int, boost::detail::function::function_buffer *, _DWORD))(*(_DWORD *)v11 + 60))(
      v11,
      &log_callback.functor,
      0);
  }
  v33.m_begin = v34;
  v33.m_end = v34;
  v36 = 0;
  v33.m_max_end = &v35;
  v34[0] = 0;
  for ( i = 0; i < v38; ++i )
  {
    (*(void (__stdcall **)(_DWORD, HRESULT, _BYTE *))(**(_DWORD **)(a2 + 192) + 16))(*(_DWORD *)(a2 + 192), i, v30);
    if ( v33.m_begin != uri )
    {
      v33.m_end = v33.m_begin;
      *v33.m_begin = 0;
      vostok::buffer_string::operator+=(&v33, (char *)uri);
    }
    if ( !vostok::core::g_log_filter_tree
      || (v13 = vostok::logging::has_passed_filters(
                  (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                  (const char *)4),
          v12 = v26,
          v13) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v12,
        &log_callback);
      v41 |= 0x10u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xE7u,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        (char *)&initiator_raw.filter_stack.m_last,
        info,
        "%d: %S",
        i,
        v31);
    }
    if ( (v41 & 0x10) != 0 )
    {
      v41 &= ~0x10u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v12,
        (int *)&log_callback);
    }
    Flags = v32;
    if ( v32 )
    {
      if ( (v32 & 1) != 0 )
        vostok::buffer_string::operator+=(&v33, "DefaultConsoleDevice ");
      if ( (Flags & 2) != 0 )
        vostok::buffer_string::operator+=(&v33, "DefaultMultimediaDevice ");
      if ( (Flags & 4) != 0 )
        vostok::buffer_string::operator+=(&v33, "DefaultCommunicationsDevice ");
      if ( (Flags & 8) != 0 )
        vostok::buffer_string::operator+=(&v33, "DefaultGameDevice ");
      if ( (Flags & 0xF) == 0 )
        goto LABEL_51;
      v14 = "GlobalDefaultDevice ";
    }
    else
    {
      v14 = "NotDefaultDevice ";
    }
    vostok::buffer_string::operator+=(&v33, v14);
LABEL_51:
    if ( !vostok::core::g_log_filter_tree
      || (v15 = vostok::logging::has_passed_filters(
                  (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                  (const char *)4),
          v12 = v27,
          v15) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v12,
        &log_callback);
      v41 |= 0x20u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xE9u,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        (char *)&initiator_raw.filter_stack.m_last,
        info,
        "role: %s",
        v33.m_begin);
    }
    if ( (v41 & 0x20) != 0 )
    {
      v41 &= ~0x20u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v12,
        (int *)&log_callback);
    }
    if ( (v32 & 2) != 0 )
      v36 = i;
  }
  i = (*(int (__stdcall **)(_DWORD, int, _DWORD, int, _DWORD, HRESULT, _DWORD))(**(_DWORD **)(a2 + 192) + 40))(
        *(_DWORD *)(a2 + 192),
        a2 + 196,
        0,
        44100,
        0,
        v36,
        0);
  if ( i >= 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v19 = vostok::logging::has_passed_filters(
                  (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                  (const char *)4),
          v16 = v29,
          v19) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v16,
        &log_callback);
      v41 |= 0x80u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xFCu,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        (char *)&initiator_raw.filter_stack.m_last,
        info,
        "Sound initialized successful.");
    }
    if ( (v41 & 0x80u) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v16,
        (int *)&log_callback);
    return 1;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v17 = vostok::logging::has_passed_filters(
                  (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                  (const char *)3),
          v16 = v28,
          v17) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v16,
        &log_callback);
      v41 |= 0x40u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xF8u,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        (char *)&initiator_raw.filter_stack.m_last,
        warning,
        "Sound initialization FAILED. Can not create MasteringVoice. %d",
        i);
    }
    if ( (v41 & 0x40) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v16,
        (int *)&log_callback);
    return 0;
  }
}
