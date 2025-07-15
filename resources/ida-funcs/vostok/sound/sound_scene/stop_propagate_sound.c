void __thiscall vostok::sound::sound_scene::stop_propagate_sound(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy_internal *proxy)
{
  vostok::sound::new_sound_propagator *m_first; // esi
  bool v3; // zf
  vostok::sound::new_sound_propagator *m_next_for_proxies; // edi

  m_first = proxy->m_propagators.m_first;
  if ( m_first )
  {
    do
    {
      v3 = m_first->m_voice == 0;
      m_first->m_propagation_state = propagating_finished;
      if ( !v3 )
        vostok::sound::new_sound_propagator::detach_voice((vostok::sound::new_sound_propagator *)this, (int)m_first);
      m_next_for_proxies = m_first->m_next_for_proxies;
      vostok::sound::sound_scene::delete_sound_propagator(
        m_first,
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        this,
        proxy);
      m_first = m_next_for_proxies;
    }
    while ( m_next_for_proxies );
  }
}
