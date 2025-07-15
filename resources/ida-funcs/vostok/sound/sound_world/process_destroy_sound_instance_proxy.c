void __thiscall vostok::sound::sound_world::process_destroy_sound_instance_proxy(
        vostok::sound::sound_world *this,
        vostok::sound::destroy_sound_instance_proxy_order *order)
{
  vostok::sound::sound_instance_proxy_internal *proxy; // [esp+10h] [ebp-4h]

  proxy = order->m_proxy;
  vostok::sound::sound_scene::stop_propagate_sound(proxy->m_scene, proxy);
  vostok::sound::sound_scene::free_sound_instance_proxy(proxy->m_scene, proxy);
}
