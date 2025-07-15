void __userpurge vostok::sound::sound_scene::tick(
        vostok::sound::sound_scene *this@<ecx>,
        float a2@<xmm0>,
        float a3@<xmm10>,
        vostok::sound::sound_scene *time_delta_ms,
        unsigned int time_delta)
{
  vostok::sound::sound_scene *v5; // ecx
  vostok::math::half *v6; // ecx
  vostok::math::half_pod *v7; // ecx
  vostok::math::half_pod *v8; // ecx
  vostok::sound::sound_instance_proxy_internal *m_first; // eax
  vostok::sound::sound_instance_proxy_internal *m_next_for_sound_world; // esi
  vostok::sound::sound_instance_proxy_internal *i; // eax
  bool m_is_audio_device_exist; // [esp+Fh] [ebp-19h]
  __int64 v13; // [esp+10h] [ebp-18h]
  vostok::math::float3 listener_position; // [esp+1Ch] [ebp-Ch] BYREF

  m_is_audio_device_exist = time_delta_ms->m_world->m_is_audio_device_exist;
  if ( !time_delta_ms->m_is_paused )
  {
    vostok::sound::sound_scene::process_fade(this, (int)time_delta_ms, time_delta);
    vostok::sound::sound_scene::update_receivers_position(v5, a2, (int)time_delta_ms);
    if ( time_delta_ms->m_is_listener_position_set )
    {
      vostok::math::half_pod::operator float(v6, &time_delta_ms->m_listener_position.m_data.m_val.x.data);
      *(float *)&v13 = a2;
      vostok::math::half_pod::operator float(v7, &time_delta_ms->m_listener_position.m_data.m_val.y.data);
      *((float *)&v13 + 1) = a2;
      vostok::math::half_pod::operator float(v8, &time_delta_ms->m_listener_position.m_data.m_val.z.data);
    }
    else
    {
      a2 = 0.0;
      v13 = 0;
    }
    m_first = time_delta_ms->m_active_proxies.m_first;
    *(_QWORD *)&listener_position.x = v13;
    listener_position.z = a2;
    if ( m_first )
    {
      do
      {
        m_next_for_sound_world = m_first->m_next_for_sound_world;
        vostok::sound::sound_instance_proxy_internal::tick(&listener_position, v6, m_first, time_delta);
        m_first = m_next_for_sound_world;
      }
      while ( m_next_for_sound_world );
    }
    for ( i = time_delta_ms->m_active_proxies.m_first; i; i = i->m_next_for_sound_world )
      ;
    if ( time_delta_ms->m_is_listener_position_set && m_is_audio_device_exist )
      vostok::sound::sound_scene::notify_listener2((vostok::sound::sound_scene *)v6, a2, a3, time_delta_ms, time_delta);
  }
}
