void __usercall vostok::apc::process(const vostok::apc::threads_enum thread_id@<eax>)
{
  vostok::apc::callback *v1; // eax
  volatile __int32 *p_m_pending; // edi
  vostok::resources::resources_manager *m_pending; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v5; // ecx
  vostok::tasks::thread_pool *v6; // ecx
  vostok::tasks::thread_pool *v7; // ecx
  vostok::apc::break_parameters m_break_parameters; // esi
  survarium::game_camera *v9; // eax
  vostok::apc::callback *thread; // [esp+Ch] [ebp-11Ch]
  boost::bad_function_call v11; // [esp+18h] [ebp-110h] BYREF

  v1 = &g_threads.m_begin[thread_id];
  thread = v1;
  p_m_pending = &v1->m_pending;
  while ( 1 )
  {
    m_pending = (vostok::resources::resources_manager *)*p_m_pending;
    if ( !*p_m_pending )
    {
      do
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
              vostok::resources::resources_manager::resources_thread_tick(m_pending);
              vostok::resources::resources_manager::cooker_thread_tick(
                v5,
                vostok::resources::g_resources_manager.m_variable);
            }
          }
          vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
        }
        if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
          vostok::tasks::thread_pool::on_current_thread_locks(v6, s_thread_pool.m_variable);
        Sleep(1u);
        if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
          vostok::tasks::thread_pool::on_current_thread_unlocks(v7, s_thread_pool.m_variable);
        m_pending = (vostok::resources::resources_manager *)thread->m_pending;
        p_m_pending = &thread->m_pending;
      }
      while ( !m_pending );
      v1 = thread;
    }
    m_break_parameters = v1->m_break_parameters;
    if ( !v1->m_callback.vtable )
    {
      boost::bad_function_call::bad_function_call(&v11);
      boost::throw_exception(v9);
      stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v11);
      v1 = thread;
    }
    (*(void (__cdecl **)(boost::detail::function::function_buffer *))(((int)v1->m_callback.vtable & 0xFFFFFFFE) + 4))(&v1->m_callback.functor);
    _InterlockedExchange(p_m_pending, 0);
    if ( m_break_parameters == break_process_loop )
      break;
    v1 = thread;
  }
}
