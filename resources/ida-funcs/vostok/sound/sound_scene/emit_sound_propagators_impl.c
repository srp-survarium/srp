void __userpurge vostok::sound::sound_scene::emit_sound_propagators_impl(
        vostok::sound::sound_scene *this@<ecx>,
        float value@<xmm0>,
        const vostok::sound::create_sound_propagator_params *params)
{
  const vostok::sound::create_sound_propagator_params *v3; // esi
  vostok::sound::sound_instance_proxy_internal *m_proxy; // ebx
  vostok::math::float3 *position; // eax
  vostok::math::half *v6; // ecx
  vostok::sound::atomic_half3 *v7; // ecx
  vostok::sound::sound_propagator_emitter_vtbl *v8; // edi
  unsigned int v9; // eax
  vostok::sound::new_sound_propagator *m_next_for_proxies; // eax
  __int32 v11; // edi
  vostok::sound::new_sound_propagator *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // edi
  vostok::memory::doug_lea_allocator *v15; // esi
  char *v16; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  vostok::memory::doug_lea_allocator *v18; // eax
  vostok::sound::world_user *m_user; // ebx
  vostok::sound::sound_instance_proxy_internal *m_first; // ecx
  vostok::sound::sound_instance_proxy_internal *v21; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>,boost::_bi::value<unsigned int> > > v22; // [esp-8h] [ebp-6Ch]
  const vostok::sound::sound_propagator_emitter *m_propagator_emitter; // [esp+18h] [ebp-4Ch]
  vostok::sound::new_sound_propagator *m_last; // [esp+1Ch] [ebp-48h]
  char v25; // [esp+20h] [ebp-44h]
  int v27; // [esp+24h] [ebp-40h]
  vostok::math::half3 v28[2]; // [esp+28h] [ebp-3Ch] BYREF
  vostok::math::float3 v29; // [esp+34h] [ebp-30h] BYREF
  unsigned int m_playback_id; // [esp+40h] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+44h] [ebp-20h] BYREF

  v25 = 0;
  m_last = 0;
  v3 = params;
  m_proxy = params->m_proxy;
  m_propagator_emitter = m_proxy->m_propagator_emitter;
  if ( params->m_continue_loop )
    m_last = m_proxy->m_propagators.m_last;
  if ( !this->m_is_listener_position_set )
  {
    position = vostok::sound::sound_instance_proxy_internal::get_position(
                 (vostok::sound::sound_instance_proxy_internal *)this,
                 (int)m_proxy,
                 value,
                 &v29);
    vostok::math::half3::half3(v28, position, v6);
    vostok::sound::atomic_half3::set(v7, (vostok::math::half3 *)&this->m_listener_position, (int)v28);
    v3 = params;
  }
  vostok::math::half_pod::operator float((vostok::math::half_pod *)this, &m_proxy->m_ext_params.m_data.m_val.x.data);
  v8 = m_propagator_emitter->__vftable;
  *(float *)&v28[0].x.data = value;
  v9 = vostok::math::ceil(value);
  v8->emit_sound_propagators(m_propagator_emitter, m_proxy, v3->m_playback_id, v9);
  if ( v3->m_continue_loop )
    m_next_for_proxies = m_last->m_next_for_proxies;
  else
    m_next_for_proxies = m_proxy->m_propagators.m_first;
  v11 = 0;
  v12 = m_next_for_proxies;
  if ( m_next_for_proxies )
  {
    do
    {
      v13 = v12->m_start_offset_ms + v12->m_sound_length_ms;
      v14 = m_next_for_proxies->m_start_offset_ms + m_next_for_proxies->m_sound_length_ms;
      m_next_for_proxies->m_is_callback_executer = 0;
      if ( v14 > v13 )
        v12 = m_next_for_proxies;
      m_next_for_proxies = m_next_for_proxies->m_next_for_proxies;
      v11 = 0;
    }
    while ( m_next_for_proxies );
    if ( v12 )
      v12->m_is_callback_executer = 1;
  }
  if ( m_proxy->m_propagators.m_first )
  {
    if ( !v3->m_continue_loop )
    {
      m_first = this->m_active_proxies.m_first;
      if ( m_first )
      {
        v21 = v3->m_proxy;
        while ( m_first != v21 )
        {
          m_first = m_first->m_next_for_sound_world;
          if ( !m_first )
            goto LABEL_25;
        }
      }
      else
      {
LABEL_25:
        m_proxy->m_next_for_sound_world = 0;
        ++this->m_active_proxies.m_size;
        if ( this->m_active_proxies.m_first )
          this->m_active_proxies.m_last->m_next_for_sound_world = m_proxy;
        else
          this->m_active_proxies.m_first = m_proxy;
        this->m_active_proxies.m_last = m_proxy;
      }
    }
  }
  else
  {
    v15 = vostok::sound::g_allocator;
    v16 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_response> `RTTI Type Descriptor');
    v27 = (int)v15->call_malloc(
                 v15,
                 48u,
                 v16,
                 "vostok::sound::sound_scene::emit_sound_propagators_impl",
                 ".\\sound_scene_propagators.cpp",
                 80u);
    if ( v27 )
    {
      m_playback_id = m_proxy->m_playback_id;
      LODWORD(v29.x) = vostok::sound::sound_instance_proxy_internal::execute_finished_callback;
      v29.y = 0.0;
      LODWORD(v29.z) = m_proxy;
      HIDWORD(v22.f_.f_) = vostok::sound::sound_instance_proxy_internal::execute_finished_callback;
      v22.l_.a1_.t_ = 0;
      v22.l_.a2_.t_ = (unsigned int)m_proxy;
      LODWORD(v22.f_.f_) = &f;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function<void __cdecl(void)> *)vostok::sound::sound_instance_proxy_internal::execute_finished_callback,
        v22,
        m_playback_id);
      v18 = vostok::sound::g_allocator;
      *(_DWORD *)(v27 + 8) = 0;
      *(_DWORD *)(v27 + 4) = v18;
      v25 = 1;
      *(_DWORD *)v27 = &vostok::sound::functor_command<vostok::sound::sound_response>::`vftable';
      boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        &f,
        (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v27 + 16));
      v11 = v27;
    }
    if ( (v25 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v17,
        (int *)&f);
    m_user = m_proxy->m_user;
    *(_DWORD *)(v11 + 8) = 0;
    _InterlockedExchange((volatile __int32 *)&m_user->m_channel.responses.m_forward_queue.m_head->m_next, v11);
    m_user->m_channel.responses.m_forward_queue.m_head = (vostok::sound::sound_response *)v11;
  }
}
