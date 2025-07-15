void __userpurge vostok::resources::resources_manager::wait_and_dispatch_callbacks(
        vostok::resources::resources_manager *this@<ecx>,
        double a2@<st0>,
        vostok::resources::resources_manager *call_from_main_thread,
        bool finalizing_thread,
        BOOL finalizing_threada)
{
  vostok::resources::resources_manager *v5; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v7; // ecx
  vostok::resources::resources_manager *v8; // ecx
  vostok::command_line::key::type_enum v9; // eax
  vostok::resources::resources_manager *v10; // ecx
  vostok::resources::resources_manager *v11; // ecx

  if ( finalizing_thread )
    goto LABEL_26;
  if ( !s_logical_core_count )
    vostok::threading::initialize_core_count();
  if ( s_logical_core_count != 1 )
  {
LABEL_26:
    while ( !TryEnterCriticalSection((LPCRITICAL_SECTION)((char *)call_from_main_thread + (_DWORD)&loc_20596 + 2)) )
    {
      m_type = vostok::threading::g_debug_single_thread.m_type;
      if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
      {
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        m_type = vostok::threading::g_debug_single_thread.m_type;
      }
      if ( m_type != type_recursive )
      {
        if ( m_type == type_unset )
        {
          vostok::threading::g_debug_single_thread.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          m_type = vostok::threading::g_debug_single_thread.m_type;
        }
        if ( m_type != type_recursive )
        {
          vostok::resources::resources_manager::resources_thread_tick(
            v5,
            vostok::resources::g_resources_manager.m_variable,
            a2);
          vostok::resources::resources_manager::cooker_thread_tick(
            v7,
            vostok::resources::g_resources_manager.m_variable);
        }
      }
      vostok::resources::resources_manager::dispatch_callbacks(call_from_main_thread, 1);
    }
    if ( !vostok::resources::resources_manager::thread_can_exit(v5, call_from_main_thread) )
    {
      do
      {
        v9 = vostok::threading::g_debug_single_thread.m_type;
        if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
        {
          vostok::threading::g_debug_single_thread.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          v9 = vostok::threading::g_debug_single_thread.m_type;
        }
        if ( v9 != type_recursive )
        {
          if ( v9 == type_unset )
          {
            vostok::threading::g_debug_single_thread.m_type = type_recursive;
            vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
            v9 = vostok::threading::g_debug_single_thread.m_type;
          }
          if ( v9 != type_recursive )
          {
            vostok::resources::resources_manager::resources_thread_tick(
              v8,
              vostok::resources::g_resources_manager.m_variable,
              a2);
            vostok::resources::resources_manager::cooker_thread_tick(
              v10,
              vostok::resources::g_resources_manager.m_variable);
          }
        }
        vostok::resources::resources_manager::dispatch_callbacks(call_from_main_thread, finalizing_threada);
      }
      while ( !vostok::resources::resources_manager::thread_can_exit(v11, call_from_main_thread) );
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)call_from_main_thread + (_DWORD)&loc_20596 + 2));
  }
}
