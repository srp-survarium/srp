void __usercall vostok::engine::engine_world::network(vostok::engine::engine_world *this@<ecx>, double a2@<st0>)
{
  vostok::engine::engine_world *v2; // edi
  vostok::resources::resources_manager *m_initialized; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v5; // ecx
  vostok::tasks::thread_pool *v6; // ecx

  v2 = this;
  g_threads.m_begin[3].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(network);
  while ( !v2->m_destruction_started )
  {
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
            v5,
            vostok::resources::g_resources_manager.m_variable);
        }
      }
      vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
    }
    v2->m_network_world->tick(v2->m_network_world, 0);
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
    {
      vostok::tasks::thread_pool::on_current_thread_locks(v6, s_thread_pool.m_variable);
      v2 = this;
    }
    Sleep(1u);
    m_initialized = (vostok::resources::resources_manager *)s_thread_pool.m_initialized;
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
    {
      vostok::tasks::thread_pool::on_current_thread_unlocks(
        (vostok::tasks::thread_pool *)m_initialized,
        s_thread_pool.m_variable);
      v2 = this;
    }
  }
  vostok::apc::process(network);
}
