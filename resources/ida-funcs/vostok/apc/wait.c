void __usercall vostok::apc::wait(const vostok::apc::threads_enum thread_id@<eax>)
{
  vostok::apc::callback *v1; // edi
  vostok::resources::resources_manager *m_initialized; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v4; // ecx
  vostok::tasks::thread_pool *v5; // ecx
  vostok::tasks::thread_pool *v6; // ecx
  vostok::apc::callback *thread; // [esp+Ch] [ebp-Ch]

  v1 = &g_threads.m_begin[thread_id];
  thread = v1;
  while ( v1->m_pending )
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
          vostok::resources::resources_manager::resources_thread_tick(m_initialized);
          vostok::resources::resources_manager::cooker_thread_tick(
            v4,
            vostok::resources::g_resources_manager.m_variable);
        }
      }
      vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
    }
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
    {
      vostok::tasks::thread_pool::on_current_thread_locks(v5, s_thread_pool.m_variable);
      v1 = thread;
    }
    Sleep(1u);
    if ( s_thread_pool.m_initialized )
    {
      if ( TlsGetValue(s_thread_affinity_tls_key) )
      {
        vostok::tasks::thread_pool::on_current_thread_unlocks(v6, s_thread_pool.m_variable);
        v1 = thread;
      }
    }
  }
}
