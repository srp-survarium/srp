vostok::render::world *__thiscall vostok::engine::engine_world::get_renderer_world(vostok::engine::engine_world *this)
{
  vostok::render::world *result; // eax
  vostok::tasks::thread_pool *v3; // ecx
  vostok::tasks::thread_pool *v4; // ecx

  result = (vostok::render::world *)this->m_editor_allocator.m_user_thread_id;
  if ( !result )
  {
    do
    {
      if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_locks(v3);
      Sleep(0xAu);
      if ( s_thread_pool.m_initialized )
      {
        if ( TlsGetValue(s_thread_affinity_tls_key) )
          vostok::tasks::thread_pool::on_current_thread_unlocks(v4);
      }
    }
    while ( !this->m_editor_allocator.m_user_thread_id );
    return (vostok::render::world *)this->m_editor_allocator.m_user_thread_id;
  }
  return result;
}
