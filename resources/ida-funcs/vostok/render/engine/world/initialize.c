void __thiscall vostok::render::engine::world::initialize(
        vostok::render::engine::world *this,
        vostok::render::engine::world *is_editor)
{
  int p_m_initialized; // ecx
  vostok::tasks::thread_pool *v3; // ecx
  vostok::tasks::thread_pool *v4; // ecx
  vostok::resources *v5; // [esp+0h] [ebp-10h]

  singletons_on_initialize::singletons_on_initialize((singletons_on_initialize *)this, (int)&s_singletons_on_initialize);
  p_m_initialized = (int)&s_singletons_on_initialize.m_initialized;
  _InterlockedExchange(&s_singletons_on_initialize.m_initialized, 1);
  if ( s_no_level.m_type == type_unset )
  {
    s_no_level.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_no_level.m_type == type_recursive )
  {
    while ( 1 )
    {
      p_m_initialized = (char *)s_singletons_on_preinitialize.m_variable->scene_manager.m_scenes._M_impl._M_finish
                      - (char *)s_singletons_on_preinitialize.m_variable->scene_manager.m_scenes._M_impl._M_start;
      if ( (p_m_initialized & 0xFFFFFFFC) != 0 )
        break;
      if ( vostok::resources::g_resources_manager.m_initialized )
      {
        if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
        {
          vostok::threading::g_debug_single_thread.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        }
        if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
          vostok::resources::tick(v5);
        vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
      }
      if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_locks(v3);
      Sleep(0xAu);
      if ( s_thread_pool.m_initialized )
      {
        if ( TlsGetValue(s_thread_affinity_tls_key) )
          vostok::tasks::thread_pool::on_current_thread_unlocks(v4);
      }
    }
  }
  is_editor->m_initialized = 1;
  vostok::render::system_renderer::system_renderer(
    p_m_initialized,
    &s_singletons_on_initialize.m_variable->renderer_context,
    (vostok::render::system_renderer *)&s_system_renderer);
  _InterlockedExchange(&s_system_renderer.m_initialized, 1);
}
