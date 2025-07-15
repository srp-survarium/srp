void __usercall thread_dispatch_callbacks(vostok::resources::resources_manager *a1@<ecx>, double a2@<st0>)
{
  vostok::resources::resources_manager *m_initialized; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v4; // ecx

  for ( ;
        !s_resources_callbacks_have_been_dispatched;
        a1 = (vostok::resources::resources_manager *)s_resources_callbacks_have_been_dispatched )
  {
    m_initialized = (vostok::resources::resources_manager *)vostok::resources::g_resources_manager.m_initialized;
    if ( vostok::resources::g_resources_manager.m_initialized )
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
            m_initialized,
            vostok::resources::g_resources_manager.m_variable,
            a2);
          vostok::resources::resources_manager::cooker_thread_tick(
            v4,
            vostok::resources::g_resources_manager.m_variable);
        }
      }
      vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
    }
    if ( !SwitchToThread() )
      Sleep(0);
  }
  vostok::resources::dispatch_callbacks(a1);
}
