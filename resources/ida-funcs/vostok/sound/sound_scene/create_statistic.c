vostok::sound::sound_scene_statistic *__thiscall vostok::sound::sound_scene::create_statistic(
        vostok::sound::sound_scene *this)
{
  _DWORD *v1; // eax
  _DWORD *v3; // [esp+8h] [ebp-34h]
  vostok::sound::sound_scene_statistic *v5; // [esp+2Ch] [ebp-10h]
  vostok::sound::sound_voice *voice; // [esp+30h] [ebp-Ch]
  vostok::sound::sound_instance_proxy_internal *proxy; // [esp+38h] [ebp-4h]

  v5 = (vostok::sound::sound_scene_statistic *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                 (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                                 0x34u);
  if ( v5 )
  {
    vostok::sound::sound_scene_statistic::sound_scene_statistic(v5);
    v3 = v1;
  }
  else
  {
    v3 = 0;
  }
  v3[6] = this->m_receivers.m_size;
  v3[4] = this->m_active_proxies.m_size;
  for ( voice = this->m_active_voices.m_first; voice; voice = voice->m_next_for_active )
    ++v3[voice->m_channels_num + 6];
  for ( proxy = this->m_active_proxies.m_first; proxy; proxy = proxy->m_next_for_sound_world )
  {
    ++v3[proxy->m_type];
    v3[5] += proxy->m_propagators.m_size;
  }
  return (vostok::sound::sound_scene_statistic *)v3;
}
