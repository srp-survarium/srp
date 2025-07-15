void __userpurge vostok::sound::sound_instance_proxy_internal::tick(
        const vostok::math::float3 *listener_position@<eax>,
        vostok::sound::new_sound_propagator *a2@<ecx>,
        vostok::sound::sound_instance_proxy_internal *this,
        unsigned int delta_time)
{
  vostok::sound::sound_instance_proxy_internal *v4; // ebx
  vostok::sound::atomic_half3 *v5; // ecx
  vostok::sound::new_sound_propagator *i; // esi
  vostok::sound::new_sound_propagator::propagation_state m_propagation_state; // eax
  unsigned int m_voice_displaced_timer; // eax
  bool v9; // zf
  vostok::sound::new_sound_propagator *m_first; // edi
  vostok::sound::new_sound_propagator *m_next_for_proxies; // ebx
  vostok::math::half3 v12; // [esp+10h] [ebp-8h] BYREF

  v4 = this;
  if ( this->m_type == hud )
  {
    vostok::math::half3::half3(&v12, listener_position, (vostok::math::half *)a2);
    vostok::sound::atomic_half3::set(v5, (vostok::math::half3 *)&this->m_position, (int)&v12);
  }
  for ( i = this->m_propagators.m_first; i; i = *(vostok::sound::new_sound_propagator **)&v12.x.data )
  {
    *(_DWORD *)&v12.x.data = i->m_next_for_proxies;
    m_propagation_state = i->m_propagation_state;
    if ( m_propagation_state )
    {
      if ( m_propagation_state == propagating_idle )
      {
        i->m_propagation_state = propagating;
        i->m_propagation_time_ms = 0;
      }
    }
    else
    {
      i->m_propagation_time_ms += delta_time;
      m_voice_displaced_timer = i->m_voice_displaced_timer;
      a2 = (vostok::sound::new_sound_propagator *)i->m_propagation_time_ms;
      if ( m_voice_displaced_timer <= delta_time )
        i->m_voice_displaced_timer = 0;
      else
        i->m_voice_displaced_timer = m_voice_displaced_timer - delta_time;
      if ( (unsigned int)a2 > i->m_end_propagation_time_ms )
      {
        v9 = i->m_voice == 0;
        i->m_propagation_state = propagating_finished;
        if ( !v9 )
          vostok::sound::new_sound_propagator::detach_voice(a2, (int)i);
        if ( i->m_is_callback_executer )
          vostok::sound::new_sound_propagator::execute_finished_callback(a2, (int)i);
      }
    }
    if ( i->m_propagation_state == propagating_finished )
    {
      m_first = v4->m_propagators.m_first;
      if ( m_first )
      {
        do
        {
          a2 = m_first->m_master_propagator;
          m_next_for_proxies = m_first->m_next_for_proxies;
          if ( a2 == i )
          {
            if ( a2 )
            {
              m_first->m_out_amplitude_value = vostok::sound::new_sound_propagator::amplitude(a2);
              m_first->m_amplitude_freezed = 1;
            }
            m_first->m_master_propagator = 0;
          }
          m_first = m_next_for_proxies;
        }
        while ( m_next_for_proxies );
        v4 = this;
      }
      vostok::sound::sound_scene::delete_sound_propagator(
        i,
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)a2,
        v4->m_scene,
        v4);
    }
  }
}
