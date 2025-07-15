void __thiscall survarium::game_options::fill_settings_data(survarium::game_options *this, int a2)
{
  vostok::fixed_string<64> *v2; // esi
  char *m_begin; // eax
  char *v4; // ecx
  char *v5; // ecx
  char *v6; // ecx
  char *v7; // ecx
  char *v8; // ecx
  char *v9; // ecx
  char *v10; // ecx
  char *v11; // ecx
  vostok::fixed_string<64> *v12; // ebx
  char *v13; // eax
  char *v14; // ecx
  char *v15; // ecx
  char *v16; // ecx
  char *v17; // ecx
  char *v18; // ecx
  char *v19; // ecx
  char *v20; // ecx
  char *v21; // ecx
  char *v22; // ecx
  char *v23; // ecx
  char *v24; // ecx
  char *v25; // ecx
  char *v26; // ecx
  char *v27; // ecx
  char *v28; // ecx
  char *v29; // ecx
  char *v30; // ecx
  char *v31; // ecx
  vostok::fixed_string<64> *v32; // esi
  char *v33; // eax
  char *v34; // ecx
  char *v35; // ecx
  char *v36; // ecx
  char *v37; // ecx
  char *v38; // ecx
  char *v39; // ecx
  vostok::fixed_string<64> *v40; // eax
  char *v41; // ecx
  vostok::buffer_string *v42; // eax
  char *v43; // ecx
  vostok::fixed_string<64> *v44; // edi
  survarium::flash_value *v45; // ecx
  survarium::flash_value *v46; // ecx
  int v47; // edx
  survarium::flash_movie *v48; // ecx
  int v49; // eax
  int v50; // eax
  survarium::text_translator *v51; // ecx
  survarium::flash_value *v52; // ecx
  survarium::flash_movie *v53; // ecx
  int v54; // esi
  survarium::flash_value *v55; // ecx
  int v56; // eax
  survarium::flash_value *v57; // ecx
  Scaleform::GFx::Value *v58; // esi
  int i; // edi
  vostok::memory::doug_lea_allocator *v60; // ecx
  vostok::memory::doug_lea_allocator *v61; // ecx
  vostok::memory::doug_lea_allocator *v62; // ecx
  vostok::memory::doug_lea_allocator *v63; // ecx
  char *v64; // [esp-8h] [ebp-2A4h]
  const char *v65; // [esp+0h] [ebp-29Ch]
  const char *v66; // [esp+0h] [ebp-29Ch]
  const char *v67; // [esp+0h] [ebp-29Ch]
  const char *v68; // [esp+0h] [ebp-29Ch]
  const char *v69; // [esp+4h] [ebp-298h]
  const char *v70; // [esp+4h] [ebp-298h]
  const char *v71; // [esp+4h] [ebp-298h]
  const char *v72; // [esp+4h] [ebp-298h]
  unsigned int v73; // [esp+8h] [ebp-294h]
  unsigned int v74; // [esp+8h] [ebp-294h]
  unsigned int v75; // [esp+8h] [ebp-294h]
  unsigned int v76; // [esp+8h] [ebp-294h]
  char v77[512]; // [esp+10h] [ebp-28Ch] BYREF
  survarium::flash_value v78; // [esp+210h] [ebp-8Ch] BYREF
  Scaleform::GFx::Value pvalue; // [esp+228h] [ebp-74h] BYREF
  survarium::flash_value v80; // [esp+240h] [ebp-5Ch] BYREF
  survarium::flash_value v81; // [esp+258h] [ebp-44h] BYREF
  int v82; // [esp+270h] [ebp-2Ch]
  vostok::fixed_string<64> *v83; // [esp+274h] [ebp-28h]
  vostok::fixed_string<64> *v84; // [esp+278h] [ebp-24h]
  vostok::fixed_string<64> *v85; // [esp+27Ch] [ebp-20h]
  int v86; // [esp+280h] [ebp-1Ch]
  _DWORD **v87; // [esp+284h] [ebp-18h]
  char **p_m_begin; // [esp+288h] [ebp-14h]
  unsigned int idx; // [esp+28Ch] [ebp-10h]
  unsigned int value; // [esp+290h] [ebp-Ch]
  unsigned __int8 v91; // [esp+297h] [ebp-5h]

  v2 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(
         survarium::g_allocator,
         9u);
  m_begin = v2->m_begin;
  v83 = v2;
  if ( m_begin != "st_invite_from_friends_option" )
  {
    v2->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(v2, "st_invite_from_friends_option");
  }
  v4 = v2[1].m_begin;
  if ( v4 != "st_friends_signin_notification_option" )
  {
    v2[1].m_end = v4;
    *v4 = 0;
    vostok::buffer_string::operator+=(v2 + 1, "st_friends_signin_notification_option");
  }
  v5 = v2[2].m_begin;
  if ( v5 != "st_messages_censor_option" )
  {
    v2[2].m_end = v5;
    *v5 = 0;
    vostok::buffer_string::operator+=(v2 + 2, "st_messages_censor_option");
  }
  v6 = v2[3].m_begin;
  if ( v6 != "st_messages_only_from_friends_option" )
  {
    v2[3].m_end = v6;
    *v6 = 0;
    vostok::buffer_string::operator+=(v2 + 3, "st_messages_only_from_friends_option");
  }
  v7 = v2[4].m_begin;
  if ( v7 != "st_private_messages_in_game_option" )
  {
    v2[4].m_end = v7;
    *v7 = 0;
    vostok::buffer_string::operator+=(v2 + 4, "st_private_messages_in_game_option");
  }
  v8 = v2[5].m_begin;
  if ( v8 != "st_hide_spam_option" )
  {
    v2[5].m_end = v8;
    *v8 = 0;
    vostok::buffer_string::operator+=(v2 + 5, "st_hide_spam_option");
  }
  v9 = v2[6].m_begin;
  if ( v9 != "st_crosshair_type_option" )
  {
    v2[6].m_end = v9;
    *v9 = 0;
    vostok::buffer_string::operator+=(v2 + 6, "st_crosshair_type_option");
  }
  v10 = v2[7].m_begin;
  if ( v10 != "st_crosshair_static_option" )
  {
    v2[7].m_end = v10;
    *v10 = 0;
    vostok::buffer_string::operator+=(v2 + 7, "st_crosshair_static_option");
  }
  v11 = v2[8].m_begin;
  if ( v11 != "st_minimap_rotable_option" )
  {
    v2[8].m_end = v11;
    *v11 = 0;
    vostok::buffer_string::operator+=(v2 + 8, "st_minimap_rotable_option");
  }
  v12 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(
          survarium::g_allocator,
          0x13u);
  v13 = v12->m_begin;
  if ( v12->m_begin != "st_monitor_count_option" )
  {
    v12->m_end = v13;
    *v13 = 0;
    vostok::buffer_string::operator+=(v12, "st_monitor_count_option");
  }
  v14 = v12[1].m_begin;
  if ( v14 != "st_resolution_option" )
  {
    v12[1].m_end = v14;
    *v14 = 0;
    vostok::buffer_string::operator+=(v12 + 1, "st_resolution_option");
  }
  v15 = v12[2].m_begin;
  if ( v15 != "st_fullscreen_option" )
  {
    v12[2].m_end = v15;
    *v15 = 0;
    vostok::buffer_string::operator+=(v12 + 2, "st_fullscreen_option");
  }
  v16 = v12[3].m_begin;
  if ( v16 != "st_vsync_option" )
  {
    v12[3].m_end = v16;
    *v16 = 0;
    vostok::buffer_string::operator+=(v12 + 3, "st_vsync_option");
  }
  v17 = v12[4].m_begin;
  if ( v17 != "st_antialiasing_option" )
  {
    v12[4].m_end = v17;
    *v17 = 0;
    vostok::buffer_string::operator+=(v12 + 4, "st_antialiasing_option");
  }
  v18 = v12[5].m_begin;
  if ( v18 != "st_aniso_filtering_option" )
  {
    v12[5].m_end = v18;
    *v18 = 0;
    vostok::buffer_string::operator+=(v12 + 5, "st_aniso_filtering_option");
  }
  v19 = v12[6].m_begin;
  if ( v19 != "st_options_adjust_gamma" )
  {
    v12[6].m_end = v19;
    *v19 = 0;
    vostok::buffer_string::operator+=(v12 + 6, "st_options_adjust_gamma");
  }
  v20 = v12[7].m_begin;
  if ( v20 != "st_fov_option" )
  {
    v12[7].m_end = v20;
    *v20 = 0;
    vostok::buffer_string::operator+=(v12 + 7, "st_fov_option");
  }
  v21 = v12[8].m_begin;
  if ( v21 != "st_graphics_quality_option" )
  {
    v12[8].m_end = v21;
    *v21 = 0;
    vostok::buffer_string::operator+=(v12 + 8, "st_graphics_quality_option");
  }
  v22 = v12[9].m_begin;
  if ( v22 != "st_texture_quality_option" )
  {
    v12[9].m_end = v22;
    *v22 = 0;
    vostok::buffer_string::operator+=(v12 + 9, "st_texture_quality_option");
  }
  v23 = v12[10].m_begin;
  if ( v23 != "st_geometry_quality_option" )
  {
    v12[10].m_end = v23;
    *v23 = 0;
    vostok::buffer_string::operator+=(v12 + 10, "st_geometry_quality_option");
  }
  v24 = v12[11].m_begin;
  if ( v24 != "st_shadow_quality_option" )
  {
    v12[11].m_end = v24;
    *v24 = 0;
    vostok::buffer_string::operator+=(v12 + 11, "st_shadow_quality_option");
  }
  v25 = v12[12].m_begin;
  if ( v25 != "st_lightning_quality_option" )
  {
    v12[12].m_end = v25;
    *v25 = 0;
    vostok::buffer_string::operator+=(v12 + 12, "st_lightning_quality_option");
  }
  v26 = v12[13].m_begin;
  if ( v26 != "st_shading_quality_option" )
  {
    v12[13].m_end = v26;
    *v26 = 0;
    vostok::buffer_string::operator+=(v12 + 13, "st_shading_quality_option");
  }
  v27 = v12[14].m_begin;
  if ( v27 != "st_decorations_options" )
  {
    v12[14].m_end = v27;
    *v27 = 0;
    vostok::buffer_string::operator+=(v12 + 14, "st_decorations_options");
  }
  v28 = v12[15].m_begin;
  if ( v28 != "st_post_process_options" )
  {
    v12[15].m_end = v28;
    *v28 = 0;
    vostok::buffer_string::operator+=(v12 + 15, "st_post_process_options");
  }
  v29 = v12[16].m_begin;
  if ( v29 != "st_ambient_occlusion_options" )
  {
    v12[16].m_end = v29;
    *v29 = 0;
    vostok::buffer_string::operator+=(v12 + 16, "st_ambient_occlusion_options");
  }
  v30 = v12[17].m_begin;
  if ( v30 != "st_particles_quality_options" )
  {
    v12[17].m_end = v30;
    *v30 = 0;
    vostok::buffer_string::operator+=(v12 + 17, "st_particles_quality_options");
  }
  v31 = v12[18].m_begin;
  if ( v31 != "st_motion_blur_amount_options" )
  {
    v12[18].m_end = v31;
    *v31 = 0;
    vostok::buffer_string::operator+=(v12 + 18, "st_motion_blur_amount_options");
  }
  v32 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(
          survarium::g_allocator,
          7u);
  v33 = v32->m_begin;
  v84 = v32;
  if ( v33 != "st_general_volume_option" )
  {
    v32->m_end = v33;
    *v33 = 0;
    vostok::buffer_string::operator+=(v32, "st_general_volume_option");
  }
  v34 = v32[1].m_begin;
  if ( v34 != "st_ingame_volume_option" )
  {
    v32[1].m_end = v34;
    *v34 = 0;
    vostok::buffer_string::operator+=(v32 + 1, "st_ingame_volume_option");
  }
  v35 = v32[2].m_begin;
  if ( v35 != "st_music_volume_option" )
  {
    v32[2].m_end = v35;
    *v35 = 0;
    vostok::buffer_string::operator+=(v32 + 2, "st_music_volume_option");
  }
  v36 = v32[3].m_begin;
  if ( v36 != "st_voice_chat_volume_option" )
  {
    v32[3].m_end = v36;
    *v36 = 0;
    vostok::buffer_string::operator+=(v32 + 3, "st_voice_chat_volume_option");
  }
  v37 = v32[4].m_begin;
  if ( v37 != "st_use_microphone_option" )
  {
    v32[4].m_end = v37;
    *v37 = 0;
    vostok::buffer_string::operator+=(v32 + 4, "st_use_microphone_option");
  }
  v38 = v32[5].m_begin;
  if ( v38 != "st_microphone_sensitivity_option" )
  {
    v32[5].m_end = v38;
    *v38 = 0;
    vostok::buffer_string::operator+=(v32 + 5, "st_microphone_sensitivity_option");
  }
  v39 = v32[6].m_begin;
  if ( v39 != "st_ptt_button_option" )
  {
    v32[6].m_end = v39;
    *v39 = 0;
    vostok::buffer_string::operator+=(v32 + 6, "st_ptt_button_option");
  }
  v40 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(
          survarium::g_allocator,
          2u);
  v41 = v40->m_begin;
  v85 = v40;
  if ( v41 != "st_mouse_invertion_option" )
  {
    v40->m_end = v41;
    *v41 = 0;
    v40 = (vostok::fixed_string<64> *)vostok::buffer_string::operator+=(v40, "st_mouse_invertion_option");
  }
  v42 = v40 + 1;
  v43 = v42->m_begin;
  if ( v42->m_begin != "st_mouse_sensitivity_option" )
  {
    v42->m_end = v43;
    *v43 = 0;
    vostok::buffer_string::operator+=(v42, "st_mouse_sensitivity_option");
  }
  value = 0;
  v87 = (_DWORD **)(a2 + 20);
  v86 = 4;
  do
  {
    v44 = 0;
    v91 = 0;
    if ( value )
    {
      switch ( value )
      {
        case 1u:
          v44 = v85;
          v91 = 2;
          break;
        case 2u:
          v44 = v12;
          v91 = 19;
          break;
        case 3u:
          v44 = v84;
          v91 = 7;
          break;
      }
    }
    else
    {
      v44 = v83;
      v91 = 9;
    }
    v45 = &v78;
    do
    {
      survarium::flash_value::flash_value(v45);
      v45 = v46 + 1;
    }
    while ( v47 - 1 >= 0 );
    survarium::flash_value::SetUInt(v45, (int)&v78, value);
    Scaleform::GFx::Movie::CreateArray(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
      &pvalue);
    if ( v91 )
    {
      idx = 0;
      p_m_begin = &v44->m_begin;
      v82 = v91;
      do
      {
        v49 = *(_DWORD *)(a2 + 12);
        *(_DWORD *)v80.body = 0;
        *(_DWORD *)&v80.body[4] = 0;
        survarium::flash_movie::CreateObject(
          v48,
          *(survarium::flash_value **)(v49 + 264),
          (Scaleform::GFx::Value *)&v80);
        v64 = *p_m_begin;
        v50 = *(_DWORD *)(a2 + 52) + 13944;
        *(_DWORD *)v81.body = 0;
        *(_DWORD *)&v81.body[4] = 0;
        survarium::text_translator::translate_text(v51, v50, v64, v77);
        survarium::flash_value::SetString(&v81, v77);
        survarium::flash_value::SetMember(v52, &v80, "label", &v81);
        if ( *v87 )
        {
          v54 = *(_DWORD *)(**v87 + 4 * idx);
          Scaleform::GFx::Movie::CreateFunction(
            *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
            (Scaleform::GFx::Value *)&v81,
            *(Scaleform::GFx::FunctionHandler **)(v54 + 4),
            0);
          survarium::flash_value::SetMember(v55, &v80, "setter", &v81);
          v56 = *(_DWORD *)(v54 + 12);
          if ( v56 == 1 )
          {
            Scaleform::GFx::Movie::CreateArray(
              *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
              (Scaleform::GFx::Value *)&v81);
LABEL_93:
            (*(void (__thiscall **)(int, survarium::flash_value *))(*(_DWORD *)v54 + 8))(v54, &v81);
            survarium::flash_value::SetMember(v57, &v80, "dataProvider", &v81);
            goto LABEL_94;
          }
          if ( v56 == 2 )
          {
            survarium::flash_movie::CreateObject(
              v53,
              *(survarium::flash_value **)(*(_DWORD *)(a2 + 12) + 264),
              (Scaleform::GFx::Value *)&v81);
            goto LABEL_93;
          }
        }
LABEL_94:
        survarium::flash_value::SetElement((survarium::flash_value *)v53, &pvalue, idx, &v80);
        Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v81);
        Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v80);
        ++idx;
        p_m_begin += 19;
        --v82;
      }
      while ( v82 );
    }
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
      "root.set_settings",
      0,
      (const Scaleform::GFx::Value *)&v78,
      2u);
    v58 = (Scaleform::GFx::Value *)&v80;
    for ( i = 1; i >= 0; --i )
      Scaleform::GFx::Value::~Value(--v58);
    ++value;
    ++v87;
    --v86;
  }
  while ( v86 );
  vostok::memory::doug_lea_allocator::free_impl(v60, (int)survarium::g_allocator, &v83[-1].m_buffer[56], v65, v69, v73);
  vostok::memory::doug_lea_allocator::free_impl(v61, (int)survarium::g_allocator, &v12[-1].m_buffer[56], v66, v70, v74);
  vostok::memory::doug_lea_allocator::free_impl(v62, (int)survarium::g_allocator, &v84[-1].m_buffer[56], v67, v71, v75);
  vostok::memory::doug_lea_allocator::free_impl(v63, (int)survarium::g_allocator, &v85[-1].m_buffer[56], v68, v72, v76);
}
