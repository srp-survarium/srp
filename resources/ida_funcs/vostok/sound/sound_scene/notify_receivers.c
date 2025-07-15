void __thiscall vostok::sound::sound_scene::notify_receivers(vostok::sound::sound_scene *this)
{
  vostok::sound::sound_instance_proxy_internal *proxy; // [esp+4h] [ebp-4h]

  for ( proxy = this->m_active_proxies.m_first; proxy; proxy = proxy->m_next_for_sound_world )
    vostok::sound::sound_instance_proxy_internal::notify_receivers(proxy, this->m_spatial_tree);
}
