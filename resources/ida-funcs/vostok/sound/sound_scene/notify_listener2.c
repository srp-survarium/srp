void __userpurge vostok::sound::sound_scene::notify_listener2(
        vostok::sound::sound_scene *this@<ecx>,
        float a2@<xmm0>,
        vostok::sound::sound_scene *time_delta_ms,
        unsigned int time_delta_msa)
{
  vostok::math::half_pod *v5; // ecx
  vostok::math::half_pod *v6; // ecx
  vostok::sound::sound_instance_proxy_internal *m_first; // esi
  vostok::sound::sound_instance_proxy_internal *v8; // ecx
  vostok::math::float3 *position; // eax
  vostok::sound::new_sound_propagator *v10; // ebx
  vostok::sound::sound_voice *v11; // ecx
  void **M_start; // eax
  vostok::sound::new_sound_propagator *v13; // ebx
  int v14; // eax
  vostok::sound::voice_bridge *v15; // ecx
  long double v16; // rdi
  bool v17; // zf
  unsigned __int8 m_channels_num; // al
  vostok::math::float3 *v19; // eax
  float v20; // xmm2_4
  vostok::sound::sound_voice *m_voice; // eax
  int v22; // eax
  vostok::sound::sound_voice *v23; // eax
  vostok::sound::voice_bridge *v24; // eax
  vostok::sound::sound_voice *v25; // esi
  vostok::sound::voice_bridge *v26; // esi
  int v27; // ebx
  float m_dist_to_listener; // [esp+0h] [ebp-5Ch]
  float v29; // [esp+Ch] [ebp-50h]
  bool v30; // [esp+10h] [ebp-4Ch]
  float level_matrix; // [esp+18h] [ebp-44h] BYREF
  float v32; // [esp+1Ch] [ebp-40h]
  float v33; // [esp+20h] [ebp-3Ch]
  float v34; // [esp+24h] [ebp-38h]
  float v35; // [esp+28h] [ebp-34h] BYREF
  vostok::vectora<vostok::sound::new_sound_propagator *> propagators; // [esp+2Ch] [ebp-30h] BYREF
  vostok::math::float3 v37; // [esp+3Ch] [ebp-20h] BYREF
  float v38; // [esp+48h] [ebp-14h]
  float v39; // [esp+4Ch] [ebp-10h] BYREF
  float v40; // [esp+50h] [ebp-Ch]
  float v41; // [esp+54h] [ebp-8h]
  void **v42; // [esp+58h] [ebp-4h] BYREF
  float time_delta_msb; // [esp+68h] [ebp+Ch]
  unsigned __int8 time_delta_ms_3; // [esp+6Bh] [ebp+Fh]

  vostok::math::half_pod::operator float(
    (vostok::math::half_pod *)this,
    &time_delta_ms->m_listener_position.m_data.m_val.x.data);
  v38 = a2;
  vostok::math::half_pod::operator float(v5, &time_delta_ms->m_listener_position.m_data.m_val.y.data);
  v39 = a2;
  vostok::math::half_pod::operator float(v6, &time_delta_ms->m_listener_position.m_data.m_val.z.data);
  m_first = time_delta_ms->m_active_proxies.m_first;
  v8 = (vostok::sound::sound_instance_proxy_internal *)vostok::sound::g_allocator;
  v40 = a2;
  propagators._M_impl._M_start = 0;
  propagators._M_impl._M_finish = 0;
  propagators._M_impl._M_end_of_storage.m_allocator = vostok::sound::g_allocator;
  for ( propagators._M_impl._M_end_of_storage._M_data = 0; m_first; m_first = m_first->m_next_for_sound_world )
  {
    position = vostok::sound::sound_instance_proxy_internal::get_position(v8, (int)m_first, a2, &v37);
    v10 = m_first->m_propagators.m_first;
    a2 = fsqrt(
           (float)((float)((float)(position->z - v40) * (float)(position->z - v40))
                 + (float)((float)(position->y - v39) * (float)(position->y - v39)))
         + (float)((float)(position->x - v38) * (float)(position->x - v38)));
    v41 = a2;
    v42 = (void **)v10;
    if ( v10 )
    {
      while ( 1 )
      {
        if ( a2 <= s_bm_current_air_resistance )
          a2 = s_bm_current_air_resistance;
        v10->m_dist_to_listener = a2;
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(
          (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)&v42,
          (stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *)&propagators);
        v10 = v10->m_next_for_proxies;
        v42 = (void **)v10;
        if ( !v10 )
          break;
        a2 = v41;
      }
    }
  }
  vostok::sound::sound_scene::calculate_hdr_audio_frame(time_delta_msa, (int)time_delta_ms, time_delta_ms, &propagators);
  M_start = propagators._M_impl._M_start;
  v42 = propagators._M_impl._M_start;
  while ( M_start != propagators._M_impl._M_finish )
  {
    v13 = (vostok::sound::new_sound_propagator *)*v42;
    if ( !*((_DWORD *)*v42 + 1) )
      goto LABEL_46;
    v14 = (int)v13->m_emitter->get_sound_options(v13->m_emitter);
    HIDWORD(v16) = v13->m_proxy;
    LODWORD(v16) = v14;
    v17 = *(_BYTE *)(v14 + 16) == 0;
    m_channels_num = v13->m_voice->m_current_sound_quality.m_object->m_channels_num;
    v41 = *(float *)&v16;
    time_delta_ms_3 = m_channels_num;
    if ( v17 || *(_DWORD *)(HIDWORD(v16) + 128) == 3 )
    {
      a2 = s_bm_current_air_resistance;
      level_matrix = s_bm_current_air_resistance;
      v35 = 0.0;
      if ( m_channels_num != 2 )
      {
        v32 = s_bm_current_air_resistance;
LABEL_24:
        if ( time_delta_ms_3 == 1 )
        {
          v20 = a2 - (float)((float)(a2 - v35) * vostok::sound::s_lpf_param);
          if ( v20 > 0.0 )
          {
            if ( a2 >= v20 )
              a2 = a2 - (float)((float)(a2 - v35) * vostok::sound::s_lpf_param);
          }
          else
          {
            a2 = 0.0;
          }
          m_voice = v13->m_voice;
          v17 = !m_voice->m_start_deffered;
          v22 = (int)m_voice->m_voice;
          if ( v17 )
          {
            vostok::sound::voice_bridge::set_filter_params_impl(v15, v22, 0, a2, LowPassFilter, v29, v30);
          }
          else if ( *(_BYTE *)(v22 + 9) )
          {
            *(_DWORD *)(v22 + 24) = 0;
            *(float *)(v22 + 28) = a2;
          }
        }
        goto LABEL_33;
      }
      v32 = 0.0;
      v33 = 0.0;
    }
    else
    {
      m_dist_to_listener = v13->m_dist_to_listener;
      v19 = vostok::sound::sound_instance_proxy_internal::get_position(
              (vostok::sound::sound_instance_proxy_internal *)v15,
              SHIDWORD(v16),
              a2,
              &v37);
      vostok::sound::sound_scene::calculate_3d_pan(
        (vostok::sound::sound_scene *)&time_delta_ms->m_world->m_panning_lut,
        v16,
        (const vostok::sound::panning_lut *)time_delta_ms,
        (const vostok::sound::sound_instance_proxy_internal *)&time_delta_ms->m_world->m_panning_lut,
        (const vostok::math::float3 *)HIDWORD(v16),
        v19,
        m_dist_to_listener,
        &v39,
        &v35);
      if ( time_delta_ms_3 != 2 )
      {
        level_matrix = v39;
        v32 = v40;
        a2 = s_bm_current_air_resistance;
        goto LABEL_24;
      }
      a2 = FLOAT_0_25;
      if ( v39 >= 0.25 )
        level_matrix = v39;
      else
        level_matrix = FLOAT_0_25;
      v32 = 0.0;
      v33 = 0.0;
      if ( v40 >= 0.25 )
      {
        v34 = v40;
        goto LABEL_33;
      }
    }
    v34 = a2;
LABEL_33:
    v23 = v13->m_voice;
    if ( v23->m_start_deffered )
    {
      v24 = v23->m_voice;
      v17 = v24->m_params.channels_num == 1;
      v24->m_output_level_matrix[0] = level_matrix;
      a2 = v32;
      v24->m_output_level_matrix[1] = v32;
      if ( v17 )
      {
        v24->m_output_level_matrix[2] = 0.0;
        v24->m_output_level_matrix[3] = 0.0;
      }
      else
      {
        v24->m_output_level_matrix[2] = v33;
        a2 = v34;
        v24->m_output_level_matrix[3] = v34;
      }
    }
    else
    {
      vostok::sound::voice_bridge::set_output_matrix_impl(v23->m_voice, &level_matrix, 0);
      *(float *)&v16 = v41;
    }
    v25 = v13->m_voice;
    time_delta_msb = vostok::sound::new_sound_propagator::amplitude(v13) * *(float *)(LODWORD(v16) + 8);
    if ( v25->m_start_deffered )
    {
      a2 = 0.0;
      v26 = v25->m_voice;
      if ( time_delta_msb > 0.0 )
      {
        a2 = s_bm_current_air_resistance;
        if ( s_bm_current_air_resistance >= time_delta_msb )
          a2 = time_delta_msb;
      }
      v26->m_volume = a2;
    }
    else
    {
      vostok::sound::voice_bridge::set_volume_impl(v25->m_voice, time_delta_msb, 0);
    }
    v27 = (int)v13->m_voice;
    if ( *(_BYTE *)(v27 + 36) )
    {
      *(_BYTE *)(v27 + 36) = 0;
      vostok::sound::sound_voice::start_impl(v11, v27);
    }
LABEL_46:
    M_start = ++v42;
  }
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    (stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *)v11,
    (int)&propagators);
}
