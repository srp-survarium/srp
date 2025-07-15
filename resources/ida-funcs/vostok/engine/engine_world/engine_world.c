void __userpurge vostok::engine::engine_world::engine_world(
        vostok::engine::engine_world *this@<ecx>,
        vostok::core::engine *proxy,
        const char *command_line,
        char *application,
        const char *build_date)
{
  vostok::core::engine *v5; // ebx
  const char *v6; // eax
  vostok::timing::timer *v7; // ecx
  vostok::logging::format_separator *v8; // ecx
  int v9; // eax
  vostok::logging::format_separator *v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vostok::memory::base_allocator *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::memory::base_allocator *v16; // ecx
  vostok::memory::base_allocator *v17; // ecx
  int v18; // edi
  vostok::memory::base_allocator *v19; // ecx
  vostok::memory::base_allocator *v20; // ecx
  vostok::command_line::key *v21; // ecx
  _BYTE v22[140]; // [esp+14h] [ebp-284h] BYREF
  _BYTE v23[140]; // [esp+A0h] [ebp-1F8h] BYREF
  _BYTE v24[140]; // [esp+12Ch] [ebp-16Ch] BYREF
  _BYTE v25[140]; // [esp+1B8h] [ebp-E0h] BYREF
  _DWORD v26[3]; // [esp+244h] [ebp-54h] BYREF
  _DWORD v27[3]; // [esp+250h] [ebp-48h] BYREF
  _DWORD v28[3]; // [esp+25Ch] [ebp-3Ch] BYREF
  _DWORD v29[3]; // [esp+268h] [ebp-30h] BYREF
  _DWORD v30[3]; // [esp+274h] [ebp-24h] BYREF
  _DWORD v31[3]; // [esp+280h] [ebp-18h] BYREF
  _DWORD v32[3]; // [esp+28Ch] [ebp-Ch] BYREF

  v5 = proxy;
  proxy->__vftable = (vostok::core::engine_vtbl *)&vostok::engine::engine_world::`vftable'{for `vostok::core::engine'};
  v5[1].__vftable = (vostok::core::engine_vtbl *)&vostok::engine::engine_world::`vftable'{for `vostok::engine_user::engine'};
  v5[2].__vftable = (vostok::core::engine_vtbl *)&vostok::engine::engine_world::`vftable'{for `vostok::editor::engine'};
  v5[5].__vftable = (vostok::core::engine_vtbl *)-1;
  v5[4].__vftable = (vostok::core::engine_vtbl *)&vostok::fs_new::windows_hdd_file_system::`vftable';
  v5[7].__vftable = (vostok::core::engine_vtbl *)-1;
  v5[6].__vftable = (vostok::core::engine_vtbl *)&vostok::fs_new::windows_hdd_file_system::`vftable';
  v5[58].__vftable = (vostok::core::engine_vtbl *)&v5[8];
  v5[59].__vftable = 0;
  v5[60].__vftable = 0;
  v5[112].__vftable = (vostok::core::engine_vtbl *)&v5[62];
  v5[113].__vftable = 0;
  v5[114].__vftable = 0;
  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)&v5[116],
    thread_id_const_true,
    1,
    0,
    1);
  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)&v5[127],
    thread_id_const_true,
    1,
    0,
    1);
  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)&v5[138],
    thread_id_const_true,
    1,
    0,
    1);
  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)&v5[149],
    thread_id_const_true,
    1,
    0,
    1);
  v6 = command_line;
  v5[160].__vftable = 0;
  v5[168].__vftable = 0;
  v5[169].__vftable = 0;
  v5[170].__vftable = 0;
  v5[171].__vftable = 0;
  v5[172].__vftable = 0;
  v5[173].__vftable = (vostok::core::engine_vtbl *)v6;
  v5[174].__vftable = 0;
  v5[175].__vftable = 0;
  v5[176].__vftable = 0;
  v5[177].__vftable = 0;
  v5[178].__vftable = 0;
  v5[179].__vftable = 0;
  v5[180].__vftable = 0;
  v5[181].__vftable = 0;
  v5[182].__vftable = 0;
  v5[183].__vftable = 0;
  v5[184].__vftable = 0;
  v5[185].__vftable = 0;
  v5[186].__vftable = 0;
  v5[187].__vftable = 0;
  LOBYTE(v5[188].__vftable) = 0;
  BYTE1(v5[188].__vftable) = 0;
  BYTE2(v5[188].__vftable) = 1;
  HIBYTE(v5[188].__vftable) = 1;
  LOBYTE(v5[189].__vftable) = 0;
  BYTE1(v5[189].__vftable) = 0;
  BYTE2(v5[189].__vftable) = 0;
  vostok::timing::timer::timer(v7, (LARGE_INTEGER *)&v5[190]);
  vostok::core::preinitialize(v5, create_log, application);
  vostok::logging::format_separator::format_separator(v8, (int)v25, " <");
  v31[1] = v9;
  v31[0] = &vostok::logging::format_initiator;
  v31[2] = 0;
  v28[0] = v31;
  v28[1] = &vostok::logging::format_verbosity;
  v28[2] = 0;
  vostok::logging::format_separator::format_separator(v10, (int)v23, ">\t");
  v29[0] = v28;
  v29[1] = v11;
  v29[2] = 0;
  vostok::logging::format_separator::format_separator((vostok::logging::format_separator *)v28, (int)v24, "[");
  v26[1] = v12;
  v26[0] = v29;
  v26[2] = 0;
  v27[0] = v26;
  v27[1] = &vostok::logging::format_time;
  v27[2] = 0;
  vostok::logging::format_separator::format_separator((vostok::logging::format_separator *)v29, (int)v22, "]\t");
  v32[1] = v13;
  v32[0] = v27;
  v32[2] = 0;
  v30[0] = v32;
  v30[1] = &vostok::logging::format_message;
  v30[2] = 0;
  vostok::logging::log_format::set((vostok::logging::log_format *)v30, vostok::core::g_log_format.string);
  vostok::memory::base_allocator::do_register(
    v14,
    (int)&vostok::engine::g_allocator,
    (unsigned int)&_sbh_sizeHeaderList,
    (const char *)&initiator_raw);
  vostok::engine::g_scaleform_allocator = &vostok::memory::g_mt_allocator;
  if ( vostok::command_line::key::is_set_as_number<unsigned int>(v15, (unsigned int *)&proxy) )
    vostok::memory::base_allocator::do_register(
      (vostok::memory::base_allocator *)&loc_100000,
      (int)&v5[138],
      (unsigned int)&loc_100000
    * (unsigned __int64)(unsigned int)((unsigned int)proxy
                                     - ((unsigned int)&proxy[-64] & (((unsigned __int64)(unsigned int)proxy - 256) >> 32))),
      (const char *)&initiator_raw.initiator_tree);
  else
    vostok::memory::base_allocator::do_register(
      v16,
      (int)&v5[138],
      0x8000000u,
      (const char *)&initiator_raw.initiator_tree);
  v18 = 0;
  LOBYTE(v5[142].__vftable) = 1;
  vostok::memory::base_allocator::do_register(
    v17,
    (int)&v5[116],
    (unsigned int)"esource_ptr<class vostok::sound::sound_emitter,class vostok::resources::unmanaged_intrusive_base>,const class vostok::sound::sound_propagator_emitter &,class vostok::sound::world_user &)",
    &initiator_raw.filter_stack.gap0);
  vostok::memory::base_allocator::do_register(
    v19,
    (int)&v5[127],
    (unsigned int)&s_ui_commands_allocator.m_buffer[2035360],
    (const char *)&initiator_raw.filter_stack.m_last);
  (*((void (__thiscall **)(vostok::core::engine_vtbl *))v5[173].~vostok::core::engine + 2))(v5[173].__vftable);
  if ( s_editor_mode )
  {
    v18 = 335544320;
    vostok::memory::base_allocator::do_register(v20, (int)&v5[149], 0x8000000u, "editor");
  }
  vostok::memory::allocate_region((unsigned int)v18, (unsigned int)v18);
  if ( vostok::command_line::key::is_set(v21, (int)&s_debug_hash_mismatches_key) )
    vostok::network_core::g_debug_hash_mismatches = 1;
}
