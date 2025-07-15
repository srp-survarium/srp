void __userpurge vostok::sound::sound_scene::calculate_hdr_audio_frame(
        const unsigned int time_delta_ms@<eax>,
        int a2@<edi>,
        vostok::sound::sound_scene *this,
        vostok::vectora<vostok::sound::new_sound_propagator *> *propagators)
{
  float v4; // xmm0_4
  vostok::vectora<vostok::sound::new_sound_propagator *> *v5; // edi
  void **M_start; // ebx
  float m_L_wintop; // xmm0_4
  float *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  int v12; // edi
  _DWORD *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  vostok::math::curve_line_points<float,0> *v16; // ecx
  float v17; // xmm0_4
  int v18; // edi
  double v19; // xmm0_8
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  void **i; // ebx
  void *v24; // esi
  int v25; // eax
  vostok::math::curve_line_points<float,0> *v26; // ecx
  float v27; // xmm1_4
  float v28; // xmm1_4
  void **j; // edi
  vostok::sound::new_sound_propagator *v30; // esi
  vostok::sound::sound_voice *sound_voice; // eax
  vostok::sound::new_sound_propagator *v32; // ecx
  long double v33; // [esp+20h] [ebp-28h]
  long double v34; // [esp+28h] [ebp-20h]
  float v35; // [esp+30h] [ebp-18h]
  float v36; // [esp+34h] [ebp-14h]
  float v37; // [esp+38h] [ebp-10h]
  float v38; // [esp+3Ch] [ebp-Ch]
  float v39; // [esp+40h] [ebp-8h]
  float v40; // [esp+40h] [ebp-8h]
  void **M_finish; // [esp+44h] [ebp-4h]

  LODWORD(v33) = a2;
  v39 = this->m_L_wintop - (double)time_delta_ms * 0.001 * s_spot_max_distance;
  v4 = v39;
  this->m_L_wintop = v39;
  if ( v39 <= 30.0 )
    v4 = default_fps_4;
  v5 = propagators;
  M_start = propagators->_M_impl._M_start;
  this->m_L_wintop = v4;
  m_L_wintop = 0.0;
  v36 = 0.0;
  M_finish = propagators->_M_impl._M_finish;
  if ( M_start != M_finish )
  {
    while ( 1 )
    {
      v8 = (float *)*M_start;
      v9 = *((_DWORD *)*M_start + 8);
      v10 = *((_DWORD *)*M_start + 7);
      if ( v9 >= v10 )
        break;
LABEL_24:
      if ( ++M_start == M_finish )
        goto LABEL_25;
    }
    v11 = v9 - v10;
    v37 = v8[13];
    v12 = v11;
    if ( *((_DWORD *)v8 + 4) )
    {
      v12 = v11 % *((_DWORD *)v8 + 10);
    }
    else if ( v11 >= *((_DWORD *)v8 + 10) )
    {
      goto LABEL_10;
    }
    v13 = (_DWORD *)(*(int (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)v8 + 3) + 4))(*((_DWORD *)v8 + 3), 0);
    v38 = ((double (__thiscall *)(_DWORD, int, _DWORD))*(_DWORD *)(*(_DWORD *)*v13 + 28))(*v13, v12, 0);
    if ( v38 > 0.0099999998 )
    {
      v14 = s_bm_current_air_resistance;
      if ( s_bm_current_air_resistance >= v38 )
      {
        v40 = v38;
        goto LABEL_12;
      }
LABEL_11:
      v40 = v14;
LABEL_12:
      v15 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v8 + 3) + 8))(*((_DWORD *)v8 + 3));
      v17 = v40;
      v18 = v15;
      v8[16] = v40;
      if ( *(_BYTE *)(v15 + 18) )
      {
        vostok::math::curve_line_points<float,0>::evaluate(
          v16,
          *(_DWORD *)v15 + 264,
          v37,
          0.0,
          range_time_type,
          0.0,
          0.0);
      }
      else
      {
        v19 = (float)(s_bm_current_air_resistance / v37);
        __libm_sse2_log10(v33);
        *(float *)&v19 = v19;
        v17 = (float)(*(float *)&v19 * 20.0) + *(float *)(v18 + 4);
      }
      v8[15] = v17;
      v20 = v17 - 3.0;
      v8[15] = v20;
      v35 = v20;
      if ( v40 <= 0.0099999998 )
      {
        v22 = 0.0;
      }
      else
      {
        if ( v40 > 0.0000099999997 )
        {
          __libm_sse2_log10(v33);
          v21 = v40 * 20.0;
        }
        else
        {
          v21 = FLOAT_N120_0;
        }
        v22 = v21 + v35;
      }
      v8[14] = v22;
      __libm_sse2_pow(v33, v34);
      v5 = propagators;
      m_L_wintop = (float)10.0 + v36;
      v36 = m_L_wintop;
      goto LABEL_24;
    }
LABEL_10:
    v14 = FLOAT_0_0099999998;
    goto LABEL_11;
  }
LABEL_25:
  if ( COERCE_FLOAT(LODWORD(m_L_wintop) & 0x7FFFFFFF) >= 0.0000099999997 )
  {
    __libm_sse2_log10(v33);
    m_L_wintop = m_L_wintop * 10.0;
    if ( this->m_L_wintop > m_L_wintop )
      m_L_wintop = this->m_L_wintop;
    this->m_L_wintop = m_L_wintop;
  }
  for ( i = v5->_M_impl._M_start; i != M_finish; ++i )
  {
    v24 = *i;
    if ( *((_DWORD *)*i + 8) >= *((_DWORD *)*i + 7) )
    {
      v25 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v24 + 3) + 8))(*((_DWORD *)v24 + 3));
      if ( *(_BYTE *)(v25 + 18) )
      {
        vostok::math::curve_line_points<float,0>::evaluate(
          v26,
          *(_DWORD *)v25 + 296,
          *((float *)v24 + 13),
          0.0,
          range_time_type,
          0.0,
          0.0);
      }
      else
      {
        v27 = *((float *)v24 + 13);
        m_L_wintop = v27 <= 2.0 ? s_bm_current_air_resistance : 2.0 / v27;
      }
      if ( !*((_BYTE *)v24 + 49) )
      {
        v28 = 0.0;
        if ( m_L_wintop <= 0.0 || (v28 = s_bm_current_air_resistance, s_bm_current_air_resistance < m_L_wintop) )
          m_L_wintop = v28;
        *((float *)v24 + 18) = m_L_wintop;
      }
    }
  }
  for ( j = v5->_M_impl._M_start; j != M_finish; ++j )
  {
    v30 = (vostok::sound::new_sound_propagator *)*j;
    if ( *((_DWORD *)*j + 8) >= *((_DWORD *)*j + 7) )
    {
      if ( vostok::sound::new_sound_propagator::amplitude((vostok::sound::new_sound_propagator *)*j) <= 0.0099999998 )
      {
        if ( v30->m_voice && v30->m_emitter->get_sound_options(v30->m_emitter)->can_be_displaced )
        {
          vostok::sound::new_sound_propagator::detach_voice(v32, (int)v30);
          v30->m_voice_displaced_timer = 2000;
        }
      }
      else if ( !v30->m_voice )
      {
        sound_voice = vostok::sound::sound_world::create_sound_voice(
                        (vostok::sound::sound_world *)v30->m_proxy->m_scene,
                        (int)v30->m_proxy->m_user->m_owner_world,
                        v30->m_proxy->m_scene,
                        v30,
                        v30->m_emitter);
        v30->m_voice = sound_voice;
        if ( sound_voice )
          sound_voice->m_start_deffered = 1;
      }
    }
  }
}
