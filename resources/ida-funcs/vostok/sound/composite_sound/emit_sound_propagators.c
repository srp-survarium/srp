void __userpurge vostok::sound::composite_sound::emit_sound_propagators(
        vostok::sound::composite_sound *this@<ecx>,
        float a2@<xmm0>,
        vostok::sound::sound_instance_proxy_internal *proxy,
        unsigned int playback_id,
        unsigned int start_delay_ms)
{
  vostok::sound::new_sound_propagator *m_first; // eax
  vostok::sound::composite_sound *v7; // esi
  vostok::math::float3 *listenet_position; // edi
  vostok::sound::sound_instance_proxy_internal *v9; // ecx
  vostok::math::float3 *position; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  void (__thiscall ***v18)(_DWORD, vostok::sound::sound_instance_proxy_internal *, unsigned int, unsigned int); // ecx
  volatile int m_flags; // eax
  int *v20; // edi
  int v21; // edx
  int v22; // eax
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // eax
  vostok::sound::new_sound_propagator *m_next_for_proxies; // ebx
  vostok::sound::new_sound_propagator *i; // esi
  vostok::sound::new_sound_propagator *v28; // edi
  vostok::sound::new_sound_propagator *m_master_propagator; // ecx
  vostok::math::float3 v30; // [esp+Ch] [ebp-28h] BYREF
  vostok::math::float3 v31; // [esp+18h] [ebp-1Ch] BYREF
  float v32; // [esp+24h] [ebp-10h]
  vostok::sound::new_sound_propagator *v33; // [esp+28h] [ebp-Ch]
  vostok::sound::new_sound_propagator *m_last; // [esp+2Ch] [ebp-8h]
  unsigned int v35; // [esp+30h] [ebp-4h]
  int v36; // [esp+3Ch] [ebp+8h]

  v33 = 0;
  m_first = proxy->m_propagators.m_first;
  v7 = this;
  if ( m_first
    && (this = (vostok::sound::composite_sound *)proxy->m_propagators.m_last,
        m_first == (vostok::sound::new_sound_propagator *)this) )
  {
    m_last = proxy->m_propagators.m_last;
  }
  else
  {
    m_last = 0;
  }
  listenet_position = vostok::sound::sound_scene::get_listenet_position(
                        (vostok::sound::sound_scene *)this,
                        (int)proxy->m_scene,
                        a2,
                        &v31);
  position = vostok::sound::sound_instance_proxy_internal::get_position(v9, (int)proxy, a2, &v30);
  x = position->x;
  y = position->y;
  z = position->z;
  v14 = (*((_DWORD *)&v7->vostok::resources::resource_flags + 3)
       - v7->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags)
      / 24;
  v15 = y - listenet_position->y;
  v16 = z - listenet_position->z;
  v17 = x - listenet_position->x;
  v35 = 0;
  v32 = fsqrt((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v17 * v17));
  if ( v14 )
  {
    v36 = 0;
    while ( 1 )
    {
      v18 = (void (__thiscall ***)(_DWORD, vostok::sound::sound_instance_proxy_internal *, unsigned int, unsigned int))(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v36 + v7->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags) + 28))(*(_DWORD *)(v36 + v7->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags));
      if ( !v18 )
        goto LABEL_14;
      m_flags = v7->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
      v20 = (int *)(m_flags + v36 + 4);
      if ( *(_BYTE *)(m_flags + v36 + 20) )
      {
        if ( *(float *)(m_flags + v36 + 12) <= v32 && v32 <= *(float *)(m_flags + v36 + 16) )
          break;
      }
LABEL_16:
      v25 = (*((_DWORD *)&v7->vostok::resources::resource_flags + 3)
           - v7->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags)
          / 24;
      ++v35;
      v36 += 24;
      if ( v35 >= v25 )
        goto LABEL_17;
    }
    v21 = *v20;
    v22 = *(_DWORD *)(m_flags + v36 + 8);
    if ( *v20 != v22 )
    {
      v23 = v22 - v21;
      v24 = 134775813 * HIDWORD(v7->m_reconstruction_info_actuality_tick) + 1;
      HIDWORD(v7->m_reconstruction_info_actuality_tick) = v24;
      v21 = *v20 + ((v23 * (unsigned __int64)(unsigned int)v24) >> 32);
    }
    (**v18)(v18, proxy, playback_id, start_delay_ms + v21);
LABEL_14:
    if ( LOWORD(v7->type) == v35 )
      v33 = proxy->m_propagators.m_last;
    goto LABEL_16;
  }
LABEL_17:
  if ( LOWORD(v7->type) != 0xFFFF )
  {
    if ( m_last )
      m_next_for_proxies = m_last->m_next_for_proxies;
    else
      m_next_for_proxies = proxy->m_propagators.m_first;
    for ( i = m_next_for_proxies; i; i = i->m_next_for_proxies )
    {
      v28 = v33;
      if ( i != v33 )
      {
        if ( !v33 )
        {
          m_master_propagator = i->m_master_propagator;
          if ( m_master_propagator )
          {
            i->m_out_amplitude_value = vostok::sound::new_sound_propagator::amplitude(m_master_propagator);
            i->m_amplitude_freezed = 1;
          }
        }
        i->m_master_propagator = v28;
      }
    }
  }
}
