void __usercall vostok::core::preinitialize(
        vostok::core::engine *engine@<ecx>,
        vostok::logging::log_file_usage_enum log_file_usage@<eax>,
        char *command_line)
{
  vostok::command_line::key *v4; // ecx
  char *m_begin; // edi
  vostok::core::engine_vtbl *v6; // eax
  vostok::threading::mutex_tasks_unaware *v7; // ecx
  vostok::logging::format_separator *v8; // ecx
  int v9; // eax
  vostok::logging::format_separator *v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  _BYTE v14[140]; // [esp+Ch] [ebp-290h] BYREF
  _BYTE v15[140]; // [esp+98h] [ebp-204h] BYREF
  _BYTE v16[140]; // [esp+124h] [ebp-178h] BYREF
  _BYTE v17[140]; // [esp+1B0h] [ebp-ECh] BYREF
  _DWORD v18[3]; // [esp+23Ch] [ebp-60h] BYREF
  _DWORD v19[3]; // [esp+248h] [ebp-54h] BYREF
  _DWORD v20[3]; // [esp+254h] [ebp-48h] BYREF
  _DWORD v21[3]; // [esp+260h] [ebp-3Ch] BYREF
  _DWORD v22[3]; // [esp+26Ch] [ebp-30h] BYREF
  _DWORD v23[3]; // [esp+278h] [ebp-24h] BYREF
  _DWORD v24[3]; // [esp+284h] [ebp-18h] BYREF
  _DWORD v25[3]; // [esp+290h] [ebp-Ch] BYREF

  vostok::core::g_log_file_usage = log_file_usage;
  s_engine_0 = engine;
  setlocale(1, ".ACP");
  vostok::command_line::initialize((int)engine, command_line);
  vostok::command_line::key::is_set_as_string(v4, &s_localization_command_line.m_string_value, &g_localization_name);
  m_begin = g_localization_name.m_begin;
  if ( vostok::strings::compare(g_localization_name.m_begin, "original") && vostok::strings::compare(m_begin, "russian") )
  {
    if ( !vostok::strings::compare(m_begin, "english") )
      setlocale(0, ".1252");
  }
  else
  {
    setlocale(0, ".1251");
  }
  setlocale(4, "C");
  v6 = s_engine_0->__vftable;
  s_debug_engine = s_engine_0;
  vostok::debug::g_disable_output_to_debugger = ((unsigned __int8 (*)(void))v6->output_to_debugger)() == 0;
  vostok::strings::copy<512>((char (*)[512])s_application_0, "Survarium");
  s_thread_logging_name_tls_key = TlsAlloc();
  *(_DWORD *)s_core_synchronous_device.m_static_memory = 0;
  *(_DWORD *)&s_core_synchronous_device.m_static_memory[4] = &s_hdd;
  s_core_synchronous_device.m_static_memory[8] = 0;
  _InterlockedExchange(&s_core_synchronous_device.m_initialized, 1);
  vostok::memory::g_use_resources_manager = engine->use_resources_manager(engine);
  vostok::memory::g_use_video_memory = engine->use_video_memory(engine);
  vostok::memory::preinitialize(v7);
  s_build_date = "Mar 20 2014";
  vostok::logging::format_separator::format_separator(v8, (int)v17, "{");
  v19[0] = v9;
  v19[1] = &vostok::logging::format_thread_id;
  v19[2] = 0;
  v23[0] = v19;
  v23[1] = &vostok::logging::format_time;
  v23[2] = 0;
  vostok::logging::format_separator::format_separator(v10, (int)v15, "} [");
  v20[1] = v11;
  v20[0] = v23;
  v20[2] = 0;
  v21[0] = v20;
  v21[1] = &vostok::logging::format_initiator;
  v21[2] = 0;
  vostok::logging::format_separator::format_separator((vostok::logging::format_separator *)v23, (int)v16, "] <");
  v18[1] = v12;
  v18[0] = v21;
  v18[2] = 0;
  v25[0] = v18;
  v25[1] = &vostok::logging::format_verbosity;
  v25[2] = 0;
  vostok::logging::format_separator::format_separator((vostok::logging::format_separator *)v21, (int)v14, ">   ");
  v24[1] = v13;
  v24[0] = v25;
  v24[2] = 0;
  v22[0] = v24;
  v22[1] = &vostok::logging::format_message;
  v22[2] = 0;
  vostok::logging::log_format::set((vostok::logging::log_format *)v22, vostok::core::g_log_format.string);
}
