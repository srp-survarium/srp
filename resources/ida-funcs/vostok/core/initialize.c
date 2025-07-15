void __usercall vostok::core::initialize(
        const char *a1@<edi>,
        char *lua_config_device_folder_to_save_to,
        const char *debug_thread_id)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool has_passed_filters; // al
  const vostok::fs_new::native_path_string *current_directory; // eax
  bool v6; // al
  vostok::core::engine_vtbl *v7; // eax
  const char *v8; // eax
  vostok::command_line::key *v9; // ecx
  vostok::threading::mutex_tasks_unaware *v10; // ecx
  char *v11; // eax
  vostok::fixed_string<260> *v12; // ecx
  char *m_end; // edi
  vostok::buffer_string *v14; // ecx
  void *v15; // ecx
  unsigned int v16; // esi
  void *v17; // ecx
  unsigned int v18; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v19; // [esp-4h] [ebp-174h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v20; // [esp-4h] [ebp-174h]
  char *v21; // [esp+0h] [ebp-170h]
  vostok::tasks::execute_while_wait_for_children_enum v22; // [esp+0h] [ebp-170h]
  vostok::tasks::do_logging_bool v23; // [esp+4h] [ebp-16Ch]
  vostok::buffer_string v24[22]; // [esp+10h] [ebp-160h] BYREF
  char v25; // [esp+120h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v26; // [esp+128h] [ebp-48h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+148h] [ebp-28h] BYREF
  int v28; // [esp+16Ch] [ebp-4h]

  v28 = 0;
  if ( debug_thread_id == (const char *)1 )
    vostok::debug::bugtrap::initialize(a1);
  vostok::threading::tls_set_value(s_thread_logging_name_tls_key, lua_config_device_folder_to_save_to);
  vostok::debug::is_debugger_present();
  if ( !s_logical_to_physical_core_index )
    vostok::threading::initialize_core_affinity();
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_802D94,
                               (const char *)4),
        v3 = v19,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v3,
      &log_callback);
    v28 = 1;
    current_directory = vostok::fs_new::get_current_directory((char *)&log_callback);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\core_entry_point.cpp",
      0xAFu,
      "void __cdecl vostok::core::initialize(const char *,const char *,enum vostok::core::debug_initialization_enum,const bool,bool)",
      (char *)&stru_802D94,
      info,
      "working directory: '%s'",
      current_directory->m_string.m_begin);
  }
  if ( (v28 & 1) != 0 )
  {
    v28 &= ~1u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
      (int *)&log_callback);
  }
  if ( vostok::memory::g_use_resources_manager )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v6 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_802D94, (const char *)4),
          v3 = v20,
          v6) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &v26);
      v7 = s_engine_0->__vftable;
      v28 |= 2u;
      v8 = v7->get_resources_path(s_engine_0);
      vostok::logging::append(
        &v26,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\core_entry_point.cpp",
        0xB1u,
        "void __cdecl vostok::core::initialize(const char *,const char *,enum vostok::core::debug_initialization_enum,const bool,bool)",
        (char *)&stru_802D94,
        info,
        "resources directory: '%s'",
        v8);
    }
    if ( (v28 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v26);
  }
  vostok::command_line::check_keys(v3);
  if ( vostok::command_line::key::is_set(v9, (int)&vostok::command_line::s_show_help) )
    vostok::command_line::show_help_and_exit();
  timeBeginPeriod(1u);
  __FUnloadDelayLoadedDLL2("winmm.dll");
  BYTE3(s_command_line_keys_creation.m_mutex[1]) = 0;
  vostok::build::initialize();
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v10, &s_manager_buffer);
  dword_A2DC34 = 0;
  memset((int)&result.m_value, 0, (unsigned int)&loc_20000);
  v11 = (char *)s_engine_0->get_user_data_directory(s_engine_0);
  vostok::fixed_string<260>::fixed_string<260>(v12, v24, v11);
  m_end = v24[0].m_end;
  v25 = 92;
  vostok::buffer_string::append(v14, (int)v24, "/replication");
  vostok::fs_new::path_string_impl::convert(
    (vostok::fs_new::path_string_impl *)m_end,
    (int)v24,
    (vostok::fs_new::path_string_impl *)v24[0].m_end,
    v21);
  v16 = vostok::threading::core_count(v15);
  v18 = vostok::threading::core_count(v17);
  vostok::tasks::thread_pool::thread_pool(
    (vostok::tasks::thread_pool *)(32 - v16),
    &s_thread_pool,
    2 * (v16 + (v16 > 0x20 ? 32 - v16 : 0)),
    v18,
    v22,
    v23);
  _InterlockedExchange(&s_thread_pool.m_initialized, 1);
  vostok::tasks::thread_pool::initialize(
    (vostok::tasks::thread_pool *)&s_thread_pool.m_initialized,
    s_thread_pool.m_variable);
  vostok::threading::set_current_thread_affinity(0);
  vostok::threading::on_thread_spawn(tasks_aware);
  s_initialized_0 = 1;
}
