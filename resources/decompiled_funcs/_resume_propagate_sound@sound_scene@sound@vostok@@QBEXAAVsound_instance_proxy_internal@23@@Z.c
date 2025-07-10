void __thiscall vostok::sound::sound_scene::resume_propagate_sound(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy_internal *proxy)
{
  vostok::sound::new_sound_propagator *prop; // [esp+4h] [ebp-4h]

  for ( prop = proxy->m_propagators.m_first; prop; prop = prop->m_next_for_proxies )
    vostok::sound::new_sound_propagator::resume_propagation(prop);
}
