void __thiscall vostok::sound::sound_scene::stop_propagate_sound(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy_internal *proxy)
{
  vostok::sound::new_sound_propagator *next; // [esp+8h] [ebp-8h]
  vostok::sound::new_sound_propagator *prop; // [esp+Ch] [ebp-4h]

  for ( prop = proxy->m_propagators.m_first; prop; prop = next )
  {
    vostok::sound::new_sound_propagator::stop_propagation(prop);
    next = prop->m_next_for_proxies;
    vostok::sound::sound_scene::delete_sound_propagator(this, proxy, prop);
  }
}
