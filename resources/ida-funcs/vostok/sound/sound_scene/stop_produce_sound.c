void __thiscall vostok::sound::sound_scene::stop_produce_sound(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy_internal *proxy)
{
  vostok::sound::new_sound_propagator *i; // eax

  for ( i = proxy->m_propagators.m_first; i; i = i->m_next_for_proxies )
    i->m_end_propagation_time_ms = i->m_propagation_time_ms;
}
