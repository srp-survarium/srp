vostok::configs::binary_config *__thiscall vostok::engine::engine_world::get_sound_world(
        vostok::engine::engine_world *this)
{
  vostok::tasks::thread_pool *v2; // ecx
  vostok::tasks::thread_pool *v3; // ecx

  while ( !this->m_shader_mask_config.m_object )
  {
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_locks(v2);
    Sleep(1u);
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_unlocks(v3);
  }
  return this->m_shader_mask_config.m_object;
}
