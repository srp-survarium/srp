void __usercall vostok::core::preinitialize(
        vostok::core::engine *engine@<esi>,
        vostok::logging::log_file_usage_enum log_file_usage@<eax>,
        const char *command_line)
{
  bool v3; // al
  vostok::core::engine_vtbl *v4; // edx
  char *v5; // eax
  const char *v6; // ecx
  vostok::logging::format_specifier *v7; // eax
  const char *v8; // ecx
  vostok::logging::format_specifier *v9; // eax
  const char *v10; // ecx
  vostok::logging::format_specifier *v11; // eax
  const char *v12; // ecx
  vostok::command_line::contains_application_bool v13; // [esp-8h] [ebp-2D0h]
  vostok::memory *v14; // [esp+0h] [ebp-2C8h]
  vostok::logging::format_specifier v15; // [esp+8h] [ebp-2C0h] BYREF
  vostok::logging::format_specifier v16; // [esp+14h] [ebp-2B4h] BYREF
  vostok::logging::format_specifier v17; // [esp+20h] [ebp-2A8h] BYREF
  vostok::logging::format_specifier format_expression; // [esp+2Ch] [ebp-29Ch] BYREF
  vostok::logging::format_specifier v19; // [esp+38h] [ebp-290h] BYREF
  vostok::logging::format_specifier v20; // [esp+44h] [ebp-284h] BYREF
  vostok::logging::format_specifier v21; // [esp+50h] [ebp-278h] BYREF
  vostok::logging::format_specifier v22; // [esp+5Ch] [ebp-26Ch] BYREF
  vostok::logging::format_specifier left; // [esp+68h] [ebp-260h] BYREF
  _BYTE *v24; // [esp+74h] [ebp-254h]
  _BYTE *v25; // [esp+78h] [ebp-250h]
  vostok::logging::format_specifier *v26; // [esp+7Ch] [ebp-24Ch]
  _BYTE v27[128]; // [esp+80h] [ebp-248h] BYREF
  vostok::logging::format_specifier v28; // [esp+100h] [ebp-1C8h] BYREF
  _BYTE *v29; // [esp+10Ch] [ebp-1BCh]
  _BYTE *v30; // [esp+110h] [ebp-1B8h]
  vostok::logging::format_specifier *p_right; // [esp+114h] [ebp-1B4h]
  _BYTE v32[128]; // [esp+118h] [ebp-1B0h] BYREF
  vostok::logging::format_specifier right; // [esp+198h] [ebp-130h] BYREF
  _BYTE *v34; // [esp+1A4h] [ebp-124h]
  _BYTE *v35; // [esp+1A8h] [ebp-120h]
  vostok::logging::format_specifier *v36; // [esp+1ACh] [ebp-11Ch]
  _BYTE v37[128]; // [esp+1B0h] [ebp-118h] BYREF
  vostok::logging::format_specifier v38; // [esp+230h] [ebp-98h] BYREF
  _BYTE *v39; // [esp+23Ch] [ebp-8Ch]
  _BYTE *v40; // [esp+240h] [ebp-88h]
  char *v41; // [esp+244h] [ebp-84h]
  _BYTE v42[128]; // [esp+248h] [ebp-80h] BYREF
  _UNKNOWN *retaddr; // [esp+2C8h] [ebp+0h] BYREF

  vostok::core::g_log_file_usage = log_file_usage;
  s_engine_0 = engine;
  setlocale(1u, ".ACP");
  vostok::command_line::initialize(engine, command_line, v13);
  vostok::debug::initialize(s_engine_0);
  strcpy_s((char *)&s_crt_allocator_creation.m_arena, 0x200u, "survarium");
  s_thread_logging_name_tls_key = TlsAlloc();
  vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
    (vostok::fs_new::synchronous_device_interface *)&s_core_synchronous_device,
    &s_hdd,
    watcher_enabled_false);
  _InterlockedExchange(&s_core_synchronous_device.m_initialized, 1);
  v3 = engine->use_resources_manager(engine);
  v4 = engine->__vftable;
  vostok::memory::g_use_resources_manager = v3;
  vostok::memory::g_use_video_memory = v4->use_video_memory(engine);
  vostok::memory::preinitialize(v14);
  s_build_date = "May  9 2013";
  vostok::logging::format_specifier::format_specifier(&v38, format_specifier_separator);
  v5 = v42;
  v39 = v42;
  v40 = v42;
  v41 = (char *)&retaddr;
  v42[0] = 0;
  v6 = ">   ";
  do
  {
    if ( v5 >= v41 )
      break;
    *v5 = *v6;
    v5 = v40 + 1;
    ++v6;
    ++v40;
  }
  while ( *v6 );
  *v5 = 0;
  vostok::logging::format_specifier::format_specifier(&v28, format_specifier_separator);
  v7 = (vostok::logging::format_specifier *)v32;
  p_right = &right;
  v29 = v32;
  v30 = v32;
  v32[0] = 0;
  v8 = "] <";
  do
  {
    if ( v7 >= p_right )
      break;
    LOBYTE(v7->m_left) = *v8;
    v7 = (vostok::logging::format_specifier *)(v30 + 1);
    ++v8;
    ++v30;
  }
  while ( *v8 );
  LOBYTE(v7->m_left) = 0;
  vostok::logging::format_specifier::format_specifier(&right, format_specifier_separator);
  v9 = (vostok::logging::format_specifier *)v37;
  v36 = &v38;
  v34 = v37;
  v35 = v37;
  v37[0] = 0;
  v10 = "} [";
  do
  {
    if ( v9 >= v36 )
      break;
    LOBYTE(v9->m_left) = *v10;
    v9 = (vostok::logging::format_specifier *)(v35 + 1);
    ++v10;
    ++v35;
  }
  while ( *v10 );
  LOBYTE(v9->m_left) = 0;
  vostok::logging::format_specifier::format_specifier(&left, format_specifier_separator);
  v11 = (vostok::logging::format_specifier *)v27;
  v26 = &v28;
  v24 = v27;
  v25 = v27;
  v27[0] = 0;
  v12 = "{";
  do
  {
    if ( v11 >= v26 )
      break;
    LOBYTE(v11->m_left) = *v12;
    v11 = (vostok::logging::format_specifier *)(v25 + 1);
    ++v12;
    ++v25;
  }
  while ( *v12 );
  LOBYTE(v11->m_left) = 0;
  vostok::logging::format_specifier::format_specifier(&v21, &left, &vostok::logging::format_thread_id);
  vostok::logging::format_specifier::format_specifier(&v17, &v21, &vostok::logging::format_time);
  vostok::logging::format_specifier::format_specifier(&v20, &v17, &right);
  vostok::logging::format_specifier::format_specifier(&v19, &v20, &vostok::logging::format_initiator);
  vostok::logging::format_specifier::format_specifier(&v22, &v19, &v28);
  vostok::logging::format_specifier::format_specifier(&v15, &v22, &vostok::logging::format_verbosity);
  vostok::logging::format_specifier::format_specifier(&v16, &v15, &v38);
  vostok::logging::format_specifier::format_specifier(&format_expression, &v16, &vostok::logging::format_message);
  vostok::logging::log_format::set(&vostok::core::g_log_format, &format_expression);
}
