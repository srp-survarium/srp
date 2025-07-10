void __cdecl vostok::core::initialize(char *lua_config_device_folder_to_save_to, const char *debug_thread_id)
{
  char v2; // bl
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  const vostok::fs_new::native_path_string *current_directory; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  const char *v7; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v9; // eax
  char *m_buffer; // ecx
  unsigned int v11; // eax
  unsigned int v12; // esi
  vostok::tasks::thread_pool *v13; // ecx
  vostok::threading *v14; // [esp+0h] [ebp-174h]
  vostok::command_line *v15; // [esp+0h] [ebp-174h]
  vostok::math *v16; // [esp+0h] [ebp-174h]
  vostok::tasks::execute_while_wait_for_children_enum v17; // [esp+4h] [ebp-170h]
  vostok::tasks::do_logging_bool v18; // [esp+8h] [ebp-16Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-15Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+38h] [ebp-13Ch] BYREF
  vostok::fs_new::native_path_string replication_folder_string; // [esp+58h] [ebp-11Ch] BYREF

  v2 = 0;
  if ( debug_thread_id == (const char *)1 )
    vostok::debug::postinitialize();
  setlocale(2u, (char *)&buf);
  TlsSetValue(s_thread_logging_name_tls_key, lua_config_device_folder_to_save_to);
  vostok::debug::is_debugger_present();
  if ( !s_logical_to_physical_core_index )
    vostok::threading::initialize_core_affinity(v14);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", info) )
  {
    v3 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v3 )
    {
      log_callback.functor.obj_ptr = v3;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 = 1;
    current_directory = vostok::fs_new::get_current_directory();
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\core_entry_point.cpp",
      0xA2u,
      "void __cdecl vostok::core::initialize(const char *,const char *,enum vostok::core::debug_initialization_enum,const bool)",
      "core:",
      info,
      "working directory: '%s'",
      current_directory->m_string.m_begin);
  }
  if ( (v2 & 1) != 0 )
  {
    v2 &= ~1u;
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&log_callback.functor, &log_callback.functor, 2);
      }
      log_callback.vtable = 0;
    }
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", info) )
  {
    v6 = vostok::core::g_log_callback;
    v20.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &v20.functor,
        &v20.functor,
        destroy_functor_tag);
    if ( v6 )
    {
      v20.functor.obj_ptr = v6;
      v20.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                          + 1);
    }
    else
    {
      v20.vtable = 0;
    }
    v2 |= 2u;
    v7 = s_engine_0->get_resources_path(s_engine_0);
    vostok::logging::append(
      &v20,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\core_entry_point.cpp",
      0xA3u,
      "void __cdecl vostok::core::initialize(const char *,const char *,enum vostok::core::debug_initialization_enum,const bool)",
      "core:",
      info,
      "resources directory: '%s'",
      v7);
  }
  if ( (v2 & 2) != 0 )
  {
    if ( v20.vtable )
    {
      if ( ((int)v20.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v20.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&v20.functor, &v20.functor, 2);
      }
    }
  }
  vostok::command_line::check_keys(v14);
  if ( vostok::command_line::s_show_help.m_type == type_unset )
  {
    vostok::command_line::s_show_help.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::command_line::s_show_help.m_type != type_recursive )
    vostok::command_line::show_help_and_exit(v15);
  timeBeginPeriod(1u);
  __FUnloadDelayLoadedDLL2("winmm.dll");
  QueryPerformanceFrequency(&vostok::timing::g_qpc_per_second);
  vostok::timing::g_cpu_supports_time_stamp = 0;
  vostok::build::initialize();
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&s_manager, 0x2710u);
  *(_DWORD *)&s_manager.m_static_memory[131100] = 0;
  memset((int)&s_manager.m_static_memory[28], 0, (unsigned int)&loc_20000);
  _InterlockedExchange(&s_manager.m_initialized, 1);
  v9 = s_engine_0->get_user_data_directory(s_engine_0);
  m_buffer = replication_folder_string.m_string.m_buffer;
  replication_folder_string.m_string.m_begin = replication_folder_string.m_string.m_buffer;
  replication_folder_string.m_string.m_end = replication_folder_string.m_string.m_buffer;
  replication_folder_string.m_string.m_max_end = &replication_folder_string.m_separator;
  replication_folder_string.m_string.m_buffer[0] = 0;
  if ( v9 )
  {
    for ( ; *v9; ++replication_folder_string.m_string.m_end )
    {
      if ( m_buffer >= replication_folder_string.m_string.m_max_end )
        break;
      *m_buffer = *v9;
      m_buffer = replication_folder_string.m_string.m_end + 1;
      ++v9;
    }
    *m_buffer = 0;
  }
  replication_folder_string.m_separator = 92;
  vostok::fs_new::path_string_impl::append_with_conversion<char const [13]>(
    (vostok::fs_new::path_string_impl *)m_buffer,
    &replication_folder_string);
  v11 = s_logical_core_count;
  if ( !s_logical_core_count )
  {
    vostok::threading::initialize_core_count(v15);
    v11 = s_logical_core_count;
  }
  v12 = v11;
  if ( !v11 )
  {
    vostok::threading::initialize_core_count(v15);
    v11 = s_logical_core_count;
  }
  vostok::tasks::thread_pool::thread_pool(
    (vostok::tasks::thread_pool *)(16 - v11),
    (int)&s_thread_pool,
    2 * (v11 + (v11 > 0x10 ? 16 - v11 : 0)),
    v12,
    (unsigned int)v15,
    v17,
    v18);
  _InterlockedExchange(&s_thread_pool.m_initialized, 1);
  vostok::tasks::thread_pool::initialize(v13, s_thread_pool.m_variable);
  vostok::threading::set_current_thread_affinity(0);
  vostok::math::on_thread_spawn(v16);
  if ( s_thread_pool.m_initialized )
    vostok::tasks::thread_pool::register_current_thread_as_core_user(
      (vostok::tasks::thread_pool *)s_thread_pool.m_initialized,
      (DWORD *)s_thread_pool.m_variable);
  s_initialized_1 = 1;
}
