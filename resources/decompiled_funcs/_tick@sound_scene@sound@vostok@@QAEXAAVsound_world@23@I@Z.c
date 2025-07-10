void __thiscall vostok::sound::sound_scene::tick(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_world *world,
        unsigned int time_delta)
{
  vostok::sound::sound_environment *current_environment; // eax
  vostok::sound::sound_instance_proxy_internal *next_proxy; // [esp+8h] [ebp-Ch]
  vostok::sound::sound_instance_proxy_internal *proxy; // [esp+Ch] [ebp-8h]
  bool device_exist; // [esp+13h] [ebp-1h]

  device_exist = world->m_is_audio_device_exist;
  if ( device_exist )
  {
    current_environment = vostok::sound::sound_scene::get_current_environment(this);
    vostok::sound::effect_cross_fader::tick(this->m_environment_crossfader, time_delta, current_environment);
  }
  if ( !this->m_is_paused )
  {
    vostok::sound::sound_scene::process_fade(this, world, time_delta);
    for ( proxy = this->m_active_proxies.m_first; proxy; proxy = next_proxy )
    {
      next_proxy = proxy->m_next_for_sound_world;
      vostok::sound::sound_instance_proxy_internal::tick(proxy, time_delta);
    }
    vostok::sound::sound_scene::update_receivers_position(this);
    vostok::sound::sound_scene::notify_receivers(this);
    if ( this->m_is_listener_position_set && device_exist )
      vostok::sound::sound_scene::notify_listener(this, world);
  }
}
