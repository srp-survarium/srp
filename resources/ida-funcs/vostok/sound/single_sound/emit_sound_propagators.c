void __thiscall vostok::sound::single_sound::emit_sound_propagators(
        vostok::sound::single_sound *this,
        vostok::sound::sound_instance_proxy_internal *proxy,
        unsigned int playback_id,
        unsigned int start_delay_ms)
{
  int v4; // eax

  vostok::sound::sound_scene::create_sound_propagator(
    (vostok::sound::sound_scene *)this,
    (int)proxy->m_scene,
    this != (vostok::sound::single_sound *)264 ? (const vostok::sound::sound_propagator_emitter *)this : 0,
    proxy,
    playback_id);
  if ( v4 )
  {
    *(_DWORD *)(v4 + 28) = start_delay_ms;
    if ( *(_DWORD *)(v4 + 16) )
      *(_DWORD *)(v4 + 36) = -1;
    else
      *(_DWORD *)(v4 + 36) = start_delay_ms + *(_DWORD *)(v4 + 40);
    *(_DWORD *)v4 = 0;
    ++proxy->m_propagators.m_size;
    if ( proxy->m_propagators.m_first )
      proxy->m_propagators.m_last->m_next_for_proxies = (vostok::sound::new_sound_propagator *)v4;
    else
      proxy->m_propagators.m_first = (vostok::sound::new_sound_propagator *)v4;
    proxy->m_propagators.m_last = (vostok::sound::new_sound_propagator *)v4;
  }
}
